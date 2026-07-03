public class CarrilEstandar extends Carril {
    @Override
    public String getTipo() {
        return "Estandar";
    }

    @Override
    public double velocidadMaxima(int km) {
        if(km<=100){
            return 80;
        }else if(km<=200){
            return 120;
        }else{
            return 100;
        }
    }

    @Override
    public boolean velocidadPermitida(int km, double velocidad) {
        if(km<=100 && velocidad<=80){
            return true;
        }else if(km<=200 && velocidad<=120){
            return true;
        }else if(km<=300 && velocidad<=100){
            return true;
        }
        return false;
    }

    @Override
    public boolean vehiculoPermitido(String categoria) {
        return switch (categoria){
            case "Motocicleta" , "Coupe" , "SUV" ,"Camioneta","Sedan","Ambulancia"-> true;
            default -> false;
        };
    }
}
