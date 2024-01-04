import React, { useState, useContext } from "react";
import {
  StyleSheet,
  Text,
  View,
  ScrollView,
  Image,
  TextInput,
  TouchableOpacity,
  KeyboardAvoidingView,
  Platform,
} from "react-native";
import RNPickerSelect from "react-native-picker-select";
import AuthContext from "../../AuthContext";
import { database } from "../../firebaseConfig";
import { ref, push, update, serverTimestamp } from "firebase/database";
import DateTimePicker from "@react-native-community/datetimepicker";

const AddPatient = () => {
  const authContext = useContext(AuthContext);
  const [date, setDate] = useState(new Date());
  const [show, setShow] = useState(false);
  const [formData, setFormData] = useState({
    patientName: "",
    appointmentDate: "",
    patientPhoneNumber: "",
    patientDisease: "",
    cost: "",
    prescription: "",
    dateOfArrival: serverTimestamp(),
    doctorID: authContext.user,
  });

  console.log("Date:::::: <<< >>> : ", formData);

  const pickerItems = [
    { label: "Covid19", value: "Covid19" },
    { label: "Diabetes", value: "Diabetes" },
    { label: "Flu", value: "Flu" },
    { label: "Fever", value: "Fever" },
    { label: "Heart Disease", value: "HeartDisease" },
    { label: "Diarrheal", value: "Diarrheal" },
  ];

  // Firebase
  const myFirebase = async () => {
    try {
      // Get a key for every new Patient.
      const newPatientKey = push(ref(database, "patients")).key;

      // Write the new patient's data simultaneously in the patients list.
      const updates = {};
      updates[`/patients/${newPatientKey}`] = formData;

      // Use await to wait for the update to complete
      await update(ref(database), updates);

      console.log("Patient added successfully!");
    } catch (error) {
      console.error("Error adding patient:", error.message);
    }
  };
  // ---------

  const handleDateChange = (event, selectedDate) => {
    const currentDate = selectedDate || date;
    setShow(Platform.OS === "ios");
    setDate(currentDate);
    setFormData({
      ...formData,
      appointmentDate: currentDate.toLocaleDateString(),
    });
  };

  const showDatePicker = async () => {
    setShow(true);
  };

  return (
    <View style={styles.container}>
      <View style={styles.headerContainer}>
        <Image
          style={styles.footer}
          source={require("../../assets/header-login-screen.png")}
        />
        <Text style={styles.topText}>Add Patient</Text>
      </View>
      <ScrollView
        showsVerticalScrollIndicator={false}
        style={styles.scrollContainer}
      >
        <KeyboardAvoidingView behavior="position">
          <Text style={styles.headingText}>Add your Patient Info</Text>
          <View>
            <TextInput
              style={styles.input}
              placeholder="Patient Name"
              onChangeText={(text) =>
                setFormData({ ...formData, patientName: text })
              }
            />
          </View>
          <View>
            <View style={styles.datePicker}>
              <Text onPress={showDatePicker} style={{ opacity: 0.3 }}>
                Appointment Date:{" "}
              </Text>
              {show && (
                <DateTimePicker value={date} onChange={handleDateChange} />
              )}
            </View>
          </View>
          <View>
            <TextInput
              style={styles.input}
              placeholder="Patient Phone Number"
              onChangeText={(text) =>
                setFormData({ ...formData, patientPhoneNumber: text })
              }
            />
          </View>
          <View style={styles.input}>
            <RNPickerSelect
              onValueChange={(value) => {
                setFormData({ ...formData, patientDisease: value });
              }}
              items={pickerItems}
              placeholder={{ label: "Select an option", value: "" }}
              value={formData.patientDisease}
            />
          </View>
          <View>
            <TextInput
              style={styles.input}
              placeholder="Cost"
              onChangeText={(text) => setFormData({ ...formData, cost: text })}
            />
          </View>
          <View>
            <TextInput
              style={styles.input}
              placeholder="Prescription"
              onChangeText={(text) =>
                setFormData({ ...formData, prescription: text })
              }
            />
          </View>

          <View style={{ alignItems: "center" }}>
            <TouchableOpacity
              style={styles.button}
              onPress={() => myFirebase()}
            >
              <Text style={styles.buttonText}>Add</Text>
            </TouchableOpacity>
          </View>
        </KeyboardAvoidingView>
      </ScrollView>
    </View>
  );
};

export default AddPatient;

const styles = StyleSheet.create({
  // Your styles remain unchanged
});
