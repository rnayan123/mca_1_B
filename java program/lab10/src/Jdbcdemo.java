import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class Jdbcdemo {
    private JFrame frame;
    private JPanel mainPanel;
    private JTextField idTextField;
    private JTextField nameTextField;
    private JTextField typeTextField;
    private JTextField locationTextField;
    private JTextField priceTextField;
    private JButton addButton;
    private JButton refreshButton;
    private JButton updateButton;
    private JButton deleteButton;
    private JTable propertyTable;
    private DefaultTableModel tableModel;

    private Connection connection;

    public Jdbcdemo() {
        initialize();
        establishConnection();
        refreshTable();
    }

    private void initialize() {
        frame = new JFrame("Property Management");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(600, 400);

        mainPanel = new JPanel();
        mainPanel.setLayout(new GridLayout(2, 1));

        JPanel inputPanel = new JPanel(new GridLayout(6, 2));
        idTextField = new JTextField();
        nameTextField = new JTextField();
        typeTextField = new JTextField();
        locationTextField = new JTextField();
        priceTextField = new JTextField();
        addButton = new JButton("Add Property");
        addButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                addProperty();
                refreshTable();
            }
        });

        updateButton = new JButton("Update Property");
        updateButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                updateProperty();
                refreshTable();
            }
        });

        deleteButton = new JButton("Delete Property");
        deleteButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                deleteProperty();
                refreshTable();
            }
        });

        inputPanel.add(new JLabel("ID:"));
        inputPanel.add(idTextField);
        inputPanel.add(new JLabel("Name:"));
        inputPanel.add(nameTextField);
        inputPanel.add(new JLabel("Type:"));
        inputPanel.add(typeTextField);
        inputPanel.add(new JLabel("Location:"));
        inputPanel.add(locationTextField);
        inputPanel.add(new JLabel("Price:"));
        inputPanel.add(priceTextField);
        inputPanel.add(addButton);
        inputPanel.add(updateButton);

        tableModel = new DefaultTableModel();
        propertyTable = new JTable(tableModel);
        propertyTable.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                int selectedRow = propertyTable.getSelectedRow();
                populateFieldsFromTable(selectedRow);
            }
        });

        JPanel tablePanel = new JPanel(new BorderLayout());
        refreshButton = new JButton("Refresh");
        refreshButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                refreshTable();
            }
        });

        tablePanel.add(new JScrollPane(propertyTable), BorderLayout.CENTER);
        tablePanel.add(refreshButton, BorderLayout.NORTH);
        tablePanel.add(deleteButton, BorderLayout.SOUTH);

        mainPanel.add(inputPanel);
        mainPanel.add(tablePanel);

        frame.add(mainPanel);
        frame.setVisible(true);
    }

    private void establishConnection() {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/Realestate", "root", "nayan1810");
        } catch (ClassNotFoundException | SQLException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(frame, "Error connecting to the database", "Error",
                    JOptionPane.ERROR_MESSAGE);
            System.exit(1);
        }
    }

    private void addProperty() {
        Property propertyToAdd = new Property();
        try {
            int id = Integer.parseInt(idTextField.getText()); 
            propertyToAdd.setId(id); 
        } catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(frame, "Invalid ID format", "Error", JOptionPane.ERROR_MESSAGE);
            return;
        }
        propertyToAdd.setName(nameTextField.getText());
        propertyToAdd.setType(typeTextField.getText());
        propertyToAdd.setLocation(locationTextField.getText());
        try {
            double price = Double.parseDouble(priceTextField.getText());
            propertyToAdd.setPrice(price);
        } catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(frame, "Invalid price format", "Error", JOptionPane.ERROR_MESSAGE);
            return;
        }

        addPropertyToDatabase(propertyToAdd);
        clearInputFields();
    }

    private void addPropertyToDatabase(Property property) {
        try (PreparedStatement preparedStatement = connection.prepareStatement(
                "INSERT INTO properties (id,name, type, location, price) VALUES (?,?, ?, ?, ?)")) {
            preparedStatement.setInt(1, property.getId());
            preparedStatement.setString(2, property.getName());
            preparedStatement.setString(3, property.getType());
            preparedStatement.setString(4, property.getLocation());
            preparedStatement.setDouble(5, property.getPrice());
            preparedStatement.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private void updateProperty() {
        int selectedRow = propertyTable.getSelectedRow();
        if (selectedRow == -1) {
            JOptionPane.showMessageDialog(frame, "Please select a property to update", "Error",
                    JOptionPane.ERROR_MESSAGE);
            return;
        }

        Property propertyToUpdate = new Property();
        try {
            propertyToUpdate.setId(Integer.parseInt(idTextField.getText()));
        } catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(frame, "Invalid ID format", "Error", JOptionPane.ERROR_MESSAGE);
            return;
        }
        propertyToUpdate.setName(nameTextField.getText());
        propertyToUpdate.setType(typeTextField.getText());
        propertyToUpdate.setLocation(locationTextField.getText());
        try {
            double price = Double.parseDouble(priceTextField.getText());
            propertyToUpdate.setPrice(price);
        } catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(frame, "Invalid price format", "Error", JOptionPane.ERROR_MESSAGE);
            return;
        }

        updatePropertyInDatabase(propertyToUpdate);
        clearInputFields();
    }

    private void updatePropertyInDatabase(Property property) {
        try (PreparedStatement preparedStatement = connection.prepareStatement(
                "UPDATE properties SET name=?, type=?, location=?, price=? WHERE id=?")) {
            preparedStatement.setString(1, property.getName());
            preparedStatement.setString(2, property.getType());
            preparedStatement.setString(3, property.getLocation());
            preparedStatement.setDouble(4, property.getPrice());
            preparedStatement.setInt(5, property.getId());
            preparedStatement.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private void deleteProperty() {
        int selectedRow = propertyTable.getSelectedRow();
        if (selectedRow == -1) {
            JOptionPane.showMessageDialog(frame, "Please select a property to delete", "Error",
                    JOptionPane.ERROR_MESSAGE);
            return;
        }

        int propertyId = (int) propertyTable.getValueAt(selectedRow, 0);
        deletePropertyFromDatabase(propertyId);
        clearInputFields();
    }

    private void deletePropertyFromDatabase(int propertyId) {
        try (PreparedStatement preparedStatement = connection.prepareStatement(
                "DELETE FROM properties WHERE id=?")) {
            preparedStatement.setInt(1, propertyId);
            preparedStatement.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private void populateFieldsFromTable(int selectedRow) {
        idTextField.setText(String.valueOf(propertyTable.getValueAt(selectedRow, 0)));
        nameTextField.setText((String) propertyTable.getValueAt(selectedRow, 1));
        typeTextField.setText((String) propertyTable.getValueAt(selectedRow, 2));
        locationTextField.setText((String) propertyTable.getValueAt(selectedRow, 3));
        priceTextField.setText(String.valueOf(propertyTable.getValueAt(selectedRow, 4)));
    }

    private void clearInputFields() {
        idTextField.setText("");
        nameTextField.setText("");
        typeTextField.setText("");
        locationTextField.setText("");
        priceTextField.setText("");
    }

    private void refreshTable() {
        tableModel.setColumnCount(0);
        tableModel.setRowCount(0);

        // Retrieve all properties from the database
        List<Property> allProperties = getAllPropertiesFromDatabase();

        // Add columns to the table model
        tableModel.addColumn("ID");
        tableModel.addColumn("Name");
        tableModel.addColumn("Type");
        tableModel.addColumn("Location");
        tableModel.addColumn("Price");

        // Add rows to the table model
        for (Property property : allProperties) {
            Object[] row = {property.getId(), property.getName(), property.getType(),
                    property.getLocation(), property.getPrice()};
            tableModel.addRow(row);
        }
    }

    private List<Property> getAllPropertiesFromDatabase() {
        List<Property> properties = new ArrayList<>();
        try (Statement statement = connection.createStatement();
             ResultSet resultSet = statement.executeQuery("SELECT * FROM properties")) {
            while (resultSet.next()) {
                Property property = new Property();
                property.setId(resultSet.getInt("id"));
                property.setName(resultSet.getString("name"));
                property.setType(resultSet.getString("type"));
                property.setLocation(resultSet.getString("location"));
                property.setPrice(resultSet.getDouble("price"));
                properties.add(property);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return properties;
    }

    // Inner Property class
    private static class Property {
        private int id;
        private String name;
        private String type;
        private String location;
        private double price;

        public Property() {
            // Default constructor
        }

        // Constructors, getters, setters

        public int getId() {
            return id;
        }

        public void setId(int id) {
            this.id = id;
        }

        public String getName() {
            return name;
        }

        public void setName(String name) {
            this.name = name;
        }

        public String getType() {
            return type;
        }

        public void setType(String type) {
            this.type = type;
        }

        public String getLocation() {
            return location;
        }

        public void setLocation(String location) {
            this.location = location;
        }

        public double getPrice() {
            return price;
        }

        public void setPrice(double price) {
            this.price = price;
        }

        @Override
        public String toString() {
            return "Property{" +
                    "id=" + id +
                    ", name='" + name + '\'' +
                    ", type='" + type + '\'' +
                    ", location='" + location + '\'' +
                    ", price=" + price +
                    '}';
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new Jdbcdemo();
            }
        });
    }
}
