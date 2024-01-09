import java.util.*;
class Arithematic
{
     public int Addition(int ivalueue1, int ivaleue2)
    {
        int iSum = 0;
        iSum = ivalueue1 + ivalue2;
        return iSum;
    }

}
class Program241
{
   
    public static void main(String Arg[])
    {
        Arithematic aobj = new Arithematic();
        Scanner sobj = new Scanner(System.in);

        int iNo1 =0,iNo2=0;
        int iAns = 0;

        System.out.println("Enter first number : ");
        iNo1= sobj.nextInt();

         System.out.println("Enter second number : ");
         iNo2 = sobj.nextInt();

         iAns = aobj.Addition(iNo1,iNo2);

         System.out.println("Addition is : "+iAns);



    }
    
}

