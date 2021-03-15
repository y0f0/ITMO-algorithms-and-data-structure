#include <fstream>
  
const int MAX_STACK_SIZE = 1e4;
  
class Stack{
public:
    void push(const int& new_value) {
        data[++head] = new_value;
    }
  
    int pop() {
        return data[head--];
    }
private:
    int head = -1;
    int data[MAX_STACK_SIZE];
};
  
  
  
  
int main() {
    std::ifstream fin("postfix.in");
    std::ofstream fout("postfix.out");
  
    char e;
    Stack stack;
  
    while (fin >> e) {
        if (e == '+') {
            int b = stack.pop();
            int a = stack.pop();
            stack.push(a + b);
        } else if (e == '-') {
            int b = stack.pop();
            int a = stack.pop();
            stack.push(a - b);
        } else if (e == '*') {
            int b = stack.pop();
            int a = stack.pop();
            stack.push(a * b);
        } else if (e >= '0' && e <= '9') {
            stack.push(e - '0');
        }
    }
      
    fout << stack.pop() << '\n';
  
    fin.close();
    fout.close();
  
    return 0;
}
