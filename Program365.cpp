#include<iostream>
using namespace std;
template<class T>
void swap(T &No1,T &No2)
{
    T Temp;
    Temp = No1;
    No1 = No2;
    No2=Temp;
}

int main()
{
   float ivalue1 = 10.9;
   float ivalue2=20.3;

    cout<<"Vallue of value1 :"<<ivalue1<<"\n";
    cout<<"Vallue of value2 :"<<ivalue2<<"\n";
    
    swap(ivalue1,ivalue2);
    cout<<"Vallue of value1 :"<<ivalue1<<"\n";
    cout<<"Vallue of value2 :"<<ivalue2<<"\n";
    
    



    return 0;
}