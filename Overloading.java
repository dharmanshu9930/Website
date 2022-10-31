public class Overloading
{
static int plusM(int x,int y)
{
return x+y;

}
static double plusM(double x, double y)
{
return x+y;
}
public static void main(String [] args)
{
int myNum1=plusM(8,5);
double myNum2=plusM(4.3,6.26);
System.out.println("int : " +myNum1);
System.out.println("double : " +myNum2);
}}
