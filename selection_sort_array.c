//Program to understand selection sort using array in c

//for best case and worst case-> O(n^2)
#ifndef __SELSORT__
#define __SELSORT__
#include "header_array.h"
#endif
//here smallest element is at top
void selection_sort_arr(int *arr, int n)
{
    int min_index = 0;
    for(int i = 0;i<n-1;i++)
    {
        min_index = i;
        for(int j=i+1;j<n;j++)
        {
            //put min_index value to jth value only if jth value is less than min_index value
            if(arr[j] < arr[min_index])
                min_index = j;
        }
        //swap min_index element with ith element
        swap_arr(arr+min_index,arr+i);

    }
}
