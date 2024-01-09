#include<iostream>
using namespace std;

class base 
{
    public:
    int i,j,k;
    void fun() //conrete method
    {
        cout<<"base fun\n";
    }
    virtual void gun()//conrete method
    {
        cout<<"base gun\n";
    }
    virtual void addition(int no1,int no2)=0; // abstract method , pure virtual 


};
class derived : public base
{
    public:
    int a,b;
    void gun() // concert method
    {
        cout<<"derived gun\n";
    }
    virtual void sun()// concert method

    {
        cout<<"derived sun\n";
    }
    int addition(int no1, int no2)//concert method
    {
        return no1 + no2;
    }

};
int main()
{
    base *bp = new derived;
    bp ->fun();
    bp->gun();
    int ret = 0;
    ret = bp->addition(10,20);
    cout<<"addition is "<<ret<<

    return 0;
}
