#include <fstream>

const int MAX_QUEUE_SIZE = 1e6;

class Queue{
public:
    void push(const int& new_value) {
        data[tail++] = new_value;
    }
    int pop() {
        return data[head++];
    }
private:
    int head = 0;
    int tail = 0;
    int data[MAX_QUEUE_SIZE];
};




int main() {
    std::ifstream fin("queue.in");
    std::ofstream fout("queue.out");
   
    int m;
    Queue queue;

    fin >> m;

    for (int i = 0; i < m; i++) {
        char type;
        int new_value;

        fin >> type;

        if (type == '+') {

            fin >> new_value;

            queue.push(new_value);
        } else {

            fout << queue.pop() << '\n';

        }
    }

    fin.close();
    fout.close();

    return 0;
}
