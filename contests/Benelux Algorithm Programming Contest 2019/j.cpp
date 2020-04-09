#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;

bool is_prime[MAXN];
bool visited[MAXN];

void E()
{
    is_prime[2] = true;
    for (int i = 3; i < MAXN; i += 2)
    {
        is_prime[i] = true;
    }
    for (int i = 3; i < MAXN; i += 2)
    {
        if (is_prime[i])
        {
            for (int j = i + i; j < MAXN; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
}

int main()
{
    E();
    int n;
    cin >> n;
    int m;
    for (int i = 2; i <= n; i++)
    {
        while (i <= n)
        {
            if (n % i == 0)
            {
                n /= i;
                visited[i] = true;
            }
            else break;
        }
    }
    for(int i=2;i<MAXN;i++) {
        if(is_prime[i] && !visited[i]) {
            m = i;
            break;
        }
    }
    cout << m << endl;
    return 0;
}