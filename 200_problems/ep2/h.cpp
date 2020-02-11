/**
 * 对l排序，再对w贪心,
 * 注意贪心的方法：每次用最接近的时间线去放，不需要找最长上升序列(拦截导弹)
 * */
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct stick {
    int l;
    int w;
    stick(int l,int w):l(l),w(w){}
};

int cmp(stick a,stick b) {
    return a.l < b.l;
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        vector<stick> sticks;
        int n;
        cin>>n;
        for(int i=0;i<n;i++) {
            int l,w;
            cin>>l>>w;
            sticks.push_back(stick(l,w));
        }
        sort(sticks.begin(),sticks.end(),cmp);
        vector<int> answer;
        for(int i=0;i<sticks.size();i++) {
            int ptr = -1,value = -1;
            for(int j=0;j<answer.size();j++) {
                if(sticks[i].w < answer[j]) continue;
                if(answer[j] > value) {
                    value = answer[j];
                    ptr = j;
                }
            }
            if(ptr != -1) answer[ptr] = sticks[i].w;
            else answer.push_back(sticks[i].w);
        }
        cout << answer.size() << endl;
    }
    return 0;
}