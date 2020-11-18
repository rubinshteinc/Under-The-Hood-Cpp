
template <typename T>
class SafePtr{
public:
    explicit SafePtr(T* ptr);
    SafePtr(SafePtr<T>& ptr);
    SafePtr<T>& operator=(SafePtr<T> &ptr);
    T& operator*()const {return *_ptr;}
    T* operator->()const { return _ptr;}
    bool operator==(T* val)const { return _ptr == val;}
    bool operator!=(T* val)const { return _ptr != val;}

    //get function according to Scott Meyers
    T* get()const {return _ptr;}
    ~SafePtr();

private:
    T* _ptr;
};

#include "safe_ptr.hpp"