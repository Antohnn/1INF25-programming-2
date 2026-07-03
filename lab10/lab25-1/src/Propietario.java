import java.util.Scanner;

public class Propietario extends Registro {
    private int dni;
    private String nombre;
    private String apellidos;
    private String direccion;

    public Propietario() {}

    public Propietario(final Propietario propietario) {
        this.dni = propietario.getDni();
        this.nombre = propietario.nombre;
        this.apellidos = propietario.apellidos;
        this.direccion = propietario.direccion;
    }

    public int getDni() {
        return dni;
    }

    public void setDni(int dni) {
        this.dni = dni;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getApellidos() {
        return apellidos;
    }

    public void setApellidos(String apellidos) {
        this.apellidos = apellidos;
    }

    public String getDireccion() {
        return direccion;
    }

    public void setDireccion(String direccion) {
        this.direccion = direccion;
    }

    @Override
    public void cargar(Scanner archivo){
        if(!archivo.hasNextInt()){
            return;
        }
        this.dni=archivo.nextInt();
        this.nombre=archivo.next();
        this.apellidos=archivo.next();
        this.direccion=archivo.next();
    }
    @Override
    public void imprimir() {
        System.out.println(this);
    }
    @Override
    public String toString() {
        return String.format(
                "DNI: %d\n Nombres: %s\n Apellidos: %s\n Direccion: %s\n",
                dni,
                nombre,
                apellidos,
                direccion
        );
    }
}
