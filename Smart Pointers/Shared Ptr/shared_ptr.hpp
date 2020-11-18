#include <iostream>

template <typename T>
inline SharedPtr<T>::SharedPtr(T *data):_ptr(data), _refCount(NULL){
    _refCount = new size_t(1);
}

template <typename T>
template <typename S>
inline SharedPtr<T>::SharedPtr(const SharedPtr<S> &other):_ptr(other._ptr), _refCount(other._refCount){
    increaseCount();
}
template <typename T>
inline SharedPtr<T>::SharedPtr(const SharedPtr &other):_ptr(other._ptr), _refCount(other._refCount){
    increaseCount();
}

template <typename T>
template <typename S>
inline SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<S> &other){
    if(_ptr == other._ptr){
        return *this;
    }

    this -> destroy();

    _ptr = other._ptr;
    _refCount = other._refCount;
    increaseCount();

    return *this;
}

template <typename T>
inline SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr &other){
    if(_ptr == other._ptr){
        return *this;
    }

    this -> destroy();

    _ptr = other._ptr;
    _refCount = other._refCount;
    increaseCount();

    return *this;
}

template <typename T>
inline SharedPtr<T>::~SharedPtr(){
    this -> destroy();
}

template <typename T>
inline void SharedPtr<T>::destroy() {

    if(*_refCount) {
        decreaseCount();
    }
	
    if(!*_refCount){
        delete _ptr;
        _ptr = NULL;

        delete _refCount;
        _refCount = NULL;
    }
}
