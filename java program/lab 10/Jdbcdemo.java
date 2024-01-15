import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class Jdbcdemo {

    public static void main(String[] args) {
        // Create a property
        Property propertyToAdd = new Property();
        propertyToAdd.setName("Luxury Villa");
        propertyToAdd.setType("Residential");
        propertyToAdd.setLocation("Prime Location");
        propertyToAdd.setPrice(1000000.00);

        // Add property to the database
        PropertyDAO propertyDAO = new PropertyDAO();
        propertyDAO.addProperty(propertyToAdd);

        // Retrieve all properties from the database and print them
        List<Property> allProperties = propertyDAO.getAllProperties();
        for (Property property : allProperties) {
            System.out.println(property);
        }
    }
}

class Property {
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

class DatabaseConnection {
    private static final String URL = "jdbc:mysql://localhost:3306/Realestate";
    private static final String USER = "System";
    private static final String PASSWORD = "nayan1810";

    public static Connection getConnection() throws SQLException {
        return DriverManager.getConnection(URL, USER, PASSWORD);
    }
}

class PropertyDAO {
    private static final String INSERT_PROPERTY = "INSERT INTO properties (name, type, location, price) VALUES (?, ?, ?, ?)";
    private static final String GET_ALL_PROPERTIES = "SELECT * FROM properties";

    public void addProperty(Property property) {
        try (Connection connection = DatabaseConnection.getConnection();
             PreparedStatement preparedStatement = connection.prepareStatement(INSERT_PROPERTY)) {
            preparedStatement.setString(1, property.getName());
            preparedStatement.setString(2, property.getType());
            preparedStatement.setString(3, property.getLocation());
            preparedStatement.setDouble(4, property.getPrice());
            preparedStatement.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public List<Property> getAllProperties() {
        List<Property> properties = new ArrayList<>();
        try (Connection connection = DatabaseConnection.getConnection();
             PreparedStatement preparedStatement = connection.prepareStatement(GET_ALL_PROPERTIES);
             ResultSet resultSet = preparedStatement.executeQuery()) {
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
}
