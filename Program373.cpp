#include<iostream>
using namespace std;

template<class T>
T Addition(T Arr[],T Length)
{
    T isum = 0;
    T Addition(T Arr[],T Length)
 icnt = 0;
    for(icnt=0;icnt<Length;icnt++)
    {
        isum = isum + Arr[icnt];
    }
    return isum;

}
int main()
{
     int isize = 0,icnt = 0,ret=0;
    int *ptr = NULL;

    cout<<"Enter the number of elemnts : "<<"\n";
    cin>>isize;

    ptr = new int[isize];

    cout<<"Enter the elements"<<"\n";
    for(icnt=0;icnt<isize;icnt++)
    {
        cin>>ptr[icnt];
    }

    ret = Addition(ptr,isize);

    cout<<"Addition of all elements is : "<<ret<<"\n";
 



}