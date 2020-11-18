#ifndef SMART_PIINTERS_SHARED_PTR_H
#define SMART_PIINTERS_SHARED_PTR_H

#include <cstddef>

template <typename T>
class SharedPtr {
public:
    template <typename S> friend class SharedPtr;

    explicit SharedPtr(T* data);
    template <typename S>
    SharedPtr(const SharedPtr<S> &other);
    SharedPtr(const SharedPtr &other);
    template <typename S>
    SharedPtr& operator=(const SharedPtr<S> &other);
    SharedPtr& operator=(const SharedPtr &other);
    T& operator*()const { return *_ptr;}
    T* operator->()const { return _ptr;}
    operator bool() const {return *_refCount;}

    //get function according to Scott Meyers
    T* get()const {return _ptr;}

    ~SharedPtr();

private:
    T *_ptr;
    size_t *_refCount;

    void destroy();
    void increaseCount(){++(*_refCount);}
    void decreaseCount(){ --(*_refCount);}

};


#include "shared_ptr.hpp"
#endif //SMART_PIINTERS_SHARED_PTR_H
