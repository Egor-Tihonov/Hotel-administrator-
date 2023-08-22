#include <iostream>
#include <map>

using namespace std;

class Hotel
{
    map<long, string> xy;

public:
    void init()
    {
        xy = {{1, "busy"}, {2, "free"}, {3, "free"}, {4, "busy"}};
    }

    void get_status_of_room(int a)
    {
        if (xy.count(a) == 1)
        {
            cout << "Status of room: " << xy[a] << "\n"
                 << "\n";
        }
        else
        {
            cout << "Room doesnt exist"
                 << "\n"
                 << "\n";
        }
    }

    void add_room()
    {
        int new_room = xy.size() + 1;
        xy[new_room] = "free";
        cout << "Room was successfully added"
             << "\n"
             << "\n";
    }

    void to_book_room(int a)
    {
        if (xy[a] == "free")
        {
            xy[a] = "booked";
            cout << "Room was successfully booked"
                 << "\n\n";
        }
        else
        {
            cout << "Now we cannot provide this number\n\n";
        }
    }

    void to_check_in(int a)
    {
        if (xy[a] == "free")
        {
            cout << "Here your keys!\n\n";
        }
        else
        {
            cout << "Now we cannot provide this number\n\n";
        }
    }

    void move_out_of_the_room(int a)
    {
        xy[a] = "free";
        cout << "Room was successfully released"
             << "\n\n";
    }
};

int main()
{
    Hotel MyHotel;
    MyHotel.init();
    int e, a, b;
    do
    {
        cout << "What do you want?"
             << "\n"
             << "1. Room..."
             << "\n"
             << "2. Add new room"
             << "\n"
             << "For exit press 0"
             << "\n";
        cin >> e;
        switch (e)
        {
        case 1:
            cout << "What do you want?"
                 << "\n"
                 << "1. ...to book"
                 << "\n"
                 << "2. ...to leave"
                 << "\n"
                 << "3. ...to check-in"
                 << "\n"
                 << "4. Check status"
                 << "\n"
                 << "For back press 5"
                 << "\n"
                 << "For exit from app press 0"
                 << "\n";
            cin >> b;

            switch (b)
            {
            case 1:
                cout << "What room do you want to book?\n";
                cin >> a;
                MyHotel.to_book_room(a);
                break;
            case 2:
                cout << "In what room do you live?\n";
                cin >> a;
                MyHotel.move_out_of_the_room(a);
                break;
                break;
            case 3:
                cout << "What room do you want to check-in?\n";
                cin >> a;
                MyHotel.to_check_in(a);
                break;
            case 4:
                cout << "Get info about room number: ";
                cin >> a;
                MyHotel.get_status_of_room(a);
                break;
            case 5:
                break;
            default:
                e = 0;
                break;
            }
            break;
        case 2:
            MyHotel.add_room();
            break;
        default:
            e = 0;
        }

    } while (e != 0);

    return 0;
}