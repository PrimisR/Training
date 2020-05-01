#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

bool prime[65536 + 1];
set<int> ans;
vector<int> primes;

void E()
{
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for (int i = 3; i <= 65536; i += 2)
    {
        if (!prime[i])
            continue;
        for (int j = i + i; j <= 65536; j += i)
        {
            prime[j] = false;
        }
    }
    primes.push_back(2);
    for (int i = 3; i <= 65536; i += 2)
    {
        if (prime[i])
            primes.push_back(i);
    }
}

int main()
{
    E();
    int n;
    cin >> n;
    for (int loop = 1; loop <= n; loop++)
    {
        long long m;
        cin >> m;
        for (int i = 0; i < primes.size(); i++)
        {
            if (m % primes[i] == 0)
            {
                ans.insert(primes[i]);
                ans.insert(m/primes[i]);
                break;
            }
        }
    }
    int out_cnt = 0;
    for (set<int>::iterator it = ans.begin(); it != ans.end(); it++)
    {
        cout << (*it);
        out_cnt++;
        if (out_cnt % 5 == 0 || out_cnt == ans.size())
            cout << endl;
        else
            cout << " ";
    }
    return 0;
}