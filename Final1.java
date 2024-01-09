class Final1
{
    public static void main(String arg[])
    {
        demo dobj = new demo();
        System.out.println("value of A",+dobj.A);
        System.out.println("value of B",+dobj.B);
        dobj.A++;
         demo dobj2 = new demo(51);
        System.out.println("value of A",+dobj.A);
        System.out.println("value of B",+dobj.B);
        dobj.A++;
        //dobj.B++;
    
    }
}
class demo
{
    public int A;
    public final int B;
    demo()
    {
        A=11;
        B=21;
    }
     demo(int i,int j)
    {
        A=i;
        B=j;
    }


}
