#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int n, m;

  fin >> n >> m;

  vector<vector<int>> matrix(n, vector<int> (n));
  for (int i = 0; i < m; i++) {
    int u, v;
    fin >> u >> v;
    matrix[u - 1][v - 1] = 1;
  }
  for (const auto& v : matrix) {
    for (auto e : v) {
      fout << e << ' ';
    }
    fout << endl;
  }

  fin.close();
  fout.close();

  return 0;
}
