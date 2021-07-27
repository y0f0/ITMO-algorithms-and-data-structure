#include <bits/stdc++.h>
using namespace std;
typedef long int ll;
const ll INF = LONG_MAX;


vector<ll> Dijkstra(const vector<vector<pair<ll,ll>>>& g, const ll& n, const ll s) {
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
  ifstream fin("pathbgep.in");
  ofstream fout("pathbgep.out");

  ll n, m;
  fin >> n >> m;
  vector <vector <pair<ll, ll> > > g(n);
  for (int i = 0; i < m; i++) {
    ll u, v, w;
    fin >> u >> v >> w;
    g[u - 1].push_back(make_pair(v - 1, w));
    g[v - 1].push_back(make_pair(u - 1, w));
  }

  for (const auto& dist : Dijkstra(g, n, 0)) {
    fout << dist << ' ';
  }

  fin.close();
  fout.close();
  return 0;
}