#include <fstream>
#include <iostream>
#include <queue>
using namespace std;

void bfs(const int& source, const vector<vector<int>>& edges, vector<int>& d) {
  queue<int> q;
  q.push(source);
  d[source] = 0;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : edges[v]) {
      if (d[u] == -1) {
        q.push(u);
        d[u] = d[v] + 1;
      }
    }
  }
}
int main() {
  ifstream fin("pathbge1.in");
  ofstream fout("pathbge1.out");

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
  vector<int> dist(n, -1);
  bfs(0, edges, dist);
  for (int i : dist) {
    i != -1 ? fout << i << ' ' : fout << 0 << ' ';
  }
  fin.close();
  fout.close();
  return 0;
}
