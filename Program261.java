import java.util.*;
public class Program261
{
    public static void main(String arg[])
    {
        Scanner sobj = new Scanner(System.in);
        int iNo = 0;
        int iDigit = 0;

        System.out.println("Enter the number :  ");
        iNo = sobj.nextInt();

        while(iNo != 0)
        {
            iDigit = iNo %2;
            iNo = iNo /2;
            System.out.print(iDigit);
           
        }
        sobj.close();
    }


}