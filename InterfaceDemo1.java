class InterfaceDemo1
{
    public static void main(String arg[])
    {
        PPA pobj = new PPA();
        System.out.println("Value of PI is :"+Circle.PI);
       // Circle.PI = 6.15; variables are final
        float fRet = 0.0f;
        fRet = pobj.Area(10.7f);
        System.out.println("Area is: "+fRet);
        fRet = pobj.Circumference(10.7f);
        System.out.println("circumference  is: "+fRet);

    }
}
interface Circle
{
    float PI = 3.14f;
     float Area(float radius);
     float circumferance(float radius);
    
}
class PPA implements Circle
{
    public float Area(float radius);
    {
        return PI * radius * radius;
    }
    public float Circumference(float radius)
    {
        return 2 * PI * radius;
    }
}
