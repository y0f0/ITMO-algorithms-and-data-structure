#include <fstream>
#include <vector>
using namespace std;

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");
  int n, m;
  fin>> n >> m;
  vector<vector<int>> edges(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    fin>> u >> v;
    edges[u - 1].push_back(v - 1);
    edges[v - 1].push_back(u - 1);
  }
  for (const auto& v : edges) {
    fout<< v.size() << ' ';
  }
  fin.close();
  fout.close();
  return 0;
}
