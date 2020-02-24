
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define N 1000
typedef struct{
    char name[N];
    int psolve;
    int time;
}score;
score* team=(score*)malloc(100000);//申请内存空间
//score team[N]={0,0,0};
 
 
bool compare(score a,score b){
    if(a.psolve==b.psolve)//问题数相同，则时间降序排序
        return a.time<b.time;
    return a.psolve>b.psolve;//解决的问题，升序排列
}
 
int main()
{
//    freopen("E:\\in.txt","r",stdin);
    int n,t=0;
    cin>>n;
    getchar();
    while(n--){
        char name[N];
        int psub[4]={0},ptime[4]={0},i=0,cnt=0,time=0,a=0;
        char c;
        while((c=getchar())!=EOF){//获取名字
            if(c==' ')break;
            name[i]=c;
            i++;
        }
        name[i]='\0';
        for(i=0;i<4;i++)
            cin>>psub[i]>>ptime[i];
        for(i=0;i<4;i++){
            if(ptime[i]>0){
                cnt++;
                time+=(psub[i]-1)*20+ptime[i];
            }
        }
        for(i=1;name[i];i++)
            team[t].name[a++]=name[i];
        team[t].name[a]='\0';
        team[t].psolve=cnt;
        team[t].time=time;
        t++;
    }
    sort(team,team+t,compare);
    cout<<team[0].name<<" "<<team[0].psolve<<" "<<team[0].time<<endl;
    return 0;
}