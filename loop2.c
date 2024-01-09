#include<stdio.h>
void display(int isize)
{
    int i=0;
   
    for(i=1;i<=isize;i++)// start counter 1, array start 0
    {
    printf("Jay ganesh.....\n");
    }
}
   
int main()
{
    int ivalue=0;
    printf("Enter The Number Of times you want do display jay ganesh on screen\n");
    scanf("%d",&ivalue);

    display(ivalue);
    return 0; 
}