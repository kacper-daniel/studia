#include <iostream>

class BST{
    private: 
        struct node{
            int data;
            node* left;
            node* right;
        };

        node* root;
        int length;

        node* insert(int x, node* t){
            if(t == NULL){
                t = new node;
                t->data = x;
                t->left = t->right = NULL;
                length++;
            }
            else if(x < t->data){
                t->left = insert(x, t->left);
            }
            else{
                t->right = insert(x, t->right);
            }

            return t;
        }

    public:
        BST(){
            root = NULL;
        }

};

int main(){
    return 0;
}