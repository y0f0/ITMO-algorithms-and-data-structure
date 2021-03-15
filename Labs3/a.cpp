<<<<<<< Updated upstream
#include <fstream>
#include <vector>

bool isHeap(const std::vector<int>& a, const int& n) {
    for (int i = 1; i <= n; i++) {
        if (2 * i <= n) {
            if (a[i] > a[2 * i]) {
                return false;
            }
        }
        if (2 * i + 1  <= n) {
            if (a[i] > a[2 * i + 1]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    std::ifstream fin("isheap.in");
    std::ofstream fout("isheap.out");

    int n;

    fin >> n;

    std::vector<int> a(n + 1); 

    for (int i = 1; i <= n; i++) {

        fin >> a[i];

    }

    isHeap(a, n) ? fout << "YES\n" : fout << "NO\n";

    fin.close();
    fout.close();
    return 0;
}
=======
#include <fstream>
#include <vector>

bool isHeap(const std::vector<int>& a, const int& n) {
    for (int i = 1; i <= n; i++) {
        if (2 * i <= n) {
            if (a[i] > a[2 * i]) {
                return false;
            }
        }
        if (2 * i + 1  <= n) {
            if (a[i] > a[2 * i + 1]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    std::ifstream fin("isheap.in");
    std::ofstream fout("isheap.out");

    int n;

    fin >> n;

    std::vector<int> a(n + 1); 

    for (int i = 1; i <= n; i++) {

        fin >> a[i];

    }

    isHeap(a, n) ? fout << "YES\n" : fout << "NO\n";

    fin.close();
    fout.close();
    return 0;
}
>>>>>>> Stashed changes
