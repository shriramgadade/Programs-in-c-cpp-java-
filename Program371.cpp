#include<iostream>
using namespace std;

int main()
{
    int isize = 0,icnt = 0;
    int *ptr = NULL;

    cout<<"Enter the number of elemnts : "<<"\n";
    cin>>isize;

    ptr = new int[isize];

    cout<<"Enter the elements"<<"\n";
    for(icnt=0;icnt<isize;icnt++)
    {
        cin>>ptr[icnt];
    }

    cout<<"Elements of the Array are : \n";
    for(icnt = 0;icnt<isize;icnt++)
    {
        cout<<ptr[icnt]<<"\t";

    }

    cout<<"\n";

    delete ptr;
    return 0;


}