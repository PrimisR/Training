/**
 * 可能公共点0，2，4 计算有4个公共点的
 * 4个公共点就是面贴面，也就是切片间隙
 * */
#include<stdio.h>
#include<iostream>
int main()
{
	int n;
	while(std::cin>>n)
	{
		std::cout<<(n*n*n*(n*n*n-1))/2-3*(n*n)*(n-1)<<std::endl;
	}
	return 0;
}