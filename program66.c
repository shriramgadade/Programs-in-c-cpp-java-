#include<stdio.h>
#include<stdlib.h>
//void Display(int *arr,int isize)
void Display(int arr[],int isize)
{
    int icnt = 0;
    printf("Elements Of The Array are : \n");
    for(icnt = 0;icnt<isize;icnt++)
    {
        printf("%d\t",arr[icnt]);
    }
    printf("\n");
}

int  main()
{
    int icount = 0,icnt=0;
    int *ptr = NULL;
    
    printf("Enter The Number Of Elements that you want to enter : \n");
    scanf("%d",&icount);
    ptr = (int *)malloc(icount * sizeof(int));
    printf("Enter the values:\n");
    for(icnt=0;icnt < icount;icnt++)
    {
        scanf("%d",&ptr[icnt]);
    }
    Display(ptr,icount);
    free(ptr);
    return 0;
}