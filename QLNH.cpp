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
    Drink(const int id, char name[20], int gia);
    void setid();
    void setname(char name[]);
    void setgia();
    int getid();
    char *getname();
    int getgia();
};
Drink::Drink(const int id, char name[20], int gia)
{
    static int id = 1;
    Drink::id = id;
    strcpy(Drink::namedrink, name);
    Drink::gia = gia;
}
/*
 * Function: setName
 * Description: Nhập tên của món ăn
 * Input:
 *      NAME - char
 * output:
 *      none
 */
void Drink::setname(char name[])
{
    strcpy(Drink::namedrink, name);
}
/*
 * Function: setPrice
 * Description: Nhập giá của món ăn
 * Input:
 *      PRICE - double
 * Output:
 *      none
 */
void Drink::setgia()
{
    Drink::gia = gia;
}
/*
 * Function: getName
 * Description: lấy tên món ăn
 * Input:
 *      none
 * Output:
 *      name of Dish
 */
char *Drink::getname()
{
    return Drink::namedrink;
}
/*
 * Function: getPrice
 * Description: lấy giá của món ăn
 * Input:
 *      none
 * output:
 *      price of dish
 */
int Drink::getgia()
{
    return this->gia;
}
/*
 * Function: getId
 * Description: lấy id của món ăn
 * Input:
 *      none
 * output:
 *      id of dish
 */
int Drink::getid()
{
    return this->id;
}
//--------------------------------------------------------------------------------------------------

class orderedDrink
{
private:
    char name[20];
    float price;
    int id;
    int quantity;

public:
    orderedDrink(const int id, const char name[], const float price, const int quantity);
    void setQuantity(const int quantity);
    int getQuantity();
    char *getNameDrink();
    float getPriceDrink();
    int getId();
};

orderedDrink::orderedDrink(const int id, const char name[], const float price, const int quantity)
{
    orderedDrink::id = id;
    orderedDrink::quantity = quantity;
    orderedDrink::price = price;
    strcpy(orderedDrink::name, name);
}

void orderedDrink::setQuantity(const int quantity)
{
    orderedDrink::quantity = quantity;
}

int orderedDrink::getQuantity()
{
    return orderedDrink::quantity;
}

char *orderedDrink::getNameDrink()
{
    return orderedDrink::name;
}

int orderedDrink::getId()
{
    return orderedDrink::id;
}

float orderedDrink::getPriceDrink()
{
    return orderedDrink::price;
}
//-----------------------------------------------------------------------------------------------
class manager
{
private:
    int id;
    int numberOfTable;
    vector<Drink> drinklist;

public:
    manager();
    void setNumberOfTable(int n);
    int getNumberOfTable();
    void addDrink();
    void updateDrink();
    void deleteDrink();
    void showList();
    void managerOptions();
    void managerAddDrink();
    void managerUpdateDrink();
    void managerDeleteDrink();

    vector<Drink> &getDrinkList() { return drinklist; }
};

void manager::setNumberOfTable(int n)
{
    manager::numberOfTable = n;
}

int manager::getNumberOfTable()
{
    return manager::numberOfTable;
}

/*
 * Function: addDrink
 * Description: hàm thêm món ăn của quản lý
 */
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
        cout << "Enter 1 to continue add dish\n  ";
        cout << "Any key to exit: ";
        cin >> k;
    } while (k == 1);
}

/*
 * Function: updateDrink
 * Description: hàm update danh sách món ăn theo id của quản lý
 */
void manager::updateDrink()
{
    int id;
    cout << "Nhap id do uong can cap nhat";
    cin >> id;
    int check = 0;
    for (int i = 0; i < drinklist.size(); i++)
    {
        Drink &drink = drinklist[i];
        {
            if (drink.getid() == id)
            {
                drinklist.erase(drinklist.begin() + i);
                manager::addDrink();
                cout << "--Ban da cap nhat thong tin  thanh cong--" << endl;
            }

            check++;
        }
    }

    if (check == 0)
        cout << "--Khong co thong tin do uong trong Data--" << endl;
}

/*
 * Function: deleteDrink
 * Description: hàm xóa danh sách món ăn theo id của quản lý
 */
void manager::deleteDrink()
{
    int id;
    cout << "Nhap id do uong can xoa";
    cin >> id;
    int check = 0;
    for (int i = 0; i < drinklist.size(); i++)
    {
        Drink &drink = drinklist[i];
        {
            if (drink.getid() == id)
            {
                drinklist.erase(drinklist.begin() + i);
                cout << "--Ban da xoa thanh cong--" << endl;
            }

            check++;
        }
    }

    if (check == 0)
        cout << "--Khong co thong tin do uong trong Data--" << endl;
}

/*
 * Function: showList
 * Description: hàm hiển thị danh sách món ăn của quản lý
 */
void manager::showList()
{
    int stt = 1;

    printf("STT     ID      Drink            Price\n");
    for (Drink Drink : drinklist)
    {
        printf("%d      %d      %s          %d\n", stt++, Drink.getid(), Drink.getname(), Drink.getgia());
    }
}

void managerFunction(manager *manager)
{
    int key;
    int quantity = 0;

    do
    {
        printf("1. Add dish\n");
        printf("2. Update dish\n");
        printf("3. Delete dish\n");
        printf("4. Show the dished list\n");
        printf("5. Set the number of tables\n");
        printf("0. Exit\n");
        printf("-------------------------------------------\n");

        do
        {

        } while (key > 5 || key < 0);

        switch (key)
        {
        case 1:
            manager->addDrink();
            break;
        case 2:
            manager->updateDrink();
            break;
        case 3:
            manager->deleteDrink();
            break;
        case 4:
            manager->showList();
            break;
        case 5:
            manager->setNumberOfTable(quantity);
            break;
        case 0:
            return;
        default:
            break;
        }
    } while (key);
}
class table
{
private:
    vector<orderedDrink> orderedList;
    vector<Drink> drinklist;
    int status = 0;
    float bill;

public:
    table(manager manager);
    void orderDrink();
    void showOrderedDrink();
    void getBill();
    bool getStatusTable();
    void updateData(manager manager);
};
table::table(manager manager)
{

}

int main()
{
}