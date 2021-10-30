#include "header.h"

/**
 * Crea un nuevo nodo de la lista
 * @param id
 * @param nombre
 * @param musica
 * @return
 */
Nodo * crearNodo(int id,string nombre,string musica){
    Nodo * nuevoNodo = NULL;
    nuevoNodo = new Nodo;
    if(nuevoNodo != NULL){
        nuevoNodo->id = id;
        nuevoNodo->amigo.nombre = nombre;
        nuevoNodo->amigo.musica = musica;
    }
    return nuevoNodo;
}

/**
 * Muestra un solo nodo de la lista
 * @param nodo
 */
void mostrarNodo(Nodo * nodo){
    if(nodo == NULL){
        cout << "Valor de nodo NULO" << endl;
        return;
    }
    cout << "\n--- Amigo con ID "  << nodo->id << " -----------" << endl;
    cout << "Nombre: " << nodo->amigo.nombre << endl;
    cout << "Genero musical: " << nodo->amigo.musica << endl;
    cout << "-------------------------------" << endl;
}

/**
 * Muestra todos los nodos de la lista
 * @param nav
 */
void mostrarNodos(Nodo * nav){
    if(nav == NULL){
        cout << "Lista vacia" << endl;
        return;
    }
    Nodo * ancla = nav;
    do {
        mostrarNodo(nav);
        nav = nav->sig;
    } while(nav != ancla);
}

/**
 * busca y retorna un nodo por su id
 * @param nav
 * @param id
 * @return
 */
Nodo * buscarNodo(Nodo * nav,int id){
    if(nav == NULL){
        cout << "Lista vacia" << endl;
        return NULL;
    }
    Nodo * primerNodo = nav;
    do {
        if(nav->id == id)
            return nav;
        nav = nav->sig;
    } while(nav != primerNodo);
    return NULL;
}

/**
 * inserta un nodo en la lista
 * @param header
 * @param nuevoNodo
 * @return
 */
bool insertarNodo(Nodo ** header,Nodo * nuevoNodo){
    // si es el primer nodo de la lista
    if(*header == NULL){
        *header = nuevoNodo;
        nuevoNodo->sig = nuevoNodo;
        nuevoNodo->ant = nuevoNodo;
        return true;
    }
    // tenemos que uscar un nav para quedamos en el penultimo nodo en el que se debe insertar
    Nodo * nav = *header;
    while(nuevoNodo->id > nav->id && nuevoNodo->id <= (*header)->id){
        nav = nav->sig;
    }
    // vericamos que no se halla repetido el nodo
    if(nuevoNodo->id == nav->id ){
        cout << "ID " << nuevoNodo->id << " repetido :´(" << endl;
        return false;
    }
    // se inserta en medio o al final
    nuevoNodo->sig = nav;
    nuevoNodo->ant = nav->ant;
    // se forma el circulo
    nav->ant->sig = nuevoNodo;
    nav->ant = nuevoNodo;
    // si inserta el princio
    if(nuevoNodo->id < (*header)->id){
        *header = nuevoNodo;
    }

    return true;
}

/**
 * mezcla los valores de n listas en una nueva lista
 * @param listas
 * @param ...
 * @return
 */
Nodo * mezclarNodos(Nodo * listas...){
    // al parecer cuando se trata de argumentos indefinidos en for, usamos la sintaxys que provee c++
    // creamos una nueva lista
    Nodo * nuevaLista = NULL;
    for(Nodo * lista: {listas}){
        // ahora tenemos que recorre cada una de las listas
        Nodo * nav = lista;
        Nodo * ancla = nav;
        do {
            Nodo * nuevoNodo = nav;
            nav = nav->sig;
            nuevoNodo->sig = nuevoNodo;
            nuevoNodo->ant = nuevoNodo;
            insertarNodo(&nuevaLista,nuevoNodo);
        } while(nav != ancla);
    }
    return nuevaLista;
}

/**
 * Establece un nuevo nombre a un nodo su amigo
 * @param nodoEditar
 * @param nombre
 * @return
 */
bool setNombre(Nodo * nodoEditar, string nombre){
    if(nodoEditar != NULL){
        nodoEditar->amigo.nombre = nombre;
        return true;
    }
    return false;
}

/**
 * Establece el genero musical de un nodo, su amigo
 * @param nodoEditar
 * @param musica
 * @return
 */
bool setMusica(Nodo * nodoEditar,string musica){
    if(nodoEditar != NULL){
        nodoEditar->amigo.musica = musica;
    }
    return false;
}

/**
 * Borra el nodo de una lista dado por su id
 * @param header
 * @param id
 * @return
 */
bool borrarNodo(Nodo ** header,int id){
    if(*header == NULL){
        cout << "Lista vacia :3" << endl;
        return false;
    }
    cout << "borrando nodo  :O" << endl;
    // en el caso de que solo tenga un solo nodo
    if(id == (*header)->id && *header == (*header)->sig){
        delete *header;
        *header = NULL;
        return true;
    }
    // si tiene mas elementos en la lista
    Nodo * nav = *header;
    // nos colocamos en el nodo que se tenga que eliminar
    while(nav->sig != *header && id != nav->id){
        nav = nav->sig;
    }
    // si ya recorrimos toda la lista y el id no es mismo al ultimo no se ecuentra
    if(id != nav->id)
        return false;
    // cambiamos las pocisiones del nodo, exluyendo el nodo encotrado
    nav->sig->ant = nav->ant;
    nav->ant->sig = nav->sig;
    // si el nodo es el primero hacemos una correcion de punteros
    if(id == (*header)->id){
        *header = (*header)->sig;
    }
    // por ultimo elimnamos le nodo
    delete nav;
    return true;
}

/**
 * retorna la cantidad de nodos de una lista
 * @param nav
 * @return
 */
int cantidad(Nodo * nav){
    int cant = 0;
    Nodo * ancla = nav;
    do {
        cant++;
        nav = nav->sig;
    } while(nav != ancla);
    return cant;
}

/**
 * Borra todos los elementos de la lista
 * @param header
 * @return
 */
bool borrarLista(Nodo ** header){
    if(*header == NULL){
        cout << "Lista vacia" << endl;
    }
    // si solo tiene un nodo
    cout << " cant: " << cantidad(*header) << " | ";
    cout << "ID " << (*header)->id << " ";
    if(!borrarNodo(header,(*header)->id)){
        cout << "no fue posible eliminar el nodo con id" << (*header)->id;
    }
    if(*header != NULL){
        borrarLista(header);
    }
    return true;
}