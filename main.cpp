#include <iostream>
#include <conio.h>
#include "TablaHash.h"

using namespace std;

// Nota: Compilar con c++ 11 o superior
// En Dev C ++
// Herramientas->Opciones del compilador->Configuración
// ->Generación de código->Language Standard->GNU C++11

int main(){
	
	TablaHash th;
	
	int llave;
	string valor;
	int seguir = 1;
	
	cout << "Tabla Hash" << endl;
	
	while(seguir == 1){
		
		cout << "Llave: ";
		cin >> llave;
		
		cout << "Valor: ";
		cin >> valor;
		
		cout << "Seguir [1: si, 0: no]: ";
		cin >> seguir;
		
		th.agregar(llave, valor);
		
		system("cls");
	}
	
	th.imprimir();
	
	getch();
	
	return 0;
}
