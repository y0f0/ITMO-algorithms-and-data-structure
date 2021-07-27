#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int move(int i, int j, int n, int m, vector<vector<int>>& dp) {
  if (i < 1 || j < 1 || i > n || j > m)
    return 0;

  if (i == 1 && j == 1)
    return 1;

  if (dp[i][j] != -1)
    return dp[i][j];

  dp[i][j] = move(i - 2, j - 1, n, m, dp) + move(i - 2, j + 1, n, m, dp) +
                move(i - 1, j - 2, n, m, dp) + move(i + 1, j - 2, n, m, dp);

  return dp[i][j];
}

int main() {
  ifstream fin("knight2.in");
  ofstream fout("knight2.out");

  int n, m;

  fin >> n >> m;

  vector<vector<int>> dp(n + 2, vector<int>(m+2, -1));

  fout << move(n, m, n, m, dp);

  fin.close();
  fout.close();

  return 0;
}