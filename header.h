//
// Created by sistemas on 30/10/21.
//
#include <iostream>
#ifndef LCDE_HEADER_H
#define LCDE_HEADER_H
#endif //LCDE_HEADER_H
using namespace std;

typedef struct amigo {
    string nombre;
    string musica;
} Amigo;

typedef struct nodo {
    int id;
    Amigo amigo;
    struct nodo * sig;
    struct nodo * ant;
} Nodo;

/**
 * Crea un nuevo nodo para ser ingresado en la lista
 * @return
 */
Nodo * crearNodo(int,string,string);

void mostrarNodo(Nodo *);

void mostrarNodos(Nodo *);

Nodo * buscarNodo(Nodo *,int);

bool insertarNodo(Nodo **,Nodo *);

Nodo * mezclarNodos(Nodo *...);

bool setNombre(Nodo *,string);

bool setMusica(Nodo *,string);

bool borrarNodo(Nodo **,int);

int cantidad(Nodo *);

bool borrarLista(Nodo **);