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