#include "isort.h"
#include <stdio.h>
#define SIZE 50

void shift_element(int* arr, int i)
{
    for(int j=i-1; j>=0; j--)
    {
        *(arr+j+1)=*(arr+j);
    }
}

void insertion_sort(int *arr,int len)
{
    for(int i=1; i<len; i++)
    {
        int val=*(arr+i);
        int j=i-1;

        while((*(arr+j)>val)&&j>=0)
        {
            shift_element(arr+j,1);
            j--;
        }
        *(arr+j+1)=val;
    }
}

int main()
{
    int arr[SIZE];
    int count =0;
    
    while(count<SIZE)
    {
        printf("PLease insert a number ");
        int number;
        if(scanf("%d",&number)==1)
        {
            *(arr+count)=number;
            count++;
        }
    }
    insertion_sort(arr,SIZE);

    for(int i=0; i<SIZE; i++)
    {
        printf("%d",arr[i]);
        printf(",");
    }
    return 0;

}   