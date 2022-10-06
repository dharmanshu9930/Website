class  abc{
    abc(int a , int b){
        System.out.println("Sum of "+a + " and "+b+ " is: ");
        System.out.println(a+b);
    }
    abc(int a , int b , int c){
        System.out.println("Sum of " +a +", "+ b + " and " +c+ " is: ");
        System.out.println(a+b+c);
    }
}
public class lab5 {
    public static void main(String[] args) {
        abc a1 = new abc(4,5);
        abc a2 = new abc(4,5,6);
    }
}
