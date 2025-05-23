#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Animal{
    protected:
        string specie;
        string info;

    public:
        Animal(): specie(""){};
        Animal(string esp){
            specie = esp;
        }
        void setSpecie(string esp);
        string getSpecie(){return specie;}
        string getInfo();           
};

void Animal::setSpecie(string esp){
    specie = esp;
}
string Animal::getInfo(){

}
#endif