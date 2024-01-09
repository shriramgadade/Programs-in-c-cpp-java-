#include<stdio.h>
#include<stdbool.h>

int DisplayFactors(int iNo)
{
    int iCnt = 0;

    printf("Factors of %d are : \n",iNo);
    //      1           2       3
    int iSum=0;
    for(iCnt = 1; iCnt <= (iNo/2); iCnt++)
    {

        if((iNo % iCnt) == 0)   // 4
        {
            iSum=iSum+iCnt;
           
        }
    }
    return iSum;
}

int main()
{   
    int iValue = 0;

    printf("Enter the number : \n");
    scanf("%d",&iValue);
    int total=DisplayFactors(iValue);
    printf("addition of factor is:--%d",total);

    return 0;
}
// time complexity :--- O(n/2)