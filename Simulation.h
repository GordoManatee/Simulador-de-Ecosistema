#ifndef SIMULATION_H
#define SIMULATION_H

#include <utility>
#include "Prey.h"
#include "Predator.h"

class Simulation {
protected:
    int timeStep;
    pair<float, float> result;

public:
    Simulation() : timeStep(0), result(0, 0) {}
    virtual ~Simulation() {}

    virtual void simulate() = 0; // Método abstracto
    pair<float, float> getResults() const { return result; }
};

#endif