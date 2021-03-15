#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
using namespace std;

struct Node {
    int height = 0;
    int idx;
    int left;
    int right;

    Node (int idx_, int left_, int right_) :
        idx(idx_), left(left_), right(right_) {}
};

int CountHeight(const int& indx, vector<Node>& avl) {
    int left_height = 0;
    int right_height = 0;
    if (avl[indx].left != -1) {
        left_height = CountHeight(avl[indx].left, avl);
    }
    if (avl[indx].right != -1) {
        right_height = CountHeight(avl[indx].right, avl);
    }
    avl[indx].height = max(left_height, right_height) + 1;
    return max(left_height, right_height) + 1;
}

int main() {
    ifstream fin ("balance.in");
    ofstream fout ("balance.out");

    int n;

    fin >> n;

    if (n == 1)  {
        fout << 0;
        return 0;
    }

    vector<Node> avl;
    vector<int> diff(n);

    for (int i = 0; i < n; i++) {
        int k, l, r;

        fin >> k >> l >> r;
        
        avl.push_back( Node{i, l - 1, r - 1} );
    }
    
    CountHeight(0, avl);
    
    for (int i = 0; i < n; i++) {
        if (avl[i].left != -1 && avl[i].right != -1) {
            diff[i] = avl[avl[i].right].height - avl[avl[i].left].height;
        } else if (avl[i].left != -1) {
            diff[i] = -avl[avl[i].left].height;
        } else if (avl[i].right != -1) {
            diff[i] = avl[avl[i].right].height;
        } else {
            diff[i] = 0;
        }
    }

    for (const auto& e : diff) {

        fout << e << '\n';

    }


    fin.close();
    fout.close();
    return 0;
}
