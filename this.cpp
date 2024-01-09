#include<iostream>
using namespace std;
class demo{
     
     public:
     int i;
     int j;
     int k;

     demo(int a=10,int b=20, int c = 30)
    {
        i=a;
        j=b;
        k=c;

    }
    void fun(int no1,int no2)
    {
        cout<<"inside fun\n";
    }
    void display()
        {
            cout<<"inside display\n";
        }
    

};
int main()
{
    demo obj1();
    demo obj2(11,21,51);
    
    return 0;
}