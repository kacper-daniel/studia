#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}

    ~Node() {
        cout << "Niszcze node o wartosci " << data << endl;
        delete left;
        delete right;
    }

    void show_tree(){
        cout << data << " ";
        if (left!=nullptr){
            left->show_tree();
        }
        if (right!=nullptr){
            right->show_tree();
        }
    }

    bool search(int val){
        if (data == val) return 1;
        else if (left != nullptr && left->search(val)){
            return 1;
        } else if (right != nullptr && right->search(val)){
            return 1;
        }
        return 0;
    }
};

int main(){
    Node* root = new Node(0);
    root->left=new Node(1);
    root->right=new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->show_tree();
    cout << "\n" << root->search(4) << endl;
    delete root;
    return 0;
}