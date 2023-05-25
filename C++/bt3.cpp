#include <stdio.h>
#include <math.h>


class Hinhtron

{
private:
    /* data */
    
    double bk;
    typedef enum check{
        error = 0,
        ok
    }Check ;
    Check check;
public:
    Hinhtron( double r);
    double getbk();
    double chuvi();
    double dientich();
    
};
Hinhtron::Hinhtron( double r)
{   
    if(bk <=0)
    {
        printf("thong so khong phu hop");
        check = error;
        return;
    }
    Hinhtron::bk = r;
}
double Hinhtron::getbk()
{
    if (check == error)
    {
        printf("thong so khong phu hop");
        return -1;
    }
    
    return bk;
}

double Hinhtron::chuvi(){
    if (check == error)
    {
        printf("thong so khong phu hop");
        return -1;
    }
    
    
    return (double)(3.14 * bk * 2);
}

double Hinhtron::dientich()
{
    if (check == error)
    {
        printf("thong so khong phu hop");
        return -1;
    }
    
    return (double)(pow(bk,2)* 3.14);
}

int main()
{
    Hinhtron ht(5);
    printf("\nban kinh :  %.2lf",ht.getbk());
    printf("\ndien tich:  %.2lf",ht.dientich());
    printf("\nchu vi   :  %.2lf",ht.chuvi());
    
    return 0;
}
