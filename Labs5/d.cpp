#include <vector>
#include <string>
#include <fstream>
#include <queue>
using namespace std; 
 
int main()
{
    using namespace std;
    queue <unsigned int> q;
    unsigned int registers[26];
    vector <string> commands;
    ifstream fin("quack.in");
    ofstream fout("quack.out");
 
    string s;
    while (fin >> s)
        commands.push_back(s);
 
    int i = 0;
    while (i < commands.size() && commands[i] != "Q")
    {
        if (commands[i][0] == '+')
        {
            unsigned int z = q.front();
            q.pop();
            z += q.front();
            q.pop();
            z %= 65536;
            q.push(z);
        }
        else if (commands[i][0] == '-')
        {
            unsigned int z = q.front();
            q.pop();
            z -= q.front();
            q.pop();
            z %= 65536;
            q.push(z);
        }
        else if (commands[i][0] == '*')
        {
            unsigned int z = q.front();
            q.pop();
            z *= q.front();
            q.pop();
            z %= 65536;
            q.push(z);
        }
        else if (commands[i][0] == '/')
        {
            unsigned int z = q.front();
            q.pop();
            if (q.front() == 0)
                z = 0;
            else
                z /= q.front();
            q.pop();
            q.push(z);
        }
        else if (commands[i][0] == '%')
        {
            unsigned int z = q.front();
            q.pop();
            if (q.front() == 0)
                z = 0;
            else
                z %= q.front();
            q.pop();
            q.push(z);
        }
        else if (commands[i][0] == '>')
        {
            registers[commands[i][1] - 'a'] = q.front();
            q.pop();
        }
        else if (commands[i][0] == '<')
        {
            q.push(registers[commands[i][1] - 'a']);
        }
        else if (commands[i][0] == 'P')
        {
            if (commands[i].length() == 1)
            {
                fout << q.front() << "\n";
                q.pop();
            }
            else
            {
                fout << registers[commands[i][1] - 'a'] << "\n";
            }
        }
        else if (commands[i][0] == 'C')
        {
            if (commands[i].length() == 1)
            {
                char c = q.front() % 256;
                q.pop();
                fout << c;
            }
            else
            {
                char c = registers[commands[i][1] - 'a'] % 256;
                fout << c;
            }
        }
        else if (commands[i][0] == ':')
        {
 
        }
        else if (commands[i][0] == 'J')
        {
            string s = commands[i];
            s[0] = ':';
            int j = 0;
            while (s != commands[j])
            {
                j++;
            }
            i = j;
        }
        else if (commands[i][0] == 'Z')
        {
            string s;
            s.push_back(':');
            int j = 2;
            while (j < commands[i].size())
            {
                s.push_back(commands[i][j]);
                j++;
            }
            int k = 0;
            if (registers[commands[i][1] - 'a'] == 0)
            {
                while (s != commands[k])
                {
                    k++;
                }
                i = k;
            }
        }
        else if (commands[i][0] == 'E')
        {
            string s;
            s.push_back(':');
            int j = 3;
            while (j < commands[i].length())
            {
                s.push_back(commands[i][j]);
                j++;
            }
            j = 0;
            if (registers[commands[i][1] - 'a'] == registers[commands[i][2] - 'a'])
            {
                while (s != commands[j])
                {
                    j++;
                }
                i = j;
            }
        }
        else if (commands[i][0] == 'G')
        {
            string s;
            s.push_back(':');
            int j = 3;
            while (j < commands[i].length())
            {
                s.push_back(commands[i][j]);
                j++;
            }
            j = 0;
            if (registers[commands[i][1]- 'a'] > registers[commands[i][2] - 'a'])
            {
                while (s != commands[j])
                {
                    j++;
                }
                i = j;
            }
        }
        else
        {
            q.push(stoi(commands[i]));
        }
        i++;
    }


    fin.close();
    fout.close();
    return 0;
}
