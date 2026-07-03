import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class PlataformaStreaming {
    private List<CanalStreaming> canales;
    private List<Usuario> usuarios;
    private List<Suscripcion> suscripciones;
    private Scanner archivo;

    public PlataformaStreaming(String nombArch) throws FileNotFoundException {
        this.canales = new ArrayList<>();
        this.usuarios = new ArrayList<>();
        this.suscripciones = new ArrayList<>();

        this.archivo = new Scanner(new File(nombArch));
    }

    public void cargarDatos(){
        this.cargarCanales();
        this.cargarUsuarios();
        this.cargarSuscripciones();
    }

    private void cargarCanales(){
        while(this.archivo.hasNext()){
            CanalStreaming canal = new CanalStreaming();
            if(!canal.leer(archivo)){
                archivo.next();
                break;
            }
            this.canales.add(canal);
        }
    }
    private void cargarUsuarios(){
        while(this.archivo.hasNext()){
            Usuario usuario = new Usuario();
            if(!usuario.leer(archivo)){
                archivo.next();
                break;
            }
            this.usuarios.add(usuario);
        }
    }
    private void cargarSuscripciones(){
        while(this.archivo.hasNext()){
            String tipo=archivo.next();
            if(tipo==null || tipo.isBlank())break;

            Suscripcion sub=crearSuscripcion(tipo);
            if(!sub.leer(archivo))break;

            Usuario userEncontrado=buscarUsuario(sub.getIdUsuario());
            CanalStreaming canalEncontrado=buscarCanal(sub.getIdCanal());

            sub.setUsuario(userEncontrado);
            sub.setCanal(canalEncontrado);

            userEncontrado.getSuscripciones().add(sub);
        }
    }
    private Suscripcion crearSuscripcion(String tipo){
        return switch (tipo){
            case "VIP" -> new SuscripcionVIP();
            case "PREMIUM" -> new SuscripcionPremium();
            default -> new SuscripcionBasica();
        };
    }
    private Usuario buscarUsuario(int idUsuario){
        for(Usuario usuario: this.usuarios){
            if(usuario.getId()== idUsuario)return usuario;
        }
        return null;
    }
    private CanalStreaming buscarCanal(int idCanal){
        for(CanalStreaming canal:this.canales){
            if(canal.getId()==idCanal)return canal;
        }
        return null;
    }

    public void imprimirReporte(){
        System.out.println("=".repeat(180));
        System.out.println("REPORTE DE USUARIOS");
        System.out.println("=".repeat(180));

        System.out.printf(
                "%-4s %-30s %-6s %-10s %-10s %-15s %-20s %-15s %-30s\n",
                "ID","Nombre Completo","DNI","Edad","Ciudad","F. Nac","Telefono",
                "Email","Ocupacion"
        );
        System.out.println("=".repeat(180));

        for(Usuario usuario: this.usuarios){
            System.out.println(usuario);
        }
        System.out.println("=".repeat(180));
    }
}
