#include "bubbleSort.h"


void cmpe180ASort(int a[], int sz)
{
    int temp; 
    for(int i = 0; i< sz-1; i++)
    {
        for(int j=0; j<sz-1;j++)
        {
            if(a[j] > a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;

            }
        }
    }
}


void cmpe180ASort(char a[], int sz)
{
    int temp; 
    for(int i = 0; i< sz-1; i++)
    {
        for(int j=0; j<sz-1;j++)
        {
            if(a[j] > a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;

            }
        }
    }
}