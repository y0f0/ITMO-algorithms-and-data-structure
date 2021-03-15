#include <iostream>
#include <fstream>
#include <vector>
#include <random>

long long inversions = 0;

int getInvCount(std::vector<int> v) { 
    int n = v.size();
    int inv_count = 0; 
    for (int i = 0; i < n - 1; i++) 
        for (int j = i + 1; j < n; j++) 
            if (v[i] > v[j]) 
                inv_count++; 
  
    return inv_count; 
} 
 
template<typename T>
std::vector<T> merge(const std::vector<T>& left, const std::vector<T>& right) {
    std::vector<T> result;
    int idx1 = 0;
    int idx2 = 0;
    while (idx1 < left.size() && idx2 < right.size()) {
        if (left[idx1] <= right[idx2]) {
            result.push_back(left[idx1++]);
        } else {
            inversions += left.size() - idx1;
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



int main() {
    std::ifstream fin("inversions.in");
    std::ofstream fout("inversions.out");

    int n;
    fin >> n;
   
    std::vector<int> v(n);

    for (auto &e : v) {
        fin >> e;
    }

    merge_sort(v);

    fout << inversions;

    fin.close();
    fout.close();

}