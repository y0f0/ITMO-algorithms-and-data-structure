#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<vector<int>> edges;
vector<bool> used;
vector<int> sorted;

void top_sort(const int& v) {
  used[v] = true;
  for (const int& u : edges[v]) {
    if (!used[u]) {
      top_sort(u);
    }
  }
  sorted.push_back(v);
}

bool exist_path(const int& u, const int& v) {
  for (const int& w : edges[u]) {
    if (w == v) {
      return true;
    }
  }
  return false;
}

int main() {
  int n, m;
  cin >> n >> m;
  edges.resize(n);
  used.resize(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    edges[u].push_back(v);
  }
  for (int v = 0; v < n; v++) {
    if (!used[v]) {
      top_sort(v);
    }
  }
  reverse(begin(sorted), end(sorted));
  for (int i = 0; i + 1 < n; i++) {
    if (!exist_path(sorted[i], sorted[i + 1])) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  return 0;
}
