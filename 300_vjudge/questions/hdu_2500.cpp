#include <stdio.h>

int main(){
    int T;
    int number;
    int i;
    int j;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&number);
        
        for(i=0;i<number*3;i++){
            for(j=0;j<number;j++)
                printf("HDU");
                
            printf("\n");
        }                        
    }        
    return 0;
}