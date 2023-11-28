// Package: realstate

public interface RealEstateListing {
    void displayDetails();
    double calculatePrice();
}

public class ResidentialProperty implements RealEstateListing {
    

    @Override
    public void displayDetails() {
        
        System.out.println("Residential Property Details");
    }

    @Override
    public double calculatePrice() {
        
        return 150000.0; // Placeholder value
    }
}

public class CommercialProperty implements RealEstateListing {
    

    @Override
    public void displayDetails() {
        
        System.out.println("Commercial Property Details");
    }

    @Override
    public double calculatePrice() {
        
        return 500000.0; // Placeholder value
    }
}



public interface RealEstateAgent {
    void promoteListing(RealEstateListing listing);
    void sellProperty(RealEstateListing listing);
}

public class ResidentialRealEstateAgent implements RealEstateAgent {
    

    @Override
    public void promoteListing(RealEstateListing listing) {
        // Promote residential property listings
        // ...
        System.out.println("Residential Property Promotion");
    }

    @Override
    public void sellProperty(RealEstateListing listing) {
        
        System.out.println("Residential Property Sold");
    }
}

public class CommercialRealEstateAgent implements RealEstateAgent {
   

    @Override
    public void promoteListing(RealEstateListing listing) {
        
        System.out.println("Commercial Property Promotion");
    }

    @Override
    public void sellProperty(RealEstateListing listing) {
       
        System.out.println("Commercial Property Sold");
    }
}
