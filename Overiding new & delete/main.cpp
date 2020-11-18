#include <iostream>
#include <cstdio>
void f(){
    std::cout << "f()" << std::endl;

}

int gVar;
int gVar1 = 0;
int gVar2 = 7;

int main() {
    int a;
    static int b;
    int* buffer = new int;

    std::cout << "gVar:" << &gVar << std::endl;
    std::cout << "gVar1:" << &gVar1 << std::endl;
    std::cout << "gVar2:" << &gVar2 << std::endl;
    std::cout << "b:" << &b << std::endl;
    std::cout << "a:" << &a << std::endl;
    std::cout << "buffer:" << buffer << std::endl;
    std::cout << "f():" << f << std::endl;
    std::cout << "printf():" << printf << std::endl;


    return 0;
}