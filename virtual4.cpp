#include<iostream>
using namespace std;

class Base
{
    public:
    int i,j,k;
   virtual void fun() //1000
    {
        cout<<"inside the base fun\n";
    }  
    virtual void gun() //2000
    {
        cout<<"inside base gun\n";
    }
    void sun() //3000
    {
        cout<<"inside base sun\n";

    }
    
   void run() ///4000
   {
    cout<<"inside base  run\n";
   }



};
class derived : public Base
{
    public:
    int a,b;
   virtual void gun() // 5000
    {
        cout<<"inside derived gun\n";
    }
   void run() //6000
   {
    cout<<"inside derived run\n";
   }
   virtual void mun() //7000
   {
    cout<<"inside derived mun\n";
   }

};
int main()
{
    cout<<sizeof(Base)<<"\n";
    cout<<sizeof(derived)<<"\n";
     Base *bp = new derived;
     bp ->fun();
    bp ->gun();
    bp ->sun();
    bp ->run();
   // bp->mun(); error
    return 0;
  
   // Base *bp1;
   //Base *bp2;
  // Base *dp1;
   //Base *dp2;


    return 0;
}
