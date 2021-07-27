#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;
const ll MOD = 1'000'000'000;
vector<int> graph;
vector<vector<ll>> d;

ll calc(int i, int j) {
    if (d[i][j] == -1) {
        if (graph[i] == graph[j])
            d[i][j] = (calc(i + 1, j) + calc(i, j - 1) + 1) % MOD;
        else
            d[i][j] = (calc(i + 1, j) + calc(i, j - 1) - calc(i + 1, j - 1) + MOD) % MOD;
    }
    return d[i][j] % MOD;
}

int main() {
    int n, color;
    cin >> n;
    graph.resize(n);
    d.resize(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                d[i][j] = 1;
            else if (i < j)
                d[i][j] = -1;
            else
                d[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> color;
        graph[i] = color;
    }

    cout << calc(0, n - 1) % MOD << endl;
    return 0;
}