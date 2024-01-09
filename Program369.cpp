#include<iostream>
using namespace std;

template<class T>
class Arithematic
{
    public:
    int No1;
    int No2;

    Arithematic(T A,T B);
    
    T Addition();
    T substraction();
    
   
};

template<class T>
Arithematic<T> :: Arithematic(T A,T B)
{
    this->No1 = A;
    this->No2 = B;
}


template<class T>
T Arithematic<T> :: Addition()
{
    T ans =0;
    ans = No1+No2;
    return ans;

}


template<class T>
T Arithematic<T> ::  substraction()
{
      T ans =0;
    ans = No1-No2;
    return ans;

}
int main()
{
    Arithematic<int>obj1(11,10);
    int Ret = 0;

    Ret = obj1.Addition();
    cout<<"Addition is"<<Ret<<"\n";

    Ret = obj1.substraction();
    cout<<"Substraction is : "<<Ret<<"\n";

}