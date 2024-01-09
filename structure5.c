#include<stdio.h>
#pragma pack(2) // pragma pack directive
struct demo
{
    int i; 
    char ch; 
    float f;
    double d;     
};

int main()
{
    struct demo obj;
    printf("size of object is :-- %d\n",sizeof(obj));
    return 0;
}

