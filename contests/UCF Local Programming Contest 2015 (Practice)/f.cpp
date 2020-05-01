#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int n, r;
int cell[100];
int table[100];
bool old[100];

int main()
{
    int CASE = 0;
    while (cin >> n >> r && n && r)
    {
        memset(cell, 0, sizeof(cell));   // 没有0号程序
        memset(table, 0, sizeof(table)); // 0表示不在cell里
        memset(old, true, sizeof(old));  // 当前cell是否old
        int faults = 0;
        int cur = 1;
        queue<int> request;
        for (int i = 1; i <= r; i++)
        {
            int page;
            cin >> page;
            request.push(page);
        }
        cout << "Program " << ++CASE << endl;
        while (!request.empty())
        {
            int u = request.front();
            request.pop();
            if (table[u] == 0)
            {
                while (!old[cur])
                {
                    old[cur] = true;
                    cur = cur % n + 1;
                }
                table[cell[cur]] = 0;
                cell[cur] = u;
                table[u] = cur;
                old[cur] = false;
                cout << "Page " << u << " loaded into cell " << cur << "." << endl;
                cur = cur % n + 1;
                faults++;
            }
            else
            {
                old[table[u]] = false; 
                cout << "Access page " << u << " in cell " << table[u] << "." << endl;
            }
        }
        cout << "There are a total of " << faults << " page faults." << endl;
        cout << endl;
    }
}