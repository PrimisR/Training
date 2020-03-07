#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
using namespace std;
map<string,int> my_map;//使用map保存关键单词
int main()
{
   my_map.clear();
   int n;
   scanf("%d",&n);
   while(n--)
    {
       string s;
       cin>>s;
       if(my_map[s]==0)my_map[s]++;//map中不存在的键值会自动初始化为0
    }
   int k;
   scanf("%d",&k);
   while(k--)
    {
       int m,sum=0;//sum为每行出现的关键单词总数
       scanf("%d",&m);
       while(m--)
       {
           string s1;
           cin>>s1;
           sum+=my_map[s1];
       }
       printf("%d\n",sum);
    }
 
   return 0;
}