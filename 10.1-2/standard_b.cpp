//正解是如果没有竖直/水平，那么放在(1,1)/(4,3)，如果再来一个就进行相应的抵消
//进行标记即可
#include <iostream>
#include <cstdio>
#include <string>
#include <stack>

using namespace std;

int main()
{
    string str;
    while(cin>>str) {
        stack<int> horizontal;
        stack<int> vertical;
        for(int i=0;i<str.size();i++) {
            char c=str[i];
            if(c=='0') {
                if(vertical.empty()) {
                    vertical.push(1);
                    cout<<"1 1"<<endl;
                }
                else {
                    vertical.pop();
                    cout<<"3 1"<<endl;
                }
            }
            else {
                if(horizontal.empty()) {
                    horizontal.push(3);
                    cout<<"4 3"<<endl;
                }
                else {
                    horizontal.pop();
                    cout<<"4 1"<<endl;
                }
            }
        }
    }
}