#include<stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int r, c;
        scanf("%d %d", &r, &c);
        int key;
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                scanf("%d", &key);
        if(key == 1)
            printf("Alice\n");
        else
            printf("Bob\n");
    }
    return 0;
}