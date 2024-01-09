#include<iostream>
using namespace std;

template<class T>  //reference variable T
T Addition(T No1,T No2)
{
    T Ans = 0.0;
    Ans = No1 + No2;
    return Ans;
}

int main()
{
   int iValue1 =10,ivalue2=11,iRet=0;
   float fvalue1 = 10.9,fvalue2=11.6,fret=0.0;
   double dvalue1=18.9,dvalue2=15.6,dret = 0.0;

   iRet = Addition(iValue1,ivalue2);
   cout<<"Addition is : "<<iRet<<"\n";

   fret = Addition(fvalue1,fvalue2);
   cout<<"Addition is : "<<fret<<"\n";

   dret = Addition(dvalue1,dvalue2);
   cout<<"Addition is : "<<dret<<"\n";
    return 0;

}