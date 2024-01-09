#include<stdio.h>
int Reverse(int iNo)
{
   int iRev = 0;
   int iDigit = 0;

   while(iNo != 0)
   {
    iDigit = iNo % 10;
    iNo = iNo/10;
    iRev = (iRev * 10) + iDigit;

   }
   return iRev;
}
int main()
{

}