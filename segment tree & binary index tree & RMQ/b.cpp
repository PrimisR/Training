/**
 * 给定一组序列，然后在所有的这个序列的循环序列中(把第一个数放到最后)
 * 求最小的序列逆序数值
 * 1.首先求初始序列的逆序数(无重复数)
 * 树状数组
 * */
#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 5005;

int arr[MAXN];
int tree[MAXN];

