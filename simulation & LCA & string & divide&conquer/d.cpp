/**
 * 模拟：
 * 两个栈：backward, forward
 * 一个当前页面：current_page
 * BACK 'B'  把当前页面push到forward里，pop出backward的一个页面，把它作为current_page
 *           如果backward栈为空，忽略(Ignored)(指忽略前面所有操作，包括push当前页面)
 * FORWARD 'F' 把当前页面push到backward里，pop出forward的一个页面，把他作为current_page
 *             如果forward栈为空，忽略(Ignored)
 * VISIT 'V' 把当前页面push到backward里，然后把VISIT后面的url作为当前页面，并清空forward
 * QUIT 'Q' 输入结束
 * */

#include <cstdio>
#include <iostream>
#include <stack>
#include <string>

using namespace std;
const string init="http://www.acm.org/";
const string Ignore="Ignored";

void stack_clear(stack<string> &s)
{
    while(!s.empty())
    {
        s.pop();
    }
}

int main()
{
    string command;
    stack<string> backward,forward;
    string current_page=init;

    while(cin>>command&&command[0]!='Q')
    {
        if(command[0]=='B')
        {
            if(!backward.empty())
            {
                forward.push(current_page);
                current_page=backward.top(); cout<<current_page<<endl; backward.pop();}
            else
                cout<<Ignore<<endl;
        }
        else if(command[0]=='F')
        {
            if(!forward.empty())
            {
                backward.push(current_page);
                current_page=forward.top(); cout<<current_page<<endl; forward.pop();}
            else
                cout<<Ignore<<endl;
        }
        else
        {
            string url; cin>>url;
            backward.push(current_page);
            current_page=url;
            stack_clear(forward);
            cout<<current_page<<endl;
        }    
    }
}