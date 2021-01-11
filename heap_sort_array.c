//Program to understand heap sort using array

//It is done by first creating the max heap and then delete root index element one by one

//e.g 8,1,4,6,7,9,3,2,3,1

static void create_heap(int *,int);
static int delete_heap(int*,int*);

void display_arr(int *arr,int n);
void adjust_elements(int *arr,int root_index,int n);
void swap_arr(int *,int*);
int printf(const char *, ...);


void heapsort_arr(int *arr,int n)
{
    
    create_heap(arr,n);
    n--;//decrement so as to start from last element
    while(n>=0)//proceed until one element remains
    {
        int max_val = delete_heap(arr,&n);
        //here we are putting the largest element from end to make the array in increasing order
        arr[n+1] = max_val;//put the largest deleted element at last index from nth 
    }
    
}

//here array is treated as heap
//create heap by going from last root node to top root node
//adjust elements to create a max heap
static void create_heap(int *arr,int n)
{
    
    for(int root_index = n/2-1;root_index>= 0;root_index--)
        adjust_elements(arr,root_index,n);
    
    
}

static void adjust_elements(int *arr,int root_index,int n)
{
    //root_num is last root value
    int root_num = arr[root_index];
    int lchild_index = 2 * root_index + 1;
    int rchild_index = lchild_index +1;//or 2 * root_index +2

    //proceed until we have rchild and lchild in the root node 
    //here if root and left child or root and right child are equal then to handle that 
    //we need to put = sign as we move from top to bottom.
    while(rchild_index < n && lchild_index < n)    
    {
        //if root element is greatest of rchild and lchild element then no need to check the 
        //rchild and lchild
        if(root_num >= arr[lchild_index] && root_num >= arr[rchild_index])
        {  
            //arr[root_index]  = root_num;
            return;
        }
        //if lchild is greater than rchild and root_index number
        else if(arr[lchild_index] >= root_num && arr[lchild_index] >= arr[rchild_index])
        {
            //put the element of lchild_index to root_index 
            swap_arr(&arr[root_index],&arr[lchild_index]);  
            //update root_index with lchild_index so as to check the lchild and rchild of lchild_index
            root_index = lchild_index;
    
        }
        //if rchild is greater than lchild and rootnum
        else if (arr[rchild_index] >= arr[lchild_index] && arr[rchild_index] >= root_num ) 
        { 
            swap_arr(&arr[root_index],&arr[rchild_index]);
            root_index = rchild_index;
        }
        
        //update the lchild and rchild index so as to move from top to bottom i.e find out the
        //rchild and lchild of corresponding lchild and rchild
        lchild_index = 2 * root_index + 1;
        rchild_index = lchild_index + 1;
    }



    //checking the last root element if only lchild is there and no rchild i.e leaf node
    //if last element is greater than last root element
    if(lchild_index == n-1 && arr[lchild_index] >= arr[root_index])
    {
	swap_arr(&arr[root_index],&arr[lchild_index]);
	    
    }
       
       
}

//function that delete the top element
static int delete_heap(int *arr,int *pn)
{
   int max_val = arr[0];
   //delete the top element
   arr[0] = arr[*pn];
   adjust_elements(arr,0,*pn);//adjust elements so as to create max heap
   --*pn;//decrement n
    
   return max_val;   //return the deleted value
    
}





