#include<iostream>
using namespace std;
class demo
{
    int i;
    public:
    
    int j;
   
    private:
    
    int k;
    
    protected:
    
    int a;
    demo
    {

        
    }
    
    void display()
    {
        cout<<"Value of i : "<<i<<"\n";
        cout<<"Value of i : "<<j<<"\n";
        cout<<"Value of i : "<<k<<"\n";
        cout<<"Value of i : "<<a<<"\n";
    }


};
class hello : public demo
{
    public:
    void hellodisplay()
    {

    }
};
int main()
{
    demo obj;
        //cout<<"Value of i : "<<obj.i<<"\n";
        cout<<"Value of i : "<<obj.j<<"\n";
       // cout<<"Value of i : "<<obj.k<<"\n";
        //cout<<"Value of i : "<<obj.a<<"\n";
        obj.display();

    

}