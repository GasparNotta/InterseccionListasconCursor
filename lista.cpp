#include "lista.h"
#include "nodo.h"
#include <iostream>

Lista::Lista() {
    primero = nullptr;
    cursor = primero;
    cantidad = 0;
}
 
Lista::Lista(const Lista &otra) {
    primero = nullptr;
    cursor = primero;
    cantidad = 0;
    Nodo* temp = otra.primero;
    for (int i = 1; i <= otra.cantidad; i++) {
        alta(temp->obtener_dato(), i);
        temp = temp->obtener_siguiente();
    }
}
 
Nodo* Lista::obtener_nodo(int pos) {
    Nodo* pn = primero;
    for (int i = 1; i < pos; i++)
        pn = pn->obtener_siguiente();
    return pn;
}

void Lista::alta(Dato d, int pos) {
    Nodo* nuevo = new Nodo(d);
    if (esta_vacia())
        cursor = nuevo;
    if (pos == 1){
        nuevo->cambiar_siguiente(primero);
        primero = nuevo;
    } else {
        Nodo* anterior = obtener_nodo(pos-1);
        Nodo* siguiente = anterior->obtener_siguiente();
        nuevo->cambiar_siguiente(siguiente);
        anterior->cambiar_siguiente(nuevo);
    }
    cantidad++;
}

void Lista::baja(int pos) { 
    Nodo* nodo_a_eliminar;
    if (pos == 1) {
        nodo_a_eliminar = primero;
        primero = primero->obtener_siguiente();
    } else {
        Nodo* anterior = obtener_nodo(pos-1);
        nodo_a_eliminar = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(nodo_a_eliminar->obtener_siguiente());
    }
    delete nodo_a_eliminar;
    cantidad--;

}

Dato Lista::consulta(int pos) {
    Nodo* pn = obtener_nodo(pos);
    return pn->obtener_dato();
}

bool Lista::esta_vacia() {
return (cantidad == 0);
}

int Lista::obtener_cantidad() {
return cantidad;
}

bool Lista::hay_siguiente() {
    return (cursor != nullptr);
}

Dato Lista::siguiente() {
    Dato dato = cursor->obtener_dato();
    cursor = cursor->obtener_siguiente();
    return dato;
}

void Lista::reiniciar_cursor() {
    cursor = primero;
}

bool Lista::buscar(Dato d) {
    Nodo* temp = primero;
    while (temp != nullptr) {
        if (temp->obtener_dato() == d) {
            return true;
        }
        temp = temp->obtener_siguiente();
    }
    return false;
}

void Lista::imprimirLista() {
    reiniciar_cursor();
    while (hay_siguiente()) {
        std::cout << siguiente() << " ";
    }
    std::cout << std::endl;
}

Lista* Lista::interseccion(Lista lista) {
    Lista* interseccionLista = new Lista(); 
    reiniciar_cursor(); 
    while (hay_siguiente()) {
        Dato datoActual = siguiente();
        if (lista.buscar(datoActual)) {
            interseccionLista->alta(datoActual, interseccionLista->obtener_cantidad() + 1);
        }
    }
    return interseccionLista;
}

Lista* Lista::interseccionOrdenada(Lista lista) {
    Lista* interseccionLista = new Lista();
    Nodo* temp1 = primero;
    Nodo* temp2 = lista.primero;

    while (temp1 != nullptr && temp2 != nullptr) {
        if (temp1->obtener_dato() == temp2->obtener_dato()) {
            interseccionLista->alta(temp1->obtener_dato(), interseccionLista->obtener_cantidad() + 1);
            temp1 = temp1->obtener_siguiente();
            temp2 = temp2->obtener_siguiente();
        } else if (temp1->obtener_dato() < temp2->obtener_dato()) {
            temp1 = temp1->obtener_siguiente();
        } else {
            temp2 = temp2->obtener_siguiente();
        }
    }
    return interseccionLista;
}

Lista::~Lista() {
    Nodo* temp = primero;
    while (!esta_vacia()) {
        temp = temp->obtener_siguiente();
        baja(1);
    }
}
