import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
//        Created Scanner
        Scanner scanner = new Scanner(System.in);
//        Input First Number
        System.out.println("Enter Your First Number");
        int FirstNumber = scanner.nextInt();
        System.out.println("Enter Your Second number");
        int SecondNumber = scanner.nextInt();
        int result= FirstNumber + SecondNumber;
        System.out.println("your result is "+ result);


    }
}
