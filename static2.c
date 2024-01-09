#include<stdio.h>
void fun()
{
   int i=10;
    i++;
    printf("value of i is %d\n",i);
}
int main()
{
    fun();//10
    fun();//11
    fun();//12
    return 0;

}