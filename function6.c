#include<stdio.h>
void printsum(int,int,char);//  function defination

int main()
{
    int a,b;
    char base;
    printf("enter the values a and b \n");
    scanf("%d%d",&a,&b);
    printf("enter the base of output(O,D or H)\n");
   scanf("%c",&base);
    printsum(a,b,base);
}
void printsum(int x, int y, char base)
{
    if( base == 'd' || base == 'D')
    {
        printf("Sum of %d and %d is %d\n",x,y,x+y);
    }
    else if(base == 'o' || base == 'O')
    {
        printf("Sum of %d and %d is %o",x,y,x+y);
    }
    else if(base == 'h' || base == 'H')
    {
        printf("Sum of %d and %d is %x\n",x,y,x+y);    
    }

    else
    {
        printf("not valid base\n");
    }

}



