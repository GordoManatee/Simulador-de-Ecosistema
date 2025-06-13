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

    // Métodos get/set...
    string getInfo() const override {
        return "Presa - Especie: " + specie + ", Natalidad: " + to_string(tasaNatalidad) +
               ", Población: " + to_string(populationPrey);
    }
};

class Conejo : public Prey {
public:
    Conejo(int pop) : Prey(2.0, "Conejo blanco", pop) {}
};

class Liebre : public Prey {
public:
    Liebre(int pop) : Prey(1.8, "Liebre europea", pop) {}
};

class Ciervo : public Prey {
public:
    Ciervo(int pop) : Prey(1.5, "Ciervo común", pop) {}
};

#endif
