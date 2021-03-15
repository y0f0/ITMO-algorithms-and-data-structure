#include <fstream>
#include <vector>
#include <utility>


int bin_search_l(const std::vector<int>& v,  const int& x) {
    if (v[0] > x || v[v.size() - 1] < x) {
        return -1;
    }

    int left = -1;
    int right = v.size(); 

    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (x > v[mid])
            left = mid;
        else
            right = mid;
    }
    if (v[right] == x) {
        return right + 1;
    }
    return -1;
}

int bin_search_r(const std::vector<int>& v,  const int& x) {
    if (v[0] > x || v[v.size() - 1] < x) {
        return -1;
    }

    int left = -1;
    int right = v.size(); 
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (x >= v[mid])
            left = mid;
        else
            right = mid;
    }
    if (v[right - 1] == x) {
        return right;
    }
    return -1;
}


int main() {
    std::ifstream fin("binsearch.in");
    std::ofstream fout("binsearch.out");

    int n;

    fin >> n;

    std::vector<int> a(n);

    for (auto& e : a) {

        fin >> e;

    }

    int m;

    fin >> m;

    std::vector<int> b(m);

    for (auto& e : b) {
        
        fin >> e;
    }

    for (const auto& search_element : b) {
        
        auto p = std::make_pair(bin_search_l(a, search_element), bin_search_r(a, search_element));

        fout << p.first << ' ' << p.second << std::endl;

    }

    fin.close();
    fout.close();
}
