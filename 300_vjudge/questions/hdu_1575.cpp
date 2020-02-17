/**
 * 矩阵快速幂
 * */
#include <cstdio>
#include <iostream>

using namespace std;

const int P = 9973;

struct matrix {
    int n;
    int arr[10][10];

    matrix(int n):n(n){
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) arr[i][j] = 0;
    }

    matrix operator* (matrix m) {
        matrix out(n);
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                for(int k=0;k<n;k++) {
                    out.arr[i][j] += (this->arr[i][k] * m.arr[k][j])%P;
                    out.arr[i][j] %= P;
                }
            }
        }
        return out;
    }
};

matrix qpow(matrix base,int index) {
    matrix out(base.n);
    for(int i=0;i<base.n;i++) out.arr[i][i] = 1; //矩阵对角线上全是1(E)
    while(index) {
        if(index & 1) out = out * base;
        index >>= 1;
        base = base * base;
    }
    return out;
}

int main() {
    int T; cin>>T;
    while(T--) {
        int n,k; cin>>n>>k;
        matrix m(n);
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cin>>m.arr[i][j];
            }
        }
        matrix result(n);
        result = qpow(m,k);
        int t = 0;
        for(int i=0;i<n;i++) {
            t += result.arr[i][i];
        }
        cout << t%P << endl;
    }
    return 0;
}