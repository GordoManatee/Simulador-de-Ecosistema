#ifndef PREY_H
#define PREY_H

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#include "Animal.h"

class Prey: public Animal{
    private:
        double tasaNatalidad;
        int populationPrey;

    public:
        Prey(): tasaNatalidad(0), populationPrey(0){};
        Prey(double tasaN, string esp, int popPrey){
            tasaNatalidad = tasaN;
            populationPrey = popPrey;
        } 
        void setNatalidad(double tasaN);
        double getNatalidad(){return tasaNatalidad;}
        void setPopulationPrey(int popPrey);
        int getPopulationPrey(){return populationPrey;}
};

void Prey::setNatalidad(double tasaN){
    tasaNatalidad = tasaN;
}
void Prey::setPopulationPrey(int popPrey){
    populationPrey = popPrey;
}
#endif
