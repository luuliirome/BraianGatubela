#include <iostream>
#include "pila.h"
#include "dicT.h"
#include <cassert>
#include <string>
#include <sstream>

using namespace std;

struct Nodo{
	int entero;
};


int main(){
	dicT<int> a;
	bool b= a.esVacio();
	assert(b==1);
	//////////////////////
	string x ="direccion";
	int* num=new int(4174);
	a.definir(x, *num);
	assert(a.definido(x) ==1);
	assert(a.obtener(x) ==4174);
	//////////////////////
	int* num2= new int(5093);
	string y="casa";
	a.definir(y, *num);
	int* num3=new int(4541);
	a.definir("superfragilisticoespiralidoso", *num);
	//////////////////////
	Conj<string> cla= a.claves();
	typename Conj<string>::Iterador it=cla.CrearIt();
	cout << "Los Hijos Son: "<<endl;
	while(it.HaySiguiente()){
		cout <<"   -"<<it.Siguiente()<< endl;
		it.Avanzar();
	}
	cout << "El Hijo mas chico es : " << a.Minimo()<<endl;
	cout << "El Hijo mas grande es: "<< a.Maximo()<< endl;
	delete(num);
	delete(num2);
	delete(num3);
	a.borrar(x);
	//TODO OK HASTA ACA, SIN PERDIDA DE MEMORIA :P
	return 0;
}
