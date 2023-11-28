// Package: realEstate

import realEstate.agents.RealEstateAgent;
import realEstate.agents.ResidentialRealEstateAgent;
import realEstate.agents.CommercialRealEstateAgent;
import realEstate.properties.RealEstateListing;
import realEstate.properties.ResidentialProperty;
import realEstate.properties.CommercialProperty;

public class Main {
    public static void main(String[] args) {
        // Create a residential property
        RealEstateListing residentialProperty = new ResidentialProperty();

        // Display details and calculate price for residential property
        residentialProperty.displayDetails();
        double residentialPrice = residentialProperty.calculatePrice();
        System.out.println("Residential Property Price: $" + residentialPrice);

        // Create a residential real estate agent
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
