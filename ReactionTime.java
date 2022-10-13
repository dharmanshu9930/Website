package Threads;

import java.util.Scanner;

public class ReactionTime {
    public static void main(String[] args) {
        System.out.println("Get Ready");
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Set");
        try {
            Thread.sleep(2223);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Go!!!!!!!!!!!!!");
        Scanner sc = new Scanner(System.in);
        long start = System.currentTimeMillis();
        sc.next();
        long end = System.currentTimeMillis();
        System.out.println(end - start + "ms");
        sc.close();
    }
}
