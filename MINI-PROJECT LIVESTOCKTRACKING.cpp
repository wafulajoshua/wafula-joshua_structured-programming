#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class Livestock
{
private:
    int animalID;
    string animalName;
    string breed;
    int age;
    float weight;
    char gender;
    float temperature;
    string disease;
    string vaccinationStatus;
    string location;

public:

    // Function to enter livestock details
    void registerAnimal()
    {
        cout << "\n===== REGISTER NEW ANIMAL =====\n";

        cout << "Enter Animal ID: ";
        cin >> animalID;

        cin.ignore();

        cout << "Enter Animal Name: ";
        getline(cin, animalName);

        cout << "Enter Breed: ";
        getline(cin, breed);

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter Weight (Kg): ";
        cin >> weight;

        cout << "Enter Gender (M/F): ";
        cin >> gender;

        cout << "Enter Body Temperature: ";
        cin >> temperature;

        cin.ignore();

        cout << "Enter Disease Condition: ";
        getline(cin, disease);

        cout << "Enter Vaccination Status: ";
        getline(cin, vaccinationStatus);

        cout << "Enter Animal Location: ";
        getline(cin, location);
    }

    // Function to display animal details
    void displayAnimal()
    {
        cout << "\n====================================";
        cout << "\nAnimal ID: " << animalID;
        cout << "\nAnimal Name: " << animalName;
        cout << "\nBreed: " << breed;
        cout << "\nAge: " << age;
        cout << "\nWeight: " << weight << " Kg";
        cout << "\nGender: " << gender;
        cout << "\nTemperature: " << temperature;
        cout << "\nDisease: " << disease;
        cout << "\nVaccination Status: " << vaccinationStatus;
        cout << "\nLocation: " << location;
        cout << "\n====================================\n";
    }

    // Save records to file
    void saveToFile()
    {
        ofstream file("livestock.txt", ios::app);

        file << animalID << endl;
        file << animalName << endl;
        file << breed << endl;
        file << age << endl;
        file << weight << endl;
        file << gender << endl;
        file << temperature << endl;
        file << disease << endl;
        file << vaccinationStatus << endl;
        file << location << endl;

        file.close();

        cout << "\nRecord saved successfully.\n";
    }

    // Read records from file
    void readFromFile()
    {
        ifstream file("livestock.txt");

        if (!file)
        {
            cout << "\nNo records found.\n";
            return;
        }

        while (!file.eof())
        {
            file >> animalID;
            file.ignore();

            getline(file, animalName);
            getline(file, breed);

            file >> age;
            file >> weight;
            file >> gender;
            file >> temperature;

            file.ignore();

            getline(file, disease);
            getline(file, vaccinationStatus);
            getline(file, location);

            if (file.fail())
                break;

            displayAnimal();
        }

        file.close();
    }

    // Search animal by ID
    void searchAnimal(int searchID)
    {
        ifstream file("livestock.txt");

        bool found = false;

        while (!file.eof())
        {
            file >> animalID;
            file.ignore();

            getline(file, animalName);
            getline(file, breed);

            file >> age;
            file >> weight;
            file >> gender;
            file >> temperature;

            file.ignore();

            getline(file, disease);
            getline(file, vaccinationStatus);
            getline(file, location);

            if (animalID == searchID)
            {
                cout << "\nAnimal Record Found!\n";
                displayAnimal();
                found = true;
            }
        }

        if (!found)
        {
            cout << "\nAnimal record not found.\n";
        }

        file.close();
    }

    // Update livestock health data
    void updateHealth(int searchID)
    {
        ifstream file("livestock.txt");
        ofstream temp("temp.txt");

        bool found = false;

        while (!file.eof())
        {
            file >> animalID;
            file.ignore();

            getline(file, animalName);
            getline(file, breed);

            file >> age;
            file >> weight;
            file >> gender;
            file >> temperature;

            file.ignore();

            getline(file, disease);
            getline(file, vaccinationStatus);
            getline(file, location);

            if (file.fail())
                break;

            if (animalID == searchID)
            {
                found = true;

                cout << "\nUpdating Health Information\n";

                cout << "Enter New Temperature: ";
                cin >> temperature;

                cin.ignore();

                cout << "Enter New Disease Condition: ";
                getline(cin, disease);

                cout << "Enter New Vaccination Status: ";
                getline(cin, vaccinationStatus);
            }

            temp << animalID << endl;
            temp << animalName << endl;
            temp << breed << endl;
            temp << age << endl;
            temp << weight << endl;
            temp << gender << endl;
            temp << temperature << endl;
            temp << disease << endl;
            temp << vaccinationStatus << endl;
            temp << location << endl;
        }

        file.close();
        temp.close();

        remove("livestock.txt");
        rename("temp.txt", "livestock.txt");

        if (found)
        {
            cout << "\nHealth record updated successfully.\n";
        }
        else
        {
            cout << "\nAnimal not found.\n";
        }
    }
};

// Login function
bool login()
{
    string username, password;

    cout << "========== LOGIN ==========\n";

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    if (username == "admin" && password == "1234")
    {
        cout << "\nLogin Successful!\n";
        return true;
    }
    else
    {
        cout << "\nInvalid Username or Password!\n";
        return false;
    }
}

// Main Function
int main()
{
    Livestock animal;

    int choice;
    int searchID;

    if (!login())
    {
        return 0;
    }

    do
    {
        cout << "\n\n========== LIVESTOCK TRACKING SYSTEM ==========\n";

        cout << "1. Register New Animal\n";
        cout << "2. View All Animals\n";
        cout << "3. Search Animal\n";
        cout << "4. Update Animal Health\n";
        cout << "5. Exit\n";

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            animal.registerAnimal();
            animal.saveToFile();
            break;

        case 2:
            animal.readFromFile();
            break;

        case 3:
            cout << "\nEnter Animal ID to Search: ";
            cin >> searchID;

            animal.searchAnimal(searchID);
            break;

        case 4:
            cout << "\nEnter Animal ID to Update: ";
            cin >> searchID;

            animal.updateHealth(searchID);
            break;

        case 5:
            cout << "\nExiting System...\n";
            break;

        default:
            cout << "\nInvalid Choice.\n";
        }

    } while (choice != 5);

    return 0;
}
