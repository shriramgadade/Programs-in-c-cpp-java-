#include<stdio.h>
//#pragma pack(1)
struct demo
{
    int i;
    char ch;
    char f;
    int d;

};
int main()
{
  struct demo obj;
    obj.i = 10;
    obj.ch ='b';
    obj.f='q';
   

    printf("size of structure is %d\n",sizeof(obj));
    printf("%c\n%c\n",obj.ch,obj.f);
}
 // aryan giramkar shriram somnath gadade


