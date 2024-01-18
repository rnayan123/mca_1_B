public class Test {
    public static void main(String[] args) {
        // Create instances of threads
        PropertyListingThread propertyListingThread = new PropertyListingThread();
        CustomerInquiryThread customerInquiryThread = new CustomerInquiryThread();

        // Start the threads
        propertyListingThread.start();
        customerInquiryThread.start();

        try {
            // Wait for both threads to finish
            propertyListingThread.join();
            customerInquiryThread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        // Main thread resumes when both threads finish
        System.out.println("Main thread exiting.");
    }
}

class PropertyListingThread extends Thread {
    public void run() {
        // Simulate fetching and displaying property listings
        for (int i = 1; i <= 5; i++) {
            System.out.println("Listing #" + i + ": Property details here");
            // Simulate some processing time for each listing
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class CustomerInquiryThread extends Thread {
    public void run() {
        // Simulate processing customer inquiries
        for (int i = 1; i <= 3; i++) {
            System.out.println("Inquiry #" + i + ": Customer inquiry details here");
            // Simulate some processing time for each inquiry
            try {
                Thread.sleep(1500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

