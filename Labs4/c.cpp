#include <fstream>
#include <string>

const int MAX_STACK_SIZE = 1e4;

class Stack{
public:
    bool empty() const {
        return head == -1;
    }
    char top() const {
        return data[head];
    }
    void push(const int& new_value) {
        data[++head] = new_value;
    }

    int pop() {
        if (empty()) {
            return -1;
        }
        
        return data[head--];
    }
private:
    int head = -1;
    char data[MAX_STACK_SIZE];
};




int main() {
    std::ifstream fin("brackets.in");
    std::ofstream fout("brackets.out");

    std::string s;

    while (fin >> s) {

        Stack psp;
        bool ok = true;

        for (const auto& element : s) {
            if (element == '(' || element == '[' || element == '{')  psp.push(element);
            else if (!psp.empty() && element == ')' && psp.top() == '(') psp.pop();
            else if (!psp.empty() && element == ']' && psp.top() == '[') psp.pop();
            else if (!psp.empty() && element == '}' && psp.top() == '{') psp.pop();
            else ok = false;
        }
        fout << ((ok && psp.empty()) ?  "YES\n" : "NO\n");
        
    }

    fin.close();
    fout.close();

    return 0;
}
