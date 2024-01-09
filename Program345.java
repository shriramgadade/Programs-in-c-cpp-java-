import java.util.*;
import java.io.*;
public class Program345
{

    public static void main(String Arg[])throws Exception
    {
        Scanner sobj = new Scanner(System.in);
        System.out.println("Enter the string");
        String str = sobj.nextLine();

        str = str.trim();

        str = str.replaceAll("\\s+"," ");
        String words[] = str.split(" ");

        for(String s: words)//frpeach
        {
            System.out.println(s);
        }
      
    }