import java.util.*;
public class Program273
{
    public static boolean Checkbit(int iNo)
    {
        int imask = 0x00004040;
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
            System.out.println("7th ans 15th  bit is ONN");
        }
        else
        {
            System.out.println("7th and 15th bit is OFF");

        }
    }
}
