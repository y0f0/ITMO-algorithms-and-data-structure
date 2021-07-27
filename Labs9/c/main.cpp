#include <vector>
#include <iostream>
using namespace std;

bool bipartite = true;
vector<vector<int>> edges;
vector<int> colors;

int invert(const int& color) {
  return (color == 1) ? 2 : 1;
}

void dfs(const int& u, const int& color) {
  colors[u] = color;
  for (const int& v : edges[u]) {
    if (colors[v] == 0) {
      dfs(v, invert(color));
    } else if (colors[v] == color) {
      bipartite = false;
    }
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  edges.resize(n);
  colors.resize(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  for (int u = 0; u < n; u++) {
    if (colors[u] == 0) {
      dfs(u, 1);
      if (!bipartite) {
        break;
      }
    }
  }
  cout << ( bipartite ? "YES" : "NO" ) << endl;

  return 0;
}
