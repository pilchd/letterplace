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
