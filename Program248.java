// Input : 5
/*
 * 1*2*3*4*5*
 */

import java.util.*;
class Program248
{
    public static void Display(int iNo)
    {
        int icnt =0;
        for(icnt=1;icnt<=iNo;icnt++)
        {
            System.out.print(icnt+"\t"+"*\t");
        }
        System.out.println();

    }
    public static void main(String Arg[])
    {
       
        Scanner sobj = new Scanner(System.in);

        int iValue = 0;

        System.out.println("Enter number : ");
        iValue = sobj.nextInt();
         Display(iValue);

       
        sobj.close();

       


    }
    
}

