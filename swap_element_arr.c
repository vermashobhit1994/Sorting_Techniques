//function to swap two elements of array
void swap_arr(int *pfirst,int *psecond)
{
    //return if both pointer pointing to same element
    if(*pfirst == *psecond)
    {   
        return;
    }
    *pfirst = (*pfirst)  ^ (*psecond);
    *psecond = (*pfirst) ^ (*psecond);
    *pfirst = (*pfirst)  ^ (*psecond); 
    
}
