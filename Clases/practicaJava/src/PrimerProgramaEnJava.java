import java.io.FileNotFoundException;

public class PrimerProgramaEnJava {
    public static void main (String[] args){
        int a=23;
        double x=54.85;
        String nombre="Juan Perez";
        boolean activo=true;

        System.out.println("Primer programa en Java");
        System.out.println("A = " + a);
        System.out.println("X = " + x);
        System.out.println("A = " + a*x);
        System.out.println("Nombre = "+ nombre);
        System.out.println("Activo = "+ activo);
        System.out.printf("A= %2d X= %5.2f Nombre = %-20s \n",a,x,nombre);
    }
}
