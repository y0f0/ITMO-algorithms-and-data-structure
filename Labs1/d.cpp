#include <fstream>
#include <vector>


std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right) {
    std::vector<int> result;
    int idx1 = 0;
    int idx2 = 0;
    while (idx1 < left.size() && idx2 < right.size()) {
        if (left[idx1] <= right[idx2]) {
            result.push_back(left[idx1++]);
        } else {
            result.push_back(right[idx2++]);
        }
    }
    for (int i = idx1; i < left.size(); i++) {
        result.push_back(left[i]);
    }
    for (int i = idx2; i < right.size(); i++) {
        result.push_back(right[i]);
    }
    return result;
}

std::vector<int> merge_sort (const std::vector<int> v) {
    const int n = v.size();
    if (n <= 1) {
        return v;
    }
    const int middle_index = n / 2;
    std::vector<int> left(middle_index), right(n - middle_index);
    for (int i = 0; i < middle_index; i++) {
        left[i] = v[i];
    }
    for (int i = middle_index; i < n; i++) {
        right[i - middle_index] = v[i];
    }
    return merge(merge_sort(left), merge_sort(right));
}


int main () {

    std::ifstream fin ("smallsort.in");
    std::ofstream fout ("smallsort.out");

    int n;

    fin >> n;

    std::vector<int> v (n);

    for (auto& e: v) {

        fin >> e;

    }
    for (const auto& e : merge_sort(v)) {

        fout << e << ' ';

    }

    fin.close();
    fout.close();

    return 0;
}