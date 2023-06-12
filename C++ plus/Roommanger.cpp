#include <iostream>
#include <vector>
#include <string.h>
#include <stdint.h>
using namespace std;

#define INPUT_TYPE(text, var, check) \
    do                               \
    {                                \
        cout << text;                \
        cin >> var;                  \
    } while (check)

class Room
{
private:
    int roomnumber;
    bool booked;
    bool cleaning;

public:
    Room(int number)
    {
        roomnumber = number;
        booked = false;
        cleaning = true;
    }
    int getroomnumber()
    {
        return this->roomnumber;
    }
    bool isAvailable()
    {
        return !booked && cleaning;
    }
    void checkin()
    {
        booked = true;
        cleaning = false;
    }
    void checkout()
    {
        booked = false;
        cleaning = true;
    }
    void bookroom()
    {
        this->booked = true;
    }
};
class Manageroom
{
private:
    vector<Room> dataroom;
    void displayavailableroom();
    void bookroom(int number);
    void checkin(int number);
    void checkout(int number);

public:
   // vector<Room> &getdataroom();
    Manageroom();
    void add_Room();
};
Manageroom::Manageroom()
{
    int roomNo;
    while (1)
    {

        cout << "--------------Mangeroom--------------";

        cout << "\n1. Display avaible room";
        cout << "\n2.Book room";
        cout << "\n3. check in";
        cout << "\n4. check out";
        cout << "\n5. them phong";
        cout << "\n6. -------------exit--------------";
        cout << "\nMoi nhap lua chon cua bn";
        int number;
        cin >> number;
        switch (number)
        {
        case 1:

            Manageroom::displayavailableroom();
            break;
        case 2:

            cout << "Enter the room number: ";
            cin >> roomNo;
            Manageroom::bookroom(roomNo);
            break;
        case 3:

            cout << "Enter the room number: ";
            cin >> roomNo;
            Manageroom::checkin(roomNo);
            break;
        case 4:

            cout << "Enter the room number: ";
            cin >> roomNo;
            Manageroom::checkout(roomNo);
            break;
        case 5:
            Manageroom::add_Room();
            
            break;
        case 6:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}
void Manageroom::add_Room()
{
    int quantity;
    int number_Room;
    static int i_cout = 1;
    INPUT_TYPE("nhap so luong phong: ", quantity, quantity <= 0);
    for (int i = 0; i < quantity; i++)
    {
        Room room(i_cout);
        dataroom.push_back(room);
        i_cout++;
    }
}
void Manageroom::displayavailableroom()
{
    string _available;
    cout << "----------Danh sach phong------ " << endl;
    for (Room room : dataroom)
    {
        if (room.isAvailable())
        {
            _available = "san sang";
        }
        else
        {
            _available = "chua san sang";
        }

        cout << room.getroomnumber() << _available << endl;
    }
}

void Manageroom::bookroom(int number)
{
    int check = 0;
    for (int i = 0; i < dataroom.size(); i++)
    {
        if (dataroom[i].getroomnumber() == number)
        {
            check = 1;
            dataroom[i].bookroom();
            cout << "da dat" << number << endl;
        }
    }
    if (check == 0)
    {
        cout << "khong co phong ban tim" << endl;
    }
}
void Manageroom::checkin(int number)
{
    int check = 0;
    for (int i = 0; i < dataroom.size(); i++)
    {
        if (dataroom[i].getroomnumber() == number)
        {
            check = 1;
            dataroom[i].checkin();
            cout << "da checkin" << number << endl;
        }
    }
    if (check == 0)
    {
        cout << "khong co phong ban tim" << endl;
    }
}
void Manageroom::checkout(int number)
{
    int check = 0;
    for (int i = 0; i < dataroom.size(); i++)
    {
        if (dataroom[i].getroomnumber() == number)
        {
            check = 1;
            dataroom[i].checkout();
            cout << "da checkin" << number << endl;
        }
    }
    if (check == 0)
    {
        cout << "khong co phong ban tim" << endl;
    }
}
int main()
{
    Manageroom *manageroom;
    manageroom = new Manageroom();
}
