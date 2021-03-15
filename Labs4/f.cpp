#include <vector>
#include <fstream>

const double EPS = 1e-6;

bool check(const double& second_h, std::vector<double> &h) {
    h[1] = second_h;
    for (int i = 2; i < h.size(); i++) {
        h[i] = 2 + 2 * h[i - 1] - h[i - 2];
        if (h[i] < 0) {
            return false;
        }
    }
    return true;
}

void bin_search(std::vector<double> &h) {
    double left = 0;
    double right = h[0];
    while (right - left > EPS) {
        double mid = (left + right) / 2;
        if (check(mid, h)) {
            right = mid;
        } else {
            left = mid;
        }
    }
}

int main() {
    std::ifstream fin("garland.in");
    std::ofstream fout("garland.out");
    
    int n;

    fin >> n;

    std::vector<double> h(n);

    fin >> h[0];

    bin_search(h);

	fout << std::fixed;
	fout.precision(2);
    fout << h[n - 1] << '\n';
    
    fin.close();
    fout.close();
    return 0;
}
