#include<stdio.h>
int main()
{
    char ch = 'A';
    int i = 21;
    float f = 12.31f;
    double d = 89.90;

    printf("Size of character is:- %d bytes\n",sizeof(ch));
    printf("size of integer is :- %d bytes\n",sizeof(i));
    printf("size of float is :%d bytes\n",sizeof(f));
    printf("size of double is :%dbytes\n",sizeof(d));
    return 0;
}