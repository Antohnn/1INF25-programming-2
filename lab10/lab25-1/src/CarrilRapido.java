public class CarrilRapido extends Carril{
    @Override
    public String getTipo() {
        return "Rapido";
    }

    @Override
    public double velocidadMaxima(int km) {
        if(km<=100){
            return 120;
        }else if(km<=200){
            return 160;
        }else{
            return 140;
        }
    }

    public double velocidadMinima(int km) {
        if(km<=100){
            return 80;
        }else if(km<=200){
            return 100;
        }else{
            return 90;
        }
    }

    @Override
    public boolean velocidadPermitida(int km, double velocidad) {
        if(km<=100 && velocidad<=120){
            return true;
        }else if(km<=200 && velocidad<=160){
            return true;
        }else if(km<=300 && velocidad<=140){
            return true;
        }
        return false;
    }

    @Override
    public boolean vehiculoPermitido(String categoria) {
        return switch (categoria){
            case "Coupe" , "SUV" ,"Camioneta","Sedan"-> true;
            default -> false;
        };
    }
}
