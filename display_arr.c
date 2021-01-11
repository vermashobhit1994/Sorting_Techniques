#ifndef __PRINT__
#define __PRINT__
#include"header_array.h"
#endif

void display_arr(int *arr, int n)
{
    if(0 == n)
        return ;
    
    for(int i = 0;i<n;i++)
        printf("%d, ",arr[i]);
    printf("\n");
}
