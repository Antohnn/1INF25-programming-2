import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class PlataformaStreaming {
    private List<CanalStreaming> canales;
    private List<Usuario> usuarios;
    private List<Suscripcion> suscripciones;
    private Scanner archivo;

    public PlataformaStreaming(String nombreArchivo) throws FileNotFoundException {
        canales = new ArrayList<>();
        usuarios = new ArrayList<>();
        suscripciones = new ArrayList<>();
        archivo = new Scanner(new File(nombreArchivo));
    }
    public void cargarDatos(){
        this.cargarCanales();
        this.cargarUsuarios();
        this.cargarSuscripciones();
    }

    private void cargarCanales(){
        while(this.archivo.hasNext()){
            CanalStreaming canal=new CanalStreaming();
            if(!canal.leer(archivo)){
                archivo.next();
                break;
            }
            this.canales.add(canal);
        }
    }
    private void cargarUsuarios(){
        while(this.archivo.hasNext()){
            Usuario usuario=new Usuario();
            if(!usuario.leer(archivo)){
                archivo.next();
                break;
            }
            this.usuarios.add(usuario);
        }
    }
    private void cargarSuscripciones(){
        while(this.archivo.hasNext()){
            String tipo = archivo.next();
            if(tipo == null || tipo.isBlank()) break;
            Suscripcion sub = crearSuscripcion(tipo);
            if(!sub.leer(archivo)) break;

            Usuario usuario=buscarUsuario(sub.getIdUsuario());
            sub.setUsuario(usuario);
            sub.setCanal(buscarCanal(sub.getIdCanal()));

            usuario.getSuscripciones().add(sub);

            suscripciones.add(sub);
        }
    }
    private Suscripcion crearSuscripcion(String tipo){
        return switch (tipo){
            case "PREMIUM" -> new SuscripcionPremium();
            case "VIP"     -> new SuscripcionVIP();
            default        -> new SuscripcionBasica();
        };
    }
    private Usuario buscarUsuario(int idUsuario){
        for(Usuario usuario : this.usuarios){
            if(usuario.getId()==idUsuario){
                return usuario;
            }
        }
        return null;
    }
    private CanalStreaming buscarCanal(int idCanal){
        for(CanalStreaming canal : this.canales){
            if(canal.getId()==idCanal){
                return canal;
            }
        }
        return null;
    }
    public void imprimirReporte(){
        System.out.println("==============================================================================================================================");
        System.out.println("                                                          REPORTE DE USUARIOS");
        System.out.println("==============================================================================================================================");

        System.out.printf(
                "%-4s %-20s %-10s %-4s %-12s %-12s %-12s %-25s %-20s\n",
                "ID", "Nombre Completo", "DNI", "Edad", "Ciudad",
                "F. Nac", "Teléfono", "Email", "Ocupación"
        );
        System.out.println("------------------------------------------------------------------------------------------------------------------------------");

        for (Usuario u : usuarios) {
            System.out.println(u);
        }

        System.out.println("==============================================================================================================================");
    }
}
