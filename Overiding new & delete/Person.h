#ifndef OVERIDING_NEW___DELETE_PERSON_H
#define OVERIDING_NEW___DELETE_PERSON_H
#include <cstddef>

class Person{
public:
    Person(const char *fullName, unsigned int id, unsigned char age);
    Person(Person &person);
    Person& operator=(Person &person);
    const char* getName()const { return _fullName;}
    unsigned int getID()const { return _id;}
    unsigned int getAge()const { return _age;}

    void* operator new(size_t size);
    void operator delete(void* deletedPerson);

private:
    static char* s_pool;
    static void* s_firstFree;

    unsigned int _id;
    char _fullName[32];
    unsigned char _age;

    static void* initializedFreeList();
    void * operator new[](size_t);
    void operator delete[](void*);

};

#endif //OVERIDING_NEW___DELETE_PERSON_H
