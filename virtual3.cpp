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
    {
        cout<<"inside base gun\n";
    }
    void sun()
    {
        cout<<"inside base sun\n";

    }
    
   void run()
   {
    cout<<"inside base  run\n";
   }



};
class derived : public Base
{
    public:
    int a,b;
    void gun() // redefination
    {
        cout<<"inside derived gun\n";
    }
   void run() // redefination
   {
    cout<<"inside derived run\n";
   }

};
int main()
{
     Base *bp = new derived;
     bp ->fun();
    bp ->gun();
    bp ->sun();
    bp ->run();
    return 0;
  
   // Base *bp1;
   //Base *bp2;
  // Base *dp1;
   //Base *dp2;


    return 0;
}
