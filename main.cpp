#include <iostream>
#include <string>
#include "Simulation.h"

using namespace std;

void mostrarInfoAnimal(Animal* a) {
    cout << a->getInfo() << endl;
}

Prey crearPresa() {
    int opcion, poblacion;
    cout << "\nSeleccione una especie de presa:\n";
    cout << "1. Conejo blanco (Natalidad: 0.8)\n";
    cout << "2. Liebre (Natalidad: 0.6)\n";
    cout << "3. Ratón de campo (Natalidad: 1.2)\n";
    cout << "Opción: ";
    cin >> opcion;

    cout << "Población inicial: ";
    cin >> poblacion;

    switch(opcion) {
        case 1: return Prey(0.8, "Conejo blanco", poblacion);
        case 2: return Prey(0.6, "Liebre", poblacion);
        case 3: return Prey(1.2, "Ratón de campo", poblacion);
        default: return Prey(0.8, "Conejo blanco", poblacion);
    }
}

Predator crearDepredador() {
    int opcion, poblacion;
    cout << "\nSeleccione una especie de depredador:\n";
    cout << "1. Zorro rojo (Dep:0.4, Rep:0.08, Mort:0.5)\n";
    cout << "2. Lobo (Dep:0.3, Rep:0.05, Mort:0.4)\n";
    cout << "3. Águila (Dep:0.2, Rep:0.1, Mort:0.6)\n";
    cout << "Opción: ";
    cin >> opcion;

    cout << "Población inicial: ";
    cin >> poblacion;

    switch(opcion) {
        case 1: return Predator(0.4, 0.08, 0.5, "Zorro rojo", poblacion);
        case 2: return Predator(0.3, 0.05, 0.4, "Lobo", poblacion);
        case 3: return Predator(0.2, 0.1, 0.6, "Águila", poblacion);
        default: return Predator(0.4, 0.08, 0.5, "Zorro rojo", poblacion);
    }
}

int main() {
    Prey presa = crearPresa();
    Predator depredador = crearDepredador();

    mostrarInfoAnimal(&presa);
    mostrarInfoAnimal(&depredador);

    int meses;
    cout << "\n¿Cuántos meses quieres simular?: ";
    cin >> meses;

    LotkaVolterraSimulation simulacion;
    simulacion.simulate(depredador, presa, meses);

    pair<float, float> res = simulacion.getResults();

    cout << "\nResultados finales:" << endl;
    cout << "Depredadores: " << res.first << endl;
    cout << "Presas: " << res.second << endl;

    return 0;
}