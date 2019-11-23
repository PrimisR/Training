/**
 * 给定n，计算lcm(1,2,3,...,n)
 * lcm最小公倍数
 * 例如lcm(1,2,3,4,5,6,7,8,9,10)=2520;
 * 
 * 唯一分解定理
 * lcm(n+1)=lcm(n) (n+1)不是一个素数p的整数次幂
 *         =lcm(n)*p (n+1)是一个素数p的整数次幂
 * 
 * 位图标记法
 * 使用32位的unsigned int进行位图标记
 * 位图标记实际上原理和bool数组一样，这里利用int进行标记
 * 例如34被访问了，那么在34的位置上进行标记
 * |0000|0000|0000|0000|0000|0000|0000|0000|0010|
 * 10123245673    4    5    6    7    8    9    --代表的数字
 * 由于一个int可以表示32位，以上在数组中的存储就是
 * bitmap[0]=0,bitmap[1]=4;
 * 这样可以压缩空间
 * 
 * bitmap数据结构
 * 1.unsigned int数组，存储
 * 操作
 * 1.插入(int x)
 * 插入应该在相应的数组位置上标记为1，例如34，标记在34/32=1的bitmap编号上，位于第34%32=2的unsigned int“数组”编号上，也就是2的2次方
 * 2.查找(int x)
 * 相应的位置上是1即被插入过，在x/32的bitmap编号上，位于x%32上的数字，利用位运算符即可找到
 * 取模结果为0是第1位为1(2^0=1<<0)
 * 
 * unsigned int无符号整数
 * 超出部分会相当于自动对2^32取模
 * */
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN=1e8;
const int SPACE=3125001;//1e8/32
const int int_size=1<<5;

// struct bitmap
// {
    unsigned int arr[SPACE];

    void insert(int x)
    {
        int bit=1<<(x%int_size);
        arr[x/int_size]|=bit;
    }

    bool find(int x)
    {
        int bit=arr[x/int_size]>>(x%int_size);
        return bit&1;
    }

//     void clear()
//     {
//         memset(arr,0,sizeof(arr));
//     }

//     bitmap()
//     {
//         clear();
//     }
// };
//动态内存爆栈
//参考博客做法
int prime[5800000];//素数密度，10^8以内大概有570万多的素数
unsigned int pre_prime_product[5800000];//前几个素数的一次方乘积和
int prime_size=0;

void Eratosthenes()
{
    prime[0]=pre_prime_product[0]=2; prime_size=1;
    for(int i=3;i<=MAXN;i+=2)
    {
        if(find(i)) continue;
        prime[prime_size]=i;
        pre_prime_product[prime_size]=pre_prime_product[prime_size-1]*i;
        prime_size++;
        for(int j=i*3;j<=MAXN;j+=i*2) insert(j);//跳过偶数
    }
}

unsigned int lcm(int x)
{
    int index=upper_bound(prime,prime+prime_size,x)-prime-1;//比n小的第一个素数
    unsigned int ans=pre_prime_product[index];
    for (int i=0;prime[i]*prime[i]<=x;i++)//此时prime[i]最多10^4,因为1次方已经算过了,至少算到2次方
	{//扫所有素数的整数次幂
		int mul=prime[i];
		int tmp=prime[i]*prime[i];
		while(tmp/mul==prime[i]&&tmp<=x) //防止int越界
		{
            mul*=prime[i];
			tmp*=prime[i];
		}
		ans*=(mul/prime[i]);//除掉1次方
	}
	return ans;
}

int main()
{
    Eratosthenes();
    int T;
    cin>>T;
    int Case=T;
    while(T--)
    {
        int n;
        cin>>n;
        printf("Case %d: %u\n",Case-T,lcm(n));
    }
    return 0;
}