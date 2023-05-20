#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

class Person
{
private:
    /* data */
    char _name[50];
     int _age;
    char _addr[50];
public:
    Person(const char* name, int age, const char* addr);
    char* getName();
    char* getAddr();
    int getAge();
    void display();
};

Person::Person(const char* name, int age, const char* addr)
{
    strcpy(Person::_name, name);
    strcpy(Person::_addr, addr);
   Person:: _age = age;
}

char* Person::getName(){
    return _name;
}

char* Person::getAddr(){
    return _addr;
}


int Person::getAge(){
    return _age;
}

void Person::display(){
    printf("Ten: %s\n", _name);
    printf("Tuoi: %d\n", _age);
    printf("Dia chi: %s\n", _addr);
}

int main(int argc, char const *argv[])
{
    /* code */
    Person ps("Name", 23, "Dia chi");
    ps.display();
    return 0;
}