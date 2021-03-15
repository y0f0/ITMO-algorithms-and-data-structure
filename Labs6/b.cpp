#include <fstream>
#include <list>
#include <vector>
#include <utility>
#include <string>
using namespace std;

const int MOD = 1'000'003;

long long hash_(string x) {
    const int k = 199;
    long long hash_code = 0;
    int charCode;
    for (char i : x) {
        charCode = tolower(i) - 'a';
        hash_code = (hash_code * k + charCode) % MOD;
    }
    return hash_code;
}

class Map {
private:
    vector<vector<pair<string, string> > > data;
public:
    Map() {
        data.resize(MOD);
    }
    void put(const string& key, const string& value) {
        data[hash_(key)].push_back(make_pair(key, value));
    }
    void delete_(const string& key) {
        vector<pair<string, string> > new_v;
        for (auto p : data[hash_(key)]) {
            if (p.first != key) {
                new_v.push_back(p);
            }
        }
        data[hash_(key)] = new_v;
    }
    string get(const string& key) const {
        string result = "none"; 
        for (auto p : data[hash_(key)]) {
            if (p.first == key) {
                result = p.second; 
            }
        }
        return result;
    }

};
int main () {
    std::ifstream fin("map.in");
    std::ofstream fout("map.out");

    Map map;
    
    string line, key, value;

    while (fin >> line) {
        if (line == "put") {
            fin >> key >> value;
            map.put(key, value);
        }
        else if (line == "delete") {
            fin >> key;
            map.delete_(key);
        }
        else if (line == "get") {
            fin >> key;
            fout << map.get(key) << '\n';
        }
    }
    fin.close();
    fout.close();
}

