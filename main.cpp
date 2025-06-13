#include <iostream>
#include <memory>
#include "Predator.h"
#include "Prey.h"
#include "Ecosystem.h"

using namespace std;

void mostrarMenu() {
    cout << "\nSeleccione las especies a simular:\n";
    cout << "Presas:\n";
    cout << "1. Conejo blanco\n";
    cout << "2. Liebre europea\n";
    cout << "3. Ciervo común\n";
    
    cout << "\nDepredadores:\n";
    cout << "4. Zorro rojo\n";
    cout << "5. Lobo gris\n";
    cout << "6. Águila real\n";
}

unique_ptr<Prey> crearPresa(int opcion, int poblacion) {
    switch(opcion) {
        case 1: return make_unique<Conejo>(poblacion);
        case 2: return make_unique<Liebre>(poblacion);
        case 3: return make_unique<Ciervo>(poblacion);
        default: return make_unique<Conejo>(poblacion);
    }
}

unique_ptr<Predator> crearDepredador(int opcion, int poblacion) {
    switch(opcion) {
        case 4: return make_unique<Zorro>(poblacion);
        case 5: return make_unique<Lobo>(poblacion);
        case 6: return make_unique<Aguila>(poblacion);
        default: return make_unique<Zorro>(poblacion);
    }
}

int main() {
    int opcionPresa, opcionDepredador;
    int poblacionPresa, poblacionDepredador;
    int meses;

    mostrarMenu();
    
    cout << "\nSeleccione una presa (1-3): ";
    cin >> opcionPresa;
    cout << "Población inicial: ";
    cin >> poblacionPresa;
    
    cout << "Seleccione un depredador (4-6): ";
    cin >> opcionDepredador;
    cout << "Población inicial: ";
    cin >> poblacionDepredador;
    
    cout << "Meses a simular: ";
    cin >> meses;

    auto presa = crearPresa(opcionPresa, poblacionPresa);
    auto depredador = crearDepredador(opcionDepredador, poblacionDepredador);

    cout << "\nConfiguración inicial:" << endl;
    cout << presa->getInfo() << endl;
    cout << depredador->getInfo() << endl;

    Ecosystem ecosistema(depredador.get(), presa.get(), meses);
    ecosistema.simulate();

    auto resultados = ecosistema.getResults();
    cout << "\nResultados finales:" << endl;
    cout << "Población de presas: " << resultados.second << endl;
    cout << "Población de depredadores: " << resultados.first << endl;

    return 0;
}