import java.util.*;
public class Program276
{
    public static int offbit(int iNo)
    {
        int imask = 0X00000400;
        int iresult = iNo&imask;
        if(imask==iresult)
        {
            return iNo^imask;
        }
        else
        {
            return iNo;
        }


    }
    public static void main(String Arg[])
    {
        Scanner sobj = new Scanner(System.in);
        int iNo = 0;
        int iRet = 0;

        System.out.println("Enter the number\n");
        iNo = sobj.nextInt();

        iRet = offbit(iNo); 
        System.out.println("Updated Number Is:------\n"+iRet);
        sobj.close();
    }
}