/**
 * 数字型构造
 * 题意：构造一个区间[l,r]，使得这个区间内所有数字的各个位数的和 对 给定的数字a 取模 等于 0
 * 保证有解
 * */
#include <iostream>

using namespace std;
//45*18*1e17 = 9*9*1e18

const long long E18 = 1000000000000000000;

int main()
{
    ios::sync_with_stdio(false);
    long long a;
    cin>>a;
    long long x = (((E18 * 9) % a) * 9) % a;
    long long t = a - x;
    cout << t << " " << E18 - 1 + t << endl;
    return 0;
}