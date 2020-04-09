#include <cstdio>

namespace FastIO{
#define SIZE 100000
    inline char nc() {
#ifdef WIN32
        return getchar();
#endif
        static char buf[SIZE],*p1=buf+SIZE,*p2=buf+SIZE;
        if(p1==p2) p2=(p1=buf)+fread(buf,1,SIZE,stdin);
        return p1==p2?-1:*p1++;
    }
    inline bool blank(char ch){
        return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';
    }
    template<class T> inline void read(T &x){
        register double tmp=1;
        register bool sign=0;x=0;
        register char ch=nc();
        for(;ch<'0'||ch>'9';ch=nc()) if(ch=='-') sign=1;
        for(;ch>='0'&&ch<='9';ch=nc()) x=x*10+ch-'0';
        if(ch=='.'){
            for(ch=nc();ch>='0'&&ch<='9';ch=nc())tmp/=10.0,x+=tmp*(ch-48);
        }
        if(sign) x=-x;
    }
    inline void read(char *s) {
        register char ch=nc();
        for (; blank(ch);ch=nc());
        for (;!blank(ch);ch=nc())*s++=ch;
        *s=0;
    }
    inline void read(char &c) {
        for (c=nc(); blank(c); c=nc());
    }
    template<class T> inline void print(T x) {
        if(x<0) putchar('-'), x=-x;
        if(x>9) print(x/10);
        putchar('0'+x%10);
    }
    template<class T> inline void print(T x,char c) {
        print(x),putchar(c);
    }
}
using namespace FastIO;

inline void write(int X)
{
	if(X<0) {X=~(X-1); putchar('-');}
	if(X>9) write(X/10);
	putchar(X%10+'0');
}

int main() {
    int T; read(T);
    while(T--) {
        int n; read(n);
        for(int i=1;i<=n;i++) {
            int a;
            read(a);
        }
        printf("YES\n");
    }
    return 0;
}