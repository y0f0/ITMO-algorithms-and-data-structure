#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
const int INF = INT_MAX;

vector<int> LIS_FAST(const vector<int>& a) {
  int n = (int)a.size();
  vector<int> prev(n);
  vector<int> d(n+1, INF);
  vector<int> pos(n+1);
  d[0] = -INF;
  pos[0] = -1;
  int length = 0;

  for (int i = 0; i < n; i++) {
    int j = (int)(lower_bound(begin(d), end(d), a[i]) - begin(d));
    if (d[j - 1] < a[i] and a[i] < d[j]) {
      d[j] = a[i];
      pos[j] = i;
      prev[i] = pos[j - 1];
      length = max(length, j);
    }
  }

  vector<int> answer;
  int p = pos[length];
  while (p != -1) {
    answer.push_back(a[p]);
    p = prev[p];
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
  auto answer = LIS_FAST(a);
  cout << answer.size() << '\n';
  for (auto e : answer) {
    cout << e << ' ';
  }
  return 0;
}
