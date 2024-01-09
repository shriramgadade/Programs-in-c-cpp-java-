#include<iostream>
using namespace std;

template<class T>
class Array
{
    public:
    T *Arr;
    T size;

    Array(T Length);
    ~Array();
    T Accept();
   T Display();
   T Addition();
   

};
template<class T>
 Array<T>:: Array(T Length)
    {
        size = Length;
        Arr = new T[size];

        
    }
    template<class T>
   Array<T> :: ~Array()
    {
        delete[]Arr;
    }
    template<class T>
    T Array<T> :: Accept()
    {
        cout<<"Enter the elements"<<"\n";
        int icnt = 0;
        for(icnt=0;icnt<size;icnt++)
        {
            cin>>Arr[icnt];
        }
    }
    template<class T>
   
    T Array<T> :: Display()
    {
        cout<<"Elements of the array : "<<"\n";
        int icnt=0;
        for(icnt=0;icnt<size;icnt++)
        {
            cout<<Arr[icnt]<<"\t";
        }
        cout<<"\n";
    }
    template<class T>
    T Array<T>:: Addition()
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
    Array<int>obj(5);
    int ret=0;

    obj.Accept();
    obj.Display();
    ret = obj.Addition();

    cout<<"Addition of all elements is: "<<ret<<"\n";
    

    return 0;
}