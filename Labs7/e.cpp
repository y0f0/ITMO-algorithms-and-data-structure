#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
#include <fstream>
using namespace std;
 
ifstream fin ("avlset.in");
ofstream fout ("avlset.out");
 
struct Node {
    int data;
    int height;
    int idx;
    Node *left;
    Node *right;
 
    Node(){}
    Node(const int& data_, const int& idx_=0, const int& height_=1,  Node *l = nullptr, Node *r = nullptr) :
        data(data_), idx(idx_), height(height_), left(l), right(r) {}
 
};
 
class AVL {
private:
    Node *root;
    int size;
 
    int countHeight(Node *node) {
        int left_height = 0;
        int right_height = 0;
        if (node->left) {
            left_height = countHeight(node->left);
        }
        if (node->right) {
            right_height = countHeight(node->right);
        }
        node->height = max(left_height, right_height) + 1;
        return max(left_height, right_height) + 1;
    }
    void countIndex() {
        Node *u = root;    
 
        queue<Node*> q;
        q.push(u);
     
        int i = 1;
 
        while (!q.empty()) {
            u = q.front();
            q.pop();
            if (u->left != nullptr && u->right != nullptr) {
                u->idx = i++;
                q.push(u->left);
                q.push(u->right);
            } else if (u->left != nullptr) {
                u->idx = i++;
                q.push(u->left);
            } else if (u->right != nullptr) {
                u->idx = i++;
                q.push(u->right);
            } else {
                u->idx = i++;
            }
        }
    }
    
    int getBalance(Node *node) {
        if (node->left && node->right) 
            return node->right->height - node->left->height;
        if (node->left) 
            return -1 * node->left->height;
        if (node->right)
            return node->right->height;
        return 0;
    }
    void fixheight(Node *node) {
        int l = node->left == nullptr ? 0 : node->left->height;
        int r = node->right == nullptr ? 0 : node->right->height;
        node->height = max(l, r) + 1;
    }
    Node *rotateRight (Node *node){
        Node *new_node = node->left;
        node->left = new_node->right;
        new_node->right = node;
        fixheight(node);
        fixheight(new_node);
        return new_node;
    }
 
    Node * rotateLeft(Node *new_node){
        Node * node = new_node->right;
        new_node->right = node->left;
        node->left = new_node;
        fixheight(new_node);
        fixheight(node);
        return node;
    }
    Node *balance(Node *node) {
        fixheight(node);    
        if (getBalance(node) == 2) {
            if (getBalance(node->right) < 0) {
                node->right = rotateRight(node->right);
            }
            return rotateLeft(node);
        }
        if (getBalance(node) == -2) {
            if (getBalance(node->left) > 0) {
                node->left = rotateLeft(node->left);
            }
            return rotateRight(node);
        }
        return node;
    }
    Node *insert_(Node *node, int value) {
        if (!node) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insert_(node->left, value);
        } else {
            node->right = insert_(node->right, value);
        }
        return balance(node);
    }
    Node *removeMin(Node *node) {
        if (!node) {
            return nullptr;
        }
        if (!node->right) {
            return node->left;
        }
        node->right = removeMin(node->right);
        return balance(node);
    }

    Node *remove_(Node *node, int value) {  
        if (!node) {
            return nullptr;
        }
        if (node->data > value) {
            node->left = remove_(node->left, value);
        } else if (node->data < value) {
            node->right = remove_(node->right, value);
        } else {
            Node *l = node->left;
            Node *r = node->right;
            if (!l) {
                return r;
            }
            Node *a = l;
            while (a->right) {
                a = a->right;
            }
            a->left = removeMin(l);
            a->right = r;
            return balance(a);
        }
        return balance(node);
    }
            
public:
    AVL() {
        root = nullptr;
        size = 0;
    }
    AVL(Node *root_, int n) {
        root = root_;
        size = n;
    };

    void print() {
        if (!size) {
            fout << 0 << endl;
            return;
        }

        countIndex();
 
        Node *u = root;    
 
        queue<Node*> q;
        q.push(u);
     
        fout << size << endl;

        while (!q.empty()) {
            u = q.front();
            q.pop();
            if (u->left && u->right) {
                fout << u->data << ' ' << u->left->idx << ' ' << u->right->idx << endl;
                q.push(u->left);
                q.push(u->right);
            } else if (u->left) {
                fout << u->data << ' ' << u->left->idx << ' ' << 0 << endl;
                q.push(u->left);
            } else if (u->right) {
                fout << u->data << ' ' << 0 << ' ' << u->right->idx << endl;
                q.push(u->right);
            } else {
                fout << u->data << ' ' << 0 << ' ' << 0 << endl;
            }
        }
    }
    void insert(int value) {
        size++;
        Node *start = root;
        countHeight(start);
        root = insert_(root, value);
    }
    void remove(int value) {
        size--;
        Node *start = root;
        countHeight(start);
        root = remove_(root, value);
    }
    int getBalanceRoot() {
        if (root == nullptr) {
            return 0;
        }
        Node *start = root;
        return getBalance(start);
    }

    char exists (const int& value) const{
        Node *new_root = root;
        while (new_root) { 
            if (value == new_root->data) {
                return 'Y';
            }

            if (value < new_root->data) {
                new_root = new_root->left;
            } else {
                new_root = new_root->right;
            }
        }
        return 'N';
    }
};
 
int main() {
 
    int n;
    int size = 0;
 
    fin >> n;
    
    AVL avl;
    
    for (int i = 0; i < n; i++) {
        int x;
        char type;
        fin >> type >> x;
        if (type == 'A') {
            avl.insert(x); 
            size++;
            if (size == 1) {
                fout << 0 << endl;
            } else {
                fout << avl.getBalanceRoot() << endl;
            }
        }
        if (type == 'D') {
            if (size > 0) {
                avl.remove(x);
                fout << avl.getBalanceRoot() << endl;
                size--;
            } else {
                fout << 0 << endl;
            }
        }
        if (type == 'C') {
            fout << avl.exists(x) << endl;
        }
    }

    fin.close();
    fout.close();
 
    return 0;
}
