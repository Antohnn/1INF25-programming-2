import java.util.Scanner;

public class Vehiculo extends Registro {
    private String placa;
    private String marca;
    private String modelo;
    private int anioFab;
    private String categoria;
    private Propietario propietario;

    public Vehiculo() {
    }

    public Vehiculo(Vehiculo other) {
        this.placa = other.placa;
        this.marca = other.marca;
        this.modelo = other.modelo;
        this.anioFab = other.anioFab;
        this.categoria = other.categoria;
        this.propietario = new Propietario(other.propietario);
    }

    public String getPlaca() {
        return placa;
    }

    public void setPlaca(String placa) {
        this.placa = placa;
    }

    public String getMarca() {
        return marca;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public String getModelo() {
        return modelo;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public int getAnioFab() {
        return anioFab;
    }

    public void setAnioFab(int anioFab) {
        this.anioFab = anioFab;
    }

    public String getCategoria() {
        return categoria;
    }

    public void setCategoria(String categoria) {
        this.categoria = categoria;
    }

    public Propietario getPropietario() {
        return propietario;
    }

    public void setPropietario(Propietario propietario) {
        this.propietario = propietario;
    }

    @Override
    public void cargar(Scanner archivo){
        if(!archivo.hasNext()){
            return;
        }
        this.placa = archivo.next();
        this.marca = archivo.next();
        this.modelo = archivo.next();
        this.anioFab = archivo.nextInt();
        this.categoria = archivo.next();
        this.propietario.setDni(archivo.nextInt());

    }
    @Override
    public void imprimir(){
        System.out.println(this);
    }
    @Override
    public String toString() {
        return String.format(
                "Placa: %s\n Marca: %s\n Modelo: %s\n Año de fabricacion: %d\n Categoria: %s\n",
                placa,
                marca,
                modelo,
                anioFab,
                categoria
        );
    }

}
