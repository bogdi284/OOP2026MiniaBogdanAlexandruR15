#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <cctype>

struct Compare {
    bool operator()(const std::pair<std::string , int>&a , const std::pair<std::string , int>&b) const {
        if(a.second != b.second) {
            return a.second < b.second;
        }
        return a.first>b.first;
    }
};
int main () {
    std::ifstream file("input.txt");
    if(!file.is_open()) {
        std::cerr << "Eroare! Nu se poate deschide fisierul!" << std::endl;
        return 1;
    }
    std::string text((std::istreambuf_iterator<char>(file)),std::istreambuf_iterator<char>());
    file.close();

    std::map<std::string , int> wordCount;
    std::string separator = " ,?!.";

    size_t start = text.find_first_not_of(separator);
    while(start != std::string::npos) {
        size_t end = text.find_first_of(separator , start);
        std::string word = text.substr(start , end - start);
        for(char& c : word) {
            c = std::tolower(static_cast<unsigned char>(c));
        }
        wordCount[word]++;
        if(end == std::string::npos) {
            break;
        }
        start = text.find_first_not_of(separator , end);
    }
    std::priority_queue<std::pair<std::string , int> , std::vector<std::pair<std::string ,int >> , Compare> pq;
    for(const auto& pair : wordCount) {
        pq.push(pair);
    }
    while(!pq.empty()) {
        std::pair<std::string , int> topItem = pq.top();
        std::cout << topItem.first << " => "<<topItem.second << std::endl;
        pq.pop();
    }
    return 0;
}