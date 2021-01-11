//Program to understand quick sort using array
//Here the stopping condition for recursion is when only single element left in array 

//time complexity -> O(nlogn) -> best case
                //-> O(n^2)   -> worst case

void swap_arr(int *,int *);  
int printf(const char *, ...);  
void display_arr(int *arr,int n);

static void quicksort(int *arr, int left_index,int right_index);

//e.g 8,1,4,6,7,9,3,2,3,1
void quicksort_arr(int *arr ,int n)
{
   quicksort(arr,0,n-1);
   
}

static void quicksort(int *arr, int left_index,int right_index)
{
    
    //for each pass while loop is written
    if(left_index < right_index)
    {
        int i = left_index+1, j = right_index,pivot_index = left_index;
        
        while(i < j){
            while(arr[i] < arr[pivot_index] && i <= right_index)
                i++;
            while(arr[j] > arr[pivot_index] && j >= left_index+1)//taken since first element is pivot
                j--;
    	    if(i <j)
            {
                swap_arr(&arr[i],&arr[j]); 
                
            }
        }
        if(i > j )//done so as to swap only when i and j crosses 
            swap_arr(arr+pivot_index, arr+j);
      
    
    
        
        //sort for left half array
        quicksort(arr,left_index,j-1);
        //sort for right half of array . Done while stack popping 
        quicksort(arr, j+1,right_index);
        
    }
}


