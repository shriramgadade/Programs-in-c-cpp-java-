// perfect number
#include<stdio.h>
#include<stdbool.h>

bool DisplayFactors(int iNo)
{
    int iCnt = 0;

   // printf("Factors of %d are : \n",iNo);
    //      1           2       3
    int iSum=0;
    for(iCnt = 1; iCnt <= (iNo/2); iCnt++)
    {

        if((iNo % iCnt) == 0)   // 4
        {
            iSum=iSum+iCnt;
           
        }
        
    }
    if(iSum==iNo)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{   
    int iValue = 0;
     bool iRate=false;
    printf("Enter the number : \n");
    scanf("%d",&iValue);
    iRate=DisplayFactors(iValue);
    if(iRate==true)
    {
        printf("it is a perfect number\n");
    }
    else
    {
        printf("it is a not a perfect number\n");
    }
    
    return 0;
}
// time complexity :--- O(n/2)