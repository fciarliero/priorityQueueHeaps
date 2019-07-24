#ifndef _COLAPRIOR_H_
#define _COLAPRIOR_H_

#include <vector>

using namespace std;
template<class T>
class ColaPrior {
public:
	ColaPrior();

	// Cantidad de elementos en la cola.
	int tam() const;

	// Encola un elemento.
	//
	// Nota: si se implementa usando un vector, es O(n) en peor caso.
	//
	void encolar(const T& elem);

	// Devuelve el elemento de mayor prioridad.
	// Pre: tam() > 0
	const T& proximo() const;

	// Saca el elemento de mayor prioridad.
	//
	// Nota: es O(n) en peor caso.
	//
	// Pre: tam() > 0
	void desencolar();

	// Constructor que hace heapify.
	ColaPrior(const vector<T>& elems);

private:
	vector<T> _arbol;
	int _currentSize;
	//-1 devuelve si no tiene padre/hijoder/hijoIz
	int padre(int i){
		int res= ((i -1)/2);
		if (res <0 || i == 0){
			res = -1;
		}
		return res;
	};
	int hijoDer(int i){
		int res = 2 * i + 2;
		if (res > _currentSize){
			res = -1;
		}
		return res;
	}
	int hijoIz(int i){
		int res = 2*i +1;
		if ( res > _currentSize){
			res = -1;
		}
		return res;
	}

	//devuelve el indice en _arbol del mayor de los hijos de una posicion en el arbol
	//devuelve -1 si no tiene hijos
	int maxHijos(int);

	void siftUp( int );
	void siftDown(int);

};

#include "ColaPrior.hpp"

#endif /*_COLAPRIOR_H_*/
