#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <utility>
#include "Prey.h"
#include "Predator.h"

class Simulation {
private:
    int timeStep;
    float predatorGrowth;
    float preyGrowth;
    pair<float,float> result;

public:
    Simulation(): timeStep(0), predatorGrowth(0), preyGrowth(0), result(0,0) {}
    Simulation(int timS, float predatorG, float preyG)
        : timeStep(timS), predatorGrowth(predatorG), preyGrowth(preyG), result(0,0) {}

    void setTimeStep(int timS) { timeStep = timS; }
    int getTimeStep() const { return timeStep; }

    void setPpGrowth(Predator tasaR, Predator tasaM, Predator popPredator, Predator tasaD,
                     Prey tasaN, Prey popPrey, float preyG, float predatorG, int timS);

    pair<float,float> getPpGrowth() const { return result; }
};

void Simulation::setPpGrowth(Predator tasaR, Predator tasaM, Predator popPredator, Predator tasaD, 
                              Prey tasaN, Prey popPrey, float preyG, float predatorG, int timS) {

    float x = popPrey.getPopulationPrey();
    float y = popPredator.getPopulationPredator();
    float alpha = tasaN.getNatalidad();
    float beta = tasaD.getDepredacion();
    float delta = tasaR.getReproduccion();
    float gamma = tasaM.getMortalidad();

    cout << "Depredador  |  Presa" << endl;

    for (int i = timS; i > 0; i--) {
        x = x + preyG;
        y = y + predatorG;

        preyG = (alpha * x - beta * x * y);
        predatorG = (delta * x * y - gamma * y);

        cout << y << "         " << x << endl;
    }

    result = make_pair(y, x); // primero depredador, luego presa
}

#endif
