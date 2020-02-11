/**
 * 直接贪心很复杂(因为直接拿较大人数的党派可能会比贪心最终花的钱少)
 * 由于数据范围不大，所以可以枚举最终获胜时1党拿到的票的数目
 * 这是为了化简判定，假设最终1党拿到了k票，那么其他党派就必定少于k-1票，所以将其他党派贿赂到k-1即可
 * 
 * */
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
const int MAXN = 3005;

struct voter {
    int id;
    int party;
    int coins;
    voter(int id,int party,int coins):id(id),party(party),coins(coins){}
};

vector<voter> voters[MAXN];
vector<voter> other_parties;
int required[MAXN]; //为了使党派小于k-1必须贿赂的人数
bool visited[MAXN]; //看是否被贿赂过
int n,m;

priority_queue<long long,vector<long long>,greater<long long> > answers;

int cmp(voter a,voter b) {
    return a.coins < b.coins;
}

bool is_enough(int k,int &votes) { //看是否总票数够贿赂
    if(votes > k) return false;
    for(int i=2;i<=m;i++) {
        if(voters[i].size() >= k) {
            int required_num = voters[i].size() - (k-1);
            votes += required_num;
            required[i] = required_num;
        }
        else {
            required[i] = 0;
        }
        if(votes > k) return false;
    }
    return true;
}

int main() {
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        int party,coins;
        cin>>party>>coins;
        voters[party].push_back(voter(i,party,coins));
        if(party != 1) {
            other_parties.push_back(voter(i,party,coins));
        }
        else {
            visited[i] = true;
        }
    }
    for(int i=1;i<=m;i++) {
        sort(voters[i].begin(),voters[i].end(),cmp);
    }
    sort(other_parties.begin(),other_parties.end(),cmp);
    for(int k=0;k<=(n/2)+1;k++) {  //k是获胜的时候1党得到的票数
        int votes = voters[1].size(); //不得不贿赂人多的党
        if(votes > (n/2)+1) { //如果总数已经超过一半多，就不继续了(因为如果全是1党会没有答案)
            answers.push(0);
            break;
        }
        if(!is_enough(k,votes)) continue; //如果总票数不够，这种情况就不合理
        //先进行必要的贿赂
        long long coins = 0;
        for(int i=0;i<n;i++) visited[i] = false;
        for(int i=2;i<=m;i++) {
            for(int j=0;j<required[i];j++) {
                coins += voters[i][j].coins;
                visited[voters[i][j].id] = true;
            }
        }
        //再进行贪心
        int left = k - votes;
        for(int i=0;i<other_parties.size();i++) {
            if(!left) break;
            if(visited[other_parties[i].id]) continue;
            coins += other_parties[i].coins; left--;
        }
        answers.push(coins);
    }
    cout << answers.top() << endl;
    return 0;
}