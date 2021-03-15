#include <fstream>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(const int& data_, Node *l = nullptr, Node *r = nullptr) :
        data(data_), left(l), right(r) {}

};

class BST {
private:
    Node *root;
public:
    int size;

    BST() {
        root = nullptr;
        size = 0;
    };


    Node *next(const int& x) {
        Node *new_root = root;
        Node *minNode = nullptr;
        int min = 2e9;
        while (new_root) {
            if (new_root->data > x) {
                if (new_root->data < min) {
                    min = new_root->data;
                    minNode = new_root;
                }
                new_root = new_root->left;
            } else {
                new_root = new_root->right;
            }
        }
        return minNode;
    }

    Node *prev(const int& x) {
        Node *new_root = root;
        Node *maxNode = nullptr;
        int max = -2e9;
        while (new_root) {
            if (new_root->data < x) {
                if (new_root->data > max) {
                    max = new_root->data;
                    maxNode = new_root;
                }
                new_root = new_root->right;
            } else {
                new_root = new_root->left;
            }
        }
        return maxNode;
    }
    void insert(const int& x) {
        if (!size) {
            root = new Node(x);
            ++size;
            return;
        }
        Node *new_root = root;
        while (new_root) {
            if (new_root->data > x) {
                if (!new_root->left) {
                    new_root->left = new Node(x);
                    ++size;
                }
                new_root = new_root->left;
            } else if (new_root->data < x) {
                if (!new_root->right) {
                    new_root->right = new Node(x);
                    ++size;
                }
                new_root = new_root->right;
            } else {
                return;
            }
        }
    }

    bool exists (const int& value) const{
        Node *new_root = root;
        while (new_root) { 
            if (value == new_root->data) {
                return true;
            }

            if (value < new_root->data) {
                new_root = new_root->left;
            } else {
                new_root = new_root->right;
            }
        }
        return false;
    }
    void delete_(const int& x) {
        Node *new_root = root;
        Node *last = nullptr;
        if (size == 0 || root == nullptr) {
            return;
        }
        if (size == 1 && root->data == x) {
            delete root;
            root = nullptr;
            --size;
            return;
        }
        while (new_root) {
            if (new_root->data  > x) {
                last = new_root;
                new_root = new_root->left;
            } else if (new_root->data < x) {
                last = new_root;
                new_root = new_root->right;
            } else {
                while (new_root) {
                    if (!new_root->left && !new_root->right) {
                        if (new_root == root) {
                            root = nullptr;
                        } else {
                            last->right = last->right == new_root ? nullptr : last->right;
                            last->left = last->left == new_root ? nullptr : last->left;
                        }
                        delete new_root;
                        new_root = nullptr;
                        --size;
                        return;
                    } else if (!new_root->left || !new_root->right) {
                        Node *child = (new_root->right ? new_root->right : new_root->left);
                        if (new_root == root) {
                            root = child;
                        } else {
                            last->right = last->right == new_root ? child : last->right;
                            last->left = last->left == new_root ? child : last->left;
                        }
                        delete new_root;
                        new_root = nullptr;
                        --size;
                        return;
                    } else {
                        int n = next(x)->data;
                        delete_(n);
                        new_root->data = n;
                        return;
                    }
                }
            }
        }
    }

};


int main() {
    ifstream fin("bstsimple.in");
    ofstream fout("bstsimple.out");

    BST tree;
    string command;
    int x;

    while (fin >> command) {
        if (command == "insert") {

            fin >> x;

            tree.insert(x);
        } 
        if (command == "exists") {

            fin >> x;

            if (tree.exists(x)) {
                fout << "true" << endl;
            } else {
                fout << "false" << endl;
            }
        } 
        if (command == "next") {

            fin >> x;

            Node *next = tree.next(x);
            if (next) {
                fout << next->data << endl;
            } else {
                fout << "none" << endl;
            }
        } 
        if (command == "prev") {

            fin >> x;

            Node *prev = tree.prev(x);
            if (prev) {
                fout << prev->data << endl;
            } else {
                fout << "none" << endl;
            }
        }
        if (command == "delete") {
            
            fin >> x;

            tree.delete_(x);
        }
    }
    
    fin.close();
    fout.close();

    return 0;
}
