#include <iostream>
#include <string>
#include "Simulation.h"

using namespace std;

// Polimorfismo: función que acepta Animal*
void mostrarInfoAnimal(Animal* a) {
    cout << a->getInfo() << endl;
}

Prey crearConejo() {
    int poblacion;
    cout << "Poblacion inicial de presas: ";
    cin >> poblacion;
    return Prey(2, "conejo blanco", poblacion);
}

Predator crearZorro() {
    int poblacion;
    cout << "Poblacion inicial de depredadores: ";
    cin >> poblacion;
    return Predator(0.4, 0.08, 0.5, "zorro rojo", poblacion);
}

int main() {
    Prey conejo = crearConejo();
    Predator zorro = crearZorro();

    // Polimorfismo
    mostrarInfoAnimal(&conejo);
    mostrarInfoAnimal(&zorro);

    int meses;
    cout << "¿Cuantos meses quieres simular?: ";
    cin >> meses;

    Simulation simulation1;
    simulation1.setPpGrowth(zorro, zorro, zorro, zorro, conejo, conejo, 0, 0, meses);

    pair<float, float> res = simulation1.getPpGrowth();

    cout << "\nResultados finales:" << endl;
    cout << "Depredadores: " << res.first << endl;
    cout << "Presas: " << res.second << endl;

    return 0;
}

