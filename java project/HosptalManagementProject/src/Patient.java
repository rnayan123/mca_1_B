import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class Patient extends JFrame {
    private Connection connection;
    private JTable doctorsTable;

    public Patient(Connection connection) {
        this.connection = connection;
        initializeUI();
    }

    private void initializeUI() {
        setTitle("Hospital Management System - Doctors");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(600, 400);
        setLocationRelativeTo(null);

        doctorsTable = new JTable();
        JScrollPane scrollPane = new JScrollPane(doctorsTable);

        JButton viewButton = new JButton("View Doctors");
        viewButton.addActionListener(e -> viewDoctors());

        JPanel buttonPanel = new JPanel();
        buttonPanel.add(viewButton);

        setLayout(new BorderLayout());
        add(scrollPane, BorderLayout.CENTER);
        add(buttonPanel, BorderLayout.SOUTH);
    }

    private void viewDoctors() {
        String query = "select * from doctors";
        try {
            PreparedStatement preparedStatement = connection.prepareStatement(query);
            ResultSet resultSet = preparedStatement.executeQuery();

            DefaultTableModel tableModel = new DefaultTableModel();
            tableModel.addColumn("Doctor Id");
            tableModel.addColumn("Name");
            tableModel.addColumn("Specialization");

            while (resultSet.next()) {
                int id = resultSet.getInt("id");
                String name = resultSet.getString("name");
                String specialization = resultSet.getString("specialization");
                tableModel.addRow(new Object[] { id, name, specialization });
            }

            doctorsTable.setModel(tableModel);

        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        Connection connection = getDatabaseConnection();

        SwingUtilities.invokeLater(() -> new Doctor(connection).setVisible(true));
    }

    private static Connection getDatabaseConnection() {
        try {
            String url = "jdbc:mysql://localhost:3306/Hospital";
            String username = "root";
            String password = "nayan1810";

            Class.forName("com.mysql.cj.jdbc.Driver");

            return DriverManager.getConnection(url, username, password);
        } catch (ClassNotFoundException | SQLException e) {
            e.printStackTrace();
            return null;
        }
    }
}
