#### edu r 65

##### c.并查集

```c
#include <cstdio>
#include <vector>

using namespace std;

const int maxn=500005;

int f[maxn];
int size[maxn]={1};

void init()
{
    for(int i=1;i<=maxn;i++)
        f[i]=i;
}
//寻找属于的根节点函数
int getf(int v)
{
    if(f[v]==v) return v;
    else
    {
        f[v]=getf(f[v]);//沿路径做好标记，以便于其他节点查找
        return f[v];
    }
}

int main()
{
    int n,m;
    init();
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int k;
        int root;
        scanf("%d",&k);
        if(k>=1) scanf("%d",&root);
        if(k>1)
        {
            int element;
            for(int i=2;i<=k;i++)
            {
                scanf("%d",&element);
                f[getf(element)]=getf(root);
            }
        }
    }
    for(int i=1;i<=n;i++)
            size[getf(i)]++;
    for(int i=1;i<=n;i++)
    {
        printf("%d",size[getf(i)]);
        if(i!=n) printf(" ");
        else printf("\n");
    }
    return 0;
}
```

一份AC代码：

```c
#include <cstdio>
using namespace std;
int fa[500005],a,b,cnt[500005],n,m;

inline int fis(int x)
{
    return fa[x]==x ? x : fa[x]=fis(fa[x]);
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++)
        fa[i]=i;//初始化
    for(int i=1,l;i<=m;i++)
    {
        scanf("%d",&l);
        if(l>0)
        {
            scanf("%d",&a);
            for(int j=2;j<=l;j++)
                scanf("%d",&b),fa[fis(b)]=fis(a);//全都接到第一个(a)后面
        }
    }
    for(int i=1;i<=n;i++)
        cnt[fis(i)]++;
    for(int i=1;i<=n;i++)
        printf("%d "cnt[fis(i)]);
   	return 0;
}
```

