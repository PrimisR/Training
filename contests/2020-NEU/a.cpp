#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int loop = 1; loop <= T; loop++)
    {
        int n;
        cin >> n;
        int gold = n / 10;
        if (gold * 10 != n)
            gold++;
        int silver = n * 3 /10;
        if (silver * 10 / 3 != n)
            silver++;
        int brown = n * 6 / 10;
        if (brown * 10 / 6 != n)
            brown++;
        brown -= silver;
        silver -= gold;
        cout << gold << endl;
        cout << silver << endl;
        cout << brown << endl;
    }
    return 0;
}