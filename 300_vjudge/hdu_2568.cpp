#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
 
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;
        int NumB = 0;
        while(N)
        {
            if(N&1)
            {
                NumB++;
                N--;
            }
            else
                N >>= 1;
        }
        cout << NumB << endl;
    }
 
    return 0;
}