#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string specie;
    string info;

public:
    Animal(): specie("Desconocida") {};
    Animal(string esp): specie(esp) {}

    void setSpecie(string esp) { specie = esp; }
    string getSpecie() const { return specie; }

    virtual string getInfo() const {  // Método virtual para sobreescribir
        return "Especie: " + specie;
    }

    virtual ~Animal() {} // Destructor virtual
};

#endif
