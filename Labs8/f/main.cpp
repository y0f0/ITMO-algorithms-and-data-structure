#include <algorithm>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

struct Point {
  int x, y;
};

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int n, m;
  fin >> m >> n;
  vector <char> ans;
  Point input{}, output{};
  vector<vector<int>> matrix(m + 2, vector<int> (n + 2));
  for(int i = 0; i < m + 2; i++) {
    matrix[i][0] = -1;
    matrix[i][n + 1] = -1;
  }
  for(int i = 0; i < n + 2; i++) {
    matrix[0][i] = -1;
    matrix[m + 1][i] = -1;
  }
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      char type;
      fin >> type;
      switch (type) {
        case '.':
          matrix[i + 1][j + 1] = 0;
          break;
        case '#':
          matrix[i + 1][j + 1] = -1;
          break;
        case 'S':
          input.x = j + 1;
          input.y = i + 1;
          matrix[i + 1][j + 1] = 1;
          break;
        case 'T':
          output.x = j + 1;
          output.y = i + 1;
          matrix[i + 1][j + 1] = 0;
          break;
      }
    }
  }
  Point u{};
  queue <Point> q;
  q.push(input);
  while(!q.empty() && ((u.x != output.x) || (u.y != output.y))) {
    Point v = q.front();
    q.pop();
    if(!matrix[v.y][v.x - 1]) {
      matrix[v.y][v.x - 1] = matrix[v.y][v.x] + 1;
      u.x = v.x - 1;
      u.y = v.y;
      q.push(u);
    }
    if(!matrix[v.y - 1][v.x]) {
      matrix[v.y - 1][v.x] = matrix[v.y][v.x] + 1;
      u.x = v.x;
      u.y = v.y - 1;
      q.push(u);
    }
    if(!matrix[v.y + 1][v.x]) {
      matrix[v.y + 1][v.x] = matrix[v.y][v.x] + 1;
      u.x = v.x;
      u.y = v.y + 1;
      q.push(u);
    }
    if(!matrix[v.y][v.x + 1]) {
      matrix[v.y][v.x + 1] = matrix[v.y][v.x] + 1;
      u.x = v.x + 1;
      u.y = v.y;
      q.push(u);
    }
  }
  if(matrix[output.y][output.x] == 0) {
    fout << "-1" << endl;
  }
  else {
    int pos = matrix[output.y][output.x];
    while(output.y != input.y || output.x != input.x) {
      if(pos - 1 == matrix[output.y + 1][output.x]) {
        output.y++;
        ans.push_back('U');
      } else if(pos - 1 == matrix[output.y][output.x + 1]) {
        output.x++;
        ans.push_back('L');
      } else if(pos - 1 == matrix[output.y - 1][output.x]) {
        output.y--;
        ans.push_back('D');
      } else if(pos - 1 == matrix[output.y][output.x - 1]) {
        output.x--;
        ans.push_back('R');
      }
      pos--;
    }
    reverse(ans.begin(), ans.end());
    fout << ans.size() << endl;
    for (auto e : ans ) fout << e;
    fout << endl;
  }
  fin.close();
  fout.close();
  return 0;
}
