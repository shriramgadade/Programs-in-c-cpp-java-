import java.util.Scanner;

public class Program277
{
    public static int Togglebit(int iNo)
    {
        int imask = 0x00004000;//15th bit are tougle
        

         return (iNo ^ imask);
        
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
      
        iret = Togglebit(iNo);

        System.out.println("updated number is : "+iret);
        
        sobj.close();

       
    
    }
    
}
