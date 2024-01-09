import java.util.*;
class Program249
{
    public static void main(String Arg[])
    {
        Scanner sobj = new Scanner(System.in);

        int isize=0;
        System.out.println("Enter the number of elements:");
        isize = sobj.nextInt();
        int icnt=0;

        int Arr[] = new int[isize];
        System.out.println("Enter the elements :");
        for(icnt = 0;icnt<isize;icnt++)
        {
            Arr[icnt] = sobj.nextInt();
        }
        System.out.println("Elements of the array are :");
         for(icnt = 0;icnt<isize;icnt++)
        {
            System.out.println(Arr[icnt]);

        }
        sobj.close();
    }
}