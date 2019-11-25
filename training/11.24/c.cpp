/**
 * 考虑每次新添加一个数所新增的n个区间中正负个数与上一次新增的关系
 * 如果新增的是正数，那么新增的区间中会多一个正数的区间(本身)
 * 如果新增的是附属，那么新增的区间所有正区间会变成负区间，负区间会变成正区间，并且负区间+1(本身)
 * */
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int pos_new_indice;
int neg_new_indice;
long long pos_indice_pair;
long long neg_indice_pair;

int num;

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>num;
        if(num > 0) {
            pos_new_indice++;
        }
        else {
            swap(pos_new_indice,neg_new_indice);
            neg_new_indice++;
        }
        pos_indice_pair += pos_new_indice;
        neg_indice_pair += neg_new_indice;
    }
    cout<<neg_indice_pair<<" "<<pos_indice_pair<<endl;
    return 0;
}