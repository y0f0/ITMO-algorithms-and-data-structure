#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int n;
  fin >> n;
  vector<vector<int>> matrix(n, vector<int> (n));

  for (auto& v : matrix) {
    for (auto& e : v) {
      fin >> e;
    }
  }

  bool ok = true;
  for (int i = 0; i < n; i++) {
    if (matrix[i][i]) {
      ok = false;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j && matrix[i][j] != matrix[j][i]) {
        ok = false;
      }
    }
  }

  ok ? fout << "YES\n" : fout << "NO\n";

  fin.close();
  fout.close();

  return 0;
}
