import java.util.*;
class Program246
{
    public static void evenoddfactors(int iNo)
    {
        int ifact = 1;
        int icnt = 0;
        for(icnt = 1;icnt<=iNo;icnt++)
        {
            if((icnt%2)==0)
            {
                System.out.println("Even factor is :"+icnt);
            }
            else
            {
                System.out.println("odd factor is :"+icnt);
            }

        }
    }
        

    
   
    public static void main(String Arg[])
    {
       
        Scanner sobj = new Scanner(System.in);

        int iValue = 0,iAns =0;

        System.out.println("Enter number : ");
        iValue = sobj.nextInt();
         evenoddfactors(iValue);

        System.out.println("Factorial is :"+iAns);
        sobj.close();

       


    }
    
}

