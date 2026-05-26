#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

enum class ContactType {
    Friend,
    Acquaintance,
    Colleague
};

class Contact {
protected:
    std::string name;
public:
    Contact(const std::string& name) : name(name) {}
    virtual ~Contact() = default;

    std::string getName() const { return name; }
    
    virtual ContactType getType() const = 0; 
    virtual void print() const = 0; 
};

class Friend : public Contact {
private:
    std::string dob;
    std::string phoneNumber;
    std::string address;
public:
    Friend(const std::string& name, const std::string& dob, const std::string& phone, const std::string& address)
        : Contact(name), dob(dob), phoneNumber(phone), address(address) {}

    ContactType getType() const override { return ContactType::Friend; }

    void print() const override {
        std::cout << "[Friend] Name: " << name << " | DOB: " << dob 
                  << " | Phone: " << phoneNumber << " | Address: " << address << "\n";
    }
};

class Acquaintance : public Contact {
private:
    std::string phoneNumber;
public:
    Acquaintance(const std::string& name, const std::string& phone)
        : Contact(name), phoneNumber(phone) {}

    ContactType getType() const override { return ContactType::Acquaintance; }

    void print() const override {
        std::cout << "[Acquaintance] Name: " << name << " | Phone: " << phoneNumber << "\n";
    }
};

class Colleague : public Contact {
private:
    std::string phoneNumber;
    std::string company;
    std::string address;
public:
    Colleague(const std::string& name, const std::string& phone, const std::string& company, const std::string& address)
        : Contact(name), phoneNumber(phone), company(company), address(address) {}

    ContactType getType() const override { return ContactType::Colleague; }

    void print() const override {
        std::cout << "[Colleague] Name: " << name << " | Phone: " << phoneNumber 
                  << " | Company: " << company << " | Address: " << address << "\n";
    }
};

class AddressBook {
private:
    std::vector<std::shared_ptr<Contact>> contacts;
public:
    void addContact(std::shared_ptr<Contact> contact) {
        contacts.push_back(contact);
    }

    std::shared_ptr<Contact> searchByName(const std::string& name) const {
        for (const auto& contact : contacts) {
            if (contact->getName() == name) {
                return contact;
            }
        }
        return nullptr;
    }

    std::vector<std::shared_ptr<Friend>> getFriends() const {
        std::vector<std::shared_ptr<Friend>> friendsList;
        for (const auto& contact : contacts) {
            if (contact->getType() == ContactType::Friend) {
                friendsList.push_back(std::static_pointer_cast<Friend>(contact));
            }
        }
        return friendsList;
    }

    bool deleteContactByName(const std::string& name) {
        auto it = std::remove_if(contacts.begin(), contacts.end(),
                                 [&name](const std::shared_ptr<Contact>& c) { return c->getName() == name; });
        if (it != contacts.end()) {
            contacts.erase(it, contacts.end());
            return true;
        }
        return false;
    }

    void printAllContacts() const {
        for (const auto& contact : contacts) {
            contact->print();
        }
    }
};

int main() {
    AddressBook myAddressBook;

    myAddressBook.addContact(std::make_shared<Friend>("Alexandru Popescu", "15-05-1990", "0722123456", "Strada Florilor nr. 10"));
    myAddressBook.addContact(std::make_shared<Acquaintance>("Mihai Ionescu", "0744987654"));
    myAddressBook.addContact(std::make_shared<Colleague>("Elena Radu", "0766111222", "TechCorp SRL", "Bulevardul Unirii 55"));
    myAddressBook.addContact(std::make_shared<Friend>("Andreea Stan", "22-11-1992", "0755333444", "Aleea Rozelor nr. 2"));

    myAddressBook.printAllContacts();

    auto searchResult = myAddressBook.searchByName("Elena Radu");
    if (searchResult) {
        searchResult->print();
    }

    std::vector<std::shared_ptr<Friend>> friends = myAddressBook.getFriends();
    for (const auto& f : friends) {
        f->print();
    }

    myAddressBook.deleteContactByName("Mihai Ionescu");

    myAddressBook.printAllContacts();

    return 0;
}