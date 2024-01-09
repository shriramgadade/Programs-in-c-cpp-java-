#include<stdio.h>
#include<stdlib.h>
//void Display(int *arr,int isize)
void evenDisplay(int arr[],int isize)
{
    int icnt = 0;
    printf("\nElements Of The Array are : \n");
    for(icnt = 0;icnt<isize;icnt++)
    {
        if(arr[icnt]%2==0)
        {
        printf("%d\t",arr[icnt]);
        }
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
    printf("Dynamic memory gets allocated succesfully for %d elements\n",icount);
    printf("enter the %d values:\n",icount);
    printf("Enter the values:\n");
    for(icnt=0;icnt < icount;icnt++)
    {
        printf("\n Enter The Element no %d :",icnt+1);
        scanf("%d",&ptr[icnt]);
    }
    evenDisplay(ptr,icount);
    free(ptr);
    printf("dynamic memory gets dealoacated succesfully\n");
    return 0;
}