#include <stdio.h>
#include <stdint.h>
#include <math.h>

class Diem
{
private:
    /* data */
    int X;
    int Y;
public:
    Diem(int x = 0 , int y = 0);
    int getx();
    int gety();
};
Diem::Diem(int x, int y){
    Diem::X = x;
    Diem::Y = y;
}
int Diem::getx(){
    return Diem::X;
}

int Diem::gety(){
    return Diem::Y;
}
class tinhOxy
{
private:
    Diem A;
    Diem B;
    Diem C;
    typedef enum
    {
        Khoangcanh = 0,
        dien_tich
    }Tinh;
    Tinh check;
public:
    Diem getA();
    Diem getB();
    Diem getC();
    tinhOxy(Diem a, Diem b);
    tinhOxy(Diem a, Diem b, Diem c);
    double Khoangcach2diem();
    double Dientich();
};
tinhOxy::tinhOxy(Diem a, Diem b){
    tinhOxy:: A = a;
    tinhOxy:: B = b;
    check = Khoangcanh;
}
tinhOxy::tinhOxy(Diem a, Diem b, Diem c){
    tinhOxy:: A = a;
    tinhOxy:: B = b;
    tinhOxy:: C = c;
    check = dien_tich;
}
Diem tinhOxy::getA(){
    return tinhOxy::A;
}
Diem tinhOxy::getB(){
    return tinhOxy::B;
}
Diem tinhOxy::getC(){
    return tinhOxy::C;
}
double tinhOxy::Khoangcach2diem(){
    if(tinhOxy::check != Khoangcanh){
        printf("DU LIEU NHAP VAO KHONG PHU HOP\n");
        return -1;
    }

    return(double)(sqrt(pow(tinhOxy::A.getx() - tinhOxy::B.getx(),2) + pow(tinhOxy::A.gety() - tinhOxy::A.gety(),2)));
}
double tinhOxy::Dientich(){
    if(tinhOxy::check != dien_tich){
        printf("KHONG PHAI LA TAM GIAC\n");
        return -1;
    }
    double distance_a = sqrt(pow(tinhOxy::A.getx() - tinhOxy::B.getx(),2) + pow(tinhOxy::A.gety() - tinhOxy::B.gety(),2));
    double distance_b = sqrt(pow(tinhOxy::A.getx() - tinhOxy::C.getx(),2) + pow(tinhOxy::B.gety() - tinhOxy::C.gety(),2));
    double distance_c = sqrt(pow(tinhOxy::C.getx() - tinhOxy::B.getx(),2) + pow(tinhOxy::C.gety() - tinhOxy::B.gety(),2));
    double p = (distance_a + distance_b + distance_c) / 2;
    return (double)(sqrt(p*(p - distance_a)*(p - distance_b)*(p - distance_c)));
}
int main(){

    Diem a(1,0 );
    Diem b(2, 3);
    Diem c(2, 5);

    tinhOxy tinhOxy1(a, b);
    tinhOxy tinhOxy2(a, b, c);

    //-------------Space 1--------------//
    printf("POINT 1(%d,%d)\n", tinhOxy1.getA().getx(), tinhOxy1.getA().gety());
    printf("POINT 2(%d,%d)\n", tinhOxy1.getB().getx(), tinhOxy1.getB().gety());
    printf("DISTANCE: %.2f\n\n", tinhOxy1.Khoangcach2diem());

    //-------------Space 2--------------//
    printf("POINT 1(%d,%d)\n", tinhOxy2.getA().getx(), tinhOxy2.getA().gety());
    printf("POINT 2(%d,%d)\n", tinhOxy2.getB().getx(), tinhOxy2.getB().gety());
    printf("AREA OF TRIANGLE: %.2lf\n\n", tinhOxy2.Dientich());

    return 0;

}