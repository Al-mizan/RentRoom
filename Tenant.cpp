class Tenant : public User
{
private:
    string roomId = "none", rating = "0";

protected:
    string tenantIdClass = "";

public:
    string getTenantIdRegistration() const { return nationalID; }
    Tenant()
    {
        cout << "Tenant Registration" << endl;
        inputData();
    }
    void FileData() override
    {
        ofstream tenantFile("tenants.txt", ios::app);
        if (tenantFile.is_open())
        {
            tenantFile << nationalID << " " << password << " " << firstName << " " << surName << " " << contactDetails
                       << " " << roomId << " " << rating << endl;
            tenantFile.close();
            cout << "Registration successful!" << endl;
        }
    }

    string tenantLogin()
    {
        string nationalID2, password2;
        // cout << "\n===== Tenant Login =====\n"
        //      << endl;
        cout << "Enter national ID: ";
        cin >> nationalID2;
        password2 = getPassword();

        ifstream tenantFile("tenants.txt");
        if (tenantFile.is_open())
        {
            string line;
            while (getline(tenantFile, line))
            {
                istringstream iss(line);
                string storedFName, storedSName, storedNationalID, storedPassword, storedContactDetails,
                    storedRoomId, storedRating;
                if (iss >> storedNationalID >> storedPassword >> storedFName >> storedSName >> storedContactDetails >> storedRoomId >> storedRating)
                {
                    if (storedNationalID == nationalID2 && storedPassword == password2)
                    {
                        cout << "Login successful! \nWelcome, " << storedFName << " " << storedSName << "." << endl;
                        tenantFile.close();
                        return storedNationalID;
                    }
                }
            }
            cout << "Login failed! \nPlease try again." << endl;
            tenantFile.close();
            return "none";
        }
        else
            cout << "file is not found! \nPlease try again." << endl;
    }

    string findRoomId(string tenantID)
    {
        ifstream tenantFile("tenants.txt");
        if (tenantFile.is_open())
        {
            string line;
            while (getline(tenantFile, line))
            {
                istringstream iss(line);
                string storedFName, storedSName, storedNationalID, storedPassword, storedContactDetails,
                    storedRoomId, storedRating;
                if (iss >> storedNationalID >> storedPassword >> storedFName >> storedSName >> storedContactDetails >> storedRoomId >> storedRating)
                {
                    if (storedNationalID == tenantID)
                    {
                        return storedRoomId;
                    }
                }
            }
            return "none";
        }
    }

    void leavingRoom(string tenantID)
    {
        string roomId = findRoomId(tenantID);
        if (roomId == "none")
        {
            cout << "There is no room under this tenant ID" << endl;
            return;
        }
        ifstream roomFile("rooms.txt");
        ofstream tempRoomFile("tempRooms.txt", ios::trunc);
        if (roomFile.is_open() && tempRoomFile.is_open())
        {
            string line;
            while (getline(roomFile, line))
            {
                bool found = true;
                istringstream iss(line);
                string storedNationalID, storedLocation, storedHasBathroom, storedRoomId,
                    storedHasBalcony, storedCost, storedOccupied, storedRating, storedFirstRoommate, storedSecondRoommate;
                if (iss >> storedRoomId >> storedNationalID >> storedLocation >> storedHasBathroom >> storedHasBalcony >> storedCost >> storedOccupied >> storedRating >> storedFirstRoommate >> storedSecondRoommate)
                {
                    if (storedRoomId == roomId)
                    {
                        found = false;
                        if (tenantID == storedFirstRoommate)
                        {
                            storedFirstRoommate = "none";
                        }
                        else
                            storedSecondRoommate = "none";
                        int so = stoi(storedOccupied);
                        if (so > 0)
                            --so;
                        storedOccupied = to_string(so);

                        tempRoomFile << storedRoomId << " " << storedNationalID << " " << storedLocation << " " << storedHasBathroom << " " << storedHasBalcony << " " << storedCost
                                     << " " << storedOccupied << " " << storedRating << " " << storedFirstRoommate << " " << storedSecondRoommate << endl;
                    }
                    if (found)
                        tempRoomFile << line << endl;
                }
            }
        }
        ifstream tFile("tempRooms.txt");
        ofstream rFile("rooms.txt", ios::trunc);
        if (rFile.is_open() && tFile.is_open())
        {
            string line;
            while (getline(tFile, line))
            {
                rFile << line << endl;
            }
        }
        roomFile.close();
        tempRoomFile.close();

        ifstream tenantFile("tenants.txt");
        ofstream tempTenantFile("tempTenant.txt", ios::trunc);
        if (tenantFile.is_open() && tempTenantFile.is_open())
        {
            string line;
            while (getline(tenantFile, line))
            {
                bool found = true;
                istringstream iss(line);
                string storedFName, storedSName, storedNationalID, storedPassword, storedContactDetails,
                    storedRoomId, storedRating;
                if (iss >> storedNationalID >> storedPassword >> storedFName >> storedSName >> storedContactDetails >> storedRoomId >> storedRating)
                {
                    if (storedNationalID == tenantID)
                    {
                        found = false;
                        tempTenantFile << storedNationalID << " " << storedPassword << " " << storedFName << " " << storedSName << " " << storedContactDetails << " "
                                       << "none"
                                       << " " << storedRating << endl;
                    }
                }
                if (found)
                    tempTenantFile << line << endl;
            }
        }
        ifstream tTenantFile("tempTenant.txt");
        ofstream mainTenantFile("tenants.txt", ios::trunc);
        if (mainTenantFile.is_open() && tTenantFile.is_open())
        {
            string line;
            while (getline(tTenantFile, line))
            {
                mainTenantFile << line << endl;
            }
        }
        mainTenantFile.close();
        tTenantFile.close();
    }

    void ratingRoommate(string tenantID)
    {
        string roommate = "";
        string roomId = findRoomId(tenantID);
        if (roomId == "none")
        {
            cout << "There is no room under this tenant ID" << endl;
            return;
        }
        cout << "Give the rating to your roommate: ";
        string rating;
        cin >> rating;

        ifstream roomFile("rooms.txt");
        if (roomFile.is_open())
        {
            string line;
            while (getline(roomFile, line))
            {
                istringstream iss(line);
                string storedNationalID, storedLocation, storedHasBathroom, storedRoomId,
                    storedHasBalcony, storedCost, storedOccupied, storedRating, storedFirstRoommate, storedSecondRoommate;
                if (iss >> storedRoomId >> storedNationalID >> storedLocation >> storedHasBathroom >> storedHasBalcony >> storedCost >> storedOccupied >> storedRating >> storedFirstRoommate >> storedSecondRoommate)
                {
                    if (storedRoomId == roomId)
                    {
                        if (tenantID == storedFirstRoommate)
                        {
                            roommate = storedSecondRoommate;
                        }
                        else
                            roommate = storedFirstRoommate;
                    }
                }
            }
        }
        ifstream tenantFile("tenants.txt");
        ofstream tempTenantFile("tempTenant.txt", ios::trunc);
        if (tenantFile.is_open() && tempTenantFile.is_open())
        {
            string line;
            while (getline(tenantFile, line))
            {
                bool found = true;
                istringstream iss(line);
                string storedFName, storedSName, storedNationalID, storedPassword, storedContactDetails,
                    storedRoomId, storedRating;
                if (iss >> storedNationalID >> storedPassword >> storedFName >> storedSName >> storedContactDetails >> storedRoomId >> storedRating)
                {
                    if (storedNationalID == roommate)
                    {
                        found = false;
                        tempTenantFile << storedNationalID << " " << storedPassword << " " << storedFName << " " << storedSName << " " << storedContactDetails << " " << storedRoomId << " " << rating << endl;
                    }
                }
                if (found)
                    tempTenantFile << line << endl;
            }
        }
        ifstream tTenantFile("tempTenant.txt");
        ofstream mainTenantFile("tenants.txt", ios::trunc);
        if (mainTenantFile.is_open() && tTenantFile.is_open())
        {
            string line;
            while (getline(tTenantFile, line))
            {
                mainTenantFile << line << endl;
            }
        }
        mainTenantFile.close();
        tTenantFile.close();
    }

    void ratingRoom(string tenantID)
    {
        cout << "Give the rating to the room(out of 5): ";
        string rate;
        cin >> rate;

        string roomId = findRoomId(tenantID);
        if (roomId == "none")
        {
            cout << "There is no room under this tenant ID" << endl;
            return;
        }
        ifstream roomFile("rooms.txt");
        ofstream tempRoomFile("tempRooms.txt", ios::trunc);
        if (roomFile.is_open() && tempRoomFile.is_open())
        {
            string line;
            while (getline(roomFile, line))
            {
                bool found = true;
                istringstream iss(line);
                string storedNationalID, storedLocation, storedHasBathroom, storedRoomId,
                    storedHasBalcony, storedCost, storedOccupied, storedRating, storedFirstRoommate, storedSecondRoommate;
                if (iss >> storedRoomId >> storedNationalID >> storedLocation >> storedHasBathroom >> storedHasBalcony >> storedCost >> storedOccupied >> storedRating >> storedFirstRoommate >> storedSecondRoommate)
                {
                    if (storedRoomId == roomId)
                    {
                        found = false;
                        tempRoomFile << storedRoomId << " " << storedNationalID << " " << storedLocation << " " << storedHasBathroom << " " << storedHasBalcony << " " << storedCost
                                     << " " << storedOccupied << " " << rate << " " << storedFirstRoommate << " " << storedSecondRoommate << endl;
                    }
                    if (found)
                        tempRoomFile << line << endl;
                }
            }
        }
        ifstream tFile("tempRooms.txt");
        ofstream rFile("rooms.txt", ios::trunc);
        if (rFile.is_open() && tFile.is_open())
        {
            string line;
            while (getline(tFile, line))
            {
                rFile << line << endl;
            }
        }
        roomFile.close();
        tempRoomFile.close();
    }
};