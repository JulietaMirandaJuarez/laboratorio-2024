import java.util.Scanner;

public class Ejercicio3 {

    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);

        int num, y, aux;

        do {
            System.out.println("Ingrese un numero: ");
            num = teclado.nextInt();
            
            aux = 0;
            for (y = 1; y <= num; y++) {
                if (num % y == 0) {
                    aux++;
                }
            }
        } while (num <= 100 || aux != 2);

        System.out.println("Saliendo del programa...");
    }
}

