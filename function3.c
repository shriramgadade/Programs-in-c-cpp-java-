#include<stdio.h>
int Addition(int No1,int No2)
{
    int Sum = 0;
    Sum = No1 + No2;
    return Sum;
}
int main()
{
    int value1 = 10;
    int value2 = 11;
    int ans = 0;
    ans = Addition(value1,value2);
    printf("Addition is %d\n",ans);
    return 0;
}