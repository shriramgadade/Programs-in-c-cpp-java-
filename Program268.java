import java.util.*;
public class Program268
{
    public static boolean Checkbit(int iNo)
    {
        int iResult = 0;
        int imask = 16448;
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
        boolean iret = false;

        System.out.println("Enter the number\n");
        iNo = sobj.nextInt();

        iret = Checkbit(iNo);
        if(iret == true)
        {
            System.out.println("7th and 18th bit is ONN\n");
        }
        else
        {
            System.out.println("7th and 18th bit is OFF\n");
        }
    }
}
