class node //struct node
{
    public int data;
    public node next; //struct node *next

    public node(int no)
    {
        data = no; // parameter is data then this.data
        next = null;
    }
}
class SinglyLL
{
    private node first;
    private int Count;

    public SinglyLL()
    {
        first = null;
        Count = 0;
    }

    public void InsertFirst(int no)
    {
        node newn = new node(no);

        if(first == null)// LL is empty
        {
            first = newn;

        }
        else
        {
            newn.next = first;
            first = newn;
        }
        Count++;
    }
    public void InsertLast(int no)
    {
         node newn = new node(no);
         node temp = first;

        if(first == null) // LL is empty
        {
            first = newn;

        }
        else
        {
            while(temp.next != null)
            {
                temp = temp.next;
            }
            temp.next = newn; 
        }
        Count++;



    }
    
    public void DeleteFirst()
    {

    }
    public void DeleteLast()
    {
        if(first == null)
        {
            return;
        }
        else if(first.next == null)
        {
            first = null;
            
        }
        
    }
     public void InsertAtPos(int no,int ipos)
    {
        int i=0;
        node newn = new node(no);
        node temp = first;
        if((ipos < 1) && (ipos > Count))
        {
            System.out.println("invalid position:---");
            return;

        }
        else if(ipos == 1)
        {
            InsertFirst(no);
        }
        else if(ipos == Count+1)
        {
            InsertLast(no);
        }
        else
        {
            for(i=1;i<ipos-1;i++)
            {
                temp = temp.next;
                
            }
            newn.next = temp.next;
            temp.next = newn;
            Count++;


        }



        
    }
    public void DeleteAtPos(int ipos)
    {
       int i=0;
        node temp = first;
        if((ipos < 1) && (ipos > Count))
        {
            System.out.println("invalid position:---");
            return;

        }
        else if(ipos == 1)
        {
            DeleteFirst();
        }
        else if(ipos == Count+1)
        {
            DeleteLast();
        }
        else
        {
             for(i=1;i<ipos-1;i++)
            {
                temp = temp.next;
                
            }
            temp.next = temp.next.next;

            Count--;


        }

        
    }
    public void Display()
    {
        node temp = first;
        System.out.println("Elements of the Linked List is");

        while(temp != null)
        {
            System.out.print("| "+temp.data+" |->");
            temp = temp.next;

        }
        System.out.println("null");

    }
    public int Count()
    {
        return Count;
    }




}



public class Program409
{
    public static void main(String Arg[])
    {
        SinglyLL obj = new SinglyLL();
        int iRet = 0;
        obj.InsertFirst((51));
        obj.InsertFirst((21));
        obj.InsertFirst((11));

        obj.Display();



        iRet = obj.Count();

        System.out.println("Number of node is :"+iRet);


        obj.InsertLast(31);
        obj.InsertLast(41);
        obj.InsertLast(51);

        obj.Display();



        iRet = obj.Count();

        System.out.println("Number of node is :"+iRet);


        obj.InsertAtPos(105,5);
        obj.Display();
        iRet = obj.Count();
        System.out.println("Number of node is :"+iRet);

        obj.DeleteAtPos(5);
        obj.Display();
        iRet = obj.Count();

        System.out.println("Number of node is :"+iRet);





    }
    
}
