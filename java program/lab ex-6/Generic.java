import java.util.List;
import java.util.ArrayList;

public class Generic {
    public static void main(String[] args) {
        
        RealEstateManager estateManager = new RealEstateManager();

        
        RealEstateProperty<String> residentialProperty1 = new RealEstateProperty<>("Details of Residential Property 1");
        RealEstateProperty<String> commercialProperty1 = new RealEstateProperty<>("Details of Commercial Property 1");
        ResidentialApartment residentialApartment = new ResidentialApartment("Details of Residential Apartment");
        CommercialOffice commercialOffice = new CommercialOffice("Details of Commercial Office");

        
        estateManager.addProperty(residentialProperty1);
        estateManager.addProperty(commercialProperty1);
        estateManager.addProperty(residentialApartment);
        estateManager.addProperty(commercialOffice);

    
        estateManager.displayAllProperties();

    
        PropertyOperations<String> propertyOperations = new PropertyOperations<>();
        double residentialValuation = propertyOperations.calculateValuation(residentialProperty1);
        double commercialRentalIncome = propertyOperations.calculateRentalIncome(commercialProperty1);

        System.out.println("Valuation for Residential Property 1: $" + residentialValuation);
        System.out.println("Rental Income for Commercial Property 1: $" + commercialRentalIncome);

        
        estateManager.conductPropertyTransaction(residentialProperty1, 300000);
        estateManager.conductPropertyTransaction(commercialOffice, 1500000);
    }
}

class RealEstateProperty<T> implements ResidentialProperty<T>, CommercialProperty<T> {
    private T details;

    public RealEstateProperty(T details) {
        this.details = details;
    }

    public void displayDetails() {
        System.out.println("Property Details: " + details.toString());
    }

    @Override
    public void displayResidentialDetails() {
        System.out.println("Residential Property Details: " + details.toString());
    }

    @Override
    public void displayCommercialDetails() {
        System.out.println("Commercial Property Details: " + details.toString());
    }
}


class PropertyOperations<T> {
    public double calculateValuation(RealEstateProperty<T> property) {
        
        return Math.random() * 1_000_000;
    }

    public double calculateRentalIncome(RealEstateProperty<T> property) {
        
        return Math.random() * 5000;
    }
}

interface ResidentialProperty<T> {
    void displayResidentialDetails();
}

interface CommercialProperty<T> {
    void displayCommercialDetails();
}


class ResidentialApartment extends RealEstateProperty<String> {
    public ResidentialApartment(String details) {
        super(details);
    }
}

class CommercialOffice extends RealEstateProperty<String> {
    public CommercialOffice(String details) {
        super(details);
    }
}


class RealEstateManager {
    private List<RealEstateProperty<?>> propertyList;

    public RealEstateManager() {
        this.propertyList = new ArrayList<>();
    }

    public void addProperty(RealEstateProperty<?> property) {
        propertyList.add(property);
    }

    public void displayAllProperties() {
        System.out.println("All Properties:");
        for (RealEstateProperty<?> property : propertyList) {
            property.displayDetails();
        }
    }

    public void conductPropertyTransaction(RealEstateProperty<?> property, double transactionAmount) {
        System.out.println("Property Transaction: " + property.toString());
        System.out.println("Transaction Amount: $" + transactionAmount);
        
        System.out.println("Transaction successful!");
    }
}

