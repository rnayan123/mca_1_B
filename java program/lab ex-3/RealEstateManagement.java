
public class RealEstateManagement {
    public static void main(String[] args) {
        
        House h1 = new House("123 Main St", 250000.0, 3, 2);
        Apartment a1 = new Apartment("456 Oak St", 180000.0, 2, 5);
        

        System.out.println(h1.displayInfo());
        System.out.println(a1.displayInfo());

        System.out.println(h1.displayFinalInfo());
        System.out.println(a1.displayFinalInfo());
    }
}
abstract class Property {
    private String address;
    private double price;

    public Property(String address, double price) {
        this.address = address;
        this.price = price;
    }

    public abstract String displayInfo();

    public double getPrice() {
        return price;
    }

    // Final method
    public final String displayFinalInfo() {
        return "Address: " + getAddress() + ", Price: $" + price;
    }

    protected String getAddress() {
        return address;
    }
}

class House extends Property {
    private int bedrooms;
    private int bathrooms;

    public House(String address, double price, int bedrooms, int bathrooms) {
        super(address, price);
        this.bedrooms = bedrooms;
        this.bathrooms = bathrooms;
    }

    @Override
    public String displayInfo() {
        return "House - " + getAddress() + ", Bedrooms: " + bedrooms + ", Bathrooms: " + bathrooms + ", Price: $" + getPrice();
    }
}

class Apartment extends Property {
    private int numRooms;
    private int floorNumber;

    public Apartment(String address, double price, int numRooms, int floorNumber) {
        super(address, price);
        this.numRooms = numRooms;
        this.floorNumber = floorNumber;
    }

    @Override
    public String displayInfo() {
        return "Apartment - " + getAddress() + ", Rooms: " + numRooms + ", Floor: " + floorNumber + ", Price: $" + getPrice();
    }
}


