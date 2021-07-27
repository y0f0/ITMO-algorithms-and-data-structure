#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


bool has_cycle = false;

void dfs(const int& v, const vector<vector<int>>& edges, vector<int>& colors, vector<int>& path) {
  if (has_cycle) return;

  colors[v] = 1;
  path.push_back(v + 1);
  for (const int& u : edges[v]) {
    if (colors[u] == 0) {
      dfs(u, edges, colors, path);
    } else if (colors[u] == 1) {
      path.push_back(u + 1);
      has_cycle = true;
      return;
    }
    if (has_cycle) return;
  }
  colors[v] = 2;
  path.pop_back();
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> edges(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    edges[u].push_back(v);
  }
  vector<int> colors(n, 0);
  vector<int> path;
  for (int v = 0; v < n; v++) {
    if (colors[v] == 0) {
      dfs(v, edges, colors, path);
      if (has_cycle) {
        break;
      }
    }
  }
  if (!has_cycle) {
    cout << "NO\n";
  } else {
    cout << "YES" << endl;
    auto it = path.end() - 2;
    for (; *it != path.back(); it--) {} //ищем вершину в которой зациклились

    for (;it != path.end() - 1; it++) { //выводим
      cout << *it << " ";
    }
    cout << endl;
  }
  return 0;
}