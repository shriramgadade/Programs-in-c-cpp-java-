#include<iostream>
using namespace std;

class Arithematic
{
    public:
    int No1;
    int No2;

    Arithematic(int A,int B);
    int Addition();
    int substraction();
    
   
};

Arithematic :: Arithematic(int A,int B)
{
    this->No1 = A;
    this->No2 = B;
}
int Arithematic :: Addition()
{
    int ans =0;
    ans = No1+No2;
    return ans;

}
int Arithematic ::  substraction()
{
      int ans =0;
    ans = No1-No2;
    return ans;

}
int main()
{
    Arithematic obj1(11,10);
    int Ret = 0;

    Ret = obj1.Addition();
    cout<<"Addition is"<<Ret<<"\n";

    Ret = obj1.substraction();
    cout<<"Substraction is : "<<Ret<<"\n";

}