#include <iostream>
#include <vector>

class BST{
    private: 
        struct node{
            int data;
            node* left;
            node* right;

            node(int val) : data(val), left(nullptr), right(nullptr){}
        };

        node* root;
        std::vector<int> bst_array;

        node* insert(int x, node* t){
            if(t == NULL){
                t = new node(x);
                t->left = t->right = NULL;
            }
            else if(x < t->data){
                t->left = insert(x, t->left);
            }
            else if(x > t->data){
                t->right = insert(x, t->right);
            }
            return t;
        }

        void tree_to_array(node* t){
            if(t==NULL){
                return;
            }
            tree_to_array(t->left);
            bst_array.push_back(t->data);
            tree_to_array(t->right);
        }

        node* negate_tree(node* t){
            if(t == NULL){
                return nullptr;
            }
            node* new_node = new node(-t->data); 
            new_node->left = negate_tree(t->left);
            new_node->right = negate_tree(t->right);
            return new_node; 
        }

        node* add_trees(node* first, node* second){
            if(first == NULL && second == NULL){
                return nullptr;
            }
            int new_value = (first ? first->data : 0) + (second ? second->data : 0);
            node* new_node = new node(new_value);
            new_node->left = add_trees(first ? first->left : nullptr, second ? second->left : nullptr);
            new_node->right = add_trees(first ? first->right : nullptr, second? second->right : nullptr);
            return new_node;
        }

        node* subtract_trees(node* first, node* second){
            if(first == NULL && second == NULL){
                return nullptr;
            }
            int new_value = (first ? first->data : 0) - (second ? second->data : 0);
            node* new_node = new node(new_value);
            new_node->left = subtract_trees(first ? first->left : nullptr, second ? second->left : nullptr);
            new_node->right = subtract_trees(first ? first->right : nullptr, second? second->right : nullptr);
            return new_node;
        }

        int& get_node(int idx){
            bst_array.clear();
            tree_to_array(root);
            return bst_array[idx];
        }

        void print_binary_tree(std::string prefix, node* node, bool isLeft){
            if(node != nullptr){
                std::cout << prefix;
                std::cout << (isLeft ? "|---" : "'---");
                std::cout << " " << node->data << std::endl;
                print_binary_tree(prefix + (isLeft ? "|   " : "   "), node->left, true);
                print_binary_tree(prefix + (isLeft ? "|   " : "   "), node->right, false);
            }
        }

    public:
        BST(){
            root = NULL;
        }

        BST(node* t){
            root = t;
        }

        void insert(int x){
            root = insert(x, root);
        }

        BST operator-() {
            return BST(negate_tree(root));
        }

        BST operator+(BST& second){
            return BST(add_trees(root, second.root));
        }

        BST operator-(BST& second){
            return BST(subtract_trees(root, second.root));
        }

        int& operator[](int idx){
            return get_node(idx);
        }

        void print_binary_tree(){
            return print_binary_tree("", root, false);
        }
};

int main(){
    int n, k;
    std::cin >> n;
    std::cin >> k;
    BST t1;
    BST t2;
    for(int i = 0; i < n; i++){
        int temp;
        std::cin >> temp;
        t1.insert(temp);
    }
    for(int i = 0; i < k; i++){
        int temp;
        std::cin >> temp;
        t2.insert(temp);
    }
    (-t1).print_binary_tree();
    (t1+t2).print_binary_tree();
    (t2-t1).print_binary_tree();

    for(int i = 0; i < n; i++){
        std::cout << t1[i] << " ";
    }
    return 0;
}