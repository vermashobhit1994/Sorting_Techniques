//code to understand merge sort in c

//e.g 8,1,4,6,7,9,3,2,3,1
//divide the array till only one element remains

//time complexity -> O(nlogn) -> for best,worst and average case
//space complexity -> O(n) 

#ifndef __MSORT__
#define __MSORT__
#include"header_array.h"
#endif


/*here first we split the array using subarray_break() and then merge them */ 
static void subarray_break(int *,int *,int,int);
static void merge_array(int *originalarray,int *temparray, int left_start_index,int right_start_index,int right_end_index);



void mergesort_arr(int *arr,int n)
{
    
    int *temp = (int*)malloc(sizeof(int) * n);
    
    subarray_break(arr,temp,0,n-1);
    free(temp);
    temp = NULL; //to avoid dangling pointer
}

static void subarray_break(int *originalarray,int *temparray,int left_index,int right_index)
{
    if(left_index < right_index)//while there are more than 1 element
    {
        int center_index = (left_index + right_index)/2;
     
        //take the left half of splitted array including center index
        subarray_break(originalarray,temparray,left_index ,center_index);
        
        
        //take the right half of splitted array including center_index+1
        subarray_break(originalarray,temparray,center_index+1,right_index);
    
        
        //merge the left half of array which start with left_index and end with center_index
        //merge the right half of array which start with center_index+1 and end with righ_index  
        merge_array(originalarray,temparray,left_index,center_index+1,right_index);
        
        
    }
}



static void merge_array(int *originalarray,int *temparray, int left_start_index,int right_start_index,int right_end_index)
{
    //no of items to be merge
    //+1 since items index start with 0 and end with n-1
    int no_of_items = right_end_index - left_start_index  + 1;

    //end of left half of array
    int left_end_index = right_start_index-1;
    //start the index of temparray with left_index i.e 0 for left half and (n/2)+1 for right half
    int temparray_index = left_start_index;

    
    //start the left half of array with using left_index and right half using right_start_index
    //moving the indexes of left_start_index upto left_end_index and right_start_index upto right_end_index
    //keep the smallest element from originalarray left half and right half into temparray
    while(left_start_index <= left_end_index && right_start_index <= right_end_index)
    {
        if(originalarray[left_start_index] < originalarray[right_start_index])
            temparray[temparray_index++] = originalarray[left_start_index++];
        else
            temparray[temparray_index++] = originalarray[right_start_index++];
        
    } 

    
    //put the remaining elements of left_half array
    while(left_start_index <= left_end_index)
        temparray[temparray_index++] = originalarray[left_start_index++];

    //put the remaining elements of right half array
    while(right_start_index <= right_end_index)
        temparray[temparray_index++] = originalarray[right_start_index++];
    
    //put the elements back to originalarray from temporary array
    //here right_end_index is at last element of right half of original array

    
    
    //copying the elements from temporary array to original array
    //where the elements are copied from righ_end_index to 0
    while(right_end_index >=0)
    {
        
        originalarray[right_end_index] = temparray[right_end_index];  
        right_end_index--;
        
    };
    
    
    
}
