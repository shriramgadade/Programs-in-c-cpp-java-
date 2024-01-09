import java.util.Scanner;

public class Program275
{
    public static int offbit(int iNo)
    {
        int imask = 0x00000008; //4th bit are tougle
        int iresult = 0;

        
        
         iresult = iNo & imask;
        if(iresult==imask)
        {
            return (iNo ^ imask);
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
        int iret = 0;
       // boolean bret = false;
      // bret = Checkbit(iNo);

        System.out.println("Enter number :");
        iNo = sobj.nextInt();
      
        iret = offbit(iNo);

        System.out.println("updated number is : "+iret);
    }
    
}
