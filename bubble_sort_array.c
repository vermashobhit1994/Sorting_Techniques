
//complexity -> worst case -> O(n^2)
         //best case -> O(n)
#ifndef __BUBBLESORT__
#define __BUBBLESORT__
void swap_arr(int *,int*);
#endif

//e.g 8,1,4,6,7,9,3,2,3,1
//here largest element is at bottom by comparing the neighbour elements
void bubble_sort_arr(int *arr,int n)
{
    for(int i = 0;i<n-1;i++)
    {
        //loop goes upto 2nd last element only since comparing with last one
        for(int j= 0;j<n-i-1;j++)
            if(arr[j] > arr[j+1])//swap only if current element is greater than next element
                 swap_arr(arr+j,arr+j+1);//push largest element to bottom
    }

}
