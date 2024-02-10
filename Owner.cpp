#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;

class Owner : public User
{
private:
    // Room *room;
    // string rating = "0", roomId = "none";
public:
    Owner()
    {
        User::inputData();
    }

    string getOwnerIdRegistration() const { return nationalID; }

    void FileData() override
    {
        ofstream ownerFile("owners.txt", ios::app);
        if (ownerFile.is_open())
        {
            ownerFile << nationalID << " " << password << " " << firstName << " " << surName << " " << contactDetails << " " << endl;
            ownerFile.close();
            cout << "Registration successful!" << endl;
        }
    }

    string login()
    {
        string nationalID1, password1;
        cout << endl;
        cout
            << "====== Owner Login ======" << endl;
        cout << "Enter national ID: ";
        cin >> nationalID1;
        password1 = getPassword();

        ifstream ownerFile("owners.txt");
        if (ownerFile.is_open())
        {
            string line;
            while (getline(ownerFile, line))
            {
                istringstream iss(line);
                string storedNationalID, storedPassword, storedFirstName, storedSurname, storedContactDetails;
                if (iss >> storedNationalID >> storedPassword >> storedFirstName >> storedSurname >> storedContactDetails)
                {
                    if (storedNationalID == nationalID1 && storedPassword == password1)
                    {
                        cout << "Login successful! \nWelcome, " << storedFirstName << " " << storedSurname << "." << endl;
                        return storedNationalID;
                    }
                }
            }
            cout << "Login failed! \nPlease try again." << endl;
            return "none";
        }
        // throw runtime_error("Login failed");
    }

    // void addingRoom() {}

    // void viewRoom() {}
};
