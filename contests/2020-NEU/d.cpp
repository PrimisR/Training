#include <cstdio>
#include <iostream>
#include <bitset>
#include <string>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for (int loop = 1; loop <= T; loop++)
    {
        bitset<60> ans;
        long long ans_num = 0;
        int n, m;
        scanf("%d %d", &n, &m); getchar();
        for (int i = 1; i <= m; i++)
        {
            int bit = 0;
            int st;
            string line;
            getline(cin, line);
            for (int i = 0; i < line.length(); i++)
            {
                if (line[i] == '[')
                {
                    st = i;
                    break;
                }
            }
            for (int i = st + 1; i < line.length(); i++)
            {
                if (line[i] == '0')
                {
                    bit++;
                }
                if (line[i] == '1')
                    break;
            }
            ans.set(bit, 1);
        }
        for (int i = 0; i < n; i++)
        {
            if(ans[i] == 1) {
                ans_num |= ((long long)1<<i);
            }
        }
        cout << ans_num << endl;
    }
    return 0;
}