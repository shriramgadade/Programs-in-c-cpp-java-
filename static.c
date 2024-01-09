#include<stdio.h>
void fun()
{
    auto int i=10;
    i++;
    printf("value of i is %d\n",i);
}
int main()
{
    fun();//11
    fun();//11
    fun();//11
    return 0;

}