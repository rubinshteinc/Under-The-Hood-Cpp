#include <cstdio>

template <typename T>
inline UniquePtr<T>::UniquePtr(T* ptr):_ptr(ptr) {
}

template <typename T>
inline UniquePtr<T>::~UniquePtr(){
    delete _ptr;
    _ptr = NULL;
}


