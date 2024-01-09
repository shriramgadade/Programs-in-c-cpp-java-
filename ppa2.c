#include<stdio.h>
float CalculatePercentage(int imarks,int itotal)
{
    float ans;
    ans = (imarks/itotal)/100;
    return ans;


}
int main()
{
   auto int ivalue1=0;
    int ivalue2=0;
    float fRet=0.0f;
    printf("enter the marks\n");
    scanf("%d",&ivalue1);
    printf("enter the total marks\n");
    scanf("%d",&ivalue2);
    fRet=CalculatePercentage(ivalue1,ivalue2);

    printf("Your Percentage is: %f\n",fRet);


    return 0;
}