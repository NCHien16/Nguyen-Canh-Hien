#include <stdio.h>
#include <math.h>

class Number
{
private:
    /* data */
    int Tuso;
    int Mauso;
public:
    Number( int tuso = 0  , int mauso = 1  );
    int gettu();
    int getmau();
    float setphanso();

};
Number::Number(int tu, int mau)
{
    if(mau == 0 )
    {
        printf("Error moi nhap lai mau so");
        return;
    }
    Number::Tuso = tu;
    Number::Mauso = mau;
}
/**
 * Function: setVal
 * Description: set phân số từ giá trị tử và mẫu
 * Input:
 *    None
 * Output:
 *    val - float
*/
float Number::setphanso()
{
    return float (Number::Tuso)/(Number::Mauso);
}
class Phanso
{
private:
    Number A;
    Number B;
public:
    Phanso( Number a, Number b);
    float cong();
    float tru();
    float nhan();
    float chia();
};
Phanso::Phanso(Number a, Number b)
{
    Phanso::A = a;
    Phanso::B = b;
}
float Phanso::cong()
{
 return A.setphanso() + B.setphanso(); 
}
float Phanso::tru()
{
 return A.setphanso() - B.setphanso(); 
}
float Phanso::chia()
{
 return A.setphanso() / B.setphanso(); 
}
float Phanso::nhan()
{
 return A.setphanso() * B.setphanso(); 
}
int main() {
  printf("Tong 2 phan so = %.2f\n", Phanso(Number(1,15), Number(12,5)).cong());
  printf("Hieu 2 phan so = %.2f\n", Phanso(Number(123,11), Number(12,5)).tru());
  printf("Tich 2 phan so = %.2f\n", Phanso(Number(7,11), Number(1,5)).nhan());
  printf("Thuong 2 phan so = %.2f\n",Phanso(Number(9,11), Number(12,5)).chia());
  return 0;
}