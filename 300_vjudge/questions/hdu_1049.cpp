#include <iostream>
using namespace std;
int main()
{
	int n;
	int a, b;
	while(cin >> n >> a >> b, n)
	{
		int t = 0;
		while(n > 0)
		{
			if((t & 1) == 0)
				n -= a;
			else
				n += b;
			t++;
		}
		cout << t << endl;
	}
	return 0;
}