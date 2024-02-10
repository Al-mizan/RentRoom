class Admin : public User
{
public:
    Admin()
    {
        inputData();
    }

    // Admin(const string &_name, const string &_nationalID, const string &_password, const string &_contactDetails)
    //     : User(_name, _nationalID, _password, _contactDetails) {}

    void FileData() override
    {
        ofstream adminFile("admins.txt", ios::app);
        if (adminFile.is_open())
        {
            adminFile << nationalID << " " << password << " " << firstName << " " << surName << " " << contactDetails << endl;
            adminFile.close();
            cout << "Registration successful!" << endl;
        }
    }

    bool login()
    {
        string nationalID3, password3;
        cout << "===== Admin Login =====" << endl;
        cout << "Enter national ID: ";
        cin >> nationalID3;
        password3 = getPassword();
        ifstream adminFile("admins.txt");
        if (adminFile.is_open())
        {
            string line;
            while (getline(adminFile, line))
            {
                istringstream iss(line);
                string storedNationalID, storedPassword, storedFName, storedSName, storedContactDetails;
                if (iss >> storedNationalID >> storedPassword >> storedFName >> storedSName >> storedContactDetails)
                {
                    if (storedNationalID == nationalID3 && storedPassword == password3)
                    {
                        cout << "Login successful!";
                        cout << " Welcome, " << storedFName << " " << storedSName << "." << endl;
                        return true;
                    }
                }
            }
            cout << "Login failed! \nPlease try again." << endl;
            return false;
        }
    }

    void viewOwnerList()
    {
        ifstream ownerFile("owners.txt");
        if (ownerFile.is_open())
        {
            string line;
            int count = 1;
            while (getline(ownerFile, line))
            {
                istringstream iss(line);
                string storedNationalID, storedPassword, storedFName, storedSName, storedContactDetails;
                if (iss >> storedNationalID >> storedPassword >> storedFName >> storedSName >> storedContactDetails)
                {
                    cout << endl
                         << count << '.' << endl;
                    cout << " First name: " << storedFName << endl;
                    cout << " Surname: " << storedSName << endl;
                    cout << " National ID: " << storedNationalID << endl;
                    cout << " Contact details: " << storedContactDetails << endl;
                }
                if (count % 10 == 0)
                {
                    cout << endl;
                    cout
                        << "For more information enter \'y\' otherwise \'n\'\n";
                    char ch;
                    cin >> ch;
                    if (ch == 'n')
                        break;
                    system("cls");
                }
                count++;
            }
        }
    }

    void viewTenantList()
    {
        ifstream tenantFile("tenants.txt");
        if (tenantFile.is_open())
        {
            string line;
            int count = 1;
            while (getline(tenantFile, line))
            {
                istringstream iss(line);
                string storedNationalID, storedPassword, storedFName, storedSName, storedContactDetails;
                string roomId, roommateRating;
                if (iss >> storedNationalID >> storedPassword >> storedFName >> storedSName >> storedContactDetails >> roomId >> roommateRating)
                {
                    cout << endl
                         << count << '.' << endl;
                    cout << " First name: " << storedFName << endl;
                    cout << " Surname: " << storedSName << endl;
                    cout << " National ID: " << storedNationalID << endl;
                    cout << " Contact details: " << storedContactDetails << endl;
                    if (roomId != "none")
                        cout << " Room ID: " << roomId << endl;
                    cout << " Rating as a roommate: " << roommateRating << endl;
                }
                if (count % 10 == 0)
                {
                    cout << endl;
                    cout
                        << "For more information enter 'y' otherwise 'n'\n";
                    char ch;
                    system("cls");
                    cin >> ch;
                    if (ch == 'n')
                        break;
                    system("cls");
                }
                count++;
            }
        }
    }
};