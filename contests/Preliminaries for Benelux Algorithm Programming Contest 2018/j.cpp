#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
char s[1005][15];
int parent[1005];
int b=0,n,k;
struct node
{
	int u,v,w;        //第i条边两端点序号和权值
	friend bool operator < (const node a,const node b){  //修改重载运算符
		return a.w>b.w;
	}
};
priority_queue<node> que;
queue<int> q;       //存生成的最小生成树的边两端的节点 
int root(int x)
{
	return parent[x]==x?x:parent[x]=root(parent[x]);
}
void merge(int x,int y)
{
	int f1=root(x);
	int f2=root(y);
	if(f1!=f2){
		parent[f2]=f1;
	}
}
int kruskal()
{
	int ans=0;
	for(int i=0;i<n;i++) parent[i]=i;
	while(!que.empty()){
		node tmp=que.top();que.pop();
		if(root(tmp.u)==root(tmp.v)) continue;
		ans+=tmp.w;
		merge(tmp.u,tmp.v);
		q.push(tmp.u);
		q.push(tmp.v);
	}
	return ans;
}
int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++){
		scanf("%s",&s[i]);
	}
	node temp;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int c=0;
			for(int d=0;d<k;d++){
				if(s[i][d]!=s[j][d])
					c++;
			}
			temp.u=i;
			temp.v=j;
			temp.w=c;
			que.push(temp);
		}
	}
	int sum=kruskal();
	cout<<sum<<endl;
	while(!q.empty()){
		cout<<q.front();q.pop();
		cout<<" "<<q.front()<<endl;q.pop();
	}
	return 0;
}