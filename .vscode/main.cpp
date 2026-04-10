#include <iostream>
#include <string>
using namespace std;

struct Patient {
    int id;
    string name;
    int age;
    string disease;
    string appointment;
};

Patient patients[100];
int count = 0;

// ================= FUNCTIONS =================

void addPatient() {
    cout << "\n--- Add Patient ---\n";

    cout << "Enter ID: ";
    cin >> patients[count].id;

    cout << "Enter Name: ";
    cin >> patients[count].name;

    cout << "Enter Age: ";
    cin >> patients[count].age;

    cout << "Enter Disease: ";
    cin >> patients[count].disease;

    patients[count].appointment = "Not Scheduled";

    count++;
    cout << "✅ Patient added successfully!\n";
}

void viewPatients() {
    cout << "\n--- Patient List ---\n";

    if (count == 0) {
        cout << "No patients found.\n";
        return;
    }

    cout << "ID\tName\tAge\tDisease\tAppointment\n";
    cout << "--------------------------------------------------\n";

    for (int i = 0; i < count; i++) {
        cout << patients[i].id << "\t"
             << patients[i].name << "\t"
             << patients[i].age << "\t"
             << patients[i].disease << "\t"
             << patients[i].appointment << endl;
    }
}

void searchPatient() {
    int id;
    cout << "\nEnter Patient ID: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (patients[i].id == id) {
            cout << "\n--- Patient Found ---\n";
            cout << "Name: " << patients[i].name << endl;
            cout << "Age: " << patients[i].age << endl;
            cout << "Disease: " << patients[i].disease << endl;
            cout << "Appointment: " << patients[i].appointment << endl;
            return;
        }
    }

    cout << "❌ Patient not found!\n";
}

void scheduleAppointment() {
    int id;
    cout << "\nEnter Patient ID: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (patients[i].id == id) {
            cout << "Enter Appointment (e.g. 12-June): ";
            cin >> patients[i].appointment;

            cout << "✅ Appointment scheduled!\n";
            return;
        }
    }

    cout << "❌ Patient not found!\n";
}

void updateInfo() {
    int id;
    cout << "\nEnter Patient ID: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (patients[i].id == id) {
            cout << "Enter new disease: ";
            cin >> patients[i].disease;

            cout << "✅ Info updated!\n";
            return;
        }
    }

    cout << "❌ Patient not found!\n";
}

// ================= MAIN =================

int main() {
    int choice;

    do {
        cout << "\n=====================================\n";
        cout << "   🏥 Hospital Management System\n";
        cout << "=====================================\n";
        cout << "1. Add Patient\n";
        cout << "2. View Patients\n";
        cout << "3. Search Patient\n";
        cout << "4. Schedule Appointment\n";
        cout << "5. Update Patient Info\n";
        cout << "6. Exit\n";
        cout << "=====================================\n";
        cout << "Enter choice: ";

        cin >> choice;

        switch (choice) {
            case 1: addPatient(); break;
            case 2: viewPatients(); break;
            case 3: searchPatient(); break;
            case 4: scheduleAppointment(); break;
            case 5: updateInfo(); break;
            case 6: cout << "👋 Exiting...\n"; break;
            default: cout << "❌ Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
