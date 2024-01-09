#include<iostream>
using namespace std;

class Array
{
    public:
    int *Arr;
    int size;

    Array(int Length)
    {
        size = Length;
        Arr = new int[size];

        
    }
    ~Array()
    {
        delete[]Arr;
    }

    void Accept()
    {
        cout<<"Enter the elements"<<"\n";
        int icnt = 0;
        for(icnt=0;icnt<size;icnt++)
        {
            cin>>Arr[icnt];
        }
    }

    void Display()
    {
        cout<<"Elements of the array : "<<"\n";
        int icnt=0;
        for(icnt=0;icnt<size;icnt++)
        {
            cout<<Arr[icnt]<<"\t";
        }
        cout<<"\n";
    }

};

int main()
{
    Array obj(5);

    obj.Accept();
    obj.Display();

    return 0;
}