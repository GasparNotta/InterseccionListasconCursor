#include <iostream>
#include "lista.h"

using namespace std;

int main() {
    // Crear las listas
    Lista lista_sin_orden1;
    Lista lista_sin_orden2;

    // Agregar elementos a lista1 y lista2
    lista_sin_orden1.alta(9, 1);
    lista_sin_orden1.alta(2, 2);
    lista_sin_orden1.alta(6, 3);
    lista_sin_orden1.alta(1, 4);
    lista_sin_orden1.alta(8, 5);
 
    lista_sin_orden2.alta(8, 1);
    lista_sin_orden2.alta(5, 2);
    lista_sin_orden2.alta(2, 3);
    lista_sin_orden2.alta(3, 4);
    lista_sin_orden2.alta(1, 5);

    // Imprimir el contenido de lista1 y lista2
    std::cout << "Contenido de lista1: ";
    lista_sin_orden1.imprimirLista();
    std::cout << "Contenido de lista2: ";
    lista_sin_orden2.imprimirLista();
    

    // Calcular la intersección de lista1 y lista2
    
    Lista* interseccionLista = lista_sin_orden2.interseccion(lista_sin_orden1);

    // Imprimir la intersección
    std::cout << "Interseccion sin orden: ";
    interseccionLista->imprimirLista();

    // Liberar la memoria
    delete interseccionLista;
    
    std::cout << std::endl;

    Lista lista_con_orden1;
    Lista lista_con_orden2;

    // Agregar elementos a lista1 y lista2
    lista_con_orden1.alta(1, 1);
    lista_con_orden1.alta(2, 2);
    lista_con_orden1.alta(6, 3);
    lista_con_orden1.alta(8, 4);
    lista_con_orden1.alta(9, 5);

    lista_con_orden2.alta(1, 1);
    lista_con_orden2.alta(2, 2);
    lista_con_orden2.alta(3, 3);
    lista_con_orden2.alta(5, 4);
    lista_con_orden2.alta(8, 5);

    // Imprimir el contenido de lista1 y lista2
    std::cout << "Contenido de lista1: ";
    lista_con_orden1.imprimirLista();

    std::cout << "Contenido de lista2: ";
    lista_con_orden2.imprimirLista();

    // Calcular la intersección de lista1 y lista2
    Lista* interseccionListaOrdenada = lista_con_orden2.interseccion(lista_con_orden1);
    std::cout << "Interseccion con orden: ";
    interseccionListaOrdenada->imprimirLista();

    delete interseccionListaOrdenada;
    
    return 0;
}



