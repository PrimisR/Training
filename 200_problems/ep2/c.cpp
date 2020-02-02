/**
 * 暴力枚举删掉的painters
 * 求两个区间交集
 * lower = max(l1,l2)
 * upper = min(r1,r2)
 * 交集情况
 * 需要求得区间中刷过1次和2次的个数
 * 可以用前缀和
 * */
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

const int inf = 0x3f3f3f3f;

priority_queue<int> answers;
int fence[5005];
int paint_1[5005];
int paint_2[5005];
int total;
pair<int,int> painters[5005];

int main() {
    int n,q;
    cin>>n>>q;
    for(int i=0;i<q;i++) {
        cin>>painters[i].first>>painters[i].second;
        for(int j=painters[i].first;j<=painters[i].second;j++) {
            fence[j]++;
            if(fence[j] == 1) total++;
        }
    }
    //cout << "total:" << total << endl;
    //区间查询预处理
    for(int i=1;i<=n;i++) {
       if(fence[i] == 1) paint_1[i] = paint_1[i-1] + 1;
       else paint_1[i] = paint_1[i-1];
       if(fence[i] == 2) paint_2[i] = paint_2[i-1] + 1;
       else paint_2[i] = paint_2[i-1];
       //cout << paint_1[i] << " ";
       //cout << paint_2[i] << " ";
    }
    //cout << endl;
    for(int i=0;i<q;i++) {
        for(int j=i+1;j<q;j++) {
            //交集
            int lower = max(painters[i].first,painters[j].first);
            int upper = min(painters[i].second,painters[j].second);
            int answer = total;
            answer = answer 
            - (paint_1[painters[i].second] - paint_1[painters[i].first-1])
            - (paint_1[painters[j].second] - paint_1[painters[j].first-1]);
            //cout << answer << endl;
            if(lower <= upper) {
                answer = answer
                + (paint_1[upper] - paint_1[lower-1])
                - (paint_2[upper] - paint_2[lower-1]);
            }
            answers.push(answer);
            //cout << "upper:" << upper << "lower:" << lower << endl;
            //cout << "answer:" << answer << endl;
        }
    }
    cout << answers.top() << endl;
    return 0;
}
