#include <fstream>
#include <vector>
#include <algorithm>


int main () {

    std::fstream fin ("turtle.in");
    std::ofstream fout ("turtle.out");

    int n, m;

    fin >> n >> m;

    std::vector<std::vector<int> > field(n, std::vector<int> (m));
    std::vector<std::vector<int> > dp(n, std::vector<int> (m, -1));
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) {
            fin >> field[i][j];
        }
    }
    dp[0][0] = field[n - 1][0];
    std::reverse(field.begin(), field.end());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i - 1 >= 0 && j - 1 >= 0) {
                dp[i][j] = field[i][j] + std::max(dp[i - 1][j], dp[i][j - 1]);
            } else if (i - 1 >= 0) {
                dp[i][j] = field[i][j] + dp[i - 1][j];
            } else if (j - 1 >= 0) {
                dp[i][j] = field[i][j] + dp[i][j - 1];
            }
        }
    }
    
    fout << dp[n - 1][m - 1];

    return 0;
}