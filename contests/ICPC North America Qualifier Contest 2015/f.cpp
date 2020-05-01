#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int cnt[26];

int main()
{
    int n;
    cin >> n;
    string line;
    getchar();
    for (int loop = 1; loop <= n; loop++)
    {
        getline(cin, line);
        memset(cnt, 0, sizeof(cnt));
        int tot = 0;
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] >= 'A' && line[i] <= 'Z')
            {
                cnt[line[i] - 'A']++;
                if (cnt[line[i] - 'A'] == 1)
                    tot++;
            }
            else if (line[i] >= 'a' && line[i] <= 'z')
            {
                cnt[line[i] - 'a']++;
                if (cnt[line[i] - 'a'] == 1)
                    tot++;
            }
        }
        if (tot == 26)
            cout << "pangram" << endl;
        else
        {
            cout << "missing ";
            for (int i = 0; i < 26; i++)
            {
                if (cnt[i] == 0)
                {
                    cout << (char)(i + 'a');
                }
            }
            cout << endl;
        }
    }
    return 0;
}
