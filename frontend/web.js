document.getElementById("sort").addEventListener("click", () => {
    let category = document.getElementById("category").value;
    let algorithm = document.getElementById("algorithm").value;
    let direction = document.getElementById("direction").value;

    fetch(`/COP3530_Project_2b?category=${category}&algorithm=${algorithm}&direction=${direction}`)
    .then(res => res.text())
    .then(output=> {
        data = document.getElementById("tableinfo");
        data.innerHTML = "";

        const tracks = output.trim().split("\n")
        document.getElementById("counter").innerHTML = tracks.shift();
        for (const track of tracks){
            const row = data.insertRow();
            const categories = track.split(",")
            for (const category of categories){
                row.insertCell().innerHTML = category;
            }
        }
    });

});

