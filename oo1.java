import java.util.*;

class Animal {
    void sleep() {
        System.out.print("Zzzzzzzzzzz");
    }

    void Noise() {
        System.out.print("Grrrr");
    }

    void roam() {
        System.out.print("Roaming near water");
    }
}

class Lion extends Animal {
    void Noise() {
        System.out.print("Roar:Rrrrrrr");
    }
}

class Cat extends Animal {
    void Noise() {
        System.out.print("Meow Meow");
    }
}

class Wolf extends Animal {
    void Noise() {
        System.out.print("Howling: Ouooooo!");
    }
}

class Main {
    public static void main(String Args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a value between 1 and 3: ");
        int n = sc.nextInt();
        if (n == 1) {
            Lion l = new Lion();
            l.Noise();
        }

        else if (n == 2) {
            Cat c = new Cat();
            c.Noise();
        }

        else if (n == 3) {
            Wolf w = new Wolf();
            w.Noise();
        }

        else {
            System.out.println("Try Again");
        }
    }
}
