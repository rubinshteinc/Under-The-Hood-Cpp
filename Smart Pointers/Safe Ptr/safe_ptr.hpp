#include <cstdio>

template <typename T>
inline SafePtr<T>::SafePtr(T* ptr):_ptr(ptr) {
}

template <typename T>
inline SafePtr<T>::SafePtr(SafePtr<T>& other):_ptr(other._ptr){
    other._ptr = NULL;
}

template <typename T>
inline SafePtr<T>& SafePtr<T>::operator=(SafePtr<T> &other){
    if(_ptr == other._ptr){
        return *this;
    }
    delete _ptr;
    _ptr = other._ptr;
    other._ptr = NULL;
    return *this;
}


template <typename T>
inline SafePtr<T>::~SafePtr(){
    delete _ptr;
    _ptr = NULL;
}
