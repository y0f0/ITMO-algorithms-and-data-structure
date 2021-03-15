#include <fstream>
#include <vector>
#include <string>
#include <map>


int main() {
    std::ifstream fin("race.in");
    std::ofstream fout("race.out");

    int n;
    std::map<std::string, std::vector<std::string> > country_to_sportmen;

    fin >> n;

    for (int i = 0; i < n; i++) {
        std::string country, sportsman;

        fin >> country >> sportsman;

        country_to_sportmen[country].push_back(sportsman);
    }    

    for (const auto& [key, value] : country_to_sportmen) {

        fout << "=== " << key << " ===\n";

        for (const auto& element : value) {

            fout << element << '\n';

        }
    }


    fin.close();
    fout.close();
    
    return 0;
}
