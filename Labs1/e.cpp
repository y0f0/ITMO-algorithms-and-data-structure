#include <fstream>
#include <vector>
#include <utility>


template<typename T>
std::vector<T> merge(const std::vector<T>& left, const std::vector<T>& right) {
    std::vector<T> result;
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

template<class T>
std::vector<T> merge_sort (const std::vector<T> v) {
    const int n = v.size();
    if (n <= 1) {
        return v;
    }
    const int middle_index = n / 2;
    std::vector<T> left(middle_index), right(n - middle_index);
    for (int i = 0; i < middle_index; i++) {
        left[i] = v[i];
    }
    for (int i = middle_index; i < n; i++) {
        right[i - middle_index] = v[i];
    }
    return merge(merge_sort(left), merge_sort(right));
}


bool operator==(const std::pair<double, int>& lhs, const std::pair<double, int>& rhs) {
    return (lhs.first == rhs.first) && (lhs.second == rhs.second);
}


int main () {

    std::fstream fin ("sortland.in");
    std::ofstream fout ("sortland.out");

    int n;

    fin >> n;

    std::vector<std::pair<double, int> > v(n);

    for (int i = 0; i < n; i++) {

        fin >> v[i].first;
        v[i].second = i + 1;

    }

    v = merge_sort(v);

    fout << v[0].second << ' ' << v[n / 2].second << ' ' << v[n - 1].second;

    fin.close();
    fout.close();

    return 0;
}