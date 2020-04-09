
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <limits>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cassert>
 
using namespace std;
 
int main()
{
	int t;
	scanf("%d", &t);
	int nums[4];
	for (int k = 0; k < t; ++k)
	{
		for (int i = 0; i < 4; ++i)
		{
			scanf("%d", &nums[i]);
			printf("%d ", nums[i]);
		}
 
		if (nums[1] - nums[0] == nums[2] - nums[1] && nums[2] - nums[1] == nums[3] - nums[2])
		{
			printf("%d\n", nums[3] + nums[1] - nums[0]);
		}
		else
		{
			printf("%d\n", nums[3] * nums[1] / nums[0]);
		}
	
	}
	return 0;  
}