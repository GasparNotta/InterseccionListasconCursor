#ifndef _LISTA_H_
#define _LISTA_H_

#include "nodo.h"
#include <iostream>
class Lista {
private:
    Nodo* primero;
    Nodo* cursor;
    int cantidad;

    // pre: 0 < pos <= cantidad
    // pos: devuelve un puntero al nodo en la posicion pos
    Nodo* obtener_nodo(int pos);
public:
    // CONSTRUCTOR
    // pre: -
    // pos: construye una Lista
    Lista();

    //CONSTRUCTOR COPIA
    // pre: -
    // pos: construye una Lista con los mismos elementos que la lista pasada por parametro
    Lista(const Lista &otra);

    // METODOS PUBLICOS
    
    // pre: 0 < pos <= obtener_cantidad() + 1
    // pos: agrega d a la Lista en la posicion pos
    void alta(Dato d, int pos);

    // pre: 0 < pos <= obtener_cantidad()
    // pos: elimina de la Lista el elemento en la posicion pos 
    void baja(int pos);

    // pre: -
    // pos: devuelve true si la Lista esta vacia
    // devuelve false en caso contrario
    bool esta_vacia();

    // pre: 0 < pos <= obtener_cantidad()
    // pos: devuelve el elemento de la posicion pos 
    Dato consulta(int pos);

    // pre: -
    // pos: devuelve la cantidad de elementos en la lista
    int obtener_cantidad();

    // pre: -
    // pos: devuelve true si hay siguiente, false si no
    bool hay_siguiente();

    // pre: hay_siguiente() == true
    // pos: devuelve el siguiente dato y actualiza el cursor
    Dato siguiente();

    // pre: -
    // pos: vuelve el cursor al inicio
    void reiniciar_cursor();

    // pre: -
    // pos: devuelve true si el dato d se encuentra en la lista, devuelve false en caso contrario
    bool buscar(Dato d);

    // pre: -
    // pos: imprime la lista
    void imprimirLista();

    // pre: -
    // pos: Devuelve un puntero a una lista que es la unión entre la lista que invoca al método y la que se pasa por parámetro.
    Lista* interseccion(Lista lista);
 
    // pre: -
    // pos: Devuelve un puntero a una lista que es la unión entre la lista ordenada que invoca al método y la otra tambien ordenada que se pasa por parámetro.
    Lista* interseccionOrdenada(Lista lista);

    // DESTRUCTOR
    // pre: -
    // pos: destruye la Lista y libera toda la memoria utilizada.
    ~Lista();
};

#endif // _LISTA_H_