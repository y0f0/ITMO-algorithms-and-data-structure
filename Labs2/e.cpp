#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;


int partition(vector<int>& array, int lo, int hi){
    int i = lo, j = hi + 1;

    while(true){
        while(array[++i] < array[lo]){
            if ( i == hi ) break;
        }

        while (array[--j] > array[lo]){
            if ( j == lo ) break;
        }

        if (i >= j) break;

        swap(array[i], array[j]);
    }

    swap(array[lo], array[j]);
    return j;
}

int findNth(vector<int>& array, int lo, int hi, int index){
    if (hi <= lo && hi == index) {
        return array[hi];
            
    }

    int j = partition(array, lo, hi);
    if (j == index){
        return array[index];
    } 

    if (j < index) {
        return findNth(array, j + 1, hi, index);
    } 

    if (j > index ){
        return findNth(array, lo, j - 1, index);
    }

    return -1;
}

int main() {

    std::ifstream fin("kth.in");
    std::ofstream fout("kth.out");
 
    int n, k, A, B, C, a1, a2;
 
    fin >> n >> k >> A >> B >> C >> a1 >> a2;
 
    std::vector<int> a(n);
    a[0] = a1;
    a[1] = a2;
 
    for (int i = 2; i < n; i++) {
        a[i] = A * a[i - 2] + B * a[i - 1] + C;
    }
 
    fout << findNth(a, 0, n - 1, k - 1)  << std::endl;

    fin.close();
    fout.close();
 
    return 0;
}
