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
	return 0;
}
