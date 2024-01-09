#include<iostream>
using namespace std;

class Array
{
    public:
    int *Arr;
    int size;

    Array(int Length);
    ~Array();
    void Accept();
    void Display();
    int Addition();
   

};
 Array :: Array(int Length)
    {
        size = Length;
        Arr = new int[size];

        
    }
   Array :: ~Array()
    {
        delete[]Arr;
    }

    void Array :: Accept()
    {
        cout<<"Enter the elements"<<"\n";
        int icnt = 0;
        for(icnt=0;icnt<size;icnt++)
        {
            cin>>Arr[icnt];
        }
    }

    void Array :: Display()
    {
        cout<<"Elements of the array : "<<"\n";
        int icnt=0;
        for(icnt=0;icnt<size;icnt++)
        {
            cout<<Arr[icnt]<<"\t";
        }
        cout<<"\n";
    }
    int Array :: Addition()
    {
        int icnt = 0,isum=0;
        for(icnt=0;icnt<size;icnt++)
        {
            isum = isum+Arr[icnt];
            
        }
        return isum;

    }

int main()
{
    Array obj(5);
    int ret=0;

    obj.Accept();
    obj.Display();
    ret = obj.Addition();

    cout<<"Addition of all elements is: "<<ret<<"\n";
    

    return 0;
}