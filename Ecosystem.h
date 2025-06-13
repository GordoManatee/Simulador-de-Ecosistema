#ifndef ECOSYSTEM_H
#define ECOSYSTEM_H

#include "Simulation.h"
#include "Predator.h"
#include "Prey.h"

class Ecosystem : public Simulation {
private:
    Predator* predator;
    Prey* prey;
    int initialPredatorPop;
    int initialPreyPop;

public:
    Ecosystem(Predator* pred, Prey* pr, int months)
        : predator(pred), prey(pr), timeStep(months) {
        initialPredatorPop = predator->getPopulationPredator();
        initialPreyPop = prey->getPopulationPrey();
    }

    void simulate() override {
        float x = initialPreyPop;
        float y = initialPredatorPop;
        
        float alpha = prey->getNatalidad();
        float beta = 0.1f; // Tasa de depredación ajustada
        float delta = 0.02f; // Tasa de reproducción ajustada
        float gamma = predator->getMortalidad();

        cout << "\nSimulando " << timeStep << " meses..." << endl;
        cout << "Mes | Presas | Depredadores" << endl;

        for (int i = 1; i <= timeStep; i++) {
            float dx = (alpha * x) - (beta * x * y);
            float dy = (delta * x * y) - (gamma * y);
            
            x += dx;
            y += dy;
            
            // Asegurar poblaciones no negativas
            x = max(0.0f, x);
            y = max(0.0f, y);

            cout << i << " | " << x << " | " << y << endl;
        }

        result = make_pair(y, x);
    }
};

#endif