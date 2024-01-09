import java.util.*;
import java.io.*;
public class Program346
{

    public static void main(String Arg[])throws Exception
    {
        Scanner sobj = new Scanner(System.in);
        System.out.println("Enter the string");
        String str = sobj.nextLine();

        str = str.trim();

        str = str.replaceAll("\\s+"," ");
        String words[] = str.split(" ");

        for(int i=0;i<words.length;i++)//for each
        {
            System.out.println("Word is: "+words[i]+ " having length : "+words[i].length());
        }
            
    }
      
}
