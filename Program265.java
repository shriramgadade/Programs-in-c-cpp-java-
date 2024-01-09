import java.util.*;
class Program265
{
    public static boolean Checkbit(int iNo)
    {
        int imask = 256;
        int iResult = 0;
        iResult = imask & iNo;
        if(iResult == imask)
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

        System.out.println("Enter the number\n");
        iNo = sobj.nextInt();

        iRet = Checkbit(iNo);
        if(iRet == true)
        {
            System.out.println("9th bit is ONN----\n");
        }
        else
        {
             System.out.println("9th bit is OFF----\n");
        
        }

    }
}