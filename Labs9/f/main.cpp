#include <iostream>
#include <vector>
#include <string>
using namespace std;


vector<vector<int>> edges;
vector<bool> used;
vector<string> how_wins;
const string win_first = "First player wins";
const string win_second = "Second player wins";

void dfs(const int& v){
  used[v] = true;
  string status = win_second;
  for (const int& u : edges[v]) {
    if (!used[u]) {
      dfs(u);
    }
    if (how_wins[u] == win_second) {
      status = win_first;
    }
  }
  how_wins[v] = status;
}

int main() {
  int n, m, s;
  cin >> n >> m >> s;
  edges.resize(n);
  used.resize(n);
  how_wins.resize(n, win_second);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    edges[u - 1].push_back(v - 1);
  }
  dfs(s - 1);
  cout << how_wins[s - 1];
  return 0;
}
