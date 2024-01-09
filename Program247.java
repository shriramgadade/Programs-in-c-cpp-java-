import java.util.*;
class Program247
{
    public static void evenoddfactors(int iNo)
    {
       int iSumeven=0;
       int iSumodd =0;
        int icnt = 0;
        for(icnt = 1;icnt<=iNo;icnt++)
        {
            if((icnt%2)==0)
            {
                iSumeven = iSumeven + icnt;
            }
            else
            {
               iSumodd = iSumodd + icnt;
            }

        }
        System.out.println("Addition of even factor is :--"+iSumEven);
        System.out.println("Addition of odd factor is :--"+iSumodd);
    }
}
        

    
   
    public static void main(String Arg[])
    {
       
        Scanner sobj = new Scanner(System.in);

        int iValue = 0,iAns =0;

        System.out.println("Enter number : ");
        iValue = sobj.nextInt();
         evenoddfactors(iValue);

        System.out.println("Factorial is :"+iAns);
        sobj.close();

       


    }
    
}

