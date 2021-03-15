#include <iostream>
#include <fstream>
#include <iostream>

const int MAX_STACK_SIZE = 1e6;

class Stack{
public:
    Stack();
    bool empty() const;
    void push(const int& new_value);
    int pop();
private:
    int top;
    int data[MAX_STACK_SIZE];
};

Stack::Stack() : top(-1) {}

bool Stack::empty() const {
    return top == -1;
}

void Stack::push(const int& new_value) {
    data[++top] = new_value;
}

int Stack::pop() {
    if (empty()) {
        return -1;
    }
    
    return data[top--];
}


int main() {
    std::ifstream fin("stack.in");
    std::ofstream fout("stack.out");
   
    int m;
    Stack stack;

    fin >> m;

    for (int i = 0; i < m; i++) {
        char type;
        int new_value;

        fin >> type;

        if (type == '+') {

            fin >> new_value;

            stack.push(new_value);
        } else {

            fout << stack.pop() << '\n';

        }
    }

    fin.close();
    fout.close();

    return 0;
}
