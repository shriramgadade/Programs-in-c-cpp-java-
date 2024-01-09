#include<iostream>
using namespace std;
class demo
{
    public:
    int x,y;

    demo()
    {
        cout<<"inside demo constructor\n";
        x=10;
        y=20;
    }
    ~demo()
    {
        cout<<"inside demo destructor\n";
    }
    void fun()
    {
        cout<<"inside fun of demo\n";
        
    }

};
// class hello extends demo 
class hello 
{
    public:
    int a,b;
    hello()
    {
        cout<<"inside hello constructor\n";
        a=30;
        b=40;
    }
    ~hello()
    {
        cout<<"inside hello distructor\n";
    }
    void gun()
    {
        cout<<"inside gun of hello\n";
    }

     
};
   //class marvellous : public demo,public hello
   class marvellous : public hello,public demo
   {
    public:
    int p;
    marvellous()
    {
        cout<<"inside constructor of marvellous\n";
        p=60;
    }
    ~marvellous()
    {
        cout<<"inside destructor of marvellous\n";
    }
    void sun()
    {
        cout<<"inside sun of marvellous\n";
    }

   };

int main()
{
    marvellous mobj;
    cout<<sizeof(mobj)<<"\n"; //20
   
   
    mobj.fun();
    mobj.gun();
    mobj.sun();



    return 0;
}