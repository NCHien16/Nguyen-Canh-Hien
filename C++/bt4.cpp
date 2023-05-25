#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;
class Animal

{
private:
    /* data */
    char Name[20];
    int  Age;
    int  Weigth;
    float  High;
public:
  
    Animal( const char* name, int age, int weight, float high );
    char* getname();
    int getage();
    int getweight();
    float gethigh();
    double getBMI();    
};
 Animal::Animal( const char* name , int age, int weight, float high )
{   
    
    strcpy( Animal::Name, name);
    Animal::Age = age;
    Animal::Weigth = weight;
    Animal::High = high;
    
}
/*
* Class: Animal
* Function: getName
* Description: This function use for get name of animal
* Input:
*   Don't have input parameters
* Output:
*   return: name of animal
*/
char* Animal::getname()
{
    return Name;
}
/*
* Class: Animal
* Function: getage
* Description: This function use for get age of animal
* Input:
*   Don't have input parameters
* Output:
*   return: age of animal
*/
int Animal::getage()
{
    return Age;
}
/*
* Class: Animal
* Function: getWeigh
* Description: This function use for get weight of animal
* Input:
*   Don't have input parameters
* Output:
*   return: weight of animal
*/
int Animal::getweight()
{
    return Weigth;
}
/*
* Class: Animal
* Function: getHinght
* Description: This function use for get high of animal
* Input:
*   Don't have input parameters
* Output:
*   return:high of animal
*/
float Animal::gethigh()
{
    return High;
}
/*
* Class: Animal
* Function: getBMI
* Description: This function use for get BMI of animal
* Input:
*   Don't have input parameters
* Output:
*   return: BMI of animal
*/
double Animal::getBMI()
{
    return double(Weigth / (High * High));
}
/*
* Class: Animal
* Function:compareWeight
* Description: This function compare weigh between 2 animal of project
* Input:
*   dongVat_1
    dongVat_2
* Output:
*   result compare
*/
void compareWeight(Animal* dongVat_1, Animal* dongVat_2){
    if (dongVat_1 -> getweight() > dongVat_2 -> getweight()) 
    { 
        printf("Con %s nang hon con %s\n",dongVat_1->getname(),dongVat_2->getname());
    }
    else if ((dongVat_1->getweight() == dongVat_2->getweight()))
    {
     printf("Con %s co trong luong bang con %s\n",dongVat_1->getname(),dongVat_2->getname());
    }
    else { 
    printf("Con %s nhe hon con %s\n",dongVat_1->getname(),dongVat_2->getname());
    }
}
/*
* Class: Animal
* Function:compareWeight
* Description: This function compare age between 2 animal of project
* Input:
*   dongVat_1
    dongVat_2
* Output:
*   result compare
*/
void compareAge(Animal* dongVat_1, Animal* dongVat_2){
    if (dongVat_1->getage() > dongVat_2->getage())  printf("Con %s gia hon con %s\n",dongVat_1->getname(),dongVat_2->getname());
     if ((dongVat_1->getage() == dongVat_2->getage()))   printf("Con %s tuoi bang con %s\n",dongVat_1->getname(),dongVat_2->getname());
    else   printf("Con %s tre hon con %s\n",dongVat_1->getname(),dongVat_2->getname());
};
int main() {
    Animal *animal[2];
 
    animal[0] = new Animal("Dog", 2, 20,0.5);
    animal[1] = new Animal("Cat", 3, 2, 0.3);
    
    for (int i = 0; i < 2; i++){
        printf("Chi so BMI cua  %s la: %.2f\n",animal[i]->Animal::getname(), animal[i]->Animal::getBMI());
    }
    compareWeight(animal[0], animal[1]);
    compareAge(animal[0], animal[1]);

   
    return 0;
}