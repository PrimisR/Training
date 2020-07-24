#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int loop = 1; loop <= T; loop++)
    {
        int n;
        cin >> n;
        vector<int> vcar(n), vmem(n * 4);
        for (int i = 0; i < n; i++)
            cin >> vcar[i];
        for (int i = 0; i < n * 4; i++)
            cin >> vmem[i];
        sort(vcar.begin(), vcar.end());
        sort(vmem.begin(), vmem.end());
        int j = n * 4 - 1;
        for (int i = 0; i < n; i++)
        {
            vcar[i] += vmem[j];
            j -= 4;
        }
        sort(vcar.begin(), vcar.end());
        cout << "Trip #" << loop << ": ";
        cout << vcar[vcar.size() - 1] << endl;
    }
}