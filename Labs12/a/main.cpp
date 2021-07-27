#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> LIS_SLOW(const vector<int>& a) {
  int n = (int)a.size();
  vector<int> prev(n, -1);
  vector<int> d(n, 1);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (a[j] < a[i] and d[j] + 1 > d[i]) {
        d[i] = d[j] + 1;
        prev[i] = j;
      }
    }
  }

  int pos = 0;
  int length = d[0];
  for (int i = 0; i < n; i++) {
    if (d[i] > length) {
      pos = i;
      length = d[i];
    }
  }

  vector<int> answer;
  while (pos != -1) {
    answer.push_back(a[pos]);
    pos = prev[pos];
  }

  reverse(begin(answer), end(answer));
  return answer;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  auto answer = LIS_SLOW(a);
  cout << answer.size() << '\n';
  for (auto e : answer) {
    cout << e << ' ';
  }
  return 0;
}
