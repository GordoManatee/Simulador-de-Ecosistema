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

    void setDepredacion(float tasaD) { tasaDepredacion = tasaD; }
    float getDepredacion() const { return tasaDepredacion; }

    void setReproduccion(float tasaR) { tasaReproduccion = tasaR; }
    float getReproduccion() const { return tasaReproduccion; }

    void setMortalidad(float tasaM) { tasaMortalidad = tasaM; }
    float getMortalidad() const { return tasaMortalidad; }

    void setPopulationPredator(int popPredator) { populationPredator = popPredator; }
    int getPopulationPredator() const { return populationPredator; }

    string getInfo() const override {
        return "Depredador - Especie: " + specie + ", Depredación: " + to_string(tasaDepredacion) +
               ", Reproducción: " + to_string(tasaReproduccion) +
               ", Mortalidad: " + to_string(tasaMortalidad) +
               ", Población: " + to_string(populationPredator);
    }
};

#endif