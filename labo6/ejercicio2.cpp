#include <iostream>
using namespace std;

//------ Creacion de nodo y de arbol ------
struct nodo{
    int info;
    struct nodo *izq;
    struct nodo *der;
};
typedef struct nodo Nodo;
typedef struct nodo *Arbol;
typedef struct nodo *Espejo;

Arbol crearArbol(int x){
    Arbol p = new Nodo;
    p->info = x;
    p->izq = NULL;
    p->der = NULL;
    return p;
}
Espejo crearEspejo(int y){
    Espejo s = new Nodo;
    s->info = y;
    s->izq = NULL;
    s->der = NULL;
    return s;
}

//------ Agregar nodos a un arbol ------
void asignarIzq(Arbol a, int unDato){
    if(a == NULL)
        cout << "Error: arbol vacio" << endl;
    else if(a->izq != NULL)
        cout << "Error: subarbol IZQ ya existe" << endl;
    else
        a->izq = crearArbol(unDato);
}

void asignarDer(Arbol a, int unDato){
    if(a == NULL)
        cout << "Error: arbol vacio" << endl;
    else if(a->der != NULL)
        cout << "Error: subarbol DER ya existe" << endl;
    else
        a->der = crearArbol(unDato);
}

void agregarNodo(Arbol a, Espejo e){
    //solicitar informacion (numero a agregar)
    int numero = 0;
    cout << "Numero a agregar: ";
    cin >> numero;
    
    Arbol p = a;
    Espejo s = e;
    //desplazarse hasta el lugar adecuado
    while(true){
        if(numero == p->info){
            cout << "Error: " << numero << " ya existe" << endl;
            return;
        }
        else if(numero < p->info){//ir a la izquierda
            if(p->izq == NULL)
                break;
            else
                p = p->izq;
                s = s->der;
        }
        else{//ir a la derecha
            if(p->der == NULL)
                break;
            else
                p = p->der;
                s = s->izq;

        }
    }
    
    //agregar el nuevo nodo
    if(numero < p->info)
    {
        asignarIzq(p, numero);
        asignarDer(s, numero);
    }
    else{
        asignarDer(p, numero);
        asignarIzq(s, numero);
    }
        

}

void inorden(Arbol a){
    if(a != NULL){
        inorden(a->izq);
        cout << " " << a->info;
        inorden(a->der);
    }
}
void espejo(Espejo a){
    if(a != NULL){
    	inorden(a->izq);
        cout << " " << a->info;
        inorden(a->der);
    }
}

void recorrerArbol(Arbol a, Espejo e){
    cout << "Recorrido IN orden:"; inorden(a); cout << endl;
    cout << "Recorrido IN orden espejo:"; espejo(e); cout << endl;
}

int main(){
    int variable = 0;
    cout<<"Inicializando arbol...\nValor contenido en la raiz: ";
    cin >> variable;
    
    Arbol arbol = crearArbol(variable);
    Espejo espejo = crearEspejo(variable);

    bool continuar = true;
    do{
        int opcion = 0;
        cout << "Menu: \n\t1) Agregar\n\t2) Recorrer"
            << "\n\t3) Salir\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: agregarNodo(arbol, espejo);
            break;
            case 2: recorrerArbol(arbol, espejo);
            break;
            case 3: continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);
    
    return 0;
}
