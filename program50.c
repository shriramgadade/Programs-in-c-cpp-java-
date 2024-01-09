#include<stdio.h>
#include<stdbool.h>
bool CheckPrime(int iNo)
{
    int iCnt=0;
    bool bFlag=true;
    if(iNo<0)//uodater
    {
        iNo = -iNo;
        
    }
    for(iCnt=2; iCnt <=(iNo/2);iCnt++)
    {
        if(iNo % iCnt == 0)
        {
           // return false;  // not use in industries
            bFlag = false;
            break;
        }
       
    }
    return bFlag;
   
}
int main()
{
    int iValue = 0;
    bool bRet = false;
    printf("Enter The number\n");
    scanf("%d",&iValue);
    bRet=CheckPrime(iValue);
    if(bRet==true)
    {
        printf("%d is a prime number\n",iValue);

    }
    else{
        printf("%d is not a prome number\n",iValue);
    }

    return 0;

}