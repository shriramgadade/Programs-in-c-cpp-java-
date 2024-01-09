#include<stdio.h>
//#pragma pack(1) // pragma pack directive
union demo
{
    int i; 
    char ch; 
    float f; 
    double d; 
};

int main()
{
   union demo obj;
    printf("size of object is :-- %d\n",sizeof(obj));
    obj.f=90.99;
    printf("%f\n",obj.f);
    obj.i=11;
    printf("%d\n",obj.i);
    
    return 0;

}

