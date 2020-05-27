
#ifndef _TABLA_HASH_
#define _TABLA_HASH_

#include <iostream>
#include <list>
#include <string.h>

class TablaHash {
	
private:
	static const int tamArreglo = 10;
	std::list<std::pair<int, std::string> > tabla[tamArreglo];
	
public:
	bool estaVacio() const;
	int funcionHash(const int llave);
	void agregar(const int llave, const std::string valor);
	void remover(const int llave);
	std::string buscar(const int llave);
	void imprimir() const;
};

bool TablaHash::estaVacio() const {
	int sum = 0;
	for(int i = 0; i < tamArreglo; i++ ){
		sum += tabla[i].size();
	}
	
	if(sum == 0){
		return true;
	}
	return false;
	
}

int TablaHash::funcionHash(const int llave) {
	return llave % tamArreglo;
}

void TablaHash::agregar(const int llave, const std::string valor){
	int valorHash = funcionHash(llave);
	
	std::list<std::pair<int, std::string> > &lista = tabla[valorHash];
	
	bool existeLlave = false;
	
	std::list<std::pair<int, std::string> >::iterator it = lista.begin();
	
	for(; it != lista.end(); it++ ){
		
		std::cout << it->first << std::endl;
		if(it->first == llave){
			existeLlave = true;
			it->second = valor;
			std::cout << "La llave existe. El valor será reemplazado" << std::endl;
			break;
		}
	}
	
	if(!existeLlave){
		std::pair<int, std::string> pareja(llave, valor);
		lista.emplace_back(pareja);
	}
	
	return;
}

void TablaHash::remover(const int llave){
	int valorHash = funcionHash(llave);
	
	std::list<std::pair<int, std::string> > &lista = tabla[valorHash];
	
	bool existeLlave = false;
	
	std::list<std::pair<int, std::string> >::iterator it = lista.begin();
	
	for(; it != lista.end(); it++ ){
		if(it->first == llave){
			existeLlave = true;
			it = lista.erase(it);
			std::cout << "Item removido" << std::endl;
			break;
		}
	}
	
	if(!existeLlave){
		std::cout << "Item no encontrado " << std::endl;
	}
	return;
}

std::string TablaHash::buscar(const int llave) {

	int valorHash = funcionHash(llave);
	
	std::list<std::pair<int, std::string> > lista = tabla[valorHash];
	
	bool existeLlave = false;
	std::string valor = "";
	
	std::list<std::pair<int, std::string> >::const_iterator it = lista.begin();
	
	for(; it != lista.end(); it++ ){
		if(it->first == llave){
			existeLlave = true;
			valor = it->second;
			break;
		}
	}
	
	if(!existeLlave){
		std::cout << "Item no encontrado " << std::endl;
	}
	
	return valor;
}

void TablaHash::imprimir() const {
	for(int i = 0; i < tamArreglo; i++){
		
		if(tabla[i].size() == 0){
			continue;
		}
		
		std::list<std::pair<int, std::string> >::const_iterator it = tabla[i].begin();
		
		for(; it != tabla[i].end(); it++){
			std::cout << "Llave: " << it->first << ", Valor: " << it->second << std::endl;
		}
		
	}
	
	return;
}

#endif
