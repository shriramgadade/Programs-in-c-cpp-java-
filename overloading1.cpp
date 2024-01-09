#include<iostream>
using namespace std;

class demo
{
    public:
    int addition(int a,int b)
    {
        return a+b;
    }
    int addition(int a,int b,int c)
    {
        int ans=0;
         ans=a+b+c;
         return ans;
    }
    float addition(float a,float b)
    {
        float ans=0.0f;
        ans=a+b;
        return ans;
    }
};
int main()
{
    demo obj;

    int i =10,j=20,k=30;
    int ret=0;
    float p=90.0,q=80.0,fret=0.0;
    fret=obj.addition(p,q);
    cout<<"addition is :"<<ret<<"\n";
    ret=obj.addition(i,j,k);
    cout<<"Addition is :"<<ret<<"\n";
    
    return 0;
}