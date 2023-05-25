#include <stdio.h>
#include <math.h>

class Date
{
private:
    /* data */
    int Ngay;
    int Thang;
    int Nam;
public:
    Date( int ngay, int thang, int nam  );
    int ageCalculate(Date* namsinh, Date* namhientai);
    int Checkngaynghile();

};
Date::Date(int ngay , int thang, int nam)
{
    Date::Ngay = ngay;
    Date::Thang = thang;
    Date::Nam = nam;
}
int Date::ageCalculate(Date* namsinh, Date* namhientai)
{    printf("Tuoi nguoi nay la: %d\n", namhientai->Nam - namsinh->Nam);
    return 0;
}
int Date::Checkngaynghile(){
 if( Date::Ngay  == 1 && Date::Thang == 1){
        printf("TET DUONG LICH\n");
    }
    else if( Date::Ngay  == 1 && Date::Thang == 5){
        printf("QUOC TE LAO DONG\n");
    }
    else if( Date::Ngay  == 1 && Date::Thang == 6){
        printf("QUOC TE THIEU NHI\n");
    }
    else if( Date::Ngay  == 8 && Date::Thang == 3){
        printf("QUOC TE PHU NU\n");
    }
    else if(Date::Ngay  == 2 && Date::Thang == 9){
        printf(" NGAY QUOC KHANH\n");
    }
    else{
        printf("KHONG PHAI NGAY NGHI LE\n");
    }
}
int main() {
  Date *namsinh, *namhientai;
    namsinh = new Date(4, 10, 2000);
   namhientai = new Date(2, 9, 2023);
    namsinh->ageCalculate(namsinh, namhientai);
   namhientai->Checkngaynghile();
  return 0;
}