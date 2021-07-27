#include <set>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int n, m;
  fin >> n >> m;
  vector<set<int>> edges(n);
  bool ok = true;
  for (int i = 0; i < m; i++) {
    int u, v;
    fin >> u >> v;
    --u, --v;
    if (edges[u].count(v) > 0) {
      ok = false;
    } else {
      edges[u].insert(v);
    }
    if (edges[v].count(u) > 0) {
      ok = false;
    } else {
      edges[v].insert(u);
    }
  }

  !ok ? fout << "YES\n" : fout << "NO\n";

  fin.close();
  fout.close();

  return 0;
}
