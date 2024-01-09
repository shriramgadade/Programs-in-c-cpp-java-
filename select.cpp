#include<iostream>
using namespace std;
class demo
{
    public:
    int x,y;

    demo()
    {
        cout<<"inside demo constructor\n";
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
class hello : public demo
{
    public:
    int a,b,c;
    hello()
    {
        cout<<"inside hello constructor\n";
        a=30;
        b=40;
        c=50;
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

int main()
{
    hello hobj;
    cout<<sizeof(hobj)<<"\n"; //20
    cout<<hobj.x<<"\n";
    cout<<hobj.y<<"\n";
    cout<<hobj.a<<"\n";
    cout<<hobj.b<<"\n";
    cout<<hobj.c<<"\n";



    return 0;
}