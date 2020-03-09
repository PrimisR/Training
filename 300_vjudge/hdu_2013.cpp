#include<iostream>
#include<cmath>
#include<iomanip>
//#include<algorithm>
using namespace std;
int num;
int main()
{
    int n;
    int sum;
    int p;
    while(cin >> n)
    {
        sum = 0;
        p = 1;
        for(int i = 0; i < n - 1; i ++)
        {
            sum += (p + 1) * 2;
            p = sum;
            sum = 0;
        }
        cout << p << endl;
    }
}