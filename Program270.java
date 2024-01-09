import java.util.*;
public class Program270 
{

    public static boolean Checkbit(int iNo)
    {
        int imask = 0x00000004;
        int iResult=0;
        iResult = imask & iNo;
        if(iResult==imask)
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
        boolean iRet = false;
        
        System.out.println("Enter The Number\n");
        iNo = sobj.nextInt();

        iRet = Checkbit(iNo);
        if(iRet==true)
        {
            System.out.println("3rd Bit is ONN\n");
        }
        else
        {
            System.out.println("3rd Bit is OFF\n");
        }

    }

}
