#include <iostream>
#include <map>

template <typename T> struct Pair {
    T value;
    int count;

    Pair(T val) : value(val), count(1) {}
};

template <typename T> struct Node {
    Pair<T> data;
    Node* left;
    Node* right;

    Node(T val) : data(val), left(nullptr), right(nullptr) {}
};

template <typename T> class Multiset {
private:
    Node<T>* _root;
    void insert(Node<T>* treeNode, T data);
    void search(Node<T>* treeNode, T value);
    Node<T>* erase(Node<T>* treeNode, T value);
    Node<T>* findMin(Node<T>* treeNode);
    void inOrder(Node<T>* treeNode, Multiset<T>* pairs);
    std::map<T, int> multisetToMap(Node<T>* treeNode, std::map<T, int> pairs);
    void print(Node<T>* treeNode);

public:    
    Multiset();
    void insert(T data) {
        insert(_root, data);
    }

    void search(T value) {
        search(_root, value);
    }

    void erase(T value){
        _root = erase(_root, value);
    }

    void isIncluded(Node<T>* second){
        isIncluded(_root, second);
    }

    std::map<T, int> multisetToMap(){
        std::map<T, int> temp;
        return multisetToMap(_root, temp);
    }

    bool operator==(Multiset<T>* other){
        std::map<T, int> temp1;
        std::map<T, int> temp2;
        std::map<T, int> multiset1 = multisetToMap(_root, temp1);
        std::map<T, int> multiset2 = multisetToMap(other->_root, temp2);
        return multiset1 == multiset2;
    }

    void print(){
        print(_root);
    }
};

template <typename T> Multiset<T>::Multiset() {
    _root = nullptr;
}

template <typename T> void Multiset<T>::insert(Node<T>* treeNode, T data) {
    if (!treeNode) {
        treeNode = new Node<T>(data);
    } 
    else {
        if (data < treeNode->data.value) {
            insert(treeNode->left, data);
        } 
        else if (data > treeNode->data.value) {
            insert(treeNode->right, data);
        } 
        else {
            treeNode->data.count++;
        }
    }
}

template <typename T> void Multiset<T>::search(Node<T>* treeNode, T value){
    if(!treeNode){
        return;
    }
    else{
        search(treeNode->left, value);
        if(treeNode->data.value == value){
            std::cout << "found!" << std::endl;
        }
        search(treeNode->right, value);        
    }
}

template <typename T> Node<T>* Multiset<T>::erase(Node<T>* treeNode, T data) {
    if (!treeNode) {
        return nullptr;
    }

    if (data < treeNode->data.value) {
        treeNode->left = erase(treeNode->left, data);
    } else if (data > treeNode->data.value) {
        treeNode->right = erase(treeNode->right, data);
    } else {
        if (treeNode->data.count > 1) {
            treeNode->data.count--;
        } else {
            if (!treeNode->left) {
                Node<T>* temp = treeNode->right;
                delete treeNode;
                return temp;
            } else if (!treeNode->right) {
                Node<T>* temp = treeNode->left;
                delete treeNode;
                return temp;
            }

            Node<T>* temp = findMin(treeNode->right);
            treeNode->data = temp->data;
            treeNode->right = erase(treeNode->right, temp->data.value);
        }
    }

    return treeNode;
}

template <typename T> Node<T>* Multiset<T>::findMin(Node<T>* treeNode) {
    while (treeNode->left) {
        treeNode = treeNode->left;
    }
    return treeNode;
}

template <typename T> void Multiset<T>::inOrder(Node<T>* treeNode, Multiset<T>* pairs) {
    if (treeNode) {
        inOrder(treeNode->left, pairs);
        for(int i = 0; i < treeNode->data.count; i++){
            pairs->insert(treeNode->data.value);
        }
        inOrder(treeNode->right, pairs);
    }
}

template <typename T> std::map<T, int> Multiset<T>::multisetToMap(Node<T>* treeNode, std::map<T, int> pairs){
    if(treeNode){
        multisetToMap(treeNode->left, pairs);
        pairs[treeNode->data.value] = treeNode->data.count;
        multisetToMap(treeNode->right, pairs);
    }
    return pairs;
}

template <typename T> void Multiset<T>::print(Node<T>* treeNode){
    if (treeNode) {
        print(treeNode->left);
        std::cout << " (" << treeNode->data.value << ", " << treeNode->data.count << ") " << std::endl;
        print(treeNode->right);
    }
}

int main() {
    Multiset<int> multiset1;
    Multiset<int> multiset2;

    int n, k;
    std::cin >> n;
    std::cin >> k;

    for(int i = 0; i < n; i++){
        int temp;
        std::cin>>temp;
        multiset1.insert(temp);
    }

    for(int i = 0; i < k; i++){
        int temp;
        std::cin>>temp;
        multiset2.insert(temp);
    }

    std::cout << "M1: " << std::endl;
    multiset1.print();

    std::cout << "\nM2: " << std::endl;
    multiset2.print();

    return 0;
}
