import java.util.Scanner;

public class ejercicio5 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner teclado = new Scanner(System.in);
		
		int num1, num2, resultado, opcion;
		do {
		System.out.println("\n--- Calculadora---");
		System.out.println("1) Sumar ");
		System.out.println("2) Restar ");
		System.out.println("3) Multiplicar ");
		System.out.println("4) Dividir ");
		System.out.println("5) Salir del programa ");
		
		System.out.println("\nElija la opcion a realizar: ");
		opcion = teclado.nextInt();
		
		System.out.println("Ingrese el primer número:");
        num1 = teclado.nextInt();

        System.out.println("Ingrese el segundo número:");
        num2 = teclado.nextInt();

        switch (opcion) {
            case 1:
                resultado = num1 + num2;
                System.out.println("El resultado de la suma es: " + resultado);
                break;
                
            case 2:
                resultado = num1 - num2;
                System.out.println("El resultado de la resta es: " + resultado);
                break;
                
            case 3:
                resultado = num1 * num2;
                System.out.println("El resultado de la multiplicación es: " + resultado);
                break;
                
            case 4:
                if (num2 != 0) {
                    resultado = num1 / num2;
                    System.out.println("El resultado de la división es: " + resultado);
                } else {
                    System.out.println("No se puede dividir por cero.");
                }
                break;
                
            case 5:
            	System.out.println("Saliendo del programa...");
            	break;
	}
        
	}while(opcion!=5);

}
	
}
