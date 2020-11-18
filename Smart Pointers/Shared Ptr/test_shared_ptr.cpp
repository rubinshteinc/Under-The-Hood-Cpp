#include <iostream>
#include <string>
#include "shared_ptr.h"
#include "test_shared_ptr.h"

class Base{
public:
    Base(int num): a(num){}
    virtual void func(){ std::cout << "I am Base" << std::endl;}
    virtual ~Base(){}
    int a;
};



class Derive: public Base{
public:
    Derive(int num1, int num2):Base(num1), b(num2){}
    void func(){ std::cout << "I am Derive" << std::endl;}

private:
    int b;
};


int main() {
    testSafePtr();
    return 0;
}




void testSafePtr(){
    std::cout << "-------- Test Shared Ptr --------" << std::endl;
    testCtor();
    testCopyCtor();
    testAssignmentOperator();
    testOperatorAsterisk();
    testOperatorArrow();
    testGetRawPtr();
    testOperatorBool();
    testInherit();
    testDtor();
}


void testCtor() {
    int num = 5;
    SharedPtr<int> pInt1(new int);
    *pInt1 = num;
    SharedPtr<char> pChar(new char[2]);
    SharedPtr<std::string> pString(new std::string("Hello"));
    SharedPtr<Base> pMyClass(new Base(2));

    std::cout << "Ctor              success " << std::endl;
}
void testCopyCtor(){

    int num = 5;
    SharedPtr<int> pInt1(new int);
    *pInt1 = num;

    SharedPtr<int> pInt2 = pInt1;
    std::cout << "CopyCtor          success " << std::endl;

}

void testAssignmentOperator(){

    char c1 = 'A';
    char c2 = 'B';

    SharedPtr<char> p1(new char);
    *p1 = c1;
    SharedPtr<char> p2(new char);
    *p2 = c2;

     p2 = p1;
    std::cout << "operator=         success " << std::endl;
}

void testOperatorAsterisk(){
    char c1 = 'A';
    char c2 = 'B';

    SharedPtr<char> p1(new char);
    *p1 = c1;
    SharedPtr<char> p2(new char);
    *p2 = c2;

    if(*p1 == 'A' and *p2 == 'B'){
        std::cout << "operator*         success " << std::endl;
    }
    else {
        std::cout << "operator*         failed " << std::endl;

    }
}

void testOperatorArrow(){
    SharedPtr<Base> p(new Base(2));
    if(p -> a == 2){
        std::cout << "operator->        success " << std::endl;
    }
    else {
        std::cout << "operator->        failed " << std::endl;

    }
}

void testGetRawPtr(){
    SharedPtr<Base> p(new Base(1));
    if(p.get()->a == 1){
            std::cout << "get               success " << std::endl;
    }
    else {
        std::cout << "get                   failed " << std::endl;

    }
}

void testOperatorBool() {
    SharedPtr<short> p(new short(50));
    if (p) {
        std::cout << "opearator bool    success " << std::endl;
    } else {
        std::cout << "opearator bool    failed " << std::endl;
    }
}

void testInherit(){
    SharedPtr<Derive> pDerive (new Derive(2, 3));
    SharedPtr<Base> pB = pDerive;

//    Base* pBase = new Derive(1, 2);

    pB -> func();
}


void testDtor() {

    SharedPtr<int> pInt(new int);
    SharedPtr<char> pChar(new char[2]);
    SharedPtr<std::string> pString(new std::string("Hello"));
    SharedPtr<Base> pMyClass(new Base(2));

    std::cout << "Dtor              Test with Valgrind flag.." << std::endl;
}
