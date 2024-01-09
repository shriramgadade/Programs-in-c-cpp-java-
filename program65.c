// ARRAY 1ST PROGRAM IN LB
#include<stdio.h> // for print and scan
#include<stdlib.h> // for malloc and free

int main()
{
    int icount = 0;
    int icnt=0;
    printf("enter the number of elements\n");
    scanf("%d",&icount);
    int *ptr = NULL;
    ptr =(int *)malloc(icount * sizeof(int));
    printf("Enter the elements:---\n");
    for(icnt=0;icnt<icount;icnt++)
    {
        scanf("%d",&ptr[icnt]);
    }



    return 0;
}
