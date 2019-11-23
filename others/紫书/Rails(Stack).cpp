#include<cstdio>
#include <stack>

using namespace std;
const int MAXN=1000+10;
//每次只有入栈和出栈两个操作 

int n,target[MAXN];
 
int main()
{
	while(scanf("%d",&n)==1)
	{
		stack<int> s;
		int A=1,B=1;//A代表入栈的数字，B代表出栈数字的下角标 
		for(int i=1;i<=n;i++)
			scanf("%d",&target[i]);
		int ok=1;
		while(B<=n)
		{
			if(A==target[B]){A++; B++;}//如果正好符合，不入栈直接开走 
			else if(!s.empty()&&s.top()==target[B]) {s.pop(); B++;}//如果栈顶（栈非空）符合，出栈，找下一个目标
			else if(A<=n) s.push(A++);//如果没有符合的，且A<=n，则入栈，检测下一个数 
			else {ok=0; break;}
		}
		printf("%s\n",ok?"Yes":"No");
	}
	return 0;
} 
