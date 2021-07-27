#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
  ifstream in("knapsack.in");
  ofstream out("knapsack.out");

  int s, n, x;
  vector<int> w;
  in >> s >> n;
  for (int i = 0; i < n; i++) {
    in >> x;
    w.push_back(x);
  }

  vector<vector<int>> answer(n+1, vector<int>(s+1));

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= s; j++) {
      if (i == 0 || j == 0)
        answer[i][j] = 0;
      else if (w[i - 1] <= j)
        answer[i][j] = max(answer[i - 1][j], answer[i - 1][j - w[i - 1]] + w[i - 1]);
      else
        answer[i][j] = answer[i - 1][j];
    }
  }

  out << answer[n][s];

  in.close();
  out.close();
  return 0;
}