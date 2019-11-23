#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

typedef long long LL;

const int coeff[3]={2,3,5};

int main()
{
	priority_queue<LL,vector<LL>,greater<LL>> pq;//��С����ΪtopԪ��
	set<LL> s;//��set��count���ж��Ѿ����ɵĳ�����pqû��count��Ա���� 
	pq.push(1);
	s.insert(1);
	LL x;
	for(int i=1;i<=1500;i++)
	{
		x=pq.top(); pq.pop(); //ȡ��С��Ԫ�أ�������С��Ԫ�أ�������һ��ȡ��С
		for(int j=0;j<3;j++)
		{
			LL x2=x*coeff[j];
			if(!s.count(x2)) {s.insert(x2); pq.push(x2);}
		} 
	}
	cout<<x<<endl;
	return 0;
}
