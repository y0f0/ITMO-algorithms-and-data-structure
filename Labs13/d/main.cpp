#include <bits/stdc++.h>
using namespace std;

auto prefixFunc(const string& str) {
  vector<int> prefix(str.size());
  for (int i = 1; i < str.size(); ++i) {
    int j = prefix[i - 1];
    while(j > 0 && str[i] != str[j])
      j = prefix[j - 1];
    if(str[i] == str[j])
      j++;
    prefix[i] = j;
  }
  return prefix;
}

int main() {
  int n;
  string str;
  cin >> n >> str;
  str += "$";
  vector<int> prefix = prefixFunc(str);
  vector<vector<int>> kmp(str.size(), vector<int>(n));
  for (int i = 0; i < str.size(); ++i) {
    for (char chr = 0; chr < n; ++chr) {
      if (i > 0 && chr + 'a' != str[i])
        kmp[i][chr] = kmp[prefix[i - 1]][chr];
      else if (chr + 'a' == str[i])
        kmp[i][chr] = i + 1;
      else
        kmp[i][chr] = i;
    }
  }

  for (auto row : kmp) {
    for (int a : row) {
      cout << a << " ";
    }
    cout << endl;
  }
  return 0;
}