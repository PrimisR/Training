#### C 删除一个数组中重复的元素--数组标记

删除一个数组中重复的元素。例如 ： 
input  :  1,2, 2,2,3,3,3,4,4,5,5,5,6,6,6 
output:  1,2,3,4,5,6

```c
#include<stdlib.h>
#include<stdio.h>
#define N 100

int delete_elem(int arr[], int new_arr[])
{
    int i = 0, new_arr_len = 0;
    int flag[N] = { 0 };//对每个元素做一个初始标记
    for ( i = 0; i < 9; i++)
    {
        if (flag[arr[i]] == 0)
        {
            new_arr[new_arr_len++] = arr[i];
            flag[arr[i]] = 1;//出现过则标记属性设为1
        }
    }
    return new_arr_len;
}

void main()
{
    int i,arr[N];
    int new_arr[N];
    int arr_len = 9;//输入number的个数
    int new_arr_len;
    printf("input 9 numbers:\n");
    for ( i = 0; i < arr_len; i++)
    {
        scanf("%d", &arr[i]);
    }

    new_arr_len = delete_elem(arr, new_arr);

    printf("\n");
    printf("new array is :\n");
    for (i = 0; i < new_arr_len; i++)
    {
        printf("%d ", new_arr[i]);
    }
    printf("\n");

    system("pause");
}
```

