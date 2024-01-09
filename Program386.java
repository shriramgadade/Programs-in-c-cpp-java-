import java.util.*;

class Matrix
{
    public void display(int Arr[][])
    {
        int i,j=0;

     System.out.println("Entered Elements are : ");

         for( i =0;i<Arr.length;i++) // irow = Arr.length
        {
            for( j =0;j<Arr[i].length;j++)
            {
                System.out.print(Arr[i][j] +"\t");
            }
            System.out.println();
        }
    }


}
class Program385
{
    public static void main(String Arg[])
    {
        Scanner sobj = new Scanner(System.in);
        int irow = 0, icol =0,i=0,j=0;

        System.out.println("Enter the number of rows : ");
        irow = sobj.nextInt();

        System.out.println("Enter the nu,ber of co;umns :" );
        icol = sobj.nextInt();

        int Arr[][] = new int[irow][icol];
        

        System.out.println("Enter the elements : ");
        for( i =0;i<irow;i++)
        {
            for( j =0;j< icol;j++)
            {
                Arr[i][j] = sobj.nextInt();
            }
        }

        Matrix mobj = new Matrix();
        mobj.display(Arr);

        
          



    }
}