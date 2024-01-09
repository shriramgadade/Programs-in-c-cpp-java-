#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;

}NODE,*PNODE,**PPNODE;

class singlyLL
{
    private:
         PNODE first;
         int count;
    public:
    singlyLL();
    
    void insertfirst(int no);
    

    void insertlast(int no);
    void display();
    
    int countnode();
    void deletefirst();
    void deletelast();
    void insertatpos(int no,int ipos);
    void deleteatpos(int ipos);
   

};
/* return value class name:: function name()
{

}*/
 singlyLL::singlyLL()
    {
    cout<<"inside constructer\n";
    first=NULL;
    count=0;
    }
    void singlyLL::insertfirst(int no)
    {
    PNODE newn = NULL;
    newn = new NODE;
    newn->data = no;
    newn->next = NULL;
    if(first==NULL) //if count==0;
    {
        first=newn;
    }
    else
    {
        newn->next=first;
        first=newn;

    }
    count++;
    }
    void singlyLL::insertlast(int no)
    {
        PNODE newn = NULL;
    newn = new NODE;
    newn->data = no;
    newn->next = NULL;
    if(first==NULL) //if count==0;
    {
        first=newn;
    }
    else
    {
        PNODE temp = first;
        while(temp->next != NULL)
        {
            temp = temp->next;
            
        }
        temp->next = newn;


    }
    count++;

    }
    int singlyLL::countnode()
    {
    return count;
    }
    void singlyLL::display()
    {
    PNODE temp = first;
    while(temp != NULL) // type 1
    {
        
        cout<<"| "<<temp->data<<"| ->";
        temp = temp->next;
        

    }
    cout<<"NULL \n";

    }
    void singlyLL::deletefirst()
    {
        if(first== NULL)
        {
            return;

        }
        else if(first->next == NULL)
        {
            delete(first);
            first==NULL;

        }
        else
        {
            PNODE temp = first;
            first=first->next;
            delete temp;


        }
        count--;

    }
    void singlyLL::deletelast()
    {
          if(first== NULL)
        {
            return;

        }
        else if(first->next == NULL)
        {
            delete(first);
            first==NULL;

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
        count--;

    }
    void singlyLL::insertatpos(int no,int ipos)
    {
        if((ipos<1) || (ipos>count+1))
        {
            return;
        }
        if(ipos==1)
        {
            insertfirst(no);
        }
        else if(ipos==count+1)
        {
            insertlast(no);
        }
        else
        {
            PNODE newn = new NODE;
            newn->data = no;
            newn->next = NULL;
            PNODE temp = first;
            int i = 0;
            for(i=1;i<ipos-1;i++)
            {
                temp = temp->next;
            }
            newn->next = temp->next;
            temp->next = newn;

            count++;



        }

    }
    void singlyLL::deleteatpos(int ipos)
    { if((ipos<1) || (ipos>count+1))
        {
            return;
        }
        if(ipos==1)
        {
            deletefirst();
        }
        else if(ipos==count+1)
        {
            deletelast();
        }
        else
        {
            PNODE temp = first;
            int i = 0;
            for(i=1;i<ipos-1;i++)
            {
                temp = temp->next;
            }
            PNODE targetednode = temp->next;
            temp->next = temp->next->next;
            delete targetednode;
            count--;

        }


    }

    

int main()
{
    singlyLL obj;
    int iret = 0;

    obj.insertfirst(11);
    obj.insertfirst(21);
    obj.insertfirst(51);
    obj.insertfirst(101);
    obj.insertfirst(111);
    obj.display();
    cout<<"number of element in the linked list are: "<<iret<<"\n";
     

    obj.insertlast(121);
    obj.insertlast(151);
    obj.insertlast(201);
    obj.display();
    cout<<"number of element in the linked list are: "<<iret<<"\n";
     
     
     obj.insertatpos(105,5);
      obj.display();
      iret = obj.countnode();
    cout<<"number of element in the linked list are: "<<iret<<"\n";
     
      obj.deleteatpos(5);
       obj.display();
       iret = obj.countnode();
    cout<<"number of element in the linked list are: "<<iret<<"\n";

    obj.deletefirst();
    obj.deletelast();
    

    obj.display();
    iret = obj.countnode();
    cout<<"number of element in the linked list are: "<<iret<<"\n";

    return 0;

}