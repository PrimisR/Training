/**
 * 霍夫曼编码--构造最优二叉树
 * */
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cstdio>

using namespace std;

struct node
{
    int left;
    int right;
    int val;
    int h;

    node(){
        left=-1;
        right=-1;
        val=0;
        h=0;
    }
    bool operator <(const node &o) const
    {
        return o.val<val;
    }
};



int main()
{
    string s;
    while(cin>>s&&s!="END")
    {
        map<char,int> m;
        priority_queue<node> nodes;
        queue<node> bfs;
        int pos=0;
        int total=0;
        int count=0;
        node nodeaddress[10000];
        for(int i=0;i<s.length();i++)
        {
            if(!m.count(s[i])) m[s[i]]=1;
            else m[s[i]]++;
        }
        if(m.size()==1) {
            total=s.length();
            count=s.length();
        }
        else {
        for(map<char,int>::iterator it=m.begin();it!=m.end();it++)
        {
            nodeaddress[pos].val=it->second;
            count+=it->second;
            nodes.push(nodeaddress[pos++]);
        }
        while(nodes.size()!=1)
        {
            nodeaddress[pos++]=nodes.top(); nodes.pop();
            nodeaddress[pos++]=nodes.top(); nodes.pop();
            nodeaddress[pos].left=pos-2; nodeaddress[pos].right=pos-1; nodeaddress[pos].val=nodeaddress[pos-2].val+nodeaddress[pos-1].val;
            nodes.push(nodeaddress[pos++]);
        }
        node root=nodes.top();
        bfs.push(root);
        int height=0;
        while(bfs.size())
        {
            int size=bfs.size();
            while(size--)
            {
                node n=bfs.front();
                if(n.left!=-1) bfs.push(nodeaddress[n.left]);
                if(n.right!=-1) bfs.push(nodeaddress[n.right]);
                if(n.left==-1&&n.right==-1) total+=height*n.val;

                bfs.pop();
            }
            height++;
        }
    }
        printf("%d %d %.1f\n",count*8,total,(float)count*8.0/(float)total);
    }
    return 0;
}