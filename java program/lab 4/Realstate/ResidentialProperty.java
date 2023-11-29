package Realstate;

public class ResidentialProperty implements RealEstateListing {
     @Override
    public void displayDetails() {
        
        System.out.println("Residential Property Details");
    }

    @Override
    public double calculatePrice() {
        
        return 150000.0; 
    }
}
    

