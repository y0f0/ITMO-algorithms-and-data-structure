#include <vector>
#include <fstream>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> PairLL;
vector<vector<PairLL>> adj;
vector<bool> used;
ll n, m;

ll pqMST() {
  ll res= 0;
  priority_queue<PairLL, vector<PairLL>, greater<> > pq;
  pq.push(make_pair(0, 0));
  while (!pq.empty()) {
    ll v_dist = pq.top().first;
    ll v = pq.top().second;
    pq.pop();
    if (used[v])
      continue;
    used[v] = true;
    res += v_dist;
    for (const auto & [u, u_dist] : adj[v])
      if (!used[u])
        pq.push(make_pair(u_dist, u));
  }
  return res;
}

int main() {
  ifstream fin("spantree3.in");
  ofstream fout("spantree3.out");
  fin >> n >> m;
  adj.resize(n);
  used.resize(n);
  for (ll i = 0; i < m; i++) {
    ll b, e, w;
    fin >> b >> e >> w;
    adj[b - 1].push_back(make_pair(e - 1, w));
    adj[e - 1].push_back(make_pair(b - 1, w));
  }
  fout << pqMST() << endl;
  fin.close();
  fout.close();
  return 0;
}