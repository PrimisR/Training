#include <cstdio>//ʹ��standard input & output 
#include <queue>
#include <map>
using namespace std;

const int maxt=1000+10;

int main()
{
	int t,kase=0;
	while(scanf("%d",&t)==1&&t)//team���� 
	{
		printf("Scenario #%d\n",++kase);
		map<int,int> team;//team[x]��ʾ���Ϊx�������ڵ��Ŷӱ��
		for(int i=0;i<t;i++)
		{
			int n,x;
			scanf("%d",&n);
			while(n--)
			{
				scanf("%d",&x);
				team[x]=i;
			}
		}//��¼ÿ������ĳ�Ա 
		queue<int> q,q2[maxt]; //q���ŶӶ��У���q2[i]���Ŷ�i��Ա�Ķ���
		//queueҲ���Կ�����q[100]��int,charһ����ÿ��[i]����һ������
		for(;;)//stop��ֹͣ 
		{
			int x;
			char cmd[10];
			scanf("%s",cmd);
			if(cmd[0]=='S') break;
			else if(cmd[0]=='D')
			{
				int t=q.front();//�ҵ�����ǰ��Ķ���
				//t�ֲ��������������Դ�����Ϊ�ֽ���
				printf("%d\n",q2[t].front()); q2[t].pop(); //�ҵ����еĵ�һ����Ϊ���ӵĵ�һ��
				if(q2[t].empty()) q.pop(); //������һ���������ˣ������Ƴ����� 
			}
			else if(cmd[0]=='E')
			{
				scanf("%d",&x);//�м��пո񣬿����ٶ�ȡ��һ������
				int t=team[x];//�ҵ������Ա�Ķ��� 
				if(q2[t].empty()) q.push(t); //����������Ŀǰ�ǿյģ����򳤶����������
				q2[t].push(x);//��x���� 
			}
		}
		printf("\n"); 
	}
	return 0;
}
 
