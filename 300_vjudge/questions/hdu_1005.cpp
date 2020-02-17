/**
 * ※
 * 类似于斐波那契数列，使用矩阵快速幂做
 * */
#include <iostream>
#include <cstdio>

using namespace std;

const int MOD = 7;

struct matrix {
    int arr[2][2];
    matrix(int a_1,int a_2,int b_1,int b_2) {
        arr[0][0] = a_1;
        arr[0][1] = a_2;
        arr[1][0] = b_1;
        arr[1][1] = b_2;
    }
    //正方形相乘
    matrix operator*(matrix b) {
        matrix out(0,0,0,0);
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                for(int k=0;k<2;k++)
                    out.arr[i][j] = (out.arr[i][j] + this->arr[i][k] * b.arr[k][j] % MOD) % MOD;
                    //记得取模
        return out;
    }
};

int main() {
    int A,B,n;
    while(cin>>A>>B>>n && n) {
        if(n <= 2) {
            printf("1\n");
        }
        else {
            matrix a(A,B,1,0),ans(A,B,1,0);
            int index = n-3;
            while(index) {
                if(index & 1) ans = ans * a;
                index >>= 1;
                a = a * a;
            }
            printf("%d\n",(ans.arr[0][0] + ans.arr[0][1]) % MOD);
        }
    }
    return 0;
}