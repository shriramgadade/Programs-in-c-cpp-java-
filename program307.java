import java.util.*;
import java.io.*;
class program307
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
        bret = fobj.createNewFile();
        if ( bret == true)
         {
            System.out.println("file gets susccesfully created\n");

        }
        else

        {
            System.out.println("File not created..\n");
        }
      }
    
      catch(Exception obj)
      {
        System.out.println("Exception occured");
      }

    }
}