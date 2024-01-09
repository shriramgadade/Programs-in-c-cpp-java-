#include<iostream>
using namespace std;
void swap(int &No1,int &No2)
{
    int Temp;
    Temp = No1;
    No1 = No2;
    No2=Temp;
}

int main()
{
    int ivalue1 = 10;
    int ivalue2=20;

    cout<<"Vallue of value1 :"<<ivalue1<<"\n";
    cout<<"Vallue of value2 :"<<ivalue2<<"\n";
    
     swap(ivalue1,ivalue2);
    cout<<"Vallue of value1 :"<<ivalue1<<"\n";
    cout<<"Vallue of value2 :"<<ivalue2<<"\n";
    
    



    return 0;
}