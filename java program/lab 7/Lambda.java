import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;
public class Lambda {
    public static void main(String[] args) {
        List<RealEstateProperty> properties = new ArrayList<>();

        // Populate the list with real estate properties
        properties.add(new RealEstateProperty("Apartment", 600000, 2));
        properties.add(new RealEstateProperty("House", 850000, 4));
        properties.add(new RealEstateProperty("Condo", 450000, 1));
        properties.add(new RealEstateProperty("Duplex", 700000, 3));

        // Example: Filter properties based on price using lambda expression
        List<RealEstateProperty> expensiveProperties = filterProperties(properties, property -> property.getPrice() > 500000);
        
        // Example: Filter properties with more than 3 bedrooms using lambda expression
        List<RealEstateProperty> largeProperties = filterProperties(properties, property -> property.getBedrooms() > 3);

        // Display or perform further operations on filtered properties
        displayProperties(expensiveProperties);
        displayProperties(largeProperties);
    }

    // Generic method to filter properties based on a condition using lambda expression
    private static List<RealEstateProperty> filterProperties(List<RealEstateProperty> properties, PropertyFilterCondition condition) {
        return properties.stream()
                .filter(condition::test)
                .collect(Collectors.toList());
    }

    // Interface representing the lambda expression condition
    @FunctionalInterface
    interface PropertyFilterCondition {
        boolean test(RealEstateProperty property);
    }

    // Display properties (for illustration purposes)
  
private static void displayProperties(List<RealEstateProperty> properties) {
    if (!properties.isEmpty()) {
        System.out.println("Large Properties:");
        for (RealEstateProperty property : properties) {
            System.out.println(property.toString());
        }
    }
}

}

class RealEstateProperty {
    private String propertyType;
    private double price;
    private int bedrooms;

    public RealEstateProperty(String propertyType, double price, int bedrooms) {
        this.propertyType = propertyType;
        this.price = price;
        this.bedrooms = bedrooms;
    }

    public String getPropertyType() {
        return propertyType;
    }

    public double getPrice() {
        return price;
    }

    public int getBedrooms() {
        return bedrooms;
    }

    @Override
    public String toString() {
        return "RealEstateProperty{" +
                "propertyType='" + propertyType + '\'' +
                ", price=" + price +
                ", bedrooms=" + bedrooms +
                '}';
    }
}

