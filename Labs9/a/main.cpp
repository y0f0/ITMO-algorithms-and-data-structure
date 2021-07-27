#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


vector<vector<int>> edges;
vector<vector<int>> invert_edges;
vector<bool> used;
vector<int> sorted;
vector<int> components;
int counter_components = 1;

void top_sort(const int& v) {
  used[v] = true;
  for (const int& u : edges[v]) {
    if (!used[u]) {
      top_sort(u);
    }
  }
  sorted.push_back(v + 1);
}

void count_components(const int& v) {
  components[v] = counter_components;
  for (const int& u : invert_edges[v]) {
    if (components[u] == 0) {
      count_components(u);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  edges.resize(n);
  used.resize(n);
  components.resize(n);
  invert_edges.resize(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    edges[u].push_back(v);
    invert_edges[v].push_back(u);
  }
  for (int v = 0; v < n; v++) {
    if (!used[v]) {
      top_sort(v);
    }
  }

  reverse(sorted.begin(), sorted.end());
  for (const int& v : sorted) {
    if (components[v] == 0) {
      count_components(v);
      counter_components++;
    }
  }
  cout << counter_components - 1 << endl;
  for (const int& v : components) {
    cout << v << ' ';
  }
  return 0;
}
