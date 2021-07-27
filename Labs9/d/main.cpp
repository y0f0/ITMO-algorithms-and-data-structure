#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


vector<vector<int>> edges, invert_edges;
vector<bool> used;
vector<int> sorted, components;


void top_sort(const int& v) {
  used[v] = true;
  for (const int& u : edges[v]) {
    if (!used[u]) {
      top_sort(u);
    }
  }
  sorted.push_back(v);
}

void count_components(const int& v, const int& cnt) {
  components[v] = cnt;
  for (const int& u : invert_edges[v]) {
    if (components[u] == -1) {
      count_components(u, cnt);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  edges.resize(n);
  invert_edges.resize(n);
  used.resize(n);
  components.resize(n, -1);

  for (int i = 0; i < m; i++) {
    int v, u;
    cin >> v >> u;
    --u, --v;
    edges[v].push_back(u);
    invert_edges[u].push_back(v);
  }
  for (int v = 0; v < n; v++) {
    if (!used[v]) {
      top_sort(v);
    }
  }
  int cnt = 1;
  reverse(begin(sorted), end(sorted));
  for (const int& v : sorted) {
    if (components[v] == -1) {
      count_components(v, cnt);
      cnt++;
    }
  }

  cout << cnt - 1 << endl;
  for (const int& comp : components) {
    cout << comp << ' ';
  }
}
