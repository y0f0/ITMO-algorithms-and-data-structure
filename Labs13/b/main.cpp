#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream fin("search2.in");
  ofstream fout("search2.out");

  string p, t;
  fin >> p >> t;
  int m = p.length();
  p = p + "#" + t;
  int n = p.length();
  vector<int> prefix(n);
  for (int i = 1; i < n; i++) {
    int j = prefix[i - 1];
    while (j > 0 && p[i] != p[j]) {
      j = prefix[j - 1];
    }
    if (p[i] == p[j]) {
      j++;
    }
    prefix[i] = j;
  }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (prefix[i] == m) {
      ans.push_back(i - 2 * m + 1);
    }
  }

  fout << ans.size() << '\n';
  for (const int& item : ans) {
    fout << item << " ";
  }

  fin.close();
  fout.close();
  return 0;
}