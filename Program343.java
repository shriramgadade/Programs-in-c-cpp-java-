import java.util.*;
import java.io.*;
public class Program343
{

    public static void main(String Arg[])throws Exception
    {
        Scanner sobj = new Scanner(System.in);

       System.out.println("Enter The String :");
       String str = sobj.nextLine();

       str = str.trim();

       System.out.println("After trim : "+str);

       str = str.replaceAll("\\s+"," ");//s :== multiple whiteapce replace with 1
      
        System.out.println("After replaceAll : "+str);

        String words[] = str.split(" ");// how many words in stirng

        System.out.println("Number of words in sentences are : "+words.length);

        for(int i = 0; i< words.length;i++)
        {
            System.out.println(words[i]);
        }



    }

}