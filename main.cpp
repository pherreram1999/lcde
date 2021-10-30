#include <cstdlib>
#include <ctime>
#include "header.h"

// vamos a crear una plantilla de datos

Amigo amigos[5] = {
        {
            "Marcos Ventura",
            "Rock"
        },
        {
            "Roberto",
            "Electronica"
        },
        {
            "Yisus",
            "alternativo"
        },
        {
            "Edgar Aguilar",
            "banda"
        },
        {
            "Luis Melgar",
            "all"
        }
};

Amigo amigosDOS[3] = {
        {
            "Alvaro",
            "Pop"
        },
        {
            "Yoali",
            "kPop"
        },
        {
            "Citlali",
            "Rock"
        }
};

// creamos un segundo sample de datos para mezclar listas


int main() {
    int id,res;
    srand(time(NULL));
    // declaramos nuestro lista de de cabecera
    Nodo * header = NULL;
    // vamos a declar una semilla para ID radoms

    // vamos a llenar nuestra lista con los valores de prueba
    for(Amigo &a: amigos){
        int id = rand() % 51;
        Nodo * nodoCreado = crearNodo(id,a.nombre,a.musica);
        if(!insertarNodo(&header,nodoCreado)){
            cout << "No fue posible ingresar el nodo con ID " << id << " a la lista " << endl;
        }
    }

    cout << "Bienvenido a la lista doblemente enlazada" << endl;
    cout << "los elementos de la lista son:" << endl;
    mostrarNodos(header);
    cout << "¿Que nodo desea buscar?" << endl;
    cout << "ID del nodo: "; cin >> id;
    Nodo * nodoBuscado = buscarNodo(header,id);
    if(nodoBuscado != NULL){
        cout << "nodo encontrado:" << endl;
        mostrarNodo(nodoBuscado);
        cout << "¿Desea editar el nodo?" << endl;
        cout << "1.- si 2.- no" << endl;
        cout << "res: "; cin >> res;
        if(res == 1){
            res = 0;
            cout << "¿Deseas editar el nombre?" << endl;
            cout << "res: "; cin >> res;
            if(res == 1){
                string nombre;
                cout << "nombre: "; cin >> nombre;
                if(!setNombre(nodoBuscado,nombre)){
                    cout << "No fue posible actualizar el nodo con id " << nodoBuscado->id << endl;
                }
            }
            res = 0;
            cout << "¿Deseas editar el genero de musica?" << endl;
            cout << "res: "; cin >> res;
            if(res == 1){
                string musica;
                cout << "Genero musica "; cin >> musica;
                if(!setMusica(nodoBuscado,musica)){
                    cout << "No fue posible actualizar el nodo con id " << nodoBuscado->id << endl;
                }
            }

        }
    } else {
        cout << "Nodo no encotrado :/" << endl;
    }
    cout << "la lista cuenta con una cantidad de " << cantidad(header) << " elementos" << endl;
    mostrarNodos(header);
    res = 0;
    cout << "¿Desea borar un nodo?" << endl;
    cout << "1.- si 2.- no" << endl;
    cout << "res: "; cin >> res;
    if(res == 1){
        cout << "¿Que nodo desea borrar?" << endl;
        cout << "id: "; cin >> id;
        if(!borrarNodo(&header,id))
            cout << "No fue posible eliminar el nodo con id " << id << endl;
        else
            cout << "Nodo borrado :O" << endl;
    }
    mostrarNodos(header);
    cout << "La cantidad de nodos actual es: " << cantidad(header) << endl;
    res = 0;
    cout << "¿Desea borrar toda la lista?" << endl;
    cout << "1.- si 2.- no" << endl;
    cout << "res: "; cin >> res;
    if(res == 1){
        cout << "borrando lista" << endl;
        borrarLista(&header);
        mostrarNodos(header);
    }
    cout << "Presentamos los otros amigos de otra lista" << endl;
    // ultimo llenamos un segunda lista con un sample data y mezclando listas
    Nodo * segundaLista = NULL;
    for(Amigo &a: amigosDOS){
        int id = rand() % 51;
        Nodo * nodoCreado = crearNodo(id,a.nombre,a.musica);
        if(!insertarNodo(&segundaLista,nodoCreado)){
            cout << "No fue posible ingresar el nodo con ID " << id << " a la lista " << endl;
        }
    }
    // mostramos la segunda lista
    mostrarNodos(segundaLista);
    res = 0;
    cout << "¿deseas mezclar las listas?" << endl;
    cout << "1.- si 2.- no" << endl;
    cout << "res: "; cin >> res;
    if(res == 1){
        Nodo * nuevaLista = mezclarNodos(header,segundaLista);
        cout << "la nueva lista esta compuesta por:" << endl;
        mostrarNodos(nuevaLista);
    }


    return 0;
}
