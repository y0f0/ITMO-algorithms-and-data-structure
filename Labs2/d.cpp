#include <fstream>
#include <vector>

int main() {
    std::ifstream fin("antiqs.in");
    std::ofstream fout("antiqs.out");

    int n;

    fin >> n;

    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        std::swap(v[i], v[i / 2]);
    }
    for (const auto& e : v) {

        fout << e << ' ';

    }

    fin.close();
    fout.close();

    return 0;
}