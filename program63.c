#include<stdio.h>
#include<stdbool.h>
bool Checkpalindrome(int iNo)
{
    int iCopy = iNo;
   int iRev = 0;
   int iDigit = 0;

   while(iNo != 0)
   {
    iDigit = iNo % 10;
    iNo = iNo/10;
    iRev = (iRev * 10) + iDigit;

   }
  /* if(iRev == iCopy)
   {
    return true;
   }
   else{
    return false;
   }
   
   */
  return(iRev == iCopy);
}

int main()
{
    int iValue = 0;
    bool iRet = false;

    printf("Enter the number:\n");
    scanf("%d",&iValue);

    iRet = Checkpalindrome(iValue);
    if(iRet == true)
    {
        printf("%d is a palindrome\n",iValue);

    }
    else
    {
        printf("%d is a not a palindrome number\n",iValue);
    }
    return 0;



}