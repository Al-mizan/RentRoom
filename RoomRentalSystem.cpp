class RoomRentalSystem
{
private:
    Admin *admin;
    Room *room;
    Owner *owner;
    Tenant *tenant;
    string tenantId = "";
    string ownerId = "";
    // RoomSorting *roomSorting;

public:
    void showMenu()
    {
        cout << '\n';
        cout << "Welcome to RentEase" << endl;
        cout << "1. Enter as an Admin" << endl;
        cout << "2. Enter as a Tenant" << endl;
        cout << "3. Enter as an Owner" << endl
             << endl;
        cout << "Enter your choice: ";
        char choice;
        cin >> choice;
        system("cls");
        switch (choice)
        {
        case '1':
            AdminLoginRegistration();
            break;
        case '2':
            TenantLoginRegistration();
            break;
        case '3':
            OwnerLoginRegistration();
            break;
        default:
            cout << "Invalid choice!\nPlease try again." << endl;
            showMenu();
            break;
        }
    }

    void AdminLoginRegistration()
    {
        cout << endl;
        cout << "====== Admin ======" << endl;
        cout << "1. Admin Registration " << endl;
        cout << "2. Admin Login " << endl;
        cout << "3. Return to main menu" << endl;
        cout << "Enter your choice: ";
        char choice;
        cin >> choice;
        system("cls");

        switch (choice)
        {
        case '1':
            cout << endl;
            cout << "====== Admin Registration ======" << endl;

            AdminRegistration();
            break;

        case '2':
            AdminLogin();
            break;

        case '3':
            showMenu();
            break;

        default:
            cout << "Invalid choice!" << endl
                 << "Try again." << endl;
            AdminLoginRegistration();
            break;
        }
    }
    void adminAfterLoginRegistration()
    {
        cout << endl;
        cout << "====== Admin ======" << endl;
        cout << "1. Owner list " << endl;
        cout << "2. Tenant list " << endl;
        cout << "3. Room list " << endl;
        cout << "4. Return to main menu" << endl;
        cout << "Enter your choice: ";
        char choice;
        cin >> choice;
        system("cls");

        switch (choice)
        {
        case '1':
            cout << endl;
            cout << "====== Owner List ======" << endl;
            OwnerList();
            adminAfterLoginRegistration();
            break;

        case '2':
            cout << endl;
            cout << "====== Tenant List ======" << endl;
            TenantList();
            adminAfterLoginRegistration();
            break;

        case '3':
            cout << endl;
            cout << "====== Room List ======" << endl;
            RoomList();
            adminAfterLoginRegistration();
            break;

        case '4':
            showMenu();
            break;

        default:
            cout << "Invalid choice!" << endl
                 << "Try again." << endl;
            adminAfterLoginRegistration();
            break;
        }
    }

    void AdminRegistration()
    {
        admin = new Admin();
        admin->Admin::FileData();
        adminAfterLoginRegistration();
    }

    void AdminLogin()
    {
        admin->Admin::login();
        adminAfterLoginRegistration();
    }

    void OwnerList()
    {
        admin->viewOwnerList();
    }

    void TenantList()
    {
        admin->viewTenantList();
    }

    void RoomList()
    {
        room->viewingAdminRoom();
    }

    ////////////////////////////////////

    void TenantLoginRegistration()
    {
        cout << endl
             << "====== Tenant ======" << endl;
        cout << "1. Tenant Registration " << endl;
        cout << "2. Tenant Login " << endl;
        cout << "3. Return to main menu" << endl;
        cout << "Enter your choice: ";
        char choice;
        cin >> choice;
        system("cls");

        switch (choice)
        {
        case '1':
            cout << endl;
            cout
                << "====== Tenant Registration ======" << endl;
            TenantRegistration();
            break;
        case '2':
            cout << endl;
            cout
                << "====== Tenant Login ======" << endl;
            TenantLogin();
            break;
        case '3':
            showMenu();
            break;
        default:
            cout << "Invalid choice." << endl
                 << "Please try again." << endl;
            TenantLoginRegistration();
            break;
        }
    }

    void tenantAfterLoginRegistration()
    {
        cout << endl;
        cout
            << "====== Tenant ======" << endl;
        cout << "1. Room searching " << endl;
        cout << "2. Room leaving " << endl;
        cout << "3. Roommate rating " << endl;
        cout << "4. Room rating " << endl;
        cout << "5. Return to main menu" << endl;
        cout << "\nEnter your choice: ";
        char choice;
        cin >> choice;
        system("cls");

        switch (choice)
        {
        case '1':
            roomSearching();
            tenantAfterLoginRegistration();
            break;

        case '2':
            roomLeaving();
            tenantAfterLoginRegistration();
            break;

        case '3':
            roommateRating();
            tenantAfterLoginRegistration();
            break;

        case '4':
            roomRating();
            tenantAfterLoginRegistration();
            break;

        case '5':
            showMenu();
            break;

        default:
            cout << "Invalid choice!" << endl
                 << "Try again." << endl;
            tenantAfterLoginRegistration();
            break;
        }
    }
    void TenantRegistration()
    {
        tenant = new Tenant;
        tenant->Tenant::FileData();
        tenantId = tenant->getTenantIdRegistration();
        tenantAfterLoginRegistration();
    }

    void TenantLogin()
    {
        tenantId = tenant->Tenant::tenantLogin();
        if (tenantId != "none")
        {
            tenantAfterLoginRegistration();
        }
        else
        {
            TenantLogin();
        }
    }

    void roomSearching()
    {
        cout << "--- Room Searching ---\n\n";
        cout << "1. Without sorting " << endl;
        cout << "2. Sorting by Location " << endl;
        cout << "3. Sorting by Cost" << endl;
        cout << "4. Sorting by 1 roommate" << endl;
        cout << "5. Return to main menu" << endl;
        cout << "Enter your choice: ";
        char choice;
        cin >> choice;
        system("cls");

        switch (choice)
        {
        case '1':
            withoutSorting();
            roomSearching();
            break;
        case '2':
            sortingByLocation();
            roomSearching();
            break;
        case '3':
            sortingByCost();
            roomSearching();
            break;
        case '4':
            sortingBy1Roommate();
            roomSearching();
            break;
        case '5':
            showMenu();
            break;
        default:
            cout << "Invalid choice." << endl
                 << "Please try again." << endl;
            roomSearching();
            break;
        }
    }

    void withoutSorting()
    {
        searchRoom();
        withoutSortingRoom(tenantId);
    }
    void sortingByLocation()
    {
        searchRoom();
        sortingByLocationRoom(tenantId);
    }
    void sortingByCost()
    {
        searchRoom();
        sortingByCostRoom(tenantId);
    }
    void sortingBy1Roommate()
    {
        searchRoom();
        sortingBy1RoommatesRoom(tenantId);
    }

    void roomLeaving()
    {
        tenant->leavingRoom(tenantId);
    }
    void roommateRating()
    {
        tenant->ratingRoommate(tenantId);
    }
    void roomRating()
    {
        tenant->ratingRoom(tenantId);
    }

    ////////////////////////////////////////////////////////////////
    void OwnerLoginRegistration()
    {
        cout << endl;
        cout
            << "====== Owner ======" << endl;
        cout << "1. Owner Registration " << endl;
        cout << "2. Owner Login " << endl;
        cout << "3. Return to main menu " << endl;
        cout << "Enter your choice: ";
        char choice;
        cin >> choice;
        system("cls");

        switch (choice)
        {
        case '1':
            cout << endl;
            cout
                << "====== Owner Registration ======" << endl;
            ownerRegistration();
            OwnerLoginRegistration();
            break;

        case '2':
            ownerLogin();
            OwnerLoginRegistration();
            break;

        case '3':
            showMenu();
            break;

        default:
            cout << "Invalid choice!" << endl
                 << "Please try again." << endl;
            ;
            OwnerLoginRegistration();
            break;
        }
    }

    void ownerAfterLoginRegistration()
    {
        cout << endl;
        cout
            << "====== Owner ======" << endl;
        cout << "1. Add Room " << endl;
        cout << "2. View room " << endl;
        cout << "3. Return to main menu" << endl;
        cout << "Enter your choice: ";
        char choice;
        cin >> choice;
        system("cls");

        switch (choice)
        {
        case '1':
            addRoom();
            ownerAfterLoginRegistration();
            break;

        case '2':
            cout << endl
                 << "====== Rooms ======" << endl;
            viewRoom();
            ownerAfterLoginRegistration();
            break;

        case '3':
            showMenu();
            break;

        default:
            cout << "Invalid choice!" << endl
                 << "Try again." << endl;
            ownerAfterLoginRegistration();
            break;
        }
    }

    void ownerRegistration()
    {
        owner = new Owner;
        owner->Owner::FileData();
        ownerId = owner->getOwnerIdRegistration();
        ownerAfterLoginRegistration();
    }

    void ownerLogin()
    {
        ownerId = owner->Owner::login();
        if (ownerId != "none")
            ownerAfterLoginRegistration();
        else
            ownerLogin();
    }

    void addRoom()
    {
        room = new Room;
        room->Room::roomFileData(ownerId);
    }

    void viewRoom()
    {
        room->Room::viewingOwnerRoom(ownerId);
    }
};