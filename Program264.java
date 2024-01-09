import java.util.Scanner;
/* 3 bit are on off */

public class Program264
{
    public static boolean Checkbit(int iNo)
    {
         int imask = 4;
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
      
        System.out.println("Enter number :");
        iNo = sobj.nextInt();
         bret = Checkbit(iNo);

         if(bret==true)
        {
            System.out.println("3 rd bit is ON");
        }
        else
        {
             System.out.println("3 rd bit is OFF");

        }


       
    
    }
}
