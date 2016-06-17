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
	//ESTOY MODIFICANDO ALGO
	
	dicT<int> a;
	bool b= a.esVacio();
	assert(b==1);
	string x ="direccion";
	int* num=new int(4174);
	a.definir(x, *num);
	assert(a.definido(x) ==1);
	assert(a.obtener(x) ==4174);
	int* num2= new int(5093);
	string y="casa";
	a.definir(y, *num2);
	int* num3=new int(4541);
	a.definir("superfragilisticoespiralidoso", *num3);


	/*Conj<string> cla= a.claves();
	typename Conj<string>::Iterador it=cla.CrearIt();
	while(it.HaySiguiente()){
		cout << it.Siguiente()<< endl;
		it.Avanzar();
	}*/
	cout << "Hijo mas chico es : " << a.Minimo()<<endl;
	cout << "Hijo mas grande es: "<< a.Maximo()<< endl;




	//a.borrar(x);
	/*typename Conj<string>::Iterador it= a.claves().CrearIt();
	while(it.HaySiguiente()){
		cout << it.Siguiente()<<endl;
		it.Avanzar();
	}*/
	
	
	//TODO OK HASTA ACA, SIN PERDIDA DE MEMORIA :P
	/*string str;
	char c= 'a';
	string aux;
	aux.push_back('a');

	string* prueba= new string(aux);
	
	
	str.insert(0,aux);
	cout << *prueba << endl;
	*/ /* Conj<int> a;
	
	int num1= 1;
	int num2=2;
	int num3=3;
	int num4=4;
	a.AgregarRapido(num1);
	typename Conj<int>::Iterador it = a.CrearIt(); 
	

	while(it.HaySiguiente()){
		cout << it.Siguiente()<<endl;
		it.Avanzar();
	}*/


	return 0;
}/*

icT();
	dicT(const dicT<T> &otro);
	~dicT();
	bool esVacio() const;
	void definir(string clave, T& elem);
	bool definido(string clave) const;
	T& obtener(string clave) const;
	void borrar(string clave);
*/