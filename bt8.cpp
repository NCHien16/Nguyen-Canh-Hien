#include <stdio.h>
#include <math.h>
#include <string.h>
class Bank
{
private:
   int STK;
   int Sodu;
   char NameTK[20];
public:
    Bank(const char* nametk, int stk, int sodu);
    int getsodu();
    void Naptien(int sotiennap);
    void Ruttien(int sotienrut);
};

Bank::Bank(const char*nametk, int stk, int sodu)
{
    strcpy( Bank::NameTK, nametk);
    Bank::STK = stk;
    Bank::Sodu = sodu;
}    
void Bank::Naptien(int sotiennap)
{
    printf(" Ban da nap vao so tien : %d\n", sotiennap);
    Bank::Sodu += sotiennap;
    printf("So du trong tai khoan hien tai cua ban la: %d\n", Bank::Sodu);
}
void Bank::Ruttien(int sotienrut)
{
    if( Bank::Sodu < sotienrut)
    {
        printf("tai khoan cua ban khong du de thuc hien giao dich\n");
    }
    else 
    {
        /* code */
        printf(" Ban da rut  so tien : %d\n", sotienrut); 
        Bank::Sodu -= sotienrut;
        printf("So tien con lai trong tai khoan cua ban la: %d\n", Bank::Sodu);
    }
    
}
int main()
{
    Bank *setData;
    setData = new Bank("Hien", 123456, 100000);
    setData->Naptien(5000);
    setData->Ruttien(10000);
    setData->Ruttien(11000);
    return 0;
}
