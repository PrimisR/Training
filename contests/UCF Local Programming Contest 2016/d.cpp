#include <cstdio>
#include <iostream>

using namespace std;

int n;
int tak[25]; // 1-index
int seg[25];
int k;
int tot;

int main()
{
    int T;
    cin >> T;
    int CD = 0;
    while (T--)
    {
        cin >> n >> k;
        tot = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> tak[i];
            tot += tak[i];
        }
        int d;
        cin >> d;
        int tmin = 0;
        cout << "CD #" << ++CD << ":" << endl;
        for (int i = 1; i <= d; i++)
        {
            int s;
            cin >> s;
            for (int j = 1; j <= s; j++)
            {
                cin >> seg[j];
            }
            int remain = 0;
            for (int j = 1; j <= s; j++)
            {
                if (j & 1)
                {
                    tmin += seg[j];
                    remain = tak[k] - (seg[j] % tak[k]);
                    if(seg[j] % tak[k] == 0) remain = 0;
                }
                else
                {
                    if (seg[j] <= remain)
                        tmin += seg[j];
                    else
                    {
                        seg[j] -= remain;
                        tmin += remain;
                        int cir = seg[j] / tot;
                        tmin += cir * tak[k];
                        int r = seg[j] % tot;
                        if (r >= tot - tak[k])
                            tmin += (r - (tot - tak[k]));
                    }
                }
            }
            cout << tmin << endl;
            tmin = 0;
        }
        cout << endl;
    }
    return 0;
}