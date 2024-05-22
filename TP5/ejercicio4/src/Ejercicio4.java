import java.util.ArrayList;
import java.util.List;

public class Ejercicio4 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		// Creamos una lista de nombres utilizando List y ArrayList
        List<String> nombres = new ArrayList<>();

        // Agregamos algunos nombres a la lista
        nombres.add("Julieta");
        nombres.add("Micaela");
        nombres.add("Sarah");
        nombres.add("Thiago");

        // Iteramos sobre la lista utilizando un bucle for-each para acceder a cada nombre
        for (String nombre : nombres) {
            // Imprimimos cada nombre en la lista
            System.out.println("Nombre: " + nombre);
        }

    }
}

