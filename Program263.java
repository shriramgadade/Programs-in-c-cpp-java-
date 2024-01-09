import java.util.*;
public class Program263
{
    public static void main(String arg[])
    {
        Scanner sobj = new Scanner(System.in);
        int iNo = 0;
        int iDigit = 0;
        int icnt = 0;

        System.out.println("Enter the number :  ");
        iNo = sobj.nextInt();

        while(iNo != 0)
        {
            iDigit = iNo %2;
            iNo = iNo /2;
            if(iDigit == 1)
            {
                icnt++;
            }

            
        }
        System.out.println("Number of 1 bit are :"+icnt);
        sobj.close();
    }


}