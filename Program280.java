import java.util.Scanner;

public class Program280
{
    public static int Togglebit(int iNo,int ipos)
    {
        int imask = 0x00000001;
        int iresult;
        
        imask = imask << (ipos-1);//15th bit are tougle
        

         iresult = (iNo ^ imask);
         return iresult;
        
    }
     public static void main(String Arg[])
    {
        Scanner sobj = new Scanner(System.in);
        int iNo = 0;
        int iret = 0;
        int ipos = 0;
       // boolean bret = false;
      // bret = Checkbit(iNo);

        System.out.println("Enter number :");
        iNo = sobj.nextInt();

        System.out.println("enter the position\n");
        ipos = sobj.nextInt();
      
        iret = Togglebit(iNo,ipos);

        System.out.println("updated number is : "+iret);
        
        

       
    
    }
}
