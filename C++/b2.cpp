#include <stdio.h>
#include <math.h>


class Hinhchunhat

{
private:
    /* data */
    double dai;
    double rong;
    typedef enum check{
        error = 0,
        ok
    }Check ;
    Check check;
public:
    Hinhchunhat( double d , double r);
    double getdai();
    double getrong();
    double chuvi();
    double dientich();
    double duongcheo();
    double checkvuong();
    
};
Hinhchunhat::Hinhchunhat(double d, double r)
{   
    if(dai <=0 || rong <=0)
    {
        printf("thong so khong phu hop");
        check = error;
        return;
    }
    Hinhchunhat::dai = d;
    Hinhchunhat::rong = r;
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
