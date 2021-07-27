#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = LONG_LONG_MAX;


vector<ll> Dijkstra(const vector<vector<pair<ll,ll>>>& g, const ll& n, const ll& s) {
  priority_queue<pair<ll, ll>, vector<pair<ll,ll>>, greater<>> pq;
  vector<ll> d(n, INF);
  d[s] = 0;
  pq.push(make_pair(0, s));

  while (!pq.empty()) {
    auto [_, u] = pq.top();
    pq.pop();
    for (const auto& [v, w] : g[u]) {
      if (d[v] > d[u] + w) {
        d[v] = d[u] + w;
        pq.push(make_pair(d[v], v));
      }
    }
  }

  return d;
}


int main() {
  ifstream fin("pathsg.in");
  ofstream fout("pathsg.out");

  ll n, m;
  fin >> n >> m;
  vector <vector <pair<ll, ll> > > g(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    fin >> u >> v >> w;
    g[u - 1].push_back(make_pair(v - 1, w));
  }

  for (int s = 0; s < n; s++) {
    for (const ll &dist : Dijkstra(g, n, s)) {
      fout << dist << ' ';
    }
    fout << endl;
  }

  fin.close();
  fout.close();
  return 0;
}
