import java.util.Scanner;
/* 9bit is on or off */

public class Program282
{
    public static boolean Checkbit(int iNo,int ipos)
    {
         int imask = 0x00000001;
         //int
        int iresult = 0;
        imask = imask << (ipos-1);

        
        
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
        int ipos = 0;
        boolean bret = false;
       bret = Checkbit(iNo,ipos);

        System.out.println("Enter number :");
        iNo = sobj.nextInt();
         System.out.println("enter the position\n");
         ipos = sobj.nextInt();
         if(bret==true)
        {
            System.out.println("given bit is ONN");
        }
        else
        {
             System.out.println("given bit is OFF");

        }


       
    
    }
}
