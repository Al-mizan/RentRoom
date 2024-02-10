class Sorting
{
    string location, hasBathroom, roomId, ownerId,
        hasBalcony, cost, roommates, rating, FirstRoommate, SecondRoommate;

public:
    Sorting() {}
    Sorting(string &_roomId, string &_ownerId, string &_location, string &_hasBathroom, string &_hasBalcony,
            string &_cost, string &_roommates, string &_rating, string &_firstRoommate, string &_secondRoommate)
    {
        roomId = _roomId;
        ownerId = _ownerId;
        location = _location;
        hasBathroom = _hasBathroom;
        hasBalcony = _hasBalcony;
        cost = _cost;
        roommates = _roommates;
        rating = _rating;
        FirstRoommate = _firstRoommate;
        SecondRoommate = _secondRoommate;
    }

    string getRoomId() const { return roomId; }
    string getOwnerId() const { return ownerId; }
    string getLocation() const { return location; }
    string getHasBathroom() const { return hasBathroom; }
    string getHasBalcony() const { return hasBalcony; }
    string getCost() const { return cost; }
    string getRoommates() const { return roommates; }
    string getRating() const { return rating; }
    string getFirstRoommate() const { return FirstRoommate; }
    string getSecondRoommate() const { return SecondRoommate; }
};

// class RoomSorting : public Sorting
// {
vector<Sorting> sortingRoom;
vector<pair<int, int>> vp;

// public:
// ~RoomSorting()
// {
//     // Clean up allocated memory
//     sortingRoom.clear();
// }

void searchRoom()
{
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
                Sorting room(storedRoomId, storedNationalID, storedLocation, storedHasBathroom,
                             storedHasBalcony, storedCost, storedOccupied, storedRating, storedFirstRoommate, storedSecondRoommate);
                sortingRoom.push_back(room);
            }
        }
    }
}

void select(string tenantId)
{
    cout << "\nSelect the Room by the serial number otherwise enter 'n': ";
    string number2;
    int number1;
    cin >> number2;
    if (number2 == "n")
    {
        return;
    }
    else
        number1 = stoi(number2);

    if (number1 < 1 || number1 > vp.size())
    {
        cout << "Invalid selection.\n";
        select(tenantId);
    }
    ofstream roomFile1("rooms.txt", ios::trunc);
    if (roomFile1.is_open())
    {
        int k = -1, f = 1;
        for (auto &it : vp)
        {
            k++;
            if (it.first == number1 && f == 1)
            {
                f = 0;
                cout << sortingRoom[it.second].getRoomId() << " room ID has been selected.\n";
                cout << "Welcome to the room!\n";
                int roommate = stoi(sortingRoom[k].getRoommates());
                string first = sortingRoom[k].getFirstRoommate();
                string second = sortingRoom[k].getSecondRoommate();
                if (first == "none")
                {
                    first = tenantId;
                }
                else
                    second = tenantId;

                roomFile1 << sortingRoom[k].getRoomId() << " " << sortingRoom[k].getOwnerId() << " " << sortingRoom[k].getLocation() << " " << sortingRoom[k].getHasBathroom() << " " << sortingRoom[k].getHasBalcony() << " " << sortingRoom[k].getCost() << " "
                          << to_string(++roommate) << " " << sortingRoom[k].getRating() << " " << first << " " << second << "\n";
                continue;
            }
            roomFile1 << sortingRoom[k].getRoomId() << " " << sortingRoom[k].getOwnerId() << " " << sortingRoom[k].getLocation() << " " << sortingRoom[k].getHasBathroom() << " " << sortingRoom[k].getHasBalcony() << " " << sortingRoom[k].getCost()
                      << " " << sortingRoom[k].getRoommates() << " " << sortingRoom[k].getRating() << " " << sortingRoom[k].getFirstRoommate() << " " << sortingRoom[k].getSecondRoommate() << "\n";
        }
    }
    vp.clear();
    sortingRoom.clear();
}
void withoutSortingRoom(string tenantId)
{
    cout << "\n===== Rooms =====\n"
         << endl;
    int cnt = 0, count = 0;
    for (auto &it : sortingRoom)
    {
        if (it.getRoommates() != "2")
        {
            cout << ++cnt << "." << endl;
            cout << ' ' << "Room ID: " << it.getRoomId() << endl;
            cout << ' ' << "Location: " << it.getLocation() << endl;
            cout << ' ' << "HasBathroom: " << it.getHasBathroom() << endl;
            cout << ' ' << "HasBalcony: " << it.getHasBalcony() << endl;
            cout << ' ' << "Cost: " << it.getCost() << " taka" << endl;
            cout << ' ' << "Number of tenants: " << it.getRoommates() << endl;
            cout << ' ' << "Room rating: " << it.getRating() << endl;
        }
        vp.push_back({cnt, count++});
        if (cnt % 5 == 0 && cnt != 0)
        {
            cout << "\nPress 'y' for more and press 'n' to exit: ";
            string ch;
            cin >> ch;
            if (ch == "n")
                break;
        }
    }
    if (cnt == 0)
        cout << "There is no available room!\n";
    else
        select(tenantId);
}

void sortingByLocationRoom(string tenantId)
{
    string searchingLocation;
    cout << "Enter the location: ";
    cin >> searchingLocation;
    cout << endl
         << "====== Rooms ======" << endl;
    int cnt = 0, count = 0;
    for (auto &it : sortingRoom)
    {
        if (it.getLocation() == searchingLocation && it.getRoommates() != "2")
        {
            cout << ++cnt << "." << endl;
            cout << ' ' << "Room ID: " << it.getRoomId() << endl;
            cout << ' ' << "Location: " << it.getLocation() << endl;
            cout << ' ' << "HasBathroom: " << it.getHasBathroom() << endl;
            cout << ' ' << "HasBalcony: " << it.getHasBalcony() << endl;
            cout << ' ' << "Cost: " << it.getCost() << " taka" << endl;
            cout << ' ' << "Number of tenants: " << it.getRoommates() << endl;
            cout << ' ' << "Room rating: " << it.getRating() << endl;
        }
        vp.push_back({cnt, count++});
        if (cnt % 5 == 0 && cnt != 0)
        {
            cout << "\nPress 'y' for more and press 'n' to exit: ";
            string ch;
            cin >> ch;
            if (ch == "n")
                break;
        }
    }
    if (cnt == 0)
        cout << "There is no available room!\n";
    else
        select(tenantId);
}

void sortingByCostRoom(string tenantId)
{
    sort(sortingRoom.begin(), sortingRoom.end(), [](const Sorting &a, const Sorting &b)
         { return a.getCost() < b.getCost(); });
    withoutSortingRoom(tenantId);
}

void sortingBy1RoommatesRoom(string tenantId)
{
    cout << "------ Rooms ------\n"
         << endl;
    int cnt = 0, count = 0;
    for (auto &it : sortingRoom)
    {
        if (it.getRoommates() == "1")
        {
            cout << ++cnt << "." << endl;
            cout << ' ' << "Room ID: " << it.getRoomId() << endl;
            cout << ' ' << "Location: " << it.getLocation() << endl;
            cout << ' ' << "HasBathroom: " << it.getHasBathroom() << endl;
            cout << ' ' << "HasBalcony: " << it.getHasBalcony() << endl;
            cout << ' ' << "Cost: " << it.getCost() << " taka" << endl;
            cout << ' ' << "Number of tenants: " << it.getRoommates() << endl;
            cout << ' ' << "Room rating: " << it.getRating() << endl;
        }
        vp.push_back({cnt, count++});
        if (cnt % 5 == 0 && cnt != 0)
        {
            cout << "\nPress 'y' for more and press 'n' to exit: ";
            string ch;
            cin >> ch;
            if (ch == "n")
                break;
        }
    }
    if (cnt == 0)
        cout << "There is no available room!\n";
    else
        select(tenantId);
}