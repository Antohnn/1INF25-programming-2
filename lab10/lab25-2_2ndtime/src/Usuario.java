import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

public class Usuario extends Registro{
    private int id;
    private String nombreCompleto;
    private int dni;
    private int edad;
    private String ciudad;
    private String fechaNacimiento;
    private String telefono;
    private String email;
    private String ocupacion;
    private List<Suscripcion> suscripciones;

    public Usuario(){
        suscripciones = new ArrayList<>();
    }
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNombreCompleto() {
        return nombreCompleto;
    }

    public void setNombreCompleto(String nombreCompleto) {
        this.nombreCompleto = nombreCompleto;
    }

    public int getDni() {
        return dni;
    }

    public void setDni(int dni) {
        this.dni = dni;
    }

    public int getEdad() {
        return edad;
    }

    public void setEdad(int edad) {
        this.edad = edad;
    }

    public String getCiudad() {
        return ciudad;
    }

    public void setCiudad(String ciudad) {
        this.ciudad = ciudad;
    }

    public String getFechaNacimiento() {
        return fechaNacimiento;
    }

    public void setFechaNacimiento(String fechaNacimiento) {
        this.fechaNacimiento = fechaNacimiento;
    }

    public String getTelefono() {
        return telefono;
    }

    public void setTelefono(String telefono) {
        this.telefono = telefono;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getOcupacion() {
        return ocupacion;
    }

    public void setOcupacion(String ocupacion) {
        this.ocupacion = ocupacion;
    }

    public List<Suscripcion> getSuscripciones() {
        return suscripciones;
    }

    public void setSuscripciones(List<Suscripcion> suscripciones) {
        this.suscripciones = suscripciones;
    }

    public double calcularCosto(){
        double costo=0.00;

        for(Suscripcion sub:suscripciones){
            costo+=sub.calcularPrecio();
        }
        return costo;
    }

    @Override
    public boolean leer(Scanner scanner){
        if(!scanner.hasNextInt()){
            return false;
        }

        this.id = scanner.nextInt();
        this.nombreCompleto = scanner.next();
        this.dni = scanner.nextInt();
        this.edad = scanner.nextInt();
        this.ciudad = scanner.next();
        this.fechaNacimiento = scanner.next();
        this.telefono = scanner.next();
        this.email = scanner.next();
        this.ocupacion = scanner.next();

        return true;
    }
    @Override
    public void imprimir(){
        System.out.println(this);
    }
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();

        sb.append(String.format(
                "%-4d %-30s %-12d %-7d %-15s %-15s %-15s %-30s %-30s\n",
                id,
                nombreCompleto,
                dni,
                edad,
                ciudad,
                fechaNacimiento,
                telefono,
                email,
                ocupacion
        ));
        if(!suscripciones.isEmpty()){
            sb.append("        Suscripciones:\n");
            for(Suscripcion suscripcion : suscripciones){
                sb.append("            - ").append(suscripcion).append("\n");
            }
            sb.append(String.format("             Costo total: %.2f\n",calcularCosto()));
        }else{
            sb.append("        (Sin sucripciones):\n");
        }

        return sb.toString();
    }
}
