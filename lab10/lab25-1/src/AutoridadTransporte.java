import java.util.List;
import java.util.ArrayList;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class AutoridadTransporte {
    private List<Propietario> propietarios;
    private List<Vehiculo> vehiculos;
    private List<Captura> capturas;
    private List<RegistroInfraccion> regInfracciones;
    private Scanner archivo;

    public AutoridadTransporte(String nombreArch) throws FileNotFoundException {
        propietarios = new ArrayList<>();
        vehiculos = new ArrayList<>();
        capturas = new ArrayList<>();
        regInfracciones = new ArrayList<>();

        this.archivo = new Scanner(new File(nombreArch));
    }

    public void cargarDatos(){
        this.cargaPropietarios();
        this.cargaVehiculos();
        this.cargaCapturas();
    }
    private void cargaPropietarios(){
        while(archivo.hasNext()){
            if(archivo.hasNext("FIN")){
                archivo.next();
                break;
            }

            Propietario propietario=new Propietario();
            propietario.cargar(archivo);
            propietarios.add(propietario);
        }
    }
    private void cargaVehiculos(){
        while(archivo.hasNext()){
            if(archivo.hasNext("FIN")){
                archivo.next();
                break;
            }

            Vehiculo vehiculo=new Vehiculo();
            vehiculo.cargar(archivo);
            vehiculo.setPropietario(buscarPropietario(vehiculo.getPropietario().getDni()));
            vehiculos.add(vehiculo);
        }
    }
    private Propietario buscarPropietario(int dniPropietario){
        for(Propietario propietario:propietarios){
            if(propietario.getDni()==dniPropietario){
                return propietario;
            }
        }
        return null;
    }
    private void cargaCapturas(){
        while(archivo.hasNext()){

            Captura captura=new Captura();
            captura.cargar(archivo);
            capturas.add(captura);
        }
    }
    public void procesarCapturas() {
        for (Captura captura : capturas) {
            procesarCaptura(captura);
        }
    }

    public void imprimirInfracciones() {
        for (RegistroInfraccion infraccion : regInfracciones) {
            System.out.println(infraccion);
        }
    }

    private void procesarCaptura(final Captura captura) {
        double velocidad = captura.getVelocidad();
        int km = captura.getKm();
        Vehiculo vehiculo = buscarVehiculo(captura.getPlaca());

        Carril carril = captura.getCarril();
        boolean vehiculoEsPermitido =
                carril.vehiculoPermitido(vehiculo.getCategoria());
        boolean velocidadPermitida =
                carril.velocidadPermitida(km, velocidad);

        if (!velocidadPermitida) {
            regInfracciones.add(new RegistroInfraccion("M20", 963.00, 50,
                    captura, vehiculo));
        }

        if (!vehiculoEsPermitido) {
            regInfracciones.add(new RegistroInfraccion("G29", 428.00, 50,
                    captura, vehiculo));
        }
    }
    private Vehiculo buscarVehiculo(final String placa) {
        for (Vehiculo v : this.vehiculos) {
            if (v.getPlaca().equals(placa)) {
                return v;
            }
        }
        return null;
    }

}
