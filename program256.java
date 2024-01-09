import java.util.*;
public class program256
 {
    public static void main(String Arg[])
    {
        Scanner sobj = new Scanner(System.in);

        String str = null;

        System.out.println("Enter your name :");
        str = sobj.nextLine();

        int icnt = 0;
        for(icnt = 0;icnt<str.length();icnt++)
        {
            System.out.println(str.charAt(icnt));//char at the index icnt
        }
        sobj.close();


    }

    
}
