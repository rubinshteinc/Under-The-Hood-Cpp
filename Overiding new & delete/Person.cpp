#include "Person.h"
#include <cstring>
#define NUM_BLOCKS_PERSON 10


char poolMemory[sizeof(Person) * NUM_BLOCKS_PERSON];
char* Person::s_pool = poolMemory;
void* Person::s_firstFree = initializedFreeList();

Person::Person(const char *fullName, unsigned int id, unsigned char age):_id(id), _age(age){
    strcpy(_fullName, fullName);
}

Person::Person(Person &person):_id(person._id), _age(person._age){
    strcpy(_fullName, person._fullName);
}


Person& Person::operator=(Person &person){
    if(this == &person){
        return *this;
    }
    strcpy(_fullName, person._fullName);
    _id = person._id;
    _age = person._age;

    return *this;
}


void* Person::operator new(size_t size) {

    void *newPerson = s_firstFree;
    size_t nextBlock = *(size_t *) s_firstFree;
    s_firstFree = (void*)nextBlock;

    return newPerson;
}

void Person::operator delete(void* deletedPerson){

    void* temp = s_firstFree;
    s_firstFree = deletedPerson;
    *(size_t*)s_firstFree = (size_t)temp;
}


void* Person::initializedFreeList() {
    size_t *currentPersonBlock = reinterpret_cast<size_t *>(poolMemory);

    for (int i = 0; i < NUM_BLOCKS_PERSON; ++i) {
        *currentPersonBlock = (size_t) ((char *) currentPersonBlock + sizeof(Person));
        currentPersonBlock = (size_t *) *currentPersonBlock;
    }
    *currentPersonBlock = '\0';

    return poolMemory;
}