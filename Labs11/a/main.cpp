#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = LONG_LONG_MAX;


vector<ll> Dijkstra(const vector<vector<pair<ll,ll>>>& g, const ll& n, const ll& s) {
  vector <char> u(n);
  vector <ll> d(n, INF), p(n);
  d[s] = 0;
  for (ll i = 0; i < n; i++) {
    ll v = -1;
    for (ll j = 0; j < n; j++)
      if (!u[j] && (v == - 1 || d[j] < d[v]))
        v = j;
    if (d[v] == INF)
      break;
    u[v] = true;

    for (auto e: g[v]) {
      auto& [to, len] = e;
      if (d[v] + len < d[to]) {
        d[to] = d[v] + len;
        p[to] = v;
      }
    }
  }
  return d;
}


int main() {
  ifstream fin("pathmgep.in");
  ofstream fout("pathmgep.out");

  ll n, s, f, w;
  fin >> n >> s >> f;
  --s, --f;
  vector <vector <pair<ll, ll> > > g(n);
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < n; j++) {
      fin >> w;
      if (w != -1)
        g[i].push_back(make_pair(j, w));
    }
  }

  Dijkstra(g, n, s)[f] == INF ? fout << -1: fout <<  Dijkstra(g, n, s)[f];

  fin.close();
  fout.close();
  return 0;
}
