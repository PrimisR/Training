#include <cstdio>//使用standard input & output 
#include <queue>
#include <map>
using namespace std;

const int maxt=1000+10;

int main()
{
	int t,kase=0;
	while(scanf("%d",&t)==1&&t)//team个数 
	{
		printf("Scenario #%d\n",++kase);
		map<int,int> team;//team[x]表示编号为x的人所在的团队编号
		for(int i=0;i<t;i++)
		{
			int n,x;
			scanf("%d",&n);
			while(n--)
			{
				scanf("%d",&x);
				team[x]=i;
			}
		}//记录每个队伍的成员 
		queue<int> q,q2[maxt]; //q是团队队列，而q2[i]是团队i成员的队列
		//queue也可以开数组q[100]像int,char一样，每个[i]代表一个队列
		for(;;)//stop才停止 
		{
			int x;
			char cmd[10];
			scanf("%s",cmd);
			if(cmd[0]=='S') break;
			else if(cmd[0]=='D')
			{
				int t=q.front();//找到排在前面的队列
				//t局部变量的作用域以大括号为分界线
				printf("%d\n",q2[t].front()); q2[t].pop(); //找到队列的第一个，为长队的第一个
				if(q2[t].empty()) q.pop(); //如果最后一个队首走了，队伍移出长队 
			}
			else if(cmd[0]=='E')
			{
				scanf("%d",&x);//中间有空格，可以再读取下一个数字
				int t=team[x];//找到这个队员的队伍 
				if(q2[t].empty()) q.push(t); //如果这个队伍目前是空的，就向长队推入队伍编号
				q2[t].push(x);//把x推入 
			}
		}
		printf("\n"); 
	}
	return 0;
}
 
