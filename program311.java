import java.util.*;
import java.io.*;
class program311
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

        FileWriter fwobj = new FileWriter(FileName);
        fwobj.write(Data);
        
        
        
     // }
    }


     
      catch(Exception obj)
      {
        System.out.println("Exception occured");
      }

    
}
}