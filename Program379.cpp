#include<iostream>
#include<stdlib.h>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node *next;
}NODE,*PNODE;

template<class T>
class singlyLL
{
    private:
    PNODE first;
    int count;

    public:
    singlyLL();
    void insertfirst(T No);
    void insertlast(T No);
    void display();
    int countnode();
    void deletefirst();
    void deletelast();
    void deleteAtpos(int ipos);
    void insertAtpos(T No,int ipos);
};

template<class T>
 singlyLL<T> :: singlyLL()
 {
    cout<<"inside constructor"<<"\n";
    first = NULL;
    Count = 0;

 }

 template<class T>
 void singlyLL<T> :: insertfirst(T No)
 {
    PNODE newn = NULL;
    newn = new NODE;

    newn->data = No;
    newn -> next = NULL;

    if(first==NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    count++;
 }
 template<class T>
 void singlyLL<T> :: insertlast(T No)
 {
    PNODE newn = NULL;
    PNODE temp = first;
    newn = new node;

    newn->data = No;
    newn->next = NULL;

    if(first == NULL)
    {
        first=newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
    }
    count++;

 }

 template<class T>
 void singlyLL<T> :: display()
 {
    PNODE first = first;

    cout<<"Elements are linked list are : --"<<"\n";
    while(temp != NULL)
    {
        cout<<temp->data<<"|->"
        temp = temp->next;
    }
    cout<<"NULL\n";

 }
 template<class T>
 int singlyLL<T> :: countnode()
 {
    return count;
 }

 template<class T>
 void singlyLL<T> :: deletefirst()
 {
    if(first==NULL)
    {
        return;
    }
    else if(first->next = NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        PNODE temp = first;
        first = first->next;
        delete temp;
    }
    count--;
 }
 template<class T>
 void singlyLL<T> :: deletelast()
 {
      if(first==NULL)
    {
        return;
    }
    else if(first->next = NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
    
    PNODE temp = first;

    while(temp->next->next != NULL)
    {
        temp=temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    }
}
template<class T>
void singlyLL<T> :: insertAtpos(T No,int ipos)
{

  if((ipos < 1) || (ipos >count+!))
  {
    cout<<"invalid position \n ";
    return;

  }
  else if(ipos == 1)
  {
    insertfirst(NO);
  }
  else if(ipos == count+1)
  {
    insertlast(No);
  }
  else
  {
    PNODE newn = new NODE;

    newn->data = No;
    newn->next = NULL;

    PNODE temp=first;
    int i=0;

    for(i=1;i<ipos-1;i++)
    {
        temp=temp->next;
    }
    newn->next = temp->next;
    temp->next=newn;
     
     count++;
  }

}
template<class T>
void singlyLL<T> :: deleteAtpos(int ipos)
{
     if((ipos < 1) || (ipos >count+!))
  {
    cout<<"invalid position \n ";
    return;

  }
  else if(ipos == 1)
  {
    deletefirst();
  }
  else if(ipos == count+1)
  {
    deletelast();
  }
  else
  {
    int i=0;
    
    PNODE temp = first;

    for(i=1;i<ipos-1;i++)
    {
        temp=temp->next;
    }
    PNODE tagetednode = temp->next;

    temp->next = temp->next->next;
    delete targetednode;
    count--;
    
  }


}
int main()
{
    singlyLL<int>obj1;
    obj1.insertfirst(10);
    obj1.insertfirst(10);
    obj1.insertfirst(10);

    obj1.display();
}

 


