#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

void siftDown(vector<pair<int, int> >& a, int heap_size, int i) {
    while (2 * i + 1 < heap_size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = left;
        if (right < heap_size && a[right] < a[left]) {
            smallest = right;
        }
        if (a[i] <= a[smallest]) {
            return;
        }
        swap(a[i], a[smallest]);
        i = smallest;
    }
}


void siftUp(vector<pair<int, int> >& a, int i, int key, int flag) {
    if (flag) {
        for (int j = 0; j < a.size(); j++) {
            if (a[j].second == i) {
                i = j;
                break;
            }
        }
    }
    a[i].first = key;
    while (a[(i - 1) / 2] > a[i]) {
        swap(a[i], a[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

string ExtractMin(vector<pair<int, int> >& a, int heap_size) {
    if (heap_size < 1) {
        return "*";
    }

    int min = a[0].first;
    a[0] = a[heap_size - 1];
    heap_size--;
    a.pop_back();
    siftDown(a, heap_size, 0);
    return to_string(min);
}


void Push(vector<pair<int, int> >& a, int key, int heap_size, int number_str) {
    a.push_back(make_pair(0, number_str));
    heap_size++; 
    a[heap_size - 1].first = key;
    siftUp(a, heap_size - 1, key, 0);
}

int main() {

    std::ifstream fin("priorityqueue.in");
    std::ofstream fout("priorityqueue.out");

    std::vector<std::pair<int, int> > priority_queue;
    std::string type;    
    int cnt = 1;

    while (fin >> type) {
        if (type == "push") {
            int new_element;

            fin >> new_element;

            Push(priority_queue, new_element, priority_queue.size(), cnt);

        } else if (type == "extract-min") {

            fout << ExtractMin(priority_queue, priority_queue.size()) << '\n';

        } else if (type == "decrease-key") {
            int idx, new_value;

            fin >> idx >> new_value; 

            siftUp(priority_queue, idx, new_value, 1);
        }
        cnt++;
    }

    fin.close();
    fout.close();

    return 0;
}