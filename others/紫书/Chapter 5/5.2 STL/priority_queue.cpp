#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

typedef long long LL;

const int coeff[3]={2,3,5};

int main()
{
	priority_queue<LL,vector<LL>,greater<LL>> pq;//最小的数为top元素
	set<LL> s;//用set的count来判断已经生成的丑数，pq没有count成员函数 
	pq.push(1);
	s.insert(1);
	LL x;
	for(int i=1;i<=1500;i++)
	{
		x=pq.top(); pq.pop(); //取最小的元素，弹出最小的元素，便于下一次取最小
		for(int j=0;j<3;j++)
		{
			LL x2=x*coeff[j];
			if(!s.count(x2)) {s.insert(x2); pq.push(x2);}
		} 
	}
	cout<<x<<endl;
	return 0;
}
