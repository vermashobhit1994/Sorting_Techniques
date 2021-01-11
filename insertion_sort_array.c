//program to understand insertion sort in array 
//worst case -> O(n^2)
        //best case -> O(n)

//eg. 5,3,4,6,8
//same as like arranging cards
//here the elements is shifted
void insertion_sort_arr(int *arr ,int n)
{
    int j = 0;
    //element 1 is considered to be in sorted array already
    for(int i = 1;i<n;i++)
    {
        int p_ele = arr[i],count_shift = 0;
        for(j = i-1; j>=0;j--)
        { 
            //shift element only jth element is greater than pth element
            if(arr[j] > p_ele)
            {
                arr[j+1] = arr[j];//shift the element to right
                //count_shift++;//increment count when shifting is done
            }
            else
                break;//if no shifting then break so that j point to element not being shifted
            
        }
        
        arr[j+1] = p_ele;//put the jth element+1 (due to loop) by p_ele
    }
}
