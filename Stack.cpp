/*
Una pila (stack) es una estructura de datos en donde el último en entrar es el primero en salir.
Construir un programa C++ que simule una pila, utilizando una estructura de datos como la que
sigue para los nodos:

struct Pila {
 int dato;
 Pila *next;
};

RESTRICCIONES:
A. La pila debe poder realizar las operaciones de Push y Pop.

B. Tener en consideración de desplegar un mensaje de “Empty Stack”, cuando se trate de
hacer un Pop cuando la pila este vacía.

C. El programa debe tener un menú para realizar las operaciones de Push, Pop y Desplegar
toda la pila realizando Pops hasta el último nodo. Además, debe tener una opción de
salir del programa.
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

struct Pila{
    int dato;
    Pila *next;
};

//Prototipo de funciones
void Push(Pila *&, int); 
void Pop(Pila *&, int &);
void readInt(int &);

int main(){
    Pila *stack = NULL;
    int opcion = 0;

    while(opcion != 4){
        cout << "\nMenu: " << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Desplegar pila" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione la operación a realizar: ";
        cin >> opcion;

        switch (opcion){
            case 1:
                int dato;
                cout << "Digite el numero a almacenar en la pila: ";
                cin >> dato;
                Push(stack, dato);
                continue;

            case 2:
                if (stack != NULL){
                    Pop(stack, dato);
                }
                else{
                    cout << "Empty Stack" << endl;
                }
                continue;

            case 3:
                cout << "Opcion 3" << endl;
               continue;
                
            case 4:
                cout << "Saliendo del programa..." <<endl;
                
                break;
            
            default:
                cout << "Seleccione un número entre 1 y 4" <<endl;
                continue;
        }
        break;
    }
    return 0;
}

void Push(Pila *&stack, int n){
    Pila *nuevo_nodo = new Pila();
    nuevo_nodo -> dato = n; 
    nuevo_nodo -> next = stack; 
    stack = nuevo_nodo; 
    cout << "Numero " << n << " Agregado a la pila" << endl;
}

void Pop(Pila *&stack, int &n){
    Pila *aux = stack;
    n = aux -> dato;
    stack = aux -> next;
    delete aux;
    cout << "Sacando elemento " << n <<" de la pila..." << endl;
}

void readInt(int &dato){
    while(!(cin >> dato)){
        cout << "Solamente valores enteros";
        cin.clear();
        cin.ignore(1000);
    }
}