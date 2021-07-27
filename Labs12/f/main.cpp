#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> num;
vector<vector<int>> d;
vector<vector<int>> graph;
int sum;

void dfs(int v) {
  d[v][0] = 0;
  d[v][1] = num[v];

  for (int u : graph[v])
    dfs(u);

  for (int u : graph[v]) {
    d[v][1] += d[u][0];
    d[v][0] += max(d[u][0], d[u][1]);
  }

  if (sum < d[v][1] || sum < d[v][0])
    if (d[v][1] <= d[v][0]) 
      sum = d[v][0];
    else 
      sum = d[v][1];

}

int main() {
  ifstream in("selectw.in");
  ofstream out("selectw.out");

  int n, x, y;
  in >> n;

  d.resize(n, vector<int>(2));
  graph.resize(n, vector<int>());
  num.resize(n);

  for (int i = 0; i < n; i++) {
    in >> x >> y;
    num[i] = y;
    if (x != 0)
      graph[x - 1].push_back(i);
  }

  for (int i = 0; i < n; i++)
    dfs(i);

  out << sum << endl;

  return 0;
}