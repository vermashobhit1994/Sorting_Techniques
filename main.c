
//main file used by all sorting techniques
#include"header_array.h"



static void copy_array(int *sourcearr,int *destarr,int n)
{
    for(int i = 0;i<n;i++)
        destarr[i] = sourcearr[i];
}
int main()
{
   int n = 0;
   printf("Enter the number of elements \n");
   scanf("%d",&n);
   int arr[n];
   
   for(int i = 0;i<n;i++)
   {
       printf("Enter %d element\n",i+1);
       scanf("%d",arr+i);
   }   
   //copy the data from main array to temporary array and then sort that temporary array
   int arr_sel[n];
   copy_array(arr,arr_sel,n) ;
   printf("Before sorting the elements are\n");
   display_arr(arr_sel ,n);
   
   selection_sort_arr(arr_sel,n);
   printf("The elements of array using selection sort are\n");
   display_arr(arr_sel,n);

   
   

}
