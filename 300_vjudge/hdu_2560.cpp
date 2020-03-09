#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n , m ;
        cin >> n >> m;
        int cnt = 0;
        for(int i = 0 ; i < n ; i ++)
        {
            for(int j = 0 ; j < m ; j ++)
            {
                int k; cin >> k;
                if(k == 1)
                    cnt ++;
            }
        }
        cout << cnt << endl;
    }
}