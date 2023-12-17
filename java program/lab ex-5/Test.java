import java.util.*;

public class Test {
    public static void main(String[] args) {
        RealEstateManager realEstateManager = new RealEstateManager();

        // Create threads for adding properties
        for (int i = 0; i < 5; i++) {
            Thread addPropertyThread = new RealEstateManager.AddPropertyThread("Property" + (i + 1), "Location" + (i + 1), (i + 1) * 100000);
            addPropertyThread.start();
        }

        // Create a thread for displaying properties
        Thread displayPropertiesThread = new RealEstateManager.DisplayPropertiesThread();
        displayPropertiesThread.start();
    }
}

class RealEstateProperty {
    String propertyName;
    String location;
    double price;
    RealEstateProperty next;

    public RealEstateProperty(String propertyName, String location, double price) {
        this.propertyName = propertyName;
        this.location = location;
        this.price = price;
        this.next = null;
    }
}

class RealEstateManager {
    private static RealEstateProperty head;
    private static final Object lock = new Object();

    // Method to insert a property into the real estate listing
    public static void addProperty(String propertyName, String location, double price) {
        synchronized (lock) {
            RealEstateProperty newProperty = new RealEstateProperty(propertyName, location, price);

            if (head == null) {
                head = newProperty;
                newProperty.next = head;
            } else {
                RealEstateProperty current = head;

                while (current.next != head) {
                    current = current.next;
                }

                newProperty.next = head;
                current.next = newProperty;
            }
        }
    }

    // Method to display real estate property details
    public static void displayProperties() {
        synchronized (lock) {
            RealEstateProperty current = head;

            if (current == null) {
                System.out.println("Real estate listing is empty.");
                return;
            }

            System.out.println("Real Estate Properties:");
            do {
                System.out.println("Property Name: " + current.propertyName +
                        ", Location: " + current.location +
                        ", Price: $" + current.price);
                current = current.next;
            } while (current != head);
        }
    }

    // Thread class for adding a property
    static class AddPropertyThread extends Thread {
        private String propertyName;
        private String location;
        private double price;

        public AddPropertyThread(String propertyName, String location, double price) {
            this.propertyName = propertyName;
            this.location = location;
            this.price = price;
        }

        @Override
        public void run() {
            addProperty(propertyName, location, price);
        }
    }

    // Thread class for displaying properties
    static class DisplayPropertiesThread extends Thread {
        @Override
        public void run() {
            while (true) {
                displayProperties();
                try {
                    // Sleep for a short duration before displaying properties again
                    Thread.sleep(2000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
