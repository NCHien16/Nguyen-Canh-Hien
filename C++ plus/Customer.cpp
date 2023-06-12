#include <iostream>
#include <vector>
#include <string.h>
#include <stdint.h>
#include <time.h>
using namespace std;
#define INPUT_TYPE(text, var, check) \
    do                               \
    {                                \
        cout << text;                \
        cin >> var;                  \
    } while (check)

typedef struct
{
    uint8_t day;
    uint8_t month;
    uint8_t year;
} Type_Date;

typedef struct
{
    uint8_t second;
    uint8_t minute;
    uint8_t hour;
} Type_Time;

typedef enum
{
    IN,
    ON
} Type_Status;

typedef struct
{
    Type_Date date;
    Type_Time time;
    Type_Status status;
} booking_History;

class Customer
{
private:
    vector<booking_History> History_Detail;
    int16_t ID_ROOM;
    string NAME;
    string ADDRESS;

public:
    Customer(string name, string address);
    void setName(string name);
    string getName();
    void setAddress(string address);
    string getAddress();
    int16_t get_Id_Room();
    void add_Hitory_Detail(booking_History history_Detail);
    vector<booking_History> get_Hitory_Detail();
};

Customer::Customer(string name, string address)
{
    static int idroom = 10;
    this->NAME = name;
    this->ADDRESS = address;
    this->ID_ROOM = idroom;
    idroom++;
}
void Customer::setName(string name)
{
    this->NAME = name;
}
string Customer::getName()
{
    return this->NAME;
}
void Customer::setAddress(string address)
{
    this->ADDRESS = address;
}
string Customer::getAddress()
{
    return this->ADDRESS;
}
int16_t Customer::get_Id_Room()
{
    this->ID_ROOM;
}
void Customer::add_Hitory_Detail(booking_History history_Detail)
{
    this->History_Detail.push_back(history_Detail);
}
vector<booking_History> Customer::get_Hitory_Detail()
{
    return this->History_Detail;
}
class CustomManager
{
private:
    vector<Customer> Datacustomer;

public:
    CustomManager();
    void addCutomer();
    void editCustomer();
    void deleteCustomer();
    void displayCustomerInfo();
    void checkEntry();
};
CustomManager::CustomManager()
{
    while (1)
    {
        cout << "--------------CustomManager--------------";

        cout << "\n1. ADD CUSTOMER";
        cout << "\n2.EDIT CUSTOMER";
        cout << "\n3.DELETE CUSTOMER";
        cout << "\n4.DISPLAY CUSTOMER";
        cout << "\n5. CHECK ENTRY";
        cout << "\n6. -------------exit--------------";
        cout << "\nMoi nhap lua chon cua bn: ";
        int number;
        cin >> number;

        switch (number)
        {
        case 1:
            CustomManager::addCutomer();
            break;
        case 2:
            CustomManager::editCustomer();

            break;
        case 3:
            CustomManager::deleteCustomer();

            break;
        case 4:

            CustomManager::displayCustomerInfo();

            break;
        case 5:
            CustomManager::checkEntry();
            break;
        case 6:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}
void CustomManager::addCutomer()
{
    int k;
    string name;
    string address;
    do
    {
        cout << "them thong tin khach hang" << endl;
        INPUT_TYPE("nhap ten: ", name, 0);
        INPUT_TYPE("nhap dia chi: ", address, 0);
        Customer customer(name, address);
        Datacustomer.push_back(customer);
        cout << "Enter 1 to continue add dish\n  ";
        cout << "Any key to exit: ";
        cin >> k;
    } while (k == 1);
}
void CustomManager::displayCustomerInfo()
{
    int stt = 1;

    printf("STT     ID     NAME            Address\n");
    for (Customer customer : Datacustomer)
    {
        printf("%d      %d      %s          %s\n", stt++, customer.get_Id_Room(), customer.getName(), customer.getAddress());
    }
}
void CustomManager::deleteCustomer()
{
    int id;
    cout << "Nhap id khach hang can xoa";
    cin >> id;
    int check = 0;
    for (int i = 0; i < Datacustomer.size(); i++)
    {
        Customer &customer = Datacustomer[i];
        {
            if (customer.get_Id_Room() == id)
            {
                Datacustomer.erase(Datacustomer.begin() + i);
                cout << "--Ban da xoa thanh cong--" << endl;
            }

            check++;
        }
    }

    if (check == 0)
        cout << "--Khong co thong tin trong Data--" << endl;
}
void CustomManager::editCustomer()
{
}
void CustomManager::checkEntry()
{
    uint8_t status = 0;
    booking_History history;
    int16_t id_Room;
    time_t current;
    time(&current);
    tm *timeCurrent = localtime(&current);
    history.time.second = timeCurrent->tm_sec;
    history.time.minute = timeCurrent->tm_min;
    history.time.hour = timeCurrent->tm_hour;
    history.date.day = timeCurrent->tm_mday;
    history.date.month = timeCurrent->tm_mon;
    history.date.year = timeCurrent->tm_year + 1900;
    INPUT_TYPE("nhap so phong: ", id_Room, 1);
    for (int i = 0; i < Datacustomer.size(); i++)
    {
        if (Datacustomer[i].get_Id_Room() == id_Room)
        {
            if (Datacustomer[i].get_Hitory_Detail().empty())
                history.status = IN;
            else
            {
                if (Datacustomer[i].get_Hitory_Detail().back().status == IN)
                    history.status = IN;
                else
                    history.status = ON;
            }

            Datacustomer[i].add_Hitory_Detail(history);
            status = 1;
            break;
        }
    }
    if (status == 0)
        cout << "khong tim so phong" << endl;
}
int main()
{
    CustomManager *manageroom;
    manageroom = new CustomManager();
}