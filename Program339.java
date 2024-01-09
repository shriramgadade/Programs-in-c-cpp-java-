import java.util.*;
import java.io.*;
public class Program339
{

    public static void main(String Arg[])throws Exception
    {
        Scanner sobj = new Scanner(System.in);

       System.out.println("Enter The String :");
       String str = sobj.nextLine();

       str = str.trim();

       System.out.println("After trim : "+str);

       str = str.replaceAll(" ", "");

       System.out.println("After replaceall : "+str);

    }

}