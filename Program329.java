import java.util.*;
import java.io.*;

public class Program329
{
    public static void main(String arg[]) throws Exception
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter The name of packed file the you wany yo unpack : ");
        String PackedFile = sobj.nextLine();

        File fobj = new File(PackedFile);
        FileInputStream fiobj = new FileInputStream(fobj);

        byte Header[] = new byte[100];

        fiobj.read(Header,0,100);

        String Hstr = new String(Header);
        System.out.println(Hstr); 
    
    }


    
}
