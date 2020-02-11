/**
 * 因为有任何的下降连接就会产生相交
 * 题意就是求最长的上升序列，dp
 * dp[x] = max(any arr[i in range (1,x)] < arr[x]) + 1 
 * 由于每个数都要比较，复杂度是O(n^2)
 * 为了寻找1到x-1之间比arr[x]小的最大dp值
 * 1.单调序列
 * 用一个数组required[len]长度为len的不下降子序列最小的末尾元素
 * 也就是说，如果想要dp[x]达到len，那么arr[x]至少要>=required[len]
 * 只记录最小的，是因为只需要填写当前的dp[x],
 * 这样形成的这个required也是单调的
 * 因为如果更长的上升序列最后一个元素更小，那么更短的子序列中最后一个元素要更小
 * 这样利用这个单调性，即可将复杂度降到logn，二分查找
 * 复杂度为O（nlogn)
 * 2.树状数组
 * */
#include <iostream>
#include <cstdio>

using namespace std;
const int MAXN = 40005;

int seq[MAXN];
int required[MAXN];
int dp[MAXN];
int max_len; //目前required最大值

int binary_search(int l,int r,int target) { //返回<=target requied[i]的最大角标
    int low=l,high=r,mid,ans;
    while(low <= high) {
        mid = low + (high - low)/2;
        if(required[mid] > target) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
            ans = mid;  //注意：需要用ans记录mid，因为如果新的mid比target大，那么不能更新查找目标指针
            if(required[mid] == target) {
                break;
            }
        }
    }
    for(int i=ans+1;i<=max_len;i++) {
        if(required[i] == target) ans++;
        else break;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    while(n--) {
        int p;
        cin>>p;
        for(int i=1;i<=p;i++) {
            cin>>seq[i];
            dp[i] = 0;
            required[i] = 0;
        }
        dp[1] = 1; required[1] = seq[1]; required[0] = 0; max_len = 1; int max_value = 1;
        for(int i=2;i<=p;i++) {
            if(seq[i] >= required[max_len]) {
                required[++max_len] = seq[i];
                dp[i] = max_len;
                if(dp[i] > max_value) max_value = dp[i];
            }
            else {
                int ptr = binary_search(0,max_len,seq[i]);
                if(seq[i] < required[ptr+1]) required[ptr+1] = seq[i];
                dp[i] = ptr + 1;
                if(dp[i] > max_value) max_value = dp[i];
            }
        }
        //cout << "answer:";
        cout << max_value << endl;
    }
    return 0;
}