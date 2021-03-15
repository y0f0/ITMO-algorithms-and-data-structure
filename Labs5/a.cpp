#include <stack>
#include <vector>
#include <utility>
#include <fstream>
using namespace std;


int CountHeight(int ind, const vector<pair<int, int>>& tree) {
    int left_height = 0;
    int right_height = 0;
    if (tree[ind].first != -1) {
        left_height = CountHeight(tree[ind].first, tree);
    }
    if (tree[ind].second != -1) {
        right_height = CountHeight(tree[ind].second, tree);
    }
    return max(left_height, right_height) + 1;
}

int main() {
    ifstream fin ("height.in");
    ofstream fout ("height.out");

    int n;

    fin >> n;

    if (n == 0)  {
        fout << 0;
        return 0;
    }

    vector<pair<int,int>> tree(n);

    for (auto& edge : tree) {

        int k, f, s;

        fin >> k >> f >> s;

        edge = make_pair(f - 1, s - 1);

    }
    

    fout << CountHeight(0, tree);

    fin.close();
    fout.close();
    return 0;
}
