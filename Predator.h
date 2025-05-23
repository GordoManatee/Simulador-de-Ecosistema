#ifndef PREDATOR_H
#define PREDATOR_H

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#include "Animal.h"
#include "Simulation.h"

class Predator: public Animal{
    private:
        float tasaDepredacion;
        float tasaReproduccion;
        float tasaMortalidad;
        int populationPredator;
          

    public:
        Predator(): tasaDepredacion(0), tasaReproduccion(0), tasaMortalidad(0), populationPredator(0){};
        Predator(float tasaD, float tasaR, float tasaM, 
        string esp, int popPredator){
            tasaDepredacion = tasaD;
            tasaReproduccion = tasaR;
            tasaMortalidad = tasaM;
            populationPredator = popPredator;
        }
        void setDepredacion(float tasaD);
        float getDepredacion(){return tasaDepredacion;}
        void setReproduccion(float tasaR);
        float getReproduccion(){return tasaReproduccion;}
        void setMortalidad(float tasaM);
        float getMortalidad(){return tasaMortalidad;}
        void setPopulationPredator(int popPredator);
        float getPopulationPredator(){return populationPredator;}


};

void Predator::setDepredacion(float tasaD){
    tasaDepredacion = tasaD;
}
void Predator::setReproduccion(float tasaR){
    tasaReproduccion = tasaR;
}
void Predator::setMortalidad(float tasaM){
    tasaMortalidad = tasaM;
}
void Predator::setPopulationPredator(int popPredator){
    populationPredator = popPredator;
}
#endif
