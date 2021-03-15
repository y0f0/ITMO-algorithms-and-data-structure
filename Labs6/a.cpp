#include <fstream>
#include <iostream>
#include <list>
#include <vector>
using namespace std;


const int MOD =  1'000'003;

int Hash(int key) {
    key = key < 0 ? -key : key;
    return key % MOD;
}

class Set {
private:
    vector<list<int> > data;
public:
    Set() {
        data.resize(MOD);
    }

    void insert(const int& value) {
        for (const int& element : data[Hash(value)]) {
            if (element == value) {
                return;
            }
        }
        data[Hash(value)].push_back(value);
    }
    void delete_(const int& value) {
        for (auto it = data[Hash(value)].begin();
                  it != data[Hash(value)].end();
                  it++) {
            if (*it == value) {
                data[Hash(value)].erase(it);
                return;
            }
        }
    }
    bool exists(const int& value) const {
        for (const int& element : data[Hash(value)]) {
            if (element == value) {
                return true;
            }
        }
        return false;
    }
};

int main () {
    ifstream fin("set.in");
    ofstream fout("set.out");

    string line;
    int value;
    Set set;

    while (fin >> line) {
        fin >> value;
        if (line == "insert") {
            set.insert(value);
        }
        if (line == "exists") {
            fout << (set.exists(value) ? "true\n" : "false\n");
        }
        if (line == "delete") {
            set.delete_(value);
        }
    }

    fin.close();
    fout.close();

    return 0;
}
