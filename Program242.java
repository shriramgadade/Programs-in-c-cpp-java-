// Best option in industrial

import java.util.*;
class Arithematic
{
    public int ivalueue1;
    public int ivalueue2;

    public Arithematic(int A,int B)
    {
        this.ivalueue1 = A;
        this.ivalueue2 = B;
    }
     public int Addition()
    {
        int iSum = 0;
        iSum = this.ivalueue1 + this.ivalueue2;
        return iSum;
    }

}
class Program242
{
   
    public static void main(String Arg[])
    {
       
        Scanner sobj = new Scanner(System.in);

        int iNo1 =0,iNo2=0;
        int iAns = 0;

        System.out.println("Enter first number : ");
        iNo1= sobj.nextInt();

         System.out.println("Enter second number : ");
         iNo2 = sobj.nextInt();

          Arithematic aobj = new Arithematic(iNo1,iNo2);

         iAns = aobj.Addition();

         System.out.println("Addition is : "+iAns);



    }
    
}

