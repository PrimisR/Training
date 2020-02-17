/**
 * 并查集
 * */
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int fa[10005];
bool is_prime[100005];
vector<int> answer;

void E() {
    for(int i=2;i<100005;i++) is_prime[i] = true;
    for(int num=2;num<100005;num++) {
        if(!is_prime[num]) continue;
        for(int i=num+num;i<100005;i+=num) {
            is_prime[i] = false;
        }
    }
}

int getfa(int x) {
    if(fa[x] != x) getfa(fa[x]);
    return x;
}

int next(int num) {
    int out = 0;
    while(num) {
        out += (num%10)*(num%10);
        num /= 10;
    }
    return out;
}

int main() {
    E();
    int l,r; cin>>l>>r;
    for(int i=l;i<=r;i++) {
        fa[i] = i;
    }
    for(int x=l;x<=r;x++) {
        if(getfa(x) != x) continue;
        int num = x;
        while(true) {
            num = next(num);
            if(fa[num] == x) {
                fa[x] = -1;
                break;
            }
            if(num != 1) fa[num] = x;
            else break;
        }
    }
    for(int i=l;i<=r;i++) { 
        if(fa[i] == i)
            answer.push_back(i);
    }
    if(answer.size() == 0) {
        cout << "SAD" << endl;
    }
    else {
        for(int i=0;i<answer.size();i++) {
            int num = answer[i];
            int count = 0;
            while (num != 1)
            {
                num = next(num);
                count++;
            }
            if(is_prime[answer[i]]) count *= 2;
            cout << answer[i] << " " << count << endl;
        }
    }
    return 0;
}