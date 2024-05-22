package ejercicio2;

public class Ejercicio2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int x, y, aux;
		for(x=50 ; x<=100 ; x++) {
			aux=0;
			for(y=1 ; y<=x ; y++) {
			if(x%y == 0){
				aux++;
			}
		}
			if(aux==2) {
				System.out.println("\n\nNumero " + x + ": primo");
			}else {
				System.out.println("\n\nNumero " + x + ": ");
				for(y=1; y<=x ; y++) {
					if(x%y==0) {
					System.out.print(" " + y);
				}
			    }
			}
	}

}
}
