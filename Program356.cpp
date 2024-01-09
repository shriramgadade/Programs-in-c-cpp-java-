#include<iostream>
using namespace std;

int Addition(int No1,int No2)
{
    int Ans=0;
    Ans = No1 + No2;


    return Ans;
}

int main()
{
    int value1 = 10,value2=11,iRet =0;

    iRet = Addition(value1,value2);

    cout<<"Addition is:  "<<iRet<<"\n";



    return 0;
}