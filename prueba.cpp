#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#include "Simulation.h"

// Función para inicializar un conejo
Prey crearConejo() {
    int poblacion;
    cout << "Poblacion inicial de presas: ";
    cin >> poblacion;

    return Prey(2, "conejo blanco", poblacion);
}

// Función para inicializar un zorro
Predator crearZorro() {
    int poblacion;
    cout << "Poblacion inicial de depredadores: ";
    cin >> poblacion;
    return Predator(0.4, 0.08, 0.5, "zorro rojo", 2);
}

int main() {
    Prey conejo = crearConejo();
    Predator zorro = crearZorro();

    int meses;
    cout << "¿Cuantos meses quieres simular?: ";
    cin >> meses;

    Simulation simulation1;
    simulation1.setPpGrowth(zorro, zorro, zorro, zorro, conejo, conejo, 0, 0, meses);
    
    pair<float, float> res = simulation1.getPpGrowth();
    
    cout << "Depredadores: " << res.first << endl;
    cout << "Presas: " << res.second << endl;

    return 0;
}
