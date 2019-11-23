#include <cstdio>
#include <iostream> 
#include <set>
#include <algorithm>//set_union在algorithm库中-泛型算法 
#include <map>
#include <iterator> 
#include <vector>
#include <stack>//后进后出

#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())

using namespace std; 

typedef set<int> Set;//专用于int的set，typedef，int用来表示集合中的元素（也是集合） 
map<Set,int> IDcache;//把每个set映射成int，用于标记和分配检查 集合编号 
vector<Set> Setcache;// 用来给集合分配ID，（ID标对应相应的集合）集合本身 

//ID函数：如果这个集合有ID，则返回ID；如果没有，则分配一个新的ID 
int ID (Set x)
{
	if(IDcache.count(x)) return IDcache[x];//IDcache[x]为map IDcache返回的x编号，x为Set类型
	Setcache.push_back(x);//大小加1 
	return IDcache[x]=Setcache.size()-1;//从0编号
}

int main()
{
	stack<int> s;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string op;
		cin>>op;
		if(op[0]=='P') s.push(ID(Set())); //空集{}入栈 注意：栈中存储的是集合的编号
		//※set<int>()可以表示空集（Set()） 
		else if(op[0]=='D') s.push(s.top());//入栈栈顶元素（复制一份）
		else //以下三个操作都需要出栈 
		{
			Set x1=Setcache[s.top()]; s.pop();
			Set x2=Setcache[s.top()]; s.pop();
			Set x;
			if(op[0]=='U') set_union(ALL(x1),ALL(x2),INS(x)); //并集 存入集合x 
			if(op[0]=='I') set_intersection (ALL(x1),ALL(x2),INS(x)); //交集 
			if(op[0]=='A') {x=x2; x.insert(ID(x1));} //把x1集合加入到x2的集合中去 
			s.push(ID(x)); 
		}
		cout<<Setcache[s.top()].size()<<endl; 
	}
}
