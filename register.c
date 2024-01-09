#include<stdio.h>
void display()
{
    register int no = 11;
    int i;
    register int j = 21;

    printf("value of no: %d\n",no);
    printf("value of i : %d\n",i);

}
int main()
{
    display();
    //printf("%d",no); 
    return 0;




}