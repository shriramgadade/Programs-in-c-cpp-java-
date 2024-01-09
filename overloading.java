class overloading
{
    public static void main(String arg[])
    {
        Arithemetic aobj = new Arithemetic();
        int iret=0;
        double dret=0.0;
        iret = aobj.Addition(10,11);
        System.out.println("Addition is : ",+iret);
        iret = aobj.Addition(10,11,21);
        System.out.println("Addition is : ",+iret);
        dret = aobj.Addition(10.8,11.7);
        System.out.println("Addition is : ",+iret);
    }
}
{
    public static void main(String arg[])
    {
        Arithemetic aobj = new Arithemetic();
        int iret=0;
        double dret=0.0;
        iret = aobj.Addition(10,11);
        System.out.println("Addition is : ",+iret);
        iret = aobj.Addition(10,11,21);
        System.out.println("Addition is : ",+iret);
        dret = aobj.Addition(10.8,11.7);
        System.out.println("Addition is : ",+iret);
    }
}

class Arithemetic
{
    public int Addition(int A,int B)
    {
    
        return A+B;
    }
    public int Addition(int A,int B,int C)
    {
        return A+B+C;
    }
    public double Addition(double A,double B)
    {
        return A+B;
    }
    public void Addition(int A,double B)
   {
    System.out.println("inside the first addition");
   }
   public void Addition(double A,int B)
   {
    System.out.println("inside the second addition");
   }
}
