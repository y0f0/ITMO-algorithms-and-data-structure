#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Node {
    int key;
    int left;
    int right;
};

bool check(int low, int high, int ind, const vector<Node>& tree) {
    if (low >= high) {
        return false;
    }

    if (ind == -1) {
        return true;
    }
    if (tree[ind].key < low || tree[ind].key > high) {
        return false;
    }
    
    return check(low, tree[ind].key, tree[ind].left, tree) &&
        check(tree[ind].key, high, tree[ind].right, tree);
}

int main() {
    ifstream fin("check.in");
    ofstream fout("check.out");
    
    int n;

    fin >> n;

    if (n <= 1)  {
        fout << "YES\n";
        return 0;
    }

    vector<Node> tree(n);

    for (auto& edge : tree) {

        int k, f, s;

        fin >> k >> f >> s;

        edge = {k, f - 1, s - 1};

    }
    
    check(-2'000'000'000, 2'000'000'000, 0, tree) ? fout << "YES\n" : fout << "NO\n";

    fin.close();
    fout.close();

    return 0;
}
