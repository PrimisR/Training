#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    getchar();
    string line;
    for (int loop = 1; loop <= n; loop++)
    {
        getline(cin,line);
        string simon = line.substr(0,10);
        if(simon == "Simon says") {
            cout << line.substr(10,line.length()-10) << endl;
        }
    }
    return 0;
}