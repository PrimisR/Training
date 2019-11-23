#include <cstdio>
#include <stack>
#include <iostream>
#include <string>
//重点：1.对于表达式的入栈计算 2.结构体构造函数的使用 

using namespace std;

struct Matrix //直接typedef 
{
	int a,b;
	Matrix(int a=0, int b=0):a(a),b(b) {} //构造函数 
} 
m[26];

stack<Matrix> s;

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string name;
		cin>>name;
		int k=name[0]-'A';
		cin>>m[k].a>>m[k].b;
	}
	string expr;//表达式
	//从左向右检查表达式，碰到字符就入栈，碰到右括号就出栈两个元素，然后将计算后的结果矩阵入栈 
	while(cin>>expr)
	{
		int len=expr.length();
		bool error=false;
		int ans=0;
		for(int i=0;i<len;i++)
		{
			if(isalpha(expr[i])) s.push(m[expr[i]-'A']);
			else if(expr[i]==')')
			{
				Matrix m2=s.top(); s.pop();
				Matrix m1=s.top(); s.pop();
				if(m1.b!=m2.a) {error=true; break;} //发现无法计算，就会报错
				ans+=m1.a*m1.b*m2.b;
				s.push(Matrix(m1.a,m2.b)); //※※用m1.a和m2.b初始化一个Matrix类型的结构体 
			}
		}
		if(error) printf("error\n");
		else printf("%d\n",ans);
	}
	return 0;
} 
