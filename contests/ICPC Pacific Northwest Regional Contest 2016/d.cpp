/**
 * 贪心，设当前位置为p，看一下p右边长度为r区间内有几个摄像头
 * 如果>2，那么不需要放摄像头，否则需要放1个或2个。为了摄像机充分利用，尽可能把摄像机给右边放
 * 区间求和：树状数组
 * */
#include <iostream>
using namespace std;
#define rep(i,a,b) for(int i = a;i <= b;++ i)
#define per(i,a,b) for(int i = a;i >= b;-- i)
#define mem(a,b) memset((a),(b),sizeof((a)))
#define FIN freopen("in.txt","r",stdin)
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define pb push_back
typedef long long LL;
typedef pair<int, LL> PIR;
const int N = 1e5+5;

LL n, k, r, x, c[N];
bool vis[N];

int lowbit(int x)   { return x&-x; }
void add(int id, int p){
    while(id <= n){
        c[id] += p;
        id += lowbit(id);
    }
}
LL sum(int id){
    LL ans = 0;
    while(id >= 1){
        ans += c[id];
        id -= lowbit(id);
    }
    return ans;
}
int main()
{IO;
    //FIN;
    cin >> n >> k >> r;
    rep(i, 1, k)    { cin >> x; vis[x] = true; add(x, 1); }
    LL ans = 0;
    rep(i, 1, n-r+1){
        LL res = sum(i+r-1)-sum(i-1);
        if(res < 2){
            per(j, i+r-1, i){
                if(res >= 2) break;
                if(!vis[j]){
                    add(j, 1);
                    vis[j] = true;
                    ans++;
                    res++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}