#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> d;
vector<vector<int>> graph;
int ans;

void dfs(int v) {
  d[v][0] = 0;
  d[v][1] = 1;

  for (int u : graph[v])
    dfs(u);

  for (int u : graph[v]) {
    d[v][1] += d[u][0];
    d[v][0] += max(d[u][0], d[u][1]);
  }

  if (ans < d[v][1] || ans < d[v][0])
    if (d[v][1] <= d[v][0])
      ans = d[v][0];
    else
      ans = d[v][1];
}

int main() {
  int n, x;
  cin >> n;

  d.resize(n, vector<int>(2));
  graph.resize(n, vector<int>());

  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x != 0)
      graph[x - 1].push_back(i);
  }

  for (int i = 0; i < n; i++)
    dfs(i);

  cout << ans << endl;

  return 0;
}