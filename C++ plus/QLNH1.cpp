#include <stdio.h>
#include <string.h>
#include <string>
#include <stdint.h>
#include <vector>
#include <iostream>
using namespace std;

class Drink
{
private:
    int id;
    char namedrink[20];
    int gia;

public:
    Drink(int id, const char name[20], int gia);
    void setid(int id);
    void setname(const char name[]);
    void setgia(int gia);
    int getid();
    const char *getname();
    int getgia();
};

Drink::Drink(int id, const char name[20], int gia)
{
    this->id = id;
    strcpy(this->namedrink, name);
    this->gia = gia;
}

void Drink::setid(int id)
{
    this->id = id;
}

void Drink::setname(const char name[])
{
    strcpy(this->namedrink, name);
}

void Drink::setgia(int gia)
{
    this->gia = gia;
}

int Drink::getid()
{
    return this->id;
}

const char *Drink::getname()
{
    return this->namedrink;
}

int Drink::getgia()
{
    return this->gia;
}

//--------------------------------------------------------------------------------------------------

typedef struct
{
    uint8_t id;
    char name[20];
    double price;
    uint8_t amount;
} orderedDishList;

//-----------------------------------------------------------------------------------------------

class manager
{
private:
    int id;
    int numberOfTable;
    vector<Drink> drinklist;

public:
    manager();
    void addDrink();
    void updateDrink();
    void deleteDrink();
    void showList();
    void managerFunction(manager *manager);
    vector<Drink> &getDrinkList()
    {
        return drinklist;
    }
};

manager::manager()
{
    id = 1;
}

void manager::addDrink()
{
    int k;
     char namedrink[20];
    int gia;
    do
    {
        cout << "Moi nhap ten do uong:  ";
        cin >> namedrink;

        cout << "Moi nhap gia do uong:  ";
        cin >> gia;
          
        Drink drink(id++, namedrink, gia);
        drinklist.push_back(drink);
        cout << "Enter 1 to continue add dish\nAny key to exit: ";
        cin >> k;
    } while (k == 1);
}

void manager::updateDrink()
{
    int id;
    cout << "Nhap id do uong can cap nhat: ";
    cin >> id;
    int check = 0;
    for (int i = 0; i < drinklist.size(); i++)
    {
        Drink &drink = drinklist[i];
        if (drink.getid() == id)
        {
            drinklist.erase(drinklist.begin() + i);
            manager::addDrink();
            cout << "--Ban da cap nhat thong tin thanh cong--" << endl;
            check++;
            break;
        }
    }

    if (check == 0)
        cout << "--Khong co thong tin do uong trong Data--" << endl;
}

void manager::deleteDrink()
{
    int id;
    cout << "Nhap id do uong can xoa: ";
    cin >> id;
    int check = 0;
    for (int i = 0; i < drinklist.size(); i++)
    {
        Drink &drink = drinklist[i];
        if (drink.getid() == id)
        {
            drinklist.erase(drinklist.begin() + i);
            cout << "--Ban da xoa thanh cong--" << endl;
            check++;
            break;
        }
    }

    if (check == 0)
        cout << "--Khong co thong tin do uong trong Data--" << endl;
}

void manager::showList()
{
    int stt = 1;

    printf("STT     ID      Drink            Price\n");
    for (Drink drink : drinklist)
    {
        printf("%d      %d      %s          %d\n", stt++, drink.getid(), drink.getname(), drink.getgia());
    }
}

int main()
{
    manager mn;
    int key;

    do
    {
        printf("1. Add dish\n");
        printf("2. Update dish\n");
        printf("3. Delete dish\n");
        printf("4. Show the dished list\n");
        printf("0. Exit\n");
        printf("-------------------------------------------\n");

        cin >> key;

        switch (key)
        {
        case 1:
            mn.addDrink();
            break;
        case 2:
            mn.updateDrink();
            break;
        case 3:
            mn.deleteDrink();
            break;
        case 4:
            mn.showList();
            break;
        case 0:
            return 0;
        default:
            cout << "Invalid option. Please try again." << endl;
            break;
        }
    } while (key != 0);

    return 0;
}
