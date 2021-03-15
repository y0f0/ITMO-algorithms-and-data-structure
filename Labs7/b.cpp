#include <tuple>
#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
using namespace std;

ifstream fin ("rotation.in");
ofstream fout ("rotation.out");

struct Node {
    int data;
    int height;
    int balance;
    int idx;
    Node *left;
    Node *right;

    Node(){}
    Node(const int& data_, const int& idx_=0, const int& height_=0,  Node *l = nullptr, Node *r = nullptr) :
        data(data_), idx(idx_), height(height_), left(l), right(r) {}

};

class AVL {
private:
    Node *root;
    int size;
    vector<int> diff;

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
    void countDifference() {
        Node *u = root;    
        Node *start = root;

        countHeight(start);

        queue<Node*> q;
        q.push(u);

        while (!q.empty()) {
            u = q.front();
            q.pop();
            if (u->left && u->right) {
                u->balance = u->right->height - u->left->height;
                q.push(u->left);
                q.push(u->right);
            } else if (u->left) {
                u->balance = -u->left->height;
                q.push(u->left);
            } else if (u->right) {
                u->balance = u->right->height; 
                q.push(u->right);
            } else {
                u->balance = 0;
            }
        }
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
public:

    AVL(Node *root_, int n) {
        root = root_;
        size = n;
    };
    vector<int> getDifference() {
        return diff;
    }
   
    void leftBigRotate() {
        Node *a, *b, *c;
        a = root;
        b = root->right;
        c = root->right->left;
        a->right = c->left;
        b->left = c->right;
        c->left = a;
        c->right = b;
        root = c;
    } 
    void leftSmallRotate() {
        Node *a, *b;
        a = root;
        b = root->right;
        a->right = b->left;
        b->left = a;
        root = b;
    }

    void rotation() {
        countDifference();
        if (root->right->balance == -1) { 
            leftBigRotate();
        } else {
            leftSmallRotate();
        }
    }
    void print() {
        countIndex();

        Node *u = root;    

        queue<Node*> q;
        q.push(u);
    
        fout << size << endl;

        while (!q.empty()) {
            u = q.front();
            q.pop();
            if (u->left != nullptr && u->right != nullptr) {
                fout << u->data << ' ' << u->left->idx << ' ' << u->right->idx << endl;
                q.push(u->left);
                q.push(u->right);
            } else if (u->left != nullptr) {
                fout << u->data << ' ' << u->left->idx << ' ' << 0 << endl;
                q.push(u->left);
            } else if (u->right != nullptr) {
                fout << u->data << ' ' << 0 << ' ' << u->right->idx << endl;
                q.push(u->right);
            } else {
                fout << u->data << ' ' << 0 << ' ' << 0 << endl;
            }
        }
    }
    /* void insert(const int& value, const int& idx_) { */
    /*     if (!size) { */
    /*         root = new Node(value, idx_); */
    /*         ++size; */
    /*         return; */
    /*     } */

    /*     Node *new_root = root; */

    /*     while (new_root) { */
    /*         if (value < new_root->data) { */
    /*             if (!new_root->left) { */ 
    /*                 new_root->left = new Node(value, idx_); */
    /*                 ++size; */
    /*             } */
    /*             new_root = new_root->left; */
    /*         } else if (value > new_root->data) { */
    /*             if (!new_root->right) { */
    /*                 new_root->right = new Node(value, idx_); */
    /*                 ++size; */
    /*             } */
    /*             new_root = new_root->right; */
    /*         } else { */
    /*             return; */
    /*         } */
    /*     } */
    /* } */
    

};

int main() {

    int n;

    fin >> n;

    vector<tuple<Node, int, int> > input(n);

    for (int i = 0; i < n; i++) {
        int k, l, r;

        fin >> k >> l >> r;
        
        input[i] = make_tuple(Node(k), l - 1, r - 1); 
    }

    for (int i = 0; i < n; i++) {
        if (get<1>(input[i]) != -1) { 
            get<0>(input[i]).left = &get<0>(input[get<1>(input[i])]);
        }
        if (get<2>(input[i]) != -1) { 
            get<0>(input[i]).right = &get<0>(input[get<2>(input[i])]);
        }
    }  

    AVL avl(&get<0>(input[0]), n);
    
    avl.rotation();
    avl.print();


    fin.close();
    fout.close();

    return 0;
}
