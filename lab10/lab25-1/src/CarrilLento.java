public class CarrilLento extends Carril{
    @Override
    public String getTipo() {
        return "Lento";
    }

    @Override
    public double velocidadMaxima(int km) {
        return 60;
    }

    @Override
    public boolean velocidadPermitida(int km, double velocidad) {
        if(velocidad > 60){
            return false;
        }
        return true;
    }

    @Override
    public boolean vehiculoPermitido(String categoria) {
        return switch (categoria){
            case "Camion" , "Tractor" , "Trailer"-> true;
            default -> false;
        };
    }
}
