#include <bits/stdc++.h>
using namespace std;

struct edge {
  int from, to, weight;
};

const int INF = INT_MAX;

int main() {
  ifstream fin("negcycle.in");
  ofstream fout("negcycle.out");
  int n;
  fin >> n;
  vector<edge> edges;
  for (int v = 0; v < n; v++) {
    for (int u = 0; u < n; u++) {
      int weight;
      fin >> weight;
      edges.push_back({v, u, weight});
    }
  }
  int start;
  vector<int> d(n, INF), p(n, -1);
  d[0] = 0;
  for (int i = 0; i < n; i++) {
    start = -1;
    for (const auto & edge : edges) {
      auto [from, to, weight] = edge;
      if(d[to] > d[from] + weight) {
        d[to] = d[from] + weight;
        p[to] = from;
        start = to;
      }
    }
  }
  if (start == -1) {
    fout << "NO" << endl;
  } else {
    vector<int> path;
    int finish = start;
    for (int i = 0; i < n; i++)
      finish = p[finish];
    for (int cur = finish; cur != finish || path.empty(); cur = p[cur])
      path.push_back(cur);
    path.push_back(finish);
    reverse(path.begin(), path.end());
    fout << "YES" << endl;
    fout << path.size() << endl;
    for (const int& v : path)
      fout << v + 1 << ' ';
  }
  fin.close();
  fout.close();
  return 0;
}