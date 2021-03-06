//#include <iostream>
//#include <string>
//#include "safe_ptr.h"
//
//class Base{
//public:
//    Base(int num): a(num){}
//    int a;
//};
//
//void testSafePtr();
//void testCtor();
//void testCopyCtor();
//void testAssignmentOperator();
//void testOperatorAsterisk();
//void testOperatorArrow();
//void testGetRawPtr();
//void testDtor();
//
//void testDtor();
//
//int main() {
//    testSafePtr();
//    return 0;
//}
//
//
//
//void testSafePtr(){
//    std::cout << "-------- Test Safe Ptr --------" << std::endl;
//    testCtor();
//    testCopyCtor();
//    testAssignmentOperator();
//    testOperatorAsterisk();
//    testOperatorArrow();
//    testGetRawPtr();
//    testDtor();
//}
//void testCtor() {
//    int num = 5;
//    SafePtr<int> pInt1(new int);
//    *pInt1 = num;
//    SafePtr<char> pChar(new char[2]);
//    SafePtr<std::string> pString(new std::string("Hello"));
//    SafePtr<Base> pMyClass(new Base(2));
//
//    std::cout << "Ctor          success " << std::endl;
//}
//void testCopyCtor(){
//
//    int num = 5;
//    SafePtr<int> pInt1(new int);
//    *pInt1 = num;
//
//    //UniquePtr<int> pInt2 = pInt1; - COMPILER ERROR
//    std::cout << "CopyCtor      success " << std::endl;
//
//}
//
//void testAssignmentOperator(){
//
//    char c1 = 'A';
//    char c2 = 'B';
//
//    SafePtr<char> p1(new char);
//    *p1 = c1;
//    SafePtr<char> p2(new char);
//    *p2 = c2;
//
//    // p2 = p1; - COMPILER ERROR
//    std::cout << "operator=     success " << std::endl;
//
//}
//void testOperatorAsterisk(){
//    char c1 = 'A';
//    char c2 = 'B';
//
//    SafePtr<char> p1(new char);
//    *p1 = c1;
//    SafePtr<char> p2(new char);
//    *p2 = c2;
//
//    if(*p1 == 'A' and *p2 == 'B'){
//        std::cout << "operator*     success " << std::endl;
//    }
//    else {
//        std::cout << "operator*       failed " << std::endl;
//
//    }
//}
//
//void testOperatorArrow(){
//    SafePtr<Base> p(new Base(2));
//    if(p -> a == 2){
//        std::cout << "operator->    success " << std::endl;
//    }
//    else {
//        std::cout << "operator->    failed " << std::endl;
//
//    }
//}
//
//void testGetRawPtr(){
//    SafePtr<Base> p(new Base(1));
//    if(p.get()->a == 1){
//        std::cout << "get           success " << std::endl;
//    }
//    else {
//        std::cout << "get           failed " << std::endl;
//
//    }
//}
//
//void testDtor() {
//
//    SafePtr<int> pInt(new int);
//    SafePtr<char> pChar(new char[2]);
//    SafePtr<std::string> pString(new std::string("Hello"));
//    SafePtr<Base> pMyClass(new Base(2));
//
//    std::cout << "Dtor          Test with Valgrind flag.." << std::endl;
//}