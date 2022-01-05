import {initializeApp} from 'firebase/app'
import {} from 'firebase/auth'


const firebaseConfig = {
  apiKey: "AIzaSyBGPNeaqxtsU-TZiYlLRVqlIus_Fk9Qbhw",
  authDomain: "letter-place.firebaseapp.com",
  projectId: "letter-place",
  storageBucket: "letter-place.appspot.com",
  messagingSenderId: "347140223350",
  appId: "1:347140223350:web:a043329534fdca6da44a57"
};
const app = initializeApp(firebaseConfig);


document.getElementById("expand").addEventListener("click", () => {

    if (!document.getElementById("expand").classList.contains("expanded")) {
        document.getElementById("cont-cred").style.visibility = "visible";
        document.getElementById("expand").classList.add("expanded");
        document.getElementById("cont-cred").classList.add("expanded");

    }
    else {
        document.getElementById("expand").classList.remove("expanded");
        document.getElementById("expand").classList.remove("expanded");
        document.getElementById("cont-cred").classList.remove("expanded");
        setTimeout(() => {
            document.getElementById("cont-cred").style.visibility = "hidden";
        },
        parseInt(getComputedStyle(document.documentElement).getPropertyValue("--anim-dur-expand")) * 1000);
    }
});
