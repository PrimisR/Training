#include <iostream>

#include <string>

using namespace std;

int main()

{

    int t, n;

    char str[110];

    scanf("%d", &t);

    for (int cas = 1; cas <= t; cas++)

    {

        scanf("%d %s", &n, str);

        str[n - 1] = '\0';

        printf("%d %s%s\n", cas, str, str + n);
    }

    return 0;
}