public class RealEstateProperty {

    private String address;
    private double price;
    private int bedrooms;
    private int bathrooms;

    public RealEstateProperty(String address, double price, int bedrooms, int bathrooms) {
        this.address = address;
        this.price = price;
        this.bedrooms = bedrooms;
        this.bathrooms = bathrooms;
    }

    public void displayDetails() {
        System.out.println("Property Details:");
        System.out.println("Address: " + address);
        System.out.println("Price: Rs." + price);
        System.out.println("Bedrooms: " + bedrooms);
        System.out.println("Bathrooms: " + bathrooms);
    }

    public void calculatePricePerBedroom() {
        if (bedrooms != 0) {
            double pricePerBedroom = price / bedrooms;
            System.out.println("Price per Bedroom: Rs." + pricePerBedroom);
        } else {
            System.out.println("Invalid number of bedrooms. Unable to calculate price per bedroom.");
        }
    }

    public void updatePrice(double newPrice) {
        if (newPrice >= 0) {
            System.out.println("Updating property price...");
            price = newPrice;
            System.out.println("New Price: Rs." + price);
        } else {
            System.out.println("Invalid price. Please provide a non-negative value.");
        }
    }

    public void updatePrice(int percentageIncrease) {
        if (percentageIncrease >= 0) {
            double increaseAmount = price * (percentageIncrease / 100.0);
            double updatedPrice = price + increaseAmount;
            updatePrice(updatedPrice);
        } else {
            System.out.println("Invalid percentage increase. Please provide a non-negative value.");
        }
    }

    public void updatePrice(float fixedAmountIncrease) {
        if (fixedAmountIncrease >= 0) {
            double updatedPrice = price + fixedAmountIncrease;
            updatePrice(updatedPrice);
        } else {
            System.out.println("Invalid fixed amount increase. Please provide a non-negative value.");
        }
    }

    public RealEstateProperty(String address, double price, int bedrooms) {
        this.address = address;
        this.price = price;
        this.bedrooms = bedrooms;
    }

   
    public RealEstateProperty(int fixedAmountIncrease) {
        updatePrice(fixedAmountIncrease); 
    }

    public static void main(String[] args) {
        RealEstateProperty property1 = new RealEstateProperty("123 Electronic City", 250000, 3, 2);

        property1.displayDetails();
        property1.calculatePricePerBedroom();
        property1.updatePrice(280000.00f);

        property1.updatePrice(10);
        property1.updatePrice(5000.00);

        RealEstateProperty property2 = new RealEstateProperty("456 SG Palya", 300000, 4);
        property2.displayDetails();

        RealEstateProperty property3 = new RealEstateProperty("789 Whitefield", 200000, 3, 5000);
        property3.displayDetails();
       property3.updatePrice(2000);
    }
}
