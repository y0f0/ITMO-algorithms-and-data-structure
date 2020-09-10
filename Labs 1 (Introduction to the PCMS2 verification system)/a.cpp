#include <fstream>

int main() {
    int a, b;
    std::ifstream fin ("aplusb.in");
    std::ofstream fout ("aplusb.out");

    fin >> a >> b;

    fout << a + b;

    fin.close();
    fout.close();

    return 0;
}