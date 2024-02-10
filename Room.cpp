class Room
{
private:
    Owner *owner;
    string location;
    string hasBathroom;
    string hasBalcony;
    string cost;
    string roomId;

protected:
    string occupied = "0";
    string roomRating = "0";
    string firstRoommate = "none";
    string secondRoommate = "none";

public:
    void roomData()
    {
        cout << endl;
        cout
            << "====== Room Registration ======" << endl;
        cout << "Enter the location of the room: ";
        cin >> location;
        cout << "Does the room have bathroom? : ";
        cin >> hasBathroom;
        cout << "Does the room haveBalcony? : ";
        cin >> hasBalcony;
        cout << "Enter the cost of the room: ";
        cin >> cost;
    }
    Room()
    {
        roomData();
    }
    void roomFileData(string ownerID)
    {
        int count = 0;
        ifstream roomFile("rooms.txt");
        if (roomFile.is_open())
        {
            string line;
            while (getline(roomFile, line))
            {
                istringstream iss(line);
                string storedNationalID, storedLocation, storedHasBathroom, storedRoomId, storedFirstRoommate,
                    storedSecondRoommate, storedHasBalcony, storedCost, storedOccupied, storedRating, storedReview;
                if (iss >> storedRoomId >> storedNationalID >> storedLocation >> storedHasBathroom >> storedHasBalcony >>
                    storedCost >> storedOccupied >> storedRating >> storedFirstRoommate >> storedSecondRoommate)
                {
                    if (storedNationalID == ownerID)
                    {
                        count++;
                    }
                }
            }
        }
        roomId = ownerID + to_string(count);
        ofstream roomFile1("rooms.txt", ios::app);
        if (roomFile1.is_open())
        {
            roomFile1 << roomId << " " << ownerID << " " << location << " " << hasBathroom << " " << hasBalcony << " "
                      << cost << " " << occupied << " " << roomRating << " " << firstRoommate << " " << secondRoommate << endl;
            roomFile1.close();
            cout << "Room registration successful!" << endl;
        }
    }

    void viewingAdminRoom()
    {
        ifstream roomFile("rooms.txt");
        if (roomFile.is_open())
        {
            string line;
            int count = 1;
            while (getline(roomFile, line))
            {
                istringstream iss(line);
                string storedNationalID, storedLocation, storedHasBathroom, storedRoomId,
                    storedHasBalcony, storedCost, storedOccupied, storedRating, storedFirstRoommate, storedSecondRoommate;
                if (iss >> storedRoomId >> storedNationalID >> storedLocation >> storedHasBathroom >> storedHasBalcony >> storedCost >> storedOccupied >> storedRating >> storedFirstRoommate >> storedSecondRoommate)
                {
                    cout << endl
                         << count << '.' << endl;
                    cout << " Owner ID: " << storedNationalID << endl;
                    cout << " Location: " << storedLocation << endl;
                    cout << " HasBathroom: " << storedHasBathroom << endl;
                    cout << " HasBalcony: " << storedHasBalcony << endl;
                    cout << " Cost: " << storedCost << " taka" << endl;
                    cout << " Number of tenants: " << storedOccupied << endl;
                    cout << " Room Rating: " << storedRating << endl;
                }
                if (count % 5 == 0)
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
    void viewingOwnerRoom(string ownerID) // under Owner class
    {
        ifstream roomFile("rooms.txt");
        if (roomFile.is_open())
        {
            string line;
            int count = 1;
            while (getline(roomFile, line))
            {
                istringstream iss(line);
                string storedNationalID, storedLocation, storedHasBathroom, storedRoomId,
                    storedHasBalcony, storedCost, storedOccupied, storedRating, storedFirstRoommate, storedSecondRoommate;
                if (iss >> storedRoomId >> storedNationalID >> storedLocation >> storedHasBathroom >> storedHasBalcony >> storedCost >>
                    storedOccupied >> storedRating >> storedFirstRoommate >> storedSecondRoommate)
                {
                    if (storedNationalID == ownerID)
                    {
                        cout << endl
                             << count++ << '.' << endl;
                        cout << " Location: " << storedLocation << endl;
                        cout << " HasBathroom: " << storedHasBathroom << endl;
                        cout << " HasBalcony: " << storedHasBalcony << endl;
                        cout << " Cost: " << storedCost << " taka" << endl;
                        cout << " Number of tenants: " << storedOccupied << endl;
                        cout << " Room Rating: " << storedRating << endl;
                    }
                }
                if (count % 5 == 0)
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
            }
        }
    }
};