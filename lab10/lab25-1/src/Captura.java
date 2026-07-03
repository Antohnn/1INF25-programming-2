import java.util.Scanner;

public class Captura extends Registro{
    private String placa;
    private double velocidad;
    private Carril carril;
    private double latitud;
    private double longitud;
    private String region;
    private String provincia;
    private int km;
    private String fecha;
    private String hora;
    private String codigoCamara;

    public Captura() {

    }
    public Captura(final Captura other) {
        this.placa = other.placa;
        this.velocidad = other.velocidad;
        this.carril = other.carril;
        this.latitud = other.latitud;
        this.longitud = other.longitud;
        this.region = other.region;
        this.provincia = other.provincia;
        this.km = other.km;
        this.fecha = other.fecha;
        this.hora = other.hora;
        this.codigoCamara = other.codigoCamara;
    }

    public String getPlaca() {
        return placa;
    }

    public void setPlaca(String placa) {
        this.placa = placa;
    }

    public double getVelocidad() {
        return velocidad;
    }

    public void setVelocidad(double velocidad) {
        this.velocidad = velocidad;
    }

    public Carril getCarril(){
        return carril;
    }

    public Carril getCarril(int tipoCarril) {
        return switch(tipoCarril){
            case 1 -> new CarrilEmergencia();
            case 2 -> new CarrilLento();
            case 3,4 -> new CarrilEstandar();
            case 5 -> new CarrilRapido();
            default -> null;
        };
    }

    public void setCarril(Carril carril) {
        this.carril = carril;
    }

    public double getLatitud() {
        return latitud;
    }

    public void setLatitud(double latitud) {
        this.latitud = latitud;
    }

    public double getLongitud() {
        return longitud;
    }

    public void setLongitud(double longitud) {
        this.longitud = longitud;
    }

    public String getRegion() {
        return region;
    }

    public void setRegion(String region) {
        this.region = region;
    }

    public String getProvincia() {
        return provincia;
    }

    public void setProvincia(String provincia) {
        this.provincia = provincia;
    }

    public int getKm() {
        return km;
    }

    public void setKm(int km) {
        this.km = km;
    }

    public String getFecha() {
        return fecha;
    }

    public void setFecha(String fecha) {
        this.fecha = fecha;
    }

    public String getHora() {
        return hora;
    }

    public void setHora(String hora) {
        this.hora = hora;
    }

    public String getCodigoCamara() {
        return codigoCamara;
    }

    public void setCodigoCamara(String codigoCamara) {
        this.codigoCamara = codigoCamara;
    }

    @Override
    public void cargar(Scanner archivo){
        if(!archivo.hasNext()){
            return;
        }

        this.placa = archivo.next();
        this.velocidad = archivo.nextDouble();

        int tipoCarril=archivo.nextInt();

        this.carril=getCarril(tipoCarril);
        this.latitud = archivo.nextDouble();
        this.longitud = archivo.nextDouble();
        this.region = archivo.next();
        this.provincia = archivo.next();
        this.km = archivo.nextInt();
        this.fecha = archivo.next();
        this.hora = archivo.next();
        this.codigoCamara = archivo.next();

    }
    @Override
    public void imprimir(){
        System.out.println(this);
    }
    @Override
    public String toString(){
        return String.format(
                "Placa: %s\n Velocidad: %.2f km/h\n Carril: %s\n Ubicacion: Lat %.6f, Lon %.6f\n Region: %s\n" +
                        "Provincia: %s\n Kilometro: %d\n Fecha: %s\n Hora: %s\n Codigo Camara: %s\n",
                placa,
                velocidad,
                carril.getTipo(),
                latitud,
                longitud,
                region,
                provincia,
                km,
                fecha,
                hora,
                codigoCamara
        );
    }
}
