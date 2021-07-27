#include <vector>
#include <fstream>
#include <cmath>
#include <iostream>
using namespace std;

struct Point{
  int x;
  int y;
  int getDist(const Point& other) const {
    return (this->x - other.x) * (this->x - other.x) + (this->y - other.y) * (this->y - other.y);
  }
};

double Prim(const vector<Point>& points) {
  int n = points.size();
  vector<vector<int>> dist_between(n, vector<int> (n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      dist_between[i][j] = points[i].getDist(points[j]);
  vector<bool> used(n);
  vector<int> dist(n, 2147483647);
  dist[0] = 0;
  for (int i = 0; i < n; i++) {
    int u = -1;
    for (int j = 0; j < n; j++)
      if (!used[j] && (u == -1 || dist[j] < dist[u]))
        u = j;
    used[u] = true;
    for (int v = 0; v < n; v++)
      if (!used[v] && dist_between[u][v] < dist[v])
        dist[v] = dist_between[u][v];
  }

  double res = 0;
  for (const auto& item : dist) {
    res += sqrt(item);
  }
  return res;
}

int main() {
  ifstream fin("spantree.in");
  ofstream fout("spantree.out");
  int n;
  fin >> n;
  vector<Point> points(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    fin >> x >> y;
    points[i] = Point{x, y};
  }
  fout.precision(10);
  fout << Prim(points);
  fin.close();
  fout.close();
  return 0;
}