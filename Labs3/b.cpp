<<<<<<< Updated upstream
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


void MaxHeapify(std::vector<int>& a, int heap_size, int i) {

    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;

    if (l < heap_size && a[l] > a[largest]) {
        largest = l;
    }

    if (r < heap_size && a[r] > a[largest]) {
        largest = r;
    }

    if (largest != i) {

        std::swap(a[i], a[largest]);
        MaxHeapify(a, heap_size, largest);

    }
}

void HeapSort(std::vector<int>& a) {

    int heap_size = a.size();

    for (int i = heap_size / 2 - 1; i >= 0; i--) {
        MaxHeapify(a, heap_size, i);
    }

    for (int i = heap_size - 1; i > 0; i--) {
        std::swap(a[0], a[i]);

        MaxHeapify(a, i, 0);
    }
}


int main() {

    std::ifstream fin("sort.in");
    std::ofstream fout("sort.out");

    int n;
    
    fin >> n;

    std::vector<int> v(n); 

    for (auto& element : v) {

        fin >> element;

    } 

    HeapSort(v);

    for (auto& e : v) { 

        fout << e << ' ';

    }
    
    fin.close();
    fout.close();

    return 0;
=======
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


void MaxHeapify(std::vector<int>& a, int heap_size, int i) {

    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;

    if (l < heap_size && a[l] > a[largest]) {
        largest = l;
    }

    if (r < heap_size && a[r] > a[largest]) {
        largest = r;
    }

    if (largest != i) {

        std::swap(a[i], a[largest]);
        MaxHeapify(a, heap_size, largest);

    }
}

void HeapSort(std::vector<int>& a) {

    int heap_size = a.size();

    for (int i = heap_size / 2 - 1; i >= 0; i--) {
        MaxHeapify(a, heap_size, i);
    }

    for (int i = heap_size - 1; i > 0; i--) {
        std::swap(a[0], a[i]);

        MaxHeapify(a, i, 0);
    }
}


int main() {

    std::ifstream fin("sort.in");
    std::ofstream fout("sort.out");

    int n;
    
    fin >> n;

    std::vector<int> v(n); 

    for (auto& element : v) {

        fin >> element;

    } 

    HeapSort(v);

    for (auto& e : v) { 

        fout << e << ' ';

    }
    
    fin.close();
    fout.close();

    return 0;
>>>>>>> Stashed changes
}