#ifndef PREY_H
#define PREY_H

#include "Animal.h"

class Prey : public Animal {
private:
    double tasaNatalidad;
    int populationPrey;

public:
    Prey(): Animal("Desconocida"), tasaNatalidad(0), populationPrey(0) {}
    Prey(double tasaN, string esp, int popPrey)
        : Animal(esp), tasaNatalidad(tasaN), populationPrey(popPrey) {}

    void setNatalidad(double tasaN) { tasaNatalidad = tasaN; }
    double getNatalidad() const { return tasaNatalidad; }

    void setPopulationPrey(int popPrey) { populationPrey = popPrey; }
    int getPopulationPrey() const { return populationPrey; }

    string getInfo() const override {
        return "Presa - Especie: " + specie + ", Natalidad: " + to_string(tasaNatalidad) +
               ", Población: " + to_string(populationPrey);
    }
};

#endif
