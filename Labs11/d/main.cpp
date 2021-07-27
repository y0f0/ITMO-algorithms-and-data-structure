#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 8e18;

struct Edge {
  int from, to;
  ll weight;
};

void dfs(int u, const vector<vector<int>> &adj, vector<bool> &used) {
  used[u] = true;
  for (const auto& v : adj[u])
    if (!used[v])
      dfs(v, adj, used);
}

void solve (const int start, const vector<Edge>& edges, vector<ll>& d, const vector<vector<int>> &adj, vector<int>& p) {
  d[start] = 0;
  vector<int> q;
  for (int _ = 0; _ < adj.size(); _++) {
    q.clear();
    for (const auto& edge : edges) {
      auto [from, to, weight] = edge;
      if (d[from] < INF)
        if (d[to] > d[from] + weight) {
          d[to] = max(-INF, d[from] + weight);
          p[to] = from;
          if (!any_of(begin(q), end(q), [edge](int i) { return i == edge.to; }))
            q.push_back(to);
        }
    }
    if (q.empty())
      break;
  }

  while (!q.empty()) {
    int x = q.back();
    q.pop_back();
    for (int i = 0; i < adj.size(); i++)
      x = p[x];

    vector<bool> visited (adj.size(), false);
    dfs(x, adj, visited);

    for (int i = 0; i < adj.size(); i++)
      if (visited[i])
        d[i] = -INF;
  }
}

int main() {
  ifstream fin("path.in");
  ofstream fout("path.out");

  int n, m, s;
  fin >> n >> m >> s;
  vector<Edge> edges;
  vector<int> p(n, -1);
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    int from, to;
    ll weight;
    fin >> from >> to >> weight;
    edges.push_back({from - 1, to - 1, weight});
    adj[from - 1].push_back(to - 1);
  }

  vector<ll> d(n, INF);
  solve(s - 1, edges, d, adj, p);

  for (const ll& dist : d) {
    switch (dist) {
      case -INF:
        fout << "-\n";
        break;
      case INF:
        fout << "*\n";
        break;
      default:
        fout << dist << "\n";
    }
  }

  fout.close();
  fin.close();
  return 0;
}