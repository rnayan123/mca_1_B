package Realstate;

public class CommercialProperty implements RealEstateListing {

    @Override
    public void displayDetails() {

        System.out.println("Commercial Property Details");
    }

    @Override
    public double calculatePrice() {

        return 500000.0; 
    }

}
