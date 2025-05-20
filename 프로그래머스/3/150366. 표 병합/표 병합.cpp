#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

pair<int, int> parents[51][51];
string cells[51][51];

vector<string> split(string str, char delim)
{
    istringstream ss(str);
    string buffer;
    vector<string> result;
    while (getline(ss, buffer, delim))
    {
        result.push_back(buffer);
    }
    
    return result;
}

pair<int, int> f(int r, int c)
{
    int pr = parents[r][c].first;
    int pc = parents[r][c].second;
    if (pr == r && pc == c) return make_pair(r, c);
    return parents[r][c] = f(pr, pc);
}

void u(int r1, int c1, int r2, int c2)
{
    pair<int, int> cell1 = f(r1, c1);
    int c1r = cell1.first;
    int c1c = cell1.second;
    pair<int, int> cell2 = f(r2, c2);
    int c2r = cell2.first;
    int c2c = cell2.second;
    if (c1r != c2r || c1c != c2c)
    {
        if (cells[c1r][c1c] == "" && cells[c2r][c2c] != "")
        {
            parents[c1r][c1c] = cell2;
        }
        else
        {
            parents[c2r][c2c] = cell1;
        }
    }
}

void um(int r, int c)
{
    pair<int, int> p = f(r, c);
    string temp = cells[p.first][p.second];
    vector<pair<int, int>> v;
    for (int i = 1; i <= 50; i++)
    {
        for (int j = 1; j <= 50; j++)
        {
            if (f(i, j) == p)
            {
                v.push_back(make_pair(i, j));
            }
        }
    }
    
    for (auto e : v)
    {
        parents[e.first][e.second] = make_pair(e.first, e.second);
        cells[e.first][e.second] = "";
    }
    cells[r][c] = temp;
}

string prt(int r, int c)
{
    pair<int, int> p = f(r, c);
    string result = cells[p.first][p.second];
    return result.compare("") == 0 ? "EMPTY" : result ;
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    
    for (int i = 1; i <= 50; i++)
    {
        for (int j = 1; j <= 50; j++)
        {
            parents[i][j] = make_pair(i, j);
        }
    }
    
    for (string command : commands)
    {
        vector<string> inputs = split(command, ' ');
        string cmd = inputs[0];
        if (cmd.compare("UPDATE") == 0)
        {
            int size = inputs.size();
            if (size == 4)
            {
                int r = stoi(inputs[1]);
                int c = stoi(inputs[2]);
                string value = inputs[3];
                pair<int, int> p = f(r, c);
                cells[p.first][p.second] = value;
            }
            else if (size == 3)
            {
                string target = inputs[1];
                string value = inputs[2];
                for (int i = 1; i <= 50; i++)
                {
                    for (int j = 1; j <= 50; j++)
                    {
                        if (cells[i][j].compare(target) == 0) cells[i][j] = value;
                    }
                }
            }
        }
        else if (cmd.compare("MERGE") == 0)
        {
            int r1 = stoi(inputs[1]);
            int c1 = stoi(inputs[2]);
            int r2 = stoi(inputs[3]);
            int c2 = stoi(inputs[4]);
            u(r1, c1, r2, c2);
        }
        else if (cmd.compare("UNMERGE") == 0)
        {
            int r = stoi(inputs[1]);
            int c = stoi(inputs[2]);
            um(r, c);
        }
        else if (cmd.compare("PRINT") == 0)
        {
            int r = stoi(inputs[1]);
            int c = stoi(inputs[2]);
            answer.push_back(prt(r, c));
        }
    }
    
    return answer;
}