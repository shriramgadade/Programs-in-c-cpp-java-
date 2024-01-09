#include<iostream>
using namespace std;

class demo
{
    public:
      int i;
      int j;
    
    demo() // default constructor
    {
        cout<<"inside default constructor\n";
        i=0;
        j=0;
    }

    demo(int a,int b)//parameter constructor
    {
        cout<<"inside parameterized constructor\n";
        i=a;
        j=b;
    
    }   
    demo(demo &ref)//copy constructor
    {
        cout<<"inside copy constructor\n";
        i=ref.i;
        j=ref.j;
    }
    ~demo()
    {
        cout<<"inside destructor";
    }

};
int main()
{
    demo obj1(); // call default constructor
    demo obj2(11,21); // call parameterised constructur
    demo obj3(obj2); // call copy constructor
    return 0;

}