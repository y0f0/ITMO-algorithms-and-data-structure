#include <fstream>
#include <vector>
#include <string>
 
void RadixSort(std::vector<std::string>& a, int n, int m, int k) {
 
    std::vector<std::string> result(n);

    for (int phase = 0; phase < k; phase++) {
        
        int j = m - phase - 1;

        std::vector<int> count(26);

        for (int i = 0; i < n; i++) {              
            count[a[i][j] - 'a']++;
        }
 
        int sum = 0;

        for (int i = 0; i < 26; ++i) {
            if (count[i]) {
                int tmp;
                tmp = count[i];

                count[i] = sum;
                sum += tmp;
            }
        }

        for (int i = 0; i < n; i++) {
            result[count[a[i][j] - 'a']] = a[i];
            count[a[i][j] - 'a']++;
        }
 
        a = result;
    }
}
 
 
int main() {
    std::ifstream fin("radixsort.in");
    std::ofstream fout("radixsort.out");
 
    int n, m, k;
     
    fin >> n >> m >> k;
 
    std::vector<std::string> v(n);
 
    for (auto& element : v) {

        fin >> element;

    }

    RadixSort(v, n, m, k);

    for (const auto& element : v) {

        fout << element << '\n';

    }

    fin.close();
    fout.close();
}