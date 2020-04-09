#include <iostream>
#include <string>
using namespace std;

struct node
{
    char c;
    node * l;
    node * r;
};

node * make_tree(string pre,string ins);

void fun(node * root);

int main()
{
    //freopen("acm.acm","r",stdin);
    string pre;
    string ins;
    node * root;
    while(cin>>pre>>ins)
    {
    //    cout<<pre<<" "<<ins<<endl;
        root = new node;
        root = make_tree(pre,ins);
        fun(root);
        cout<<endl;
    }
}

node * make_tree(string pre,string ins)
{
//    cout<<" ------------ pre "<<pre<<"----------------- ins "<<ins<<endl;
    node * root;
    int index;
    if(pre.length() > 0)
    {
        root = new node;
        root->c = pre[0];
        index = ins.find(pre[0]);
        root->l = make_tree(pre.substr(1,index),ins.substr(0,index));
        root->r = make_tree(pre.substr(index+1),ins.substr(index+1));
    }
    else 
        root = NULL;
    return root;
}

void fun(node * root)
{
    if(root->l)
    {
        fun(root->l);
    }
    if(root->r)
    {
        fun(root->r);
    }
    cout<<root->c;
}