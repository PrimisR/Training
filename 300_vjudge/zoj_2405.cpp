#include <iostream>
 
using namespace std;
 
int main()
{
    for(int m = 2991;m<10000;m++)
    {
        int s1 = 0,s2 = 0,s3 = 0,sum;
        s1 = m/1000 + m/100%10 + m%10 + m%100/10;
        sum = m;
        while(sum != 0)
        {
            s2 += sum%12;
            sum /= 12;
        }
        sum = m;
        while(sum != 0)
        {
            s3 += sum%16;
            sum /= 16;
        }
        if(s1 == s2 && s2 == s3)
            cout << m << endl;
    }
    return 0;
}