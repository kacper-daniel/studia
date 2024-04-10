#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;

    node(int val) : data(val), left(nullptr), right(nullptr){}
    
    // zadanie (iv)
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

// zadanie (v)      
int height(node* node){
    if (node == nullptr){
        return 0;
    }
    int depth = max(height(node->left), height(node->right)) + 1;
    return depth;
}

// zadanie (vi)
int nodes = 0;
int leafs = 0;
void count_nodes_and_leafs(node* root){
    if (root != nullptr){
        if (root->left != nullptr || root->right != nullptr){
            nodes += 1;
        }
        else{
            leafs += 1;
        }
        count_nodes_and_leafs(root->left);
        count_nodes_and_leafs(root->right);
    }
}

// zadanie (iii) 
node* build_tree(int arr[], int n){
    if(n <= 0){
        return nullptr;
    }
    node* root = new node(arr[n-1]);
    queue<node*> q;
    q.push(root);
    int i = n - 2;
    while(i >= 0){
        node* curr = q.front();
        q.pop();
        if (i >= 0){
            curr->left = new node(arr[i--]);
            q.push(curr->left);
        }
        if (i >= 0){
            curr->right = new node(arr[i--]);
            q.push(curr->right);
        }
    }
    return root;
}

// zadanie (i) - najpierw wyżej wyświetla lewe dziecko a potem niżej dopiero prawe
void print_binary_tree(string prefix, node* node, bool isLeft){
    if(node != nullptr){
        cout << prefix;
        cout << (isLeft ? "|---" : "'---");
        cout << node->data << endl;
        print_binary_tree(prefix + (isLeft ? "|   " : "   "), node->left, true);
        print_binary_tree(prefix + (isLeft ? "|   " : "   "), node->right, false);
    }
}

// zadanie (ii)


int main(){
    int n, s;
    cin >> n;
    cin >> s;

    int* bt_array;
    bt_array = new int[n];
    for(int i =0; i < n; i++){
        cin >>  bt_array[i];
    }

    node* root = build_tree(bt_array, n);

    print_binary_tree("", root, false);

    cout << "wysokosc: " << height(root) << endl;
    
    count_nodes_and_leafs(root);
    cout << "wezly:" << nodes << endl;
    cout << "liscie: " << leafs << endl;

    cout << (root->search(s) ? "jest w drzewie wartosc s = " : "nie ma w drzewie wartosci s = " ) << s << endl;
    return 0;
}