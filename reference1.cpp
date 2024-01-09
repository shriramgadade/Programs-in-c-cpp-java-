#include<iostream>

using namespace std;
int main()
{
    int no=11;
    int &ref=no;
    int &x = no;

    int *p=&no;
    int *(&q)=p;



    cout<<no<<"\n";  //11
    cout<<ref<<"\n";//11

    cout<<&no<<"\n"; //10000
    cout<<&ref<<"\n";//10000

    cout<<*p<<"\n";  //11
    cout<<*q<<"\n";  //11



    return 0;
}