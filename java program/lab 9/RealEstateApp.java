import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class RealEstateApp {

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            JFrame frame = new JFrame("Real Estate Application");
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setSize(400, 250);
            frame.setLayout(new GridLayout(6, 2));

            JLabel nameLabel = new JLabel("Property Name:");
            JTextField nameTextField = new JTextField();

            JLabel locationLabel = new JLabel("Location:");
            JTextField locationTextField = new JTextField();

            JLabel typeLabel = new JLabel("Property Type:");
            JTextField typeTextField = new JTextField();

            JLabel bedroomsLabel = new JLabel("Number of Bedrooms:");
            JTextField bedroomsTextField = new JTextField();

            JLabel priceLabel = new JLabel("Price:");
            JTextField priceTextField = new JTextField();

            JButton submitButton = new JButton("Submit");

            submitButton.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    // In a real application, you would handle the submission of data here
                    String propertyName = nameTextField.getText();
                    String location = locationTextField.getText();
                    String propertyType = typeTextField.getText();
                    String bedrooms = bedroomsTextField.getText();
                    String price = priceTextField.getText();

                    // For now, let's just display the information in a dialog
                    String message = "Property Name: " + propertyName + "\n" +
                            "Location: " + location + "\n" +
                            "Property Type: " + propertyType + "\n" +
                            "Bedrooms: " + bedrooms + "\n" +
                            "Price: " + price;

                    JOptionPane.showMessageDialog(frame, message, "Property Information",
                            JOptionPane.INFORMATION_MESSAGE);
                }
            });

            frame.add(nameLabel);
            frame.add(nameTextField);
            frame.add(locationLabel);
            frame.add(locationTextField);
            frame.add(typeLabel);
            frame.add(typeTextField);
            frame.add(bedroomsLabel);
            frame.add(bedroomsTextField);
            frame.add(priceLabel);
            frame.add(priceTextField);
            frame.add(new JLabel()); // Empty label for spacing
            frame.add(submitButton);

            frame.setVisible(true);
        });
    }
}
