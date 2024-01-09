import java.util.Scanner;

public class Program267
{
    public static boolean Checkbit(int iNo)
    {
        int imask = 65536;
        int iresult = 0;

        
        
         iresult = iNo & imask;
        if(iresult==imask)
        {
            return true;
        }
        else
        {
             return false; 

        }

    }
     public static void main(String Arg[])
    {
        Scanner sobj = new Scanner(System.in);
        int iNo = 0;
        boolean bret = false;
       bret = Checkbit(iNo);

        System.out.println("Enter number :");
        iNo = sobj.nextInt();
         if(bret==true)
        {
            System.out.println("17 th bit is ONN");
        }
        else
        {
             System.out.println("17 th bit is OFF");

        }


       
    
    }
}
