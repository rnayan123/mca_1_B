import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Scanner;

 class HospitalManagementSystemSwing extends JFrame {
    private static final String url = "jdbc:mysql://localhost:3306/hospital";
    private static final String username = "root";
    private static final String password = "nayan1810";

    private Connection connection;

    public HospitalManagementSystemSwing() {
        initializeUI();
        initializeDatabase();
    }

    private void initializeUI() {
        setTitle("Hospital Management System");
        setSize(400, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        JButton addPatientButton = new JButton("Add Patient");
        JButton viewPatientsButton = new JButton("View Patients");
        JButton viewDoctorsButton = new JButton("View Doctors");
        JButton bookAppointmentButton = new JButton("Book Appointment");
        JButton exitButton = new JButton("Exit");

        addPatientButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                addPatient();
            }
        });

        viewPatientsButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                viewPatients();
            }
        });

        viewDoctorsButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                viewDoctors();
            }
        });

        bookAppointmentButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                bookAppointment();
            }
        });

        exitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });

        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(5, 1));
        panel.add(addPatientButton);
        panel.add(viewPatientsButton);
        panel.add(viewDoctorsButton);
        panel.add(bookAppointmentButton);
        panel.add(exitButton);

        add(panel, BorderLayout.CENTER);
    }

    private void initializeDatabase() {
    try {
        Class.forName("com.mysql.cj.jdbc.Driver");
        Connection connection = DriverManager.getConnection(url, username, password);
        patient = new Patient(connection, new Scanner(System.in));
        doctor = new Doctor(connection);
    } catch (ClassNotFoundException | SQLException e) {
        e.printStackTrace();
    }


    }

    private void addPatient() {
        JTextField nameField = new JTextField();
        JTextField diseaseField = new JTextField();

        JPanel inputPanel = new JPanel(new GridLayout(2, 2));
        inputPanel.add(new JLabel("Patient Name: "));
        inputPanel.add(nameField);
        inputPanel.add(new JLabel("Disease: "));
        inputPanel.add(diseaseField);

        int result = JOptionPane.showConfirmDialog(
                this,
                inputPanel,
                "Add Patient",
                JOptionPane.OK_CANCEL_OPTION);

        if (result == JOptionPane.OK_OPTION) {
            String name = nameField.getText();
            String disease = diseaseField.getText();

            if (!name.isEmpty() && !disease.isEmpty()) {
                try {
                    String query = "INSERT INTO patients (name, disease) VALUES (?, ?)";
                    try (PreparedStatement preparedStatement = connection.prepareStatement(query)) {
                        preparedStatement.setString(1, name);
                        preparedStatement.setString(2, disease);

                        int rowsAffected = preparedStatement.executeUpdate();

                        if (rowsAffected > 0) {
                            JOptionPane.showMessageDialog(
                                    this,
                                    "Patient added successfully!",
                                    "Success",
                                    JOptionPane.INFORMATION_MESSAGE);
                        } else {
                            JOptionPane.showMessageDialog(
                                    this,
                                    "Failed to add patient.",
                                    "Error",
                                    JOptionPane.ERROR_MESSAGE);
                        }
                    }
                } catch (SQLException ex) {
                    ex.printStackTrace();
                }
            } else {
                JOptionPane.showMessageDialog(
                        this,
                        "Please enter valid values.",
                        "Error",
                        JOptionPane.ERROR_MESSAGE);
            }
        }
    }

    private void viewPatients() {
        try {
            String query = "SELECT * FROM patients";
            try (PreparedStatement preparedStatement = connection.prepareStatement(query);
                    ResultSet resultSet = preparedStatement.executeQuery()) {

                StringBuilder patientsInfo = new StringBuilder("Patients:\n");
                patientsInfo.append("+----+-------------------+-----------------+\n");
                patientsInfo.append("| ID | Name              | Disease         |\n");
                patientsInfo.append("+----+-------------------+-----------------+\n");

                while (resultSet.next()) {
                    int id = resultSet.getInt("id");
                    String name = resultSet.getString("name");
                    String disease = resultSet.getString("disease");

                    patientsInfo.append(String.format("| %-2d | %-17s | %-15s |\n", id, name, disease));
                }

                patientsInfo.append("+----+-------------------+-----------------+");

                JTextArea patientsTextArea = new JTextArea(patientsInfo.toString());
                patientsTextArea.setEditable(false);
                JScrollPane scrollPane = new JScrollPane(patientsTextArea);

                JOptionPane.showMessageDialog(
                        this,
                        scrollPane,
                        "View Patients",
                        JOptionPane.INFORMATION_MESSAGE);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private void viewDoctors() {
        try {
            String query = "SELECT * FROM patients";
            try (PreparedStatement preparedStatement = connection.prepareStatement(query);
                    ResultSet resultSet = preparedStatement.executeQuery()) {

                StringBuilder patientsInfo = new StringBuilder("Patients:\n");
                patientsInfo.append("+----+-------------------+-----------------+\n");
                patientsInfo.append("| ID | Name              | Disease         |\n");
                patientsInfo.append("+----+-------------------+-----------------+\n");

                while (resultSet.next()) {
                    int id = resultSet.getInt("id");
                    String name = resultSet.getString("name");
                    String disease = resultSet.getString("disease");

                    patientsInfo.append(String.format("| %-2d | %-17s | %-15s |\n", id, name, disease));
                }

                patientsInfo.append("+----+-------------------+-----------------+");

                JTextArea patientsTextArea = new JTextArea(patientsInfo.toString());
                patientsTextArea.setEditable(false);
                JScrollPane scrollPane = new JScrollPane(patientsTextArea);

                JOptionPane.showMessageDialog(
                        this,
                        scrollPane,
                        "View Patients",
                        JOptionPane.INFORMATION_MESSAGE);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private void bookAppointment() {
        JTextField patientIdField = new JTextField();
        JTextField doctorIdField = new JTextField();
        JTextField appointmentDateField = new JTextField();

        JPanel inputPanel = new JPanel(new GridLayout(3, 2));
        inputPanel.add(new JLabel("Patient ID: "));
        inputPanel.add(patientIdField);
        inputPanel.add(new JLabel("Doctor ID: "));
        inputPanel.add(doctorIdField);
        inputPanel.add(new JLabel("Appointment Date (YYYY-MM-DD): "));
        inputPanel.add(appointmentDateField);

        int result = JOptionPane.showConfirmDialog(
                this,
                inputPanel,
                "Book Appointment",
                JOptionPane.OK_CANCEL_OPTION);

        if (result == JOptionPane.OK_OPTION) {
            try {
                int patientId = Integer.parseInt(patientIdField.getText());
                int doctorId = Integer.parseInt(doctorIdField.getText());
                String appointmentDate = appointmentDateField.getText();

                // Implement the logic to check patient and doctor existence, and doctor
                // availability

                // If everything is valid, insert the appointment into the database

            } catch (NumberFormatException e) {
                e.printStackTrace();
                JOptionPane.showMessageDialog(
                        this,
                        "Invalid input. Please enter valid values.",
                        "Error",
                        JOptionPane.ERROR_MESSAGE);
            }
        }
    }

    

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new HospitalManagementSystemSwing().setVisible(true);
            }
        });
    }
}
