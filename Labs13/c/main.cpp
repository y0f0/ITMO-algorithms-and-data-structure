#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream fin("prefix.in");
  ofstream fout("prefix.out");
  
  string p;
  fin >> p;
  int n = p.length();
  vector<int> prefix(n, 0);
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
  for (const int& item : prefix) {
    fout << item << " ";
  }
  
  fin.close();
  fout.close();
  return 0;
}
