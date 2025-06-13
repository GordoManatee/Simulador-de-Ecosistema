#ifndef PREDATOR_H
#define PREDATOR_H

#include "Animal.h"

class Predator : public Animal {
private:
    float tasaDepredacion;
    float tasaReproduccion;
    float tasaMortalidad;
    int populationPredator;

public:
    Predator(): Animal("Desconocida"), tasaDepredacion(0), tasaReproduccion(0), tasaMortalidad(0), populationPredator(0) {}

    Predator(float tasaD, float tasaR, float tasaM, string esp, int popPredator)
        : Animal(esp), tasaDepredacion(tasaD), tasaReproduccion(tasaR), 
          tasaMortalidad(tasaM), populationPredator(popPredator) {}

    // Métodos get/set...
    string getInfo() const override {
        return "Depredador - Especie: " + specie + ", Depredación: " + to_string(tasaDepredacion) +
               ", Reproducción: " + to_string(tasaReproduccion) +
               ", Mortalidad: " + to_string(tasaMortalidad) +
               ", Población: " + to_string(populationPredator);
    }
};

class Zorro : public Predator {
public:
    Zorro(int pop) : Predator(0.4, 0.08, 0.5, "Zorro rojo", pop) {}
};

class Lobo : public Predator {
public:
    Lobo(int pop) : Predator(0.35, 0.07, 0.45, "Lobo gris", pop) {}
};

class Aguila : public Predator {
public:
    Aguila(int pop) : Predator(0.3, 0.06, 0.4, "Águila real", pop) {}
};

#endif