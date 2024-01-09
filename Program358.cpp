#include<iostream>
using namespace std;

double Addition(double No1, double No2)
{
    float Ans=0;
    Ans = No1 + No2;


    return Ans;
}

int main()
{
    double value1 = 10.964,value2=11.6084;
    double iRet =0;

    iRet = Addition(value1,value2);

    cout<<"Addition is:  "<<iRet<<"\n";



    return 0;
}