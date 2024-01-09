#include<iostream>
using namespace std;

class Base
{
    public:
    int i,j,k;
    void fun()
    {
        cout<<"inside the fun\n";
    }  void gun()
   
};
class derived : public Base
{
    public:
    int a,b;
    void gun()
    {
        cout<<"inside derived gun\n";
    }
  

};
int main()
{

   // Base *bp1;
   //Base *bp2;
  // Base *dp1;
   //Base *dp2;


    return 0;
}
