#include<cstdio>
#include <stack>

using namespace std;
const int MAXN=1000+10;
//ÿ��ֻ����ջ�ͳ�ջ�������� 

int n,target[MAXN];
 
int main()
{
	while(scanf("%d",&n)==1)
	{
		stack<int> s;
		int A=1,B=1;//A������ջ�����֣�B�����ջ���ֵ��½Ǳ� 
		for(int i=1;i<=n;i++)
			scanf("%d",&target[i]);
		int ok=1;
		while(B<=n)
		{
			if(A==target[B]){A++; B++;}//������÷��ϣ�����ջֱ�ӿ��� 
			else if(!s.empty()&&s.top()==target[B]) {s.pop(); B++;}//���ջ����ջ�ǿգ����ϣ���ջ������һ��Ŀ��
			else if(A<=n) s.push(A++);//���û�з��ϵģ���A<=n������ջ�������һ���� 
			else {ok=0; break;}
		}
		printf("%s\n",ok?"Yes":"No");
	}
	return 0;
} 
