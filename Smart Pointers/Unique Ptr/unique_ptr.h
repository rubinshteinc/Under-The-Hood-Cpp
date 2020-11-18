#ifndef SMART_PIINTERS_UNIQUE_PTR_H
#define SMART_PIINTERS_UNIQUE_PTR_H

class UnCopyable{
public:
    UnCopyable(){}
private:
    UnCopyable(UnCopyable&);
    UnCopyable& operator=(UnCopyable&);
};


template <typename T>
class UniquePtr:private UnCopyable {
public:
    explicit UniquePtr(T* ptr);
    T& operator*()const {return *_ptr;}
    T* operator->()const { return _ptr;}
    bool operator==(T* val)const { return _ptr == val;}
    bool operator!=(T* val)const { return _ptr != val;}

    //get function according to Scott Meyers
    T* get()const {return _ptr;}
    ~UniquePtr();


private:
    T* _ptr;

};


#include "unique_ptr.hpp"

#endif //SMART_PIINTERS_UNIQUE_PTR_H
