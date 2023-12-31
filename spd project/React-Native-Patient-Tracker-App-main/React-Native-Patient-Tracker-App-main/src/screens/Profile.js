import {
  StyleSheet,
  Text,
  View,
  Image,
  TextInput,
  TouchableOpacity,
} from "react-native";
import React, { useContext, useEffect, useState } from "react";
import { ref, onValue } from "firebase/database";
import { database } from "../../firebaseConfig";
import AuthContext from "../../AuthContext";
import { getAuth, signOut } from "firebase/auth";

const Profile = ({ navigation }) => {
  const [profileData, setProfileData] = useState();
  const authContext = useContext(AuthContext);

  useEffect(() => {
    const dbRef = ref(database, "user/" + authContext.user);
    onValue(dbRef, (snapshot) => {
      const data = snapshot.val();
      setProfileData(data);
    });
  }, []);

  // Signout User
  const signOutUser = () => {
    const auth = getAuth();
    signOut(auth)
      .then(() => {
        authContext.signout();
        navigation.replace("Login");
      })
      .catch((error) => {
        console.log(error);
      });
  };

  return (
    <View style={styles.container}>
      <View style={styles.headerContainer}>
        <Image
          style={styles.footer}
          source={require("../../assets/header-login-screen.png")}
        />
        <Text style={styles.topText}>My Profile</Text>
      </View>
      <View style={styles.subContainer}>
        <Text style={styles.headingText}>My Profile</Text>
        <TextInput
          style={styles.input}
          placeholder="Username"
          value={profileData?.username}
          editable={false}
        />
        <TextInput
          style={styles.input}
          placeholder="Email "
          value={profileData?.email}
          editable={false}
        />
        <TextInput
          style={styles.input}
          placeholder="Password"
          secureTextEntry={true}
          value={profileData?.password}
          editable={false}
        />
        <TouchableOpacity style={styles.button}>
          <Text style={styles.buttonText}>Update</Text>
        </TouchableOpacity>
        <TouchableOpacity style={styles.button} onPress={signOutUser}>
          <Text style={styles.buttonText}>Signout</Text>
        </TouchableOpacity>
      </View>
    </View>
  );
};

export default Profile;

const styles = StyleSheet.create({
  container: {
    flex: 1,

    justifyContent: "space-between",
    alignItems: "center",
  },
  headerContainer: {
    flex: 1,
    justifyContent: "center",
    alignItems: "center",
  },
  subContainer: {
    flex: 3,
    justifyContent: "center",
    alignItems: "center",
    width: "95%",
  },
  topText: {
    position: "absolute",
    top: 70,
    fontWeight: "bold",
    color: "white",
    fontSize: 18,
  },
  bottomText: {
    position: "absolute",
    bottom: 50,
    color: "white",
    fontSize: 14,
  },
  headingText: {
    fontWeight: "bold",
    color: "#35A2CD",
    fontSize: 25,
    marginBottom: 8,
  },
  simpleText: {
    marginBottom: 15,
  },
  input: {
    width: "90%",
    height: 40,
    margin: 12,
    backgroundColor: "rgb(220,220,220)",
    padding: 10,
    borderRadius: 12,
  },
  button: {
    marginTop: 10,
    height: 35,
    width: "50%",
    alignItems: "center",
    justifyContent: "center",
    backgroundColor: "#35A2CD",
    borderRadius: 12,
  },
  buttonText: {
    color: "#fff",
  },
});
