#include <cstdio>
#include <iostream> 
#include <set>
#include <algorithm>//set_union��algorithm����-�����㷨 
#include <map>
#include <iterator> 
#include <vector>
#include <stack>//������

#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())

using namespace std; 

typedef set<int> Set;//ר����int��set��typedef��int������ʾ�����е�Ԫ�أ�Ҳ�Ǽ��ϣ� 
map<Set,int> IDcache;//��ÿ��setӳ���int�����ڱ�Ǻͷ����� ���ϱ�� 
vector<Set> Setcache;// ���������Ϸ���ID����ID���Ӧ��Ӧ�ļ��ϣ����ϱ��� 

//ID������������������ID���򷵻�ID�����û�У������һ���µ�ID 
int ID (Set x)
{
	if(IDcache.count(x)) return IDcache[x];//IDcache[x]Ϊmap IDcache���ص�x��ţ�xΪSet����
	Setcache.push_back(x);//��С��1 
	return IDcache[x]=Setcache.size()-1;//��0���
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
		if(op[0]=='P') s.push(ID(Set())); //�ռ�{}��ջ ע�⣺ջ�д洢���Ǽ��ϵı��
		//��set<int>()���Ա�ʾ�ռ���Set()�� 
		else if(op[0]=='D') s.push(s.top());//��ջջ��Ԫ�أ�����һ�ݣ�
		else //����������������Ҫ��ջ 
		{
			Set x1=Setcache[s.top()]; s.pop();
			Set x2=Setcache[s.top()]; s.pop();
			Set x;
			if(op[0]=='U') set_union(ALL(x1),ALL(x2),INS(x)); //���� ���뼯��x 
			if(op[0]=='I') set_intersection (ALL(x1),ALL(x2),INS(x)); //���� 
			if(op[0]=='A') {x=x2; x.insert(ID(x1));} //��x1���ϼ��뵽x2�ļ�����ȥ 
			s.push(ID(x)); 
		}
		cout<<Setcache[s.top()].size()<<endl; 
	}
}
