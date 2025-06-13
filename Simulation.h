#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <utility>
#include "Prey.h"
#include "Predator.h"

class Simulation {
protected:
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

    // Método abstracto puro
    virtual void simulate(Predator& predator, Prey& prey, int months) = 0;

    pair<float,float> getResults() const { return result; }
    
    virtual ~Simulation() {}
};

class LotkaVolterraSimulation : public Simulation {
public:
    void simulate(Predator& predator, Prey& prey, int months) override {
        float x = prey.getPopulationPrey();
        float y = predator.getPopulationPredator();
        float alpha = prey.getNatalidad();
        float beta = predator.getDepredacion();
        float delta = predator.getReproduccion();
        float gamma = predator.getMortalidad();

        cout << "\nSimulando " << months << " meses..." << endl;
        cout << "Mes | Depredadores | Presas" << endl;

        for (int i = 1; i <= months; i++) {
            float dx = (alpha * x) - (beta * x * y);
            float dy = (delta * x * y) - (gamma * y);

            x += dx;
            y += dy;

            // Asegurar que las poblaciones no sean negativas
            if (x < 0) x = 0;
            if (y < 0) y = 0;

            cout << i << " | " << y << " | " << x << endl;
        }

        result = make_pair(y, x);
    }
};

#endif