#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_LEN = 1000005;
char str[MAX_LEN];

int main()
{
    int q;
    cin>>q;
    while(q--) {
        int n;
        long long k;
        cin>>n>>k;
        scanf("%s",str);
        int cursor = 0;
        int insert = 0;
        for(int i=0;i<n;i++) { //考虑开始有一些0的情况
            if(str[i] == '0') {
                insert++;
                cursor++;
            }
            else break;
        }
        if(insert == n) {
            printf("%s\n",str);
            continue;
        }
        //每次找到0，然后向前面放置
        while(k>0) {
            int pos_0 = -1;
            for(int i=cursor;i<n;i++,cursor++) {
                if(str[i] == '0') {
                    pos_0 = i;
                    break;
                }
            }
            if(pos_0 == -1) break;
            int dist = pos_0 - insert;
            if(dist <= k) {
                swap(str[pos_0],str[insert++]);
            }
            else {
                swap(str[pos_0],str[pos_0-k]);
            }
            k -= dist;
        }
        printf("%s\n",str);
    }
    return 0;
}