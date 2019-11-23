#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int maxn=300;

char s[maxn];  //保存读入节点
bool failed; //标记是否有重复赋值
vector<int> ans;

struct Node
{
    bool have_value;  //是否被赋值过
    int v;  //节点值
    Node *left,*right; //左右节点的指针
    Node():have_value(false),left(NULL),right(NULL){}   //构造函数
};

Node* newnode() {return new Node();} //申请空间并执行构造函数,new返回申请空间的正确指针

Node* root; //根节点指针

void addnode(int v,char* s)//字符串char*
{
    int n=strlen(s);
    Node* u=root;  //从根节点开始访问
    for(int i=0;i<n;i++) //逐字读取字符串逗号后面的部分
    {
        if(s[i]=='L')
        {
            if(u->left==NULL) u->left=newnode(); //如果左节点指针为空（解引用）那么开辟新空间
            u=u->left; //往左走
        }
        else if(s[i]=='R')
        {
            if(u->right==NULL) u->right=newnode();
            u=u->right;
        }
    } //忽略其他情况，即右括号
    if(u->have_value) failed=true; //如果发现该节点已经被赋值过了，那么失败
    u->v=v;
    u->have_value=true;
}

void remove_tree(Node* u)
{
    if(u==NULL) return; //如果地址为NULL，那么返回
    //这样提前判断是比较稳妥的
    remove_tree(u->left); //递归释放左子树的空间
    remove_tree(u->right); //递归释放右子树的空间
    delete u; //调用u的析构函数并释放u节点本身的内存
}

bool read_input() //读入字符串，返回读取成功与否
{
    failed=false;
//动态申请内存请注意内存泄漏
    remove_tree(root); //在输入新的一组数据，申请新的内存之前，先释放原来的内存，移除原来的树
    root=newnode(); //创建根节点（会被赋予新的地址，那么原来的内存就找不到了，会导致内存泄漏）
    for(;;)
    {
        if(scanf("%s",s)!=1) return false; //整个读入结束(如果读到空括号之前文件结束，则返回0，在主程序内能知道)
        if(!strcmp(s,"()")) break; //读到结束标志，退出循环，strcmp相同字符串返回0
        int v;
        sscanf(&s[1],"%d",&v); //从s[1]处开始读入一个整数
        addnode(v,strchr(s,',')+1); //查找逗号+1，把从字符串读到的整数和字符传入建立节点
    }
}

bool bfs(vector<int> & ans)  //引用
{
    queue<Node*> q; //存放Node*指针的队列
    ans.clear();
    q.push(root);  //放入根节点
    while(!q.empty())
    {
        Node* u=q.front(); q.pop();
        if(!u->have_value) return false; //如果发现没有赋值，则返回false
        ans.push_back(u->v); //把节点值放到vector中
        if(u->left!=NULL) q.push(u->left);
        if(u->right!=NULL) q.push(u->right); //如果有左/右子节点，那么放进队列
    }
    return true;//输入正确
}//返回一个bool值可以很方便地标记正确失败与否

int main()//如何多次读入呢？
{
    read_input();
        bfs(ans);
        for(int i=0;i<ans.size();i++)
            printf("%d\n",ans[i]);
    return 0;
}
