import {initializeApp} from "firebase/app"
import {
    getAuth,
    createUserWithEmailAndPassword as createUser,
    signInWithEmailAndPassword as signIn,
    AuthErrorCodes as AuthErr
} from "firebase/auth"
import {getDatabase} from "firebase/database"

const firebaseConfig = {
  apiKey: "AIzaSyBGPNeaqxtsU-TZiYlLRVqlIus_Fk9Qbhw",
  authDomain: "letter-place.firebaseapp.com",
  projectId: "letter-place",
  storageBucket: "letter-place.appspot.com",
  messagingSenderId: "347140223350",
  appId: "1:347140223350:web:a043329534fdca6da44a57"
};
const app = initializeApp(firebaseConfig);
const auth = getAuth();
const db = getDatabase(app);


if (!auth.currentUser) {
    document.getElementById("login").classList.toggle("active");
}


document.getElementById("login_expand").addEventListener("click", () => {

    const animDur = parseInt(getComputedStyle(document.documentElement).getPropertyValue("--anim-dur-expand")) * 1000;

    const expand = document.getElementById("login_expand").classList.toggle("expand");
    document.getElementById("login_cont_login").classList.toggle("login");
    setTimeout(() => {
        document.getElementById("login_cont_login").style.visibility = expand ? "visible" : "hidden";
    }, expand ? 0 : animDur);

    if (document.getElementById("login_cont_register").classList.contains("register")) {
        document.getElementById("login_cont_register").classList.remove("register");
        setTimeout(() => {
            document.getElementById("login_cont_register").style.visibility = "hidden";
        }, animDur);
    }
});
document.getElementById("login_expand-register").addEventListener("click", () => {
    document.getElementById("login_cont_register").classList.add("register");
    document.getElementById("login_cont_register").style.visibility = "visible";
});

const login = function() {
    const userCreds = getClassIdValue("cred");
    signIn(auth, userCreds["login_email"], userCreds["login_password"]).then(() => {
        document.getElementById("page_login").classList.toggle("active");
    }).catch((e) => {
        switch (e.code) {
            case AuthErr.INVALID_EMAIL:
                toggleErrorId("login_email");
                break;
            case AuthErr.INVALID_PASSWORD:
                toggleErrorId("login_password");
                break;
            case AuthErr.INTERNAL_ERROR:
                toggleErrorId("login_password");
                break;
            default:
                console.error(e.code);
        }
    });
}
document.getElementById("login_login").addEventListener("click", login);
document.getElementById("login_password").addEventListener("keyup", event => {
    if (event.key == "Enter") login();
});

const register = function () {

    const userCreds = getClassIdValue("cred");
    let valid = true;

    for (let cred in userCreds) {
        if (userCreds[cred] === "") {
            toggleErrorId(cred);
            valid = false;
        }
    }

    if (userCreds["login_password"] != userCreds["login_password-conf"]) {
        ["login_password", "login_password-conf"].forEach(id => toggleErrorId(id));
        valid = false;
    }

    if (valid) {
        createUser(auth, userCreds["login_email"], userCreds["login_password"]).then(() => {

        }).catch(e => {
            switch (e.code) {
                default:
                    console.log(e.code);
            }
        });
    }
}
document.getElementById("login_register").addEventListener("click", register);
document.getElementById("login_addr").addEventListener("keyup", event => {
    if (event.key == "Enter") register();
});


function getClassIdValue(classStr) {
    let userCreds = {};
    for (let elem of document.getElementsByClassName(classStr)) {
        userCreds[elem.id] = elem.value;
    }
    return userCreds;
}
function toggleErrorId(id) {
    document.getElementById(id).classList.toggle("error");
    setTimeout(() => {document.getElementById(id).classList.toggle("error")}, 2000);
}
