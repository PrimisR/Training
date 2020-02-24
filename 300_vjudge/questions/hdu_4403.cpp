#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
#define ms(a) memset(a,0,sizeof a)
using namespace std;
int sum[20][20];
vector<int> v;
string s;
int ans;
//处理等号右边
void dfs2(int lsu,int su,int l)//等号左边的和，和，起点
{
    if(lsu<su)return;
    if(l==(int)s.size()&&lsu==su)
    {
        ans++;
        return;
    }
    for(int i=l+1; i<=(int)s.size(); i++)
    {
        dfs2(lsu,su+sum[l][i-1],i);
    }
}
//处理等号左边
void dfs1(int su,int l,int r)//和，左，右界
{
    if(l==r)
    {
        dfs2(su,0,r);
        return;
    }
    for(int i=l+1; i<=r; i++)
    {
        dfs1(su+sum[l][i-1],i,r);
    }
}
int main()
{
    string::iterator it1,it2;
    while(cin>>s)
    {
        if(s=="END")break;
        //ms(sum);
        ans=0;
        if(s.size()==1)printf("0\n");
        else
        {
            //预处理，得到某个区间的数值
            for(it1=s.begin(); it1!=s.end(); it1++)
            {
                int t=*it1-'0';
                sum[it1-s.begin()][it1-s.begin()]=t;
                for(it2=it1+1; it2!=s.end(); it2++)
                {
                    t=t*10+(*it2-'0');
                    sum[it1-s.begin()][it2-s.begin()]=t;
                }
            }
            //1=234566=6,等号的位置
            for(it1=s.begin()+1; it1!=s.end(); it1++)
            {
                dfs1(0,0,it1-s.begin());
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}