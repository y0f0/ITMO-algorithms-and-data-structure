#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

void dfs (int& u, vector<bool>& used, vector<vector<int>>& edges, vector<vector<int>>& comp) {
  used[u] = true;
  comp.back().push_back(u);
  for (auto v : edges[u]) {
    if (!used[v]) {
      dfs(v, used, edges, comp);
    }
  }
}
int main() {
  ifstream fin("components.in");
  ofstream fout("components.out");

  int n, m;
  fin >> n >> m;
  vector<vector<int>> edges(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    fin >> u >> v;
    u--, v--;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  vector<bool> used(n);
  vector<vector<int>> comp;
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      comp.emplace_back();

      dfs(i, used, edges, comp);
    }
  }
  fout << comp.size() << endl;
  vector<int> count(n);
  for (int i = 0; i < comp.size(); i++) {
    for (int vertex : comp[i]) {
      count[vertex] = i + 1;
    }
  }
  for (int e : count) {
    fout << e << ' ';
  }
  fin.close();
  fout.close();

  return 0;
}
