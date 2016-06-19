#include <iostream>
#include "pila.h"
#include "dicA.h"
#include <cassert>
#include <string>
#include <sstream>

using namespace std;

struct Nodo{
	int entero;
};

void devolverBool(bool b){
	if(b) cout << "True"<< endl;
	else cout << "False"<< endl;
}


int main(){
	dicA<string, int> edades;
	int eyo=20;
	int echaro=20;
	int elucia=20;
	edades.definir("gregorio", eyo);	
	edades.definir("charo", echaro);
	edades.definir("turra", elucia); 
	edades.definir("brian", eyo);
	edades.definir("dante", eyo);
	assert(1==edades.definido("gregorio"));
	assert(1==edades.definido("charo"));
	assert(1==edades.definido("turra")); 
	assert(0==edades.definido("tuvieja")); // funciona defindio
	//edades.definir("brian", eyo);
	//edades.definir("dante", eyo);
	cout<< "los nodos hasta ahroa son : "<<endl;
	edades.mostrarNodos();
	edades.borrar("gregorio");
	edades.borrar("brian");
	edades.borrar("charo");
	edades.borrar("dante");
	edades.borrar("turra");
	cout << "\nHago borrado: "<<endl;
	edades.mostrarNodos();
	//edades.borrar("brian");
	//
	//edades.borrar("turra");
	//edades.borrar("dante");

	

	//edades.borrar("charo");


	return 0;
}	
