#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

bool visited[1000005];

int main()
{
    int T;
    cin >> T;
    for (int loop=1;loop<=T;loop++) {
        int p;
        cin >> p;
        visited[0] = true;
        visited[1] = true;
        for (int i=2;i<=p-1;i++)
            visited[i] = false;
        vector<int> ans;
        ans.push_back(1);
        while (ans.size() < p-1) {
            int nxt2 = ans[ans.size()-1] * 2 % p;
            int nxt3 = ans[ans.size()-1] * 3 % p;
            if (!visited[nxt2]) {
                ans.push_back(nxt2);
                visited[nxt2] = true;
            }
            else if (!visited[nxt3]) {
                ans.push_back(nxt3);
                visited[nxt3] = true;
            }
            else {
                ans.push_back(-1);
                break;
            }
        }
        if (ans[ans.size()-1] == -1) {
            cout << -1 << endl;
        }
        else {
            for (int i=0;i<ans.size() - 1;i++) {
                cout << ans[i] << " ";
            }
            cout << ans[ans.size()-1] << endl;
        }
    }
}