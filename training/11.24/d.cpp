/**
 * 求大于某个数最小由不重复的3的次幂的和表示的数，如30=3^3+3^1,而2不是，2=3^0+3^0
 * 也就是化成三进制只包含0和1的数
 * 那么寻找最小的这样的并且比给定的n大的数，就寻找2的最高位，把这位变成0，然后下一位+1，之后前面位全部清零，这样找到的是最小的
 * */
#include <cstdio>
#include <iostream>

using namespace std;

int base_3[40];

int to_base_3(long long n) {
    int digit = 0;
    while(n) {
        base_3[digit++] = n % 3;
        n /= 3;
    }
    return digit;
}

long long to_base_10(int digit) {
    long long base = 1;
    long long ans = 0;
    for(int i=0;i<=digit;i++) { //考虑进位
        ans += base_3[i] * base;
        base *= 3;
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--) {
        for(int i=0;i<40;i++) base_3[i] = 0; //需要每次清空数组
        long long n;
        cin>>n;
        int digit = to_base_3(n);
        int highest_2 = -1;
        for(int i=0;i<digit;i++) {
            if(base_3[i] == 2) {
                highest_2 = i;
            }
        }
        if(highest_2 != -1) {
            for(int i=0;i<highest_2;i++) {
                base_3[i] = 0;
            }
            for(int i=highest_2;i<digit;i++) {
                if(base_3[i] == 2) {
                    base_3[i] = 0;
                    base_3[i+1]++;
                }
                else break;
            }
        }
        cout<<to_base_10(digit)<<endl;
    }
    return 0;
}
