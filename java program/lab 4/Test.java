
import Realstate.*;

public class Test {
    public static void main(String[] args) {
        
        RealEstateListing residentialProperty = new ResidentialProperty();

        residentialProperty.displayDetails();
        double residentialPrice = residentialProperty.calculatePrice();
        System.out.println("Residential Property Price: $" + residentialPrice);

        /
        RealEstateAgent residentialAgent = new ResidentialRealEstateAgent();

        // Promote and sell the residential property
        residentialAgent.promoteListing(residentialProperty);
        residentialAgent.sellProperty(residentialProperty);

        System.out.println(); // Add a line break for better readability

        // Create a commercial property
        RealEstateListing commercialProperty = new CommercialProperty();

        // Display details and calculate price for commercial property
        commercialProperty.displayDetails();
        double commercialPrice = commercialProperty.calculatePrice();
        System.out.println("Commercial Property Price: $" + commercialPrice);

        // Create a commercial real estate agent
        RealEstateAgent commercialAgent = new CommercialRealEstateAgent();

        // Promote and sell the commercial property
        commercialAgent.promoteListing(commercialProperty);
        commercialAgent.sellProperty(commercialProperty);
    }
}
