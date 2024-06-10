package calculadoraMatriz;

/*import org.apache.commons.math3.linear.Array2DRowRealMatrix;
import org.apache.commons.math3.linear.DecompositionSolver;
import org.apache.commons.math3.linear.LUDecomposition;
import org.apache.commons.math3.linear.RealMatrix;*/

public class operaciones {


    public static int[][] sumarDosMatrices(int[][] a, int[][] b) {

        // En este metodo se supone que las 2 matrices tienen el mismo tamaño
        int matrizResultante[][];
        int i, j, filasA, columnasA;
        filasA = a.length;
        columnasA = a[0].length;

        matrizResultante = new int[filasA][columnasA];

        for (i = 0; i < filasA; i++) {
            for (j = 0; j < columnasA; j++) {
                matrizResultante[i][j] = a[i][j] + b[i][j];
            }
        }
        return matrizResultante;
    }

    public static int[][] restarDosMatrices(int[][] a, int[][] b) {

        // En este metodo se supone que las 2 matrices tienen el mismo tamaño
        int matrizResultante[][];
        int i, j, filasA, columnasA;

        filasA = a.length;
        columnasA = a[0].length;

        matrizResultante = new int[filasA][columnasA];

        for (i = 0; i < filasA; i++) {
            for (j = 0; j < columnasA; j++) {
                matrizResultante[i][j] = a[i][j] - b[i][j];
            }
        }
        return matrizResultante;
    }

    public static int[][] multiplicarDosMatrices(int[][] a, int[][] b) {
        
        int sum, c [][] = new int [a.length][b[0].length];

        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < b[0].length; j++) {
                sum=0;
                for(int k=0;k<a[0].length;k++){
                    sum += a[i][k]*b[k][j];
                }
                c[i][j]=sum;
            }
        }
        return c;

    }
    
    public static int[][] matrizPorEscalar(int[][] a, int b) {

        int[][] matrizResultado = new int[a.length][a[0].length];
        for (int i = 0; i != a.length; i++) {
            for (int j = 0; j != a[i].length; j++) {
                matrizResultado[i][j] = a[i][j] * b; //simplemente se multiplica cada valor de la matriz por el valor escalar.
            }
        }
        return matrizResultado;
    }
    
    public static int[][] determinanteMatriz(int[][] a) {
        
        int b [][] = new int [1][1];
        int n = a.length;
        
        
        if (n == 1) {
        	b[0][0]=a[0][0]; 
        }
        
        if (n == 2) {
        	
            b[0][0] = a[0][0] * a[1][1] - a[0][1] * a[1][0];
        }
        
        if (n == 3) {
            b[0][0] = ((a[0][0] * a[1][1] * a[2][2]) + (a[0][1] * a[1][2] * a[2][0]) + (a[0][2] * a[1][0] * a[2][1])) - ((a[0][2] * a[1][1] * a[2][0]) - (a[0][0] * a[1][2] * a[2][1]) - (a[0][1] * a[1][0] * a[2][2]));
        }
        
        
        return b;
    }
    
    /*public static int[][] inversaMatriz(int[][] a) {
        
        int b [][] = new int[a.length][a[0].length];
        int n = a.length;
        
        
        DecompositionSolver solver = new LUDecomposition(matrix).getSolver();
        return solver.getInverse();
        

    }*/
    
    /*public static int[][] dividirDosMatrices(int[][] a) {
}*/
    
    
    

}
