#include <stdio.h>
#include <math.h>


class Animal

{
private:
    /* data */
    char Name[20];
    int  Age;
    int  Weigth;
    int  High;
public:
    Animal(){}
    Animal( const char* name, int age, int weight, int high );
    char* getname();
    int getage();
    int getweight();
    int gethigh();
    double getBMI();    
};
 Animal( const char* name , int age, int weight, int high );
{   
    
    Animal::Name = name;
    Animal::Age = age;
    Animal::Weight = weight;
    Animal::High = high;
    
}
double Hinhchunhat::getdai()
{
    if (check == error)
    {
        printf("thong so khong phu hop");
        return -1;
    }
    
    return dai;
}
double Hinhchunhat::getrong()
{
    if (check == error)
    {
        printf("thong so khong phu hop");
        return -1;
    }
    
    return rong;
}

double Hinhchunhat::chuvi(){
    if (check == error)
    {
        printf("thong so khong phu hop");
        return -1;
    }
    
    
    return (double)((dai  + rong) * 2);
}

double Hinhchunhat::dientich()
{
    if (check == error)
    {
        printf("thong so khong phu hop");
        return -1;
    }
    
    return (double)(dai * rong);
}
double Hinhchunhat::duongcheo()
{
    if (check == error)
    {
        printf("thong so khong phu hop");
        return -1;
    }
    
    return (double)(sqrt(pow(dai,2))*(pow(rong,2)));

}
double Hinhchunhat::checkvuong(){
    if (check == error)
    {
        printf("thong so khong phu hop");
        return -1;
    }
    if(dai == rong)
    {
        printf("\nday la hinh vuong");
    }
    else{
        printf("\nday khong phai la hinh vuong");
    }

}
int main()
{
    Hinhchunhat cn(5,4);
    printf("\nchieudai:   %.2lf",cn.getdai());
    printf("\nchieurong:  %.2lf",cn.getrong());
    printf("\nchu vi:     %.2lf",cn.chuvi());
    printf("\ndien tich:  %.2lf",cn.dientich());
    printf("\nduong cheo: %.2lf",cn.duongcheo());
    cn.checkvuong();
    return 0;
}
