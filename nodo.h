#ifndef _NODO_H_
#define _NODO_H_

typedef int Dato;
 
class Nodo {
private:
    // ATRIBUTOS
    Dato dato;
    Nodo* siguiente;

public:
    // CONSTRUCTORES
    // pre: -
    // pos: construye un Nodo con un dato d y siguiente en nullptr.
    Nodo(Dato d);
    // pre: -
    // pos: construye un Nodo con un dato d y siguiente en pn
    Nodo(Dato d, Nodo* pn);
 
    // METODOS
    // pre: -
    // pos: devuelve el dato del nodo
    Dato obtener_dato();

    // pre: -
    // pos: devuelve el siguiente nodo
    Nodo* obtener_siguiente();

    // pre: -
    // pos: cambia el dato del nodo
    void cambiar_dato(Dato d);

    // pre: -
    // pos: cambia el siguiente nodo
    void cambiar_siguiente(Nodo* pn);
};

#endif // _NODO_H_