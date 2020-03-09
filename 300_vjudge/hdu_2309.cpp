#include <iostream>
#include <algorithm>
using namespace std;

int A[110];

int main()
{
    int N;
    while (cin >> N && N)
    {
        for (int i = 0; i < N; ++i)
            cin >> A[i];
        sort(A, A + N);
        int aver = 0;
        for (int i = 1; i < N - 1; ++i)
            aver += A[i];
        cout << aver / (N - 2) << endl;
    }

    return 0;
}
