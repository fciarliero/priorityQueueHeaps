
template<class T>
ColaPrior<T>::ColaPrior() {
    _currentSize = 0;
}

template<class T>
int ColaPrior<T>::tam() const {
	return _currentSize;

}

template<class T>
void ColaPrior<T>::encolar(const T& elem) {
	_arbol.push_back(elem);
    _currentSize++;
    siftUp(_currentSize -1);

}

template<class T>
const T& ColaPrior<T>::proximo() const {
	return _arbol[0];
}

template<class T>
void ColaPrior<T>::desencolar() {
    _arbol[0] = _arbol[_currentSize -1];
    _currentSize--;
    _arbol.pop_back();
    siftDown(0);

}

template<class T>
ColaPrior<T>::ColaPrior(const vector<T>& elems) {
	_currentSize = 0;
    int tam = elems.size() -1 ;
    for (int i = 0; i <= tam; ++i) {
        encolar(elems[i]);
    }
}
template<class T>
void ColaPrior<T>::siftUp(int i) {
    bool seguir = false;
    int papa = padre(i);
    if ( papa != -1){
        if( _arbol[padre(i)] < _arbol[i] ){
            //seguro hay una forma nativa de vectores de hacer esto pero duele pensar
            T aux = _arbol[padre(i)];
            _arbol[padre(i)] = _arbol[i];
            _arbol[i] = aux;
            seguir = true;
            }
        }
    if ( seguir ){
        siftUp(padre(i));
    }
}

template<class T>
void ColaPrior<T>::siftDown(int i) {
    bool seguir = false;
    int max_hijo = maxHijos(i);
    if ( max_hijo != -1){
        if( _arbol[max_hijo]>_arbol[i]){
            T aux = _arbol[max_hijo];
            _arbol[max_hijo] = _arbol[i];
            _arbol[i]= aux;
            seguir = true;
        }
    }
    if ( seguir ){
        siftDown(max_hijo);
    }




}
template<class T>
int ColaPrior<T>::maxHijos(int i) {
    int hijo_iz = hijoIz(i);
    int hijo_de = hijoDer(i);

    int aux = -1;
    if ( hijo_de != -1){
        aux = hijo_de;
        if ( hijo_iz != -1){
            if ( _arbol[hijo_iz] > _arbol[aux]){
                aux = hijo_iz;
            }
        }
    }else if ( hijo_iz != -1){
        aux = hijo_iz;
    }
    return aux;
}

