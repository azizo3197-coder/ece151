// Array to store patient records (This replaces your C++ patients array)
let patients = [];
let nextId = 103; // Starting at 103 since your HTML already has 101 and 102

// Grab the form and the table from your HTML
const form = document.querySelector('form');
const table = document.querySelector('table');

// Listen for when someone clicks "Submit"
form.addEventListener('submit', function(event) {
    event.preventDefault(); // Prevents the page from refreshing

    // Get the values the user typed into the input boxes
    const inputs = form.querySelectorAll('input');
    const name = inputs[0].value;
    const age = inputs[1].value;
    const disease = inputs[2].value;
    const appointment = inputs[3].value || "Not Scheduled"; // Default if left blank

    // Basic check to make sure they didn't leave it blank
    if (name === "" || age === "" || disease === "") {
        alert("Please fill in Name, Age, and Disease!");
        return;
    }

    // Create a new patient object (This replaces your C++ struct)
    const newPatient = {
        id: nextId,
        name: name,
        age: age,
        disease: disease,
        appointment: appointment
    };

    // Add to our system memory
    patients.push(newPatient);
    nextId++; // Increase the ID for the next person

    // Add the new patient to the HTML table visually
    displayPatientInTable(newPatient);

    // Clear the typing boxes
    form.reset();
    
    // Show a success message like in your C++ code
    alert("✅ Patient added successfully!");
});

// Function to draw the patient row (Replaces your C++ viewPatients loop)
function displayPatientInTable(patient) {
    const row = document.createElement('tr');

    row.innerHTML = `
        <td>${patient.id}</td>
        <td>${patient.name}</td>
        <td>${patient.age}</td>
        <td>${patient.disease}</td>
        <td>${patient.appointment}</td>
    `;

    table.appendChild(row);
}
