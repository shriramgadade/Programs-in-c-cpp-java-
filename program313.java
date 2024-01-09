import java.util.*;
import java.io.*;
class program313
{
    public static void main(String Arg[])
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the name of file\n");
        String FileName = sobj.nextLine();
       try
    {
        System.out.println("Enter The data from that you want to write in the file");
        String Data = sobj.nextLine();

        FileOutputStream fobj = new FileOutputStream(FileName,true);

        byte arr[] = Data.getBytes();

        fobj.write(arr);
        fobj.close();

    }
    catch(Exception obj)
      {
        System.out.println("Exception occured");
      }

    
}
}