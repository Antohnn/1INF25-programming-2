import java.util.Scanner;

public abstract class Suscripcion extends Registro {
    private int idUsuario;
    private int idCanal;
    private Usuario usuario;
    private CanalStreaming canal;

    public int getIdUsuario() {
        return idUsuario;
    }

    public void setIdUsuario(int idUsuario) {
        this.idUsuario = idUsuario;
    }

    public int getIdCanal() {
        return idCanal;
    }

    public void setIdCanal(int idCanal) {
        this.idCanal = idCanal;
    }

    public Usuario getUsuario() {
        return usuario;
    }

    public void setUsuario(Usuario usuario) {
        this.usuario = usuario;
    }

    public CanalStreaming getCanal() {
        return canal;
    }

    public void setCanal(CanalStreaming canal) {
        this.canal = canal;
    }

    public abstract String getTipo();
    public abstract double calcularPrecio();

    @Override
    public boolean leer(Scanner scanner){
        if(!scanner.hasNextInt()){
            return false;
        }

        this.idUsuario = scanner.nextInt();
        this.idCanal = scanner.nextInt();

        return true;
    }
    @Override
    public void imprimir(){
        System.out.println(this);
    }
    @Override
    public String toString(){
        return String.format(
                "%-12s | Usuario: %-5d %-30s | Canal: %-5d %-30s | Precio: %-5.2f",
                getTipo(),
                (usuario!=null ? usuario.getId():idUsuario),
                (usuario!=null ? usuario.getNombreCompleto():"N/A"),
                (canal!=null ? canal.getId():idCanal),
                (canal!=null ? canal.getNombre():"N/A"),
                calcularPrecio()
        );
    }
}
