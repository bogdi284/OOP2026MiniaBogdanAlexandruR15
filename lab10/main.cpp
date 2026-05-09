#include <iostream>
#include <exception>

using namespace std;

class IndexOutOfBoundsException : public exception
{
public:
    virtual const char* what() const throw()
    {
        return "Indexul este in afara domeniului!";
    }
};
class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};
template<class T> class Array;
template<class T>
class ArrayIterator
{
private:
    int Current;
    T** List;
public:
    ArrayIterator() : Current(0), List(nullptr) {}
    ArrayIterator(int index, T** list) : Current(index), List(list) {}
    ArrayIterator& operator ++ () {
        Current++;
        return *this;
    }
    ArrayIterator& operator -- () {
        Current--;
        return *this;
    }
    bool operator=(ArrayIterator<T>& other) {
        Current = other.Current;
        List = other.List;
        return true;
    }
    bool operator!=(ArrayIterator<T>& other) {
        return Current != other.Current;
    }
    T* GetElement() {
        if (List == nullptr) return nullptr;
        return List[Current];
    }
};
template<class T>
class Array
{
private:
    T** List;
    int Capacity;
    int Size;
    void Resize() {
        Capacity = (Capacity == 0) ? 1 : Capacity * 2;
        T** newList = new T*[Capacity];
        for (int i = 0; i < Size; i++) {
            newList[i] = List[i];
        }
        delete[] List;
        List = newList;
    }
public:
    Array() : List(nullptr), Capacity(0), Size(0) {}
    ~Array() {
        for (int i = 0; i < Size; i++) {
            delete List[i];
        }
        delete[] List;
    }
    Array(int capacity) : Capacity(capacity), Size(0) {
        List = new T*[Capacity];
    }
    Array(const Array<T>& otherArray) : Capacity(otherArray.Capacity), Size(otherArray.Size) {
        List = new T*[Capacity];
        for (int i = 0; i < Size; i++) {
            List[i] = new T(*(otherArray.List[i]));
        }
    }
    T& operator[] (int index) {
        if (index < 0 || index >= Size) {
            throw IndexOutOfBoundsException();
        }
        return *(List[index]);
    }
    const Array<T>& operator+=(const T& newElem) {
        if (Size == Capacity) Resize();
        List[Size++] = new T(newElem);
        return *this;
    }
    const Array<T>& Insert(int index, const T& newElem) {
        if (index < 0 || index > Size) {
            throw IndexOutOfBoundsException();
        }
        if (Size == Capacity) Resize();
        
        for (int i = Size; i > index; i--) {
            List[i] = List[i - 1];
        }
        List[index] = new T(newElem);
        Size++;
        return *this;
    }
    const Array<T>& Insert(int index, const Array<T> otherArray) {
        if (index < 0 || index > Size) throw IndexOutOfBoundsException();
        
        while (Size + otherArray.Size > Capacity) Resize();
        
        for (int i = Size - 1; i >= index; i--) {
            List[i + otherArray.Size] = List[i];
        }
        for (int i = 0; i < otherArray.Size; i++) {
            List[index + i] = new T(*(otherArray.List[i]));
        }
        Size += otherArray.Size;
        return *this;
    }
    const Array<T>& Delete(int index) {
        if (index < 0 || index >= Size) {
            throw IndexOutOfBoundsException();
        }
        delete List[index];
        for (int i = index; i < Size - 1; i++) {
            List[i] = List[i + 1];
        }
        Size--;
        return *this;
    }
    bool operator=(const Array<T>& otherArray) {
        for (int i = 0; i < Size; i++) delete List[i];
        delete[] List;
        
        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        List = new T*[Capacity];
        for (int i = 0; i < Size; i++) {
            List[i] = new T(*(otherArray.List[i]));
        }
        return true;
    }
    void Sort() {
        for (int i = 0; i < Size - 1; i++)
            for (int j = 0; j < Size - i - 1; j++)
                if (*(List[j]) > *(List[j + 1])) {
                    T* temp = List[j];
                    List[j] = List[j + 1];
                    List[j + 1] = temp;
                }
    }
    void Sort(int(*compare)(const T&, const T&)) {
        for (int i = 0; i < Size - 1; i++)
            for (int j = 0; j < Size - i - 1; j++)
                if (compare(*(List[j]), *(List[j + 1])) > 0) {
                    T* temp = List[j];
                    List[j] = List[j + 1];
                    List[j + 1] = temp;
                }
    }
    void Sort(Compare* comparator) {
        for (int i = 0; i < Size - 1; i++)
            for (int j = 0; j < Size - i - 1; j++)
                if (comparator->CompareElements(List[j], List[j + 1]) > 0) {
                    T* temp = List[j];
                    List[j] = List[j + 1];
                    List[j + 1] = temp;
                }
    }
    int BinarySearch(const T& elem) {
        int l = 0, r = Size - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (*(List[m]) == elem) return m;
            if (*(List[m]) < elem) l = m + 1;
            else r = m - 1;
        }
        return -1;
    }
    int Find(const T& elem) {
        for (int i = 0; i < Size; i++) {
            if (*(List[i]) == elem) return i;
        }
        return -1;
    }
    int GetSize() { return Size; }
    int GetCapacity() { return Capacity; }
    ArrayIterator<T> GetBeginIterator() {
        return ArrayIterator<T>(0, List);
    }
    ArrayIterator<T> GetEndIterator() {
        return ArrayIterator<T>(Size, List);
    }
};
int main()
{
    try
    {
        Array<int> arr(5);
        arr += 10;
        arr += 20;
        arr.Insert(1, 15);
        
        cout << "Elementul de la index 1: " << arr[1] << endl;
        
        cout << "Element in afara limitelor: " << arr[50] << endl;
    }
    catch (exception& e)
    {
        cout << "Exceptie prinsa: " << e.what() << endl;
    }
    return 0;
}