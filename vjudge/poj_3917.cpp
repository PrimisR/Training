#include<stdio.h>
#include<string.h>
int main(){
    char a1[80],a2[80];
    char a3[3] = {'R','S','P'};
    int length;
    int p1,p2;//p1为第一个选手赢的次数，p2是第二个选手赢的次数 
    int i1,i2;
    int temp1,temp2;
    while(true){
        scanf("%s %s",a1,a2);
        if(strcmp(a1,"E")==0&&strcmp(a2,"E")==0){
            break;
        }
        p1 = 0;
        p2 = 0;
        length = strlen(a1);
        
        for(i1=0;i1<length;i1++){
            temp1 = 0;//记录第一个选手的出牌 
            temp2 = 0;//记录第二个选手的出牌 
            for(i2=1;i2<3;i2++){
                if(a1[i1]==a3[i2]){
                    temp1 = i2;
                }
                if(a2[i1]==a3[i2]){
                    temp2 = i2;
                } 
            }
            if(temp1==temp2){
                continue;
            }
            switch(temp1){
                case 0:
                    if(temp2==1){
                        p1++;
                    }
                    else if(temp2==2){
                        p2++;
                    }
                    break;
                case 1:
                    if(temp2==0){
                        p2++;
                    }
                    else if(temp2==2){
                        p1++;
                    }
                    break;
                case 2:
                    if(temp2==0){
                        p1++;
                    }
                    else if(temp2==1){
                        p2++;
                    }
            }
        }
        printf("P1: %d\nP2: %d\n",p1,p2);
    }
    return 0;
}