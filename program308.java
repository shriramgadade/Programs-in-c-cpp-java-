import java.util.*;
import java.io.*;
class program308
{
    public static void main(String Arg[])
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the name of file\n");
        String FileName = sobj.nextLine();
       try
       {

       
        File fobj = new File(FileName);

       boolean bret = false;

       bret = fobj.exists();
       if(bret == true)
       {
        System.out.println("file is present");

       }
       else
       {
        System.out.println("ther is no such file");
       }
     }
     
      catch(Exception obj)
      {
        System.out.println("Exception occured");
      }

    }
}