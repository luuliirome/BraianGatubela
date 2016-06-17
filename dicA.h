#ifndef DICC_A
#define DICC_A

#include "pila.h"
#include "Conj.h"
#include <iostream>

using namespace aed2;
using namespace std;

template<typename K, typename T>
class dicA{
public:
	struct Nodo{
			Nodo(K c, T& s, Nodo* p)
			: significado(&s), clave(c), padre(p), izq(NULL), der(NULL){}
			T* significado;
			K clave;
			Nodo* padre;
			Nodo* izq;
			Nodo* der;
	};

	class Iterador;
	///////////////////////////
	dicA();  				//definida
	///////////////////////////
	dicA(const dicA<K,T> &otro);//definida
	///////////////////////////
	~dicA();  				//definida
	///////////////////////////
	bool esVacio() const;  	//definida
	///////////////////////////
	void definir(K clave, T& elem);  //definida
	///////////////////////////
	bool definido(K clave) const;  //definida
	///////////////////////////
	T& obtener(K clave);  //definida
	///////////////////////////
	void borrar(K clave);  //definida
	///////////////////////////
	aed2::Conj<K> claves();  //definida
	///////////////////////////
	Iterador CrearIt();  
	///////////////////////////
	bool operator ==( dicA<K,T> &otro) ;  //definida
	///////////////////////////
	string Minimo(); 		//definida
	///////////////////////////
	string Maximo(); 		//definida
	///////////////////////////

	class Iterador{
	public:
		Iterador();
        ///////////////////////////
		Iterador(const typename dicA<K,T>::Iterador& otra);
		///////////////////////////
		bool HaySiguiente() const;
		///////////////////////////
		string  SiguienteClave();
		///////////////////////////
		T& SiguienteSignificado();
		///////////////////////////
		void Avanzar();
	private:
		Nodo* siguente;
		pila<Nodo> camino;
		dicA<K,T>* dic;
	};
private:
	
	Nodo* raiz;
	///////////////////////////////////////////////
	//FUNCIONES AUXILIARES
	///////////////////////////////////////////////
	void destruir(Nodo* n){
		if(n->der!=NULL) destruir(n->der);
		if(n->izq!=NULL) destruir(n->izq);
		if(n!=NULL)delete(n);
	}
};
template<typename K, typename T>
dicA<K,T>::dicA(): raiz(NULL)
{}

template<typename K, typename T>
dicA<K,T>::~dicA(){
	destruir(raiz);
}

template<typename K, typename T>
bool dicA<K,T>::esVacio() const{
	return (raiz==NULL);
}
template<typename K, typename T>
void dicA<K,T>::definir(K c, T& elem){
	if(raiz==NULL)raiz=new Nodo(c, elem, NULL);
	else{
		Nodo* actual =raiz;
		while(actual->clave != c){
			if(actual->clave < c){
				if(actual->der==NULL){
					actual->der=new Nodo(c, elem, actual);
				}
				actual=actual->der;	
			}
			else{
				if(actual->izq==NULL) actual->izq = new Nodo(c, elem, actual);
				actual=actual->izq;
			}
		}
	}
}

template<typename K, typename T>
bool dicA<K, T>::definido(K c) const{
	Nodo* actual=raiz;
	while(actual!=NULL){
		if(actual->clave == c) return true;
		else if(actual->clave < c){
			actual=actual->der;
		}
		else{
			actual = actual->izq;
		}
	}
}

template<typename K, typename T>
T& dicA<K,T>::obtener(K c){
	Nodo* actual=raiz;
	while(actual->clave != c){
		if(actual->clave < c) actual=actual->der;
		else actual=actual->izq;
	}
	return actual->significado;
}

#endif