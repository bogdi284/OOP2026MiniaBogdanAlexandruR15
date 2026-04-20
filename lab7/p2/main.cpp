#include <iostream>

template <typename T>
class vector {
    private:
        T* data;
        size_t capacity;
        size_t current_size;
        void resize() {
            capacity = (capacity == 0) ? 2 : capacity * 2;
            T* new_data = new T[capacity];
            for (size_t i = 0 ; i < current_size ; ++i) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
        }
    public:
        vector() : data(nullptr), capacity(0) , current_size(0) {}
        ~vector() {
            delete[] data;
        }
        void push_back(const T& element) {
            if(current_size == capacity) resize();
            data[current_size++] = element;
        }
        void insert(size_t index , const T& element) {
            if (index > current_size) return;
            if (current_size == capacity) resize();
            for(size_t i = current_size ; i> index ; --i) {
                data[i] = data[i-1];
            }
            data[index] = element;
            current_size++;
        }
        void remove(size_t index) {
            if(index >= current_size) return;
            for(size_t i = index ; i < current_size - 1 ; ++i) {
                data[i] = data[i+1];   
            }
            current_size--;
        }
        size_t size() const { return current_size; }
        T& operator[](size_t index) { return data[index]; }
        const T& operator[](size_t index) const { return data[index]; }
};

template <typename T>
struct TreeNode {
    T value;
    vector<TreeNode*> children;
    TreeNode* parent;

    TreeNode(T val ,TreeNode* p = nullptr) : value(val) , parent(p) {}
};

template <typename T>
class Tree {
    private:
        TreeNode<T>* root;
        void delete_subtree(TreeNode<T>* node) {
            if(!node) return;
            for(size_t i = 0 ; i<node->children.size() ; ++i) {
                delete_subtree(node->children[i]);
            }
            delete node;
        }
        TreeNode<T>* find_rec(TreeNode<T>* node , bool (*compare)(const T&)) {
            if (!node) return nullptr;
            if (compare(node->value)) return node;
            for(size_t i = 0 ; i < node->children.size() ; ++i) {
                TreeNode<T>* found = find_rec(node->children[i] , compare);
                if(found) return found;
            }
            return nullptr;
        }
        size_t count_rec(TreeNode<T>* node) {
            if(!node) return 0;
            size_t total = node->children.size();
            for(size_t i = 0 ; i< node->children.size() ; ++i) {
                total += count_rec(node->children[i]);
            }
            return total;
        }
    public:
        Tree() : root(nullptr) {}
        ~Tree() { delete_subtree(root); }
        TreeNode<T>* add_node(TreeNode<T>* parent , T value) {
            TreeNode<T>* new_node = new TreeNode<T>(value , parent);
            if (parent == nullptr) {
                if(root) delete_subtree(root);
                root=new_node;
            }
            else {
                parent->children.push_back(new_node);
            }
            return new_node;
        }
        TreeNode<T>* get_node(TreeNode<T>* parent) {
            return(parent == nullptr) ? root : parent;
        }
        void delete_node(TreeNode<T>* node) {
            if(!node) return;
            if(node->parent) {
                for(size_t i = 0 ; i < node->parent->children.size(); ++i) {
                    if(node->parent->children[i] == node) {
                        node->parent->children.remove(i);
                        break;
                    }
                }
            }
            else if(node == root) {
                root = nullptr;
            }
            delete_subtree(node);
        }
        TreeNode<T>* find(bool (*compare)(const T&)) {
            return find_rec(root , compare);
        }
        TreeNode<T>* insert(TreeNode<T>* parent , size_t index , T value) {
            if(!parent) return nullptr;
            TreeNode<T>* new_node = new TreeNode<T>(value , parent);
            parent->children.insert(index , new_node);
            return new_node;
        }
        void sort(TreeNode<T>* node , bool (*compare_func)(const T& , const T&) = nullptr) {
            if(!node || node->children.size() < 2) return;
            size_t n = node->children.size();
            for(size_t i = 0 ; i < n-1 ; ++i) {
                for(size_t j=0 ; j < n-i-1 ; ++j) {
                    bool swp = false;
                    if(compare_func !=nullptr) {
                        if(compare_func(node->children[j+1]->value , node->children[j]->value)) {
                            swp = true;
                        }
                    }
                    else {
                        if(node->children[j+1]->value < node->children[j]->value) {
                            swp = true;
                        }
                    }
                    if(swp) {
                        TreeNode<T>* temp = node->children[j];
                        node->children[j] = node->children[j+1];
                        node->children[j+1] = temp;
                    }
                }
            }
        }
        size_t count(TreeNode<T>* node) {
            return (node == nullptr) ? count_rec(root) : count_rec(node);
        }
};
bool compare_val(const int& val) {
    return val == 10;
}
int main() {
    Tree<int> myTree;
    TreeNode<int> *r = myTree.add_node(nullptr , 1);
    myTree.add_node(r,5);
    myTree.add_node(r , 10);
    std::cout<<myTree.count(nullptr)<<"\n";
    TreeNode<int>* found = myTree.find(compare_val);
    if(found) std::cout <<"It was found node with value: "<<found->value << "\n";
    return 0;
}