#include <iostream>

template<typename K , typename V>
class Map {
    private:
        struct Element {
            K key;
            V value;
            int index;
        };
        Element* data;
        int count ;
        int capacity;
        void resize() {
            capacity *= 2;
            Element* newData = new Element[capacity];
            for(int i = 0 ; i < count ; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
    public:
        Map() {
            capacity = 10;
            count = 0 ;
            data = new Element[capacity];
        }
        ~Map() {
            delete[] data;
        }
        V& operator[] (const K& key) {
            for (int i = 0 ; i < count ; i++) {
                if(data[i].key == key) {
                    return data[i].value;
                }
            }
            if(count == capacity) {
                resize();
            }
            data[count].key = key;
            data[count].index = count;
            return data[count++].value;
        }
        void Set(const K& key , const V& value) {
            (*this)[key] = value;
        }
        bool Get(const K& key , V& value) const {
            for(int i = 0 ; i < count ; i++) {
                if(data[i].key == key) {
                    value = data[i].value;
                    return true;
                }
            }
            return false;
        }
        int Count() const {
            return count;
        }
        void Clear() {
            count = 0;
        }
        bool Delete(const K& key) {
            for(int i = 0 ; i < count ; i++) {
                if(data[i].key == key) {
                    for(int j = i ; j < count - 1 ; j++) {
                        data[j] = data[j+1];
                        data[j].index = j;
                    }
                    count--;
                    return true;
                }
            }
            return false;
        }
        bool Includes(const Map<K , V>& map) const {
            for(int i = 0 ; i < map.count ; i++) {
                bool found = false;
                for(int j = 0 ; j<count ; j++) {
                    if(data[j].key == map.data[i].key) {
                        found = true;
                        break;
                    }
                }
                if(!found) {
                    return false;
                }
            }
            return true;
        }
        Element* begin() {
            return data;
        }
        Element* end() {
            return data+count;
        }
};
int main () {
    Map<int , const char*>m;
    m[10]="C++";
    m[20]="test";
    m[30]="Poo";
    for(auto[key , value , index]:m) {
        printf("Index:%d , Key=%d , Value=%s \n" , index , key , value);
    }
    m[20]="result";
    for(auto[key , value , index]:m) {
        printf("Index:%d , Key=%d , Value=%s \n" , index , key , value);
    }
    return 0;
}