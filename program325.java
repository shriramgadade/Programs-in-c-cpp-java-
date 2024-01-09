import java.util.*;
import java.io.*;

class program325
{
    public static void main(String arg[]) throws Exception
    {
        Scanner sobj = new Scanner(System.in);
        boolean bret = false;

        System.out.println("Enter the name of Directory : ");
        String DirectoryName = sobj.nextLine();

        System.out.println("Enter the name of packed file that you want to create : ");
        String PackedFile = sobj.nextLine();

        File fobjPack = new File(PackedFile);

       
         File fobj = new File(DirectoryName);

        bret = fobj.isDirectory();
        if(bret == true)
        {
            System.out.println("Directory is present");

            File Arr[] = fobj.listFiles();
            System.out.println("Number of files in the directory are : "+Arr.length);

             
            String Header = null;
            FileOutputStream fcombine = new FileOutputStream(PackedFile);

            //travel ditectory
            for(int i = 0; i < Arr.length; i++)
            {
                //create header
                Header = Arr[i].getName() + " "+Arr[i].length();
                
                // add extre space at the end of header
                for(int j = Header.length();j<100;j++)
                {
                    Header = Header +" ";
                }
                // convert string header into byte
                byte hArr[] = Header.getBytes();

                // write header into packed file
                fcombine.write(hArr,0,100);
               
            }
           
        }
        else 
        {
            System.out.println("There is no such directory");
        }
    }
}
