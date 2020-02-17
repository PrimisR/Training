#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int fully_6(string str) {
    int count = 0;
    for(int i=0;i<str.length();i++) {
        if(str[i] == '6') count++;
        else return -1;
    }
    return count;
}

int main() {
    string line;
    getline(cin,line);
    stringstream ss(line);
    string new_str;
    string pre_str;
    string answer_str;
    int total = 0;
    while (ss>>new_str)
    {
        if(total != 0) {
            answer_str = answer_str + pre_str + " "; 
        }
        total++;
        int result = fully_6(new_str);
        if(result != -1) {
            if(result > 3 && result <= 9) {
                new_str = "9";
            }
            else if(result > 9) {
                new_str = "27";
            }
        }
        pre_str = new_str;
    }
    answer_str = answer_str + pre_str;
    cout << answer_str;
    return 0;
}