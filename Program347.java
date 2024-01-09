import java.util.*;
import java.io.*;

public class Program347
{
    public static void main(String arg[]) throws Exception
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter The name of packed file the you want to unpack : ");

        String PackedFile = sobj.nextLine();

        File fobj = new File(PackedFile);

        FileInputStream fiobj = new FileInputStream(fobj);

        byte Header[] = new byte[100];

        fiobj.read(Header,0,100);

        String Hstr = new String(Header);

        System.out.println(Hstr); 

        System.out.println("Length of header string is :"+Hstr.length());

        String str = Hstr.trim(); // used cut the whitespace of end

        System.out.println("Length of final header string are :"+str.length());

        String Token[] = str.split(" ");//return value should be array of string 

        System.out.println("Name of file is : "+Token[0]);

        System.out.println("size of file is : "+Token[1]);

        File NewFile = new File(Token[0]);
        NewFile.createNewFile();
        
    
    }


    
}
