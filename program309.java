import java.util.*;
import java.io.*;
class program309
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
       
       
       if(bret) //bret == true;
       {
        System.out.println("name of file is :"+fobj.getName());
        System.out.println("absolute path of file is :"+fobj.getAbsolutePath()); 
        System.out.println("file size is  :"+fobj.length());
        System.out.println("we can read from file  is :"+fobj.canRead());
        System.out.println("we can write into file  :"+fobj.canWrite());
      }
    }


     
      catch(Exception obj)
      {
        System.out.println("Exception occured");
      }

    
}
}