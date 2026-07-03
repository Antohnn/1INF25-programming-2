public class CarrilEmergencia extends Carril {

    @Override
    public String getTipo() {
        return "Emergencia";
    }

    @Override
    public double velocidadMaxima(int km) {
        return 80;
    }

    @Override
    public boolean velocidadPermitida(int km, double velocidad) {
        if(velocidad > 80){
            return false;
        }
        return true;
    }

    @Override
    public boolean vehiculoPermitido(String categoria) {
        return switch (categoria) {
            case "Ambulacia", "Grua" -> true;
            default -> false;
        };

    }
}
