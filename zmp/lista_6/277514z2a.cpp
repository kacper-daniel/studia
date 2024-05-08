#include <iostream>

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}

    ~Node(){
        delete left;
        delete right;
    }
};

class BST{
    private:
        Node* _root;
        void insert(Node* treeNode, int data);
        void inOrder(Node* treeNode);
    
    public:
        BST();
        void insert(int data){
            insert(_root, data);
        }
        void inOrder(){
            inOrder(_root);
        }
};

BST::BST(){
    _root = NULL;
}

void BST::insert(Node* treeNode, int data){
    if (!treeNode){
        treeNode = new Node(data);
        _root = treeNode;
    }
    else{
        if(data < treeNode->data){
            if(!treeNode->left){
                Node* treeTemp = new Node(data);
                treeNode->left = treeTemp;
            }
            else{
                insert(treeNode->left, data);
            }
        }
        else{
            if(!treeNode->right){
                Node* treeTemp = new Node(data);
                treeNode->right = treeTemp;
            }
            else{
                insert(treeNode->right, data);
            }
        }
    }
}

void BST::inOrder(Node* treeNode){
    if(!treeNode){
        return;
    }
    inOrder(treeNode->left);
    std::cout << treeNode->data << " ";
    inOrder(treeNode->right);
}

int main(){
    int* array;
    int n;
    std::cin >> n;
    array = new int[n];

    BST bst;

    for(int i = 0; i < n; i++){
        std::cin >> array[i];
        bst.insert(array[i]);
    }

    bst.inOrder();
    return 0;
}