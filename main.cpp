#include <iostream>
#include <conio.h>
#include "TablaHash.h"

using namespace std;

// Nota: Compilar con c++ 11 o superior
// En Dev C ++
// Herramientas->Opciones del compilador->Configuración
// ->Generación de código->Language Standard->GNU C++11

TablaHash th;

void menu(int e);
void menuAgregar();
void menuBuscar();
void menuEliminar();
void menuVerTodos();

int main(){
		
	int eleccion;
	
	do {
		eleccion = 0;
		
		cout << " Tabla Hash" << endl;
		cout << " 1. Agregar " << endl;
		cout << " 2. Buscar" << endl;
		cout << " 3. Eliminar" << endl;
		cout << " 4. Ver Todos " << endl;
		cout << " 0. Salir" << endl;
		cin >> eleccion;
		
		system("cls");
		
		menu(eleccion);
		
		getch();
		
		system("cls");
		
	}while( eleccion != 0 );
	
	return 0;
}

void menu(int e) {
	switch(e){
		
		case 1:
			menuAgregar();
			break;
		case 2:
			menuBuscar();
			break;
		case 3:
			menuEliminar();
			break;
		case 4:
			menuVerTodos();
			break;
		default:
			break;
	}
}

void menuAgregar(){
	
	int llave;
	string valor;
	
	cout << " Menu Agregar " << endl;
	cout << " Llave: ";
	cin >> llave;
	cout << " Valor: ";
	cin >> valor;
	
	th.agregar(llave, valor);
}

void menuBuscar(){
	int llave;
	string valor;
	
	cout << " Menu Buscar " << endl;
	cout << " Llave: ";
	cin >> llave;
	
	valor = th.buscar(llave);
	
	if(!valor.empty()){
		cout << " Llave: " << llave << ", Valor: " <<  valor << endl;
	}
}

void menuEliminar() {
	int llave;
	
	cout << " Menu Eliminar " << endl;
	cout << " Llave: ";
	cin >> llave;
	
	th.remover(llave);
}

void menuVerTodos() {
	
	cout << " Menu Ver Todos " << endl;
	th.imprimir();
}
