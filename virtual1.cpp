#include<iostream>
using namespace std;

class Base
{
    public:
    int i,j,k;
    void fun()
    {
        cout<<"inside the fun\n";
    }

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
    Base bobj;
    derived dobj;
    cout<<sizeof(bobj)<<"\n";
    cout<<sizeof(dobj)<<"\n";

    bobj.fun();

    dobj.fun();
    dobj.gun();



    return 0;
}
