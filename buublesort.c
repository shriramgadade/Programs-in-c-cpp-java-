#include<stdio.h>
int main()
{
    int i,j,temp;
    int arr[5]={2,3,4,2,1};
    for(i=0;i<5;i++)
    {
        for(j=0;j<5-i;j++)
        {
        if(arr[j]>arr[j+1])
        {
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
        }
    }
    for(i=0;i<5;i++)
    {
        printf("%d ",arr[i]);
    }
}