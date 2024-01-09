#include<stdio.h>
#include<stdlib.h>
int main()
{
    int arr[5]; // static memory 
    float fvalue; // static memory
    double brr[4];// static memory

    int isize = 0;
    int *ptr = NULL;

    printf("ENTER THE SIZE OF ARRAY\n");
    scanf("%d",&isize);

    ptr = (int *)calloc(isize ,sizeof(int));

    return 0;

}