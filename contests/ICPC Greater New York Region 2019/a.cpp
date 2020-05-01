#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    cout << ((str.substr(0, 3) == "555") ? "YES" : "NO") << endl;
}