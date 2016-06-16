#ifndef DICCT_H
#define DICCT_H

#include "pila.h"
#include "Conj.h"
#include <iostream>


using namespace aed2;
using namespace std;

template < typename T>
class dicT
{
public:
	class Iterador;

	dicT();
	dicT(const dicT<T> &otro);
	~dicT();
	bool esVacio() const;
	void definir(string clave, T& elem);
	bool definido(string clave) const;
	T& obtener(string clave) const;
	void borrar(string clave);

	 aed2::Conj<string> claves() ;

	Iterador CrearIt();
	bool operator ==(const dicT<T> &otro) const;


	class Iterador{
	public:
		Iterador();

        Iterador(const typename dicT<T>::Iterador& otra);
		bool HaySiguiente() const;
		string  SiguienteClave();
		T& SiguienteSignificado();
		void Avanzar();
	private:

		pair<string, T> Siguiente;
		aed2::Conj<string> claves;
		dicT<T>* dic;
	};

private:
	struct Nodo{
		Nodo():  letra('a'), padre(NULL){
			ponerTodoEnNull(hijos);
		}
		Nodo(char c, Nodo* p) :  letra(c), padre(p){
			ponerTodoEnNull(hijos);
		} 
		//averiguar si puedo hacer una copia del elemento sin tener q si o si crear un nodo
		// solucion altenra a este problme es crear un nodo copiando el elemento y  poner el significado de ese nodo en el elemento
		Nodo(char c, Nodo* p, T& elem ): significado(&elem), letra(c), padre(p){
			ponerTodoEnNull(hijos);
		} 
		T* significado;
		char letra;
		Nodo* padre;
		Nodo* hijos [256];
		

		void ponerTodoEnNull(Nodo* hijos []){
			
			for(int i=0; i<256; i++) hijos[i]=NULL;
		}
	};

	Nodo* raiz;

	template <typename K>
	void apilarHijos(Nodo* actual, pila<K>& recoridos){
		for(int i=255;i>=0;i--){
			if(actual->hijos[i]!=NULL)recoridos.apilar(*actual->hijos[i]);
		}
	}

	Lista<Nodo*> hijos(Nodo* actual){
		Lista<Nodo*> res;
		int i=0;
		while(i<256){
			if(actual->hijos[i]!=NULL)res.AgregarAtras(actual->hijos[i]);
			i++;
		}
		return res;
	}

	bool EsVaciaHijos(Nodo* actual){
		bool res=true;
		int i=0;
		while(i<256){
			if(actual->hijos[i]!=NULL) return false;
			i++;
		}
		return true;

	}

	bool esPalabra(Nodo* actual){
		return (actual->significado!=NULL);
	}
	string DameNombre(Nodo* n){
		Nodo* actual= n;
		string res;
		while(actual->padre!=NULL){
			string aux;
			aux.push_back(actual->letra);
			res.insert(0,aux);
			actual=actual->padre;
		}
		return res;
	}
	void destruir(Nodo* actual){
		if(actual!=NULL){
			if(esPalabra(actual)) delete(actual->significado);
			for(int i=0; i<255;i++) destruir(actual->hijos[i]);
			
			delete(actual);
		}
	}
	

};

template <typename T>
dicT<T>::dicT(){
	raiz= new Nodo();

}
template <typename T>
dicT<T>::~dicT(){
	destruir(raiz);
	
}

template <typename T>
bool dicT<T>::esVacio()const {
	int i=0;
	while(i<27){
		if(raiz->hijos[i]!=NULL) return false;
		i++;
	}
	return true;
}

template<typename T>
void dicT<T>::definir(string clave, T& elem){
	Nodo* actual = raiz;
	int i=0;
	int tamanio = clave.size();
	while(i<tamanio){
		if( actual->hijos[clave[i]] != NULL) actual= actual->hijos[clave[i]];
		else {
			actual->hijos[clave[i]] = new Nodo( clave[i], actual);
			actual= actual->hijos[clave[i]];
		}
		i++;
	}	
	// version bizzarra d como copiar un elementeo... preguntar!
	Nodo* aux = new Nodo('a', NULL, elem);
	actual->significado= aux->significado;
	delete aux;
}

template <typename T>
bool dicT<T>::definido(string clave) const{
	Nodo* actual = raiz;
	int i=0;
	while(actual->hijos[clave[i]] != NULL){
		actual = actual->hijos[clave[i]];
		i++;
	}
	if(i==clave.size()){
		return true;
	}
	else return false;
}

template<typename T>
T& dicT<T>::obtener(string clave) const{
	Nodo* actual = raiz;
	int i=0;
	int tamanio = clave.size();
	while(i<tamanio){
		actual= actual->hijos[clave[i]];
		i++;
	}	
	return *(actual->significado);
}

template<typename T>
void dicT<T>::borrar(string s){
	Nodo* actual= raiz;
	int i=0;
	int tamanio=s.size();
	


	pila<Nodo> recorridos;
	while(i<tamanio){
		recorridos.apilar(*actual);
		actual= actual -> hijos[s[i]];
		
		i++;
	}
	recorridos.apilar(*actual);
	delete(actual->significado);
	while(recorridos.size()>1){
		actual=&recorridos.tope();
		recorridos.desapilar();
		
		if(EsVaciaHijos(actual)){// por alguna razon estoy no esta devolviendo bien y me deja lagos de memoria
			int aux= actual->letra;
			recorridos.tope().hijos[aux]=0;
			delete(actual);
			
		}
	}
}

template<typename T>
aed2::Conj<string> dicT<T>::claves() {
	Nodo* actual= raiz;
	pila<Nodo> recorridos;
	apilarHijos(actual, recorridos);
	Conj<string> res;

	while(!(recorridos.EsVacia())){
		actual = &recorridos.tope();
		recorridos.desapilar();
		
		if(! EsVaciaHijos(actual)) apilarHijos(actual, recorridos);
		if(esPalabra(actual)){
			string* aux= new string(DameNombre(actual)); ///ANDA DAME NOMBRE ! :D

			res.AgregarRapido(*aux); //aca hay problema	
		}
		
	}

	//ACA PASA ALGO AL DEVOLVER, HAST ESTE PUNTO RES TIENE UN ELEMENTO Y FUNCIONA BIEN!
	//CONSUTAR
	///////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////	
	///////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////


	return res;
}

template <typename T>
bool dicT<T>::operator ==(const dicT<T> &otro) const{
	bool res;
	typename Conj<string>::Iterador it = otro.claves().CrearIt();
	while(it.HaySiguiente()){
		if(!definido(it.Siguiente())) return false;
		if(otro.obtener(it.Siguiente()) != this.obtener(it.Siguiente())) return false;
		it.Avanzar();
	}
	return true;
}





#endif