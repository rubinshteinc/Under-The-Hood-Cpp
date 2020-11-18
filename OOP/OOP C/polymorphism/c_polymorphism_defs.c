#include "c_polymorphism_defs.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

const char DOLLAR_DEFAULT_SYMBOL = '$';
const char HASH_DEFAULT_SYMBOL = '#';
const char STRUDEL_DEFAULT_SYMBOL = '@';
int next_id = 0;

void*(*vTableTextFormatter[])(void*) = {(ptrToFunc)_Z13TextFormatter13TextFormatterFD_13TextFormatterP, NULL};

void* (*vTableDefaultTextFormatter[])(void*) = {(ptrToFunc)_Z20DefaultTextFormatterFD_20DefaultTextFormatterPk,
                                                 (ptrToFunc)_Z20DefaultTextFormatter5printFK_20DefaultTextFormatterPK4charPK};

void*(*vTablePrePostFixer[])(void*) = {(ptrToFunc)_Z12PrePostFixer12PrePostFixerFD_12PrePostFixerP,
                                        (ptrToFunc) _Z12PrePostFixer5printFK_12PrePostFixerPK4charPK,
                                        (ptrToFunc) _Z12PrePostFixer5printFK_12PrePostFixerPK4long4char,
                                        (ptrToFunc) _Z12PrePostFixer16getDefaultSymbolFK_12PrePostFixerPK};

void*(*vTablePrePostDollarFixer[])(void*) = {(ptrToFunc) _Z18PrePostDollarFixer18PrePostDollarFixerFD_18PrePostDollarFixerP,
                                              (ptrToFunc) _Z12PrePostFixer5printFK_12PrePostFixerPK4charPK,
                                              (ptrToFunc) _Z18PrePostDollarFixer5printFK_18PrePostDollarFixerPK4long4char,
                                              (ptrToFunc) _Z18PrePostDollarFixer16getDefaultSymbolFK_18PrePostDollarFixerPK};

void*(*vTablePrePostHashFixer[])(void*) = {(ptrToFunc) PrePostHashFixerDtor,
                                            (ptrToFunc) _Z12PrePostFixer5printFK_12PrePostFixerPK4charPK,
                                            (ptrToFunc) printpphfd,
                                            (ptrToFunc) getDefaultSymbolpphf};

void*(*vTablePrePostFloatDollarFixer[])(void*) = {(ptrToFunc) PrePostFloatDollarFixerDtor,
                                                   (ptrToFunc) _Z12PrePostFixer5printFK_12PrePostFixerPK4charPK,
                                                   (ptrToFunc) _Z18PrePostDollarFixer5printFK_18PrePostDollarFixerPK4long4char,
                                                   (ptrToFunc) getDefaultSymbolpphf};

void*(*vTablePrePostChecker[])(void*) = {(ptrToFunc)PrePostCheckerDtorDefault,
                                         (ptrToFunc)_Z12PrePostFixer5printFK_12PrePostFixerPK4charPK,
                                         (ptrToFunc)_Z18PrePostDollarFixer5printFK_18PrePostDollarFixerPK4long4char,
                                         (ptrToFunc)getDefaultSymbolppfdf};


void*(*vTableMultiplier[])(void*) = {(ptrToFunc )MultiplierDtor,
                                      (ptrToFunc )printMulti};

/*//// TextFormatter Defs ////////////*/

void _Z13TextFormatter13TextFormatterFD_13TextFormatterP(TextFormatter *this){}

/*//// DefaultTextFormatter Defs ////////////*/

void _Z20DefaultTextFormatter20DefaultTextFormatterFC_20DefaultTextFormatterP(DefaultTextFormatter *this)
{
    ((TextFormatter*)this) -> vptr = vTableTextFormatter;
    this -> m_id = next_id++;
    ((TextFormatter*)this) -> vptr = vTableDefaultTextFormatter;
    printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", this -> m_id);
}
void _Z20DefaultTextFormatterFD_20DefaultTextFormatterPk(DefaultTextFormatter *this)
{
    printf("--- DefaultTextFormatter DTOR\n########## D %d ##########\n", this -> m_id);
    ((TextFormatter*)this) -> vptr = vTableTextFormatter;
    ((dtor)((TextFormatter*)this) -> vptr[DTOR])(this);
}

void _Z20DefaultTextFormatter20DefaultTextFormatterFC_20DefaultTextFormatterP20DefaultTextFormatterPK(DefaultTextFormatter *this, const DefaultTextFormatter *other)
{
    ((TextFormatter*)this) -> vptr = vTableTextFormatter;
    this -> m_id = next_id++;
    ((TextFormatter*)this) -> vptr = vTableDefaultTextFormatter;
    printf("--- DefaultTextFormatter Copy CTOR, from m_id: %d\n########## C %d ##########\n", other -> m_id, this -> m_id);
}

const DefaultTextFormatter* _Z20DefaultTextFormatter10assignmentF_20DefaulttextFormatterP20DefaultTextFormatterPK(DefaultTextFormatter *this, const DefaultTextFormatter* other)
{
    printf("--- DefaultTextFormatter operator=(), from m_id: %d to m_id: %d\n", other -> m_id, this -> m_id);
    return this;
}

void _Z20DefaultTextFormatter5printFK_20DefaultTextFormatterPK4charPK(const DefaultTextFormatter *this, const char* text)
{
    printf("%-60s | ", "[DefaultTextFormatter::print(const char*)]");
    printf("%s\n", text);
}

DefaultTextFormatter* generateFormatterArray()
{
    DefaultTextFormatter *newDefaultTextFormatter = (void*)malloc(3 * sizeof(DefaultTextFormatter));
    int i = 0;
    for(; i < 3; i++){
        _Z20DefaultTextFormatter20DefaultTextFormatterFC_20DefaultTextFormatterP(&newDefaultTextFormatter[i]);
    }
    return newDefaultTextFormatter;
}



/*//// PrePostFixer Defs ////////////*/
void _Z12PrePostFixer12PrePostFixerFC_12PrePostFixerP4charPK4charPK(PrePostFixer *this, const char* prefix, const char* postfix)
{
    _Z20DefaultTextFormatter20DefaultTextFormatterFC_20DefaultTextFormatterP((DefaultTextFormatter *) this);
    ((TextFormatter*)this) -> vptr = vTablePrePostFixer;
    this -> pre = prefix;
    this -> post = postfix;
    printf("--- PrePostFixer CTOR: \"%s\"...\"%s\"\n", this -> pre, this -> post);
}

void _Z12PrePostFixer12PrePostFixerFC_12PrePostFixerP12PrePostFixerPK(PrePostFixer *this, const PrePostFixer *other)
{
    _Z20DefaultTextFormatter20DefaultTextFormatterFC_20DefaultTextFormatterP20DefaultTextFormatterPK(
            (DefaultTextFormatter *) this, (DefaultTextFormatter *) other);
    memcpy(this + sizeof(DefaultTextFormatter), other + sizeof(DefaultTextFormatter), sizeof(PrePostFixer) - sizeof(DefaultTextFormatter));
    ((TextFormatter*)this) -> vptr = vTablePrePostFixer;
}


void _Z12PrePostFixer12PrePostFixerFD_12PrePostFixerP(PrePostFixer *this)
{
    printf("--- PrePostFixer DTOR: \"%s\"...\"%s\"\n", this -> pre, this -> post);
    ((TextFormatter*)this) -> vptr = vTableDefaultTextFormatter;
    ( ((TextFormatter*)this) -> vptr[DTOR])(this);

}

void _Z12PrePostFixer5printFK_12PrePostFixerPK4charPK(const PrePostFixer *this, const char* text)
{
    printf("%-60s | ", "[PrePostFixer::print(const char*)]");
    printf("%s%s%s\n", this -> pre, text, this -> post);
}

char _Z12PrePostFixer16getDefaultSymbolFK_12PrePostFixerPK(const PrePostFixer *this)
{
    return '\0';
}

void _Z12PrePostFixer5printFK_12PrePostFixerPK4long4char(const PrePostFixer *this, long num, char symbol)
{
    printf("%-60s | ", "[PrePostFixer::print(long, char)]");
    printf("-->\n");

    if (symbol){
        printf("%-60s | ", "[PrePostFixer::print_num(long, char)]");
        printf("%s%c%ld%s\n", this -> pre, symbol, num, this -> post);
    }
    else{
        printf("%-60s | ", "[PrePostFixer::print_num(long)]");
        printf("%s%ld%s\n", this -> pre, num, this -> post);
    }
}

/*//// PrePostDollarFixer Defs ////////////*/

void _Z18PrePostDollarFixer18PrePostDollarFixerFC_18PrePostDollarFixerP4charPK4charPK(PrePostDollarFixer *this, const char* prefix, const char* postfix)
{
    _Z12PrePostFixer12PrePostFixerFC_12PrePostFixerP4charPK4charPK((PrePostFixer *) this, prefix, postfix);
    ((TextFormatter*)this) -> vptr = vTablePrePostDollarFixer;

    printf("--- PrePostDollarFixer CTOR: \"%s\"...\"%s\"\n", this -> m_prePostFixer.pre, this -> m_prePostFixer.post);
}

void _Z18PrePostDollarFixer18PrePostDollarFixerFC_18PrePostDollarFixerP18PrePostDollarFixerPK(PrePostDollarFixer *this, const PrePostDollarFixer *other)
{
    _Z12PrePostFixer12PrePostFixerFC_12PrePostFixerP12PrePostFixerPK((PrePostFixer *) this, (PrePostFixer *) other);
    this -> m_prePostFixer.pre = other -> m_prePostFixer.pre;
    this -> m_prePostFixer.post = other -> m_prePostFixer.post;
    ((TextFormatter*)this) -> vptr = vTablePrePostDollarFixer;
    printf("--- PrePostDollarFixer Copy CTOR: \"%s\"...\"%s\"\n", this -> m_prePostFixer.pre, other -> m_prePostFixer.post);
}

void _Z18PrePostDollarFixer18PrePostDollarFixerFD_18PrePostDollarFixerP(PrePostDollarFixer *this)
{
    printf("--- PrePostDollarFixer DTOR: \"%s\"...\"%s\"\n", this -> m_prePostFixer.pre, this -> m_prePostFixer.post);
    ((TextFormatter*)this) -> vptr = vTablePrePostFixer;
    ((dtor)((TextFormatter*)this) -> vptr[DTOR])(this);
}

void _Z18PrePostDollarFixer5printFK_18PrePostDollarFixerPK3int4char(const PrePostDollarFixer *this, int num, char symbol)
{
    printf("%-60s | ", "[PrePostDollarFixer::print(int, char)]");
    printf("-->\n");

    ((print_long_char)((TextFormatter*)this) -> vptr [PRINT_LONG_CHAR])(this, (long)(num), symbol);
}

void _Z18PrePostDollarFixer5printFK_18PrePostDollarFixerPK4long4char(const PrePostDollarFixer *this, long num, char symbol)
{
    printf("%-60s | ", "[PrePostDollarFixer::print(long, char)]");
    printf("-->\n");

    _Z12PrePostFixer5printFK_12PrePostFixerPK4long4char((PrePostFixer *) this, num, symbol);
}

void _Z18PrePostDollarFixer5printFK_18PrePostDollarFixerPK6double4char(const PrePostDollarFixer *this, double num, char symbol)
{
    printf("%-60s | ", "[PrePostDollarFixer::print(double, char)]");
    printf("%s%c%f%s\n", this -> m_prePostFixer.pre, symbol, num, this -> m_prePostFixer.post);
}

char _Z18PrePostDollarFixer16getDefaultSymbolFK_18PrePostDollarFixerPK(const PrePostDollarFixer *this)
{
    return DOLLAR_DEFAULT_SYMBOL;
}

/*//// PrePostHashFixer Defs ////////////*/

void PrePostHashFixerCtor(PrePostHashFixer *this, int prc)
{
    _Z18PrePostDollarFixer18PrePostDollarFixerFC_18PrePostDollarFixerP4charPK4charPK((PrePostDollarFixer *) this,
                                                                                     "===> ", " <===");
    ((TextFormatter*)this) -> vptr = vTablePrePostHashFixer;
    this -> m_precision = prc;

    printf("--- PrePostHashFixer CTOR: \"%s\"...\"%s\", precision: %d\n", this -> m_prePostDollarFixer.m_prePostFixer.pre, this -> m_prePostDollarFixer.m_prePostFixer.post, this -> m_precision);

    printf("%-60s | ", "[PrePostHashFixer::print(double, char)]");
    printf("%s[%c%.*f]%s\n", this -> m_prePostDollarFixer.m_prePostFixer.pre, HASH_DEFAULT_SYMBOL, this -> m_precision, 9999.9999, this -> m_prePostDollarFixer.m_prePostFixer.post);
}

void PrePostHashFixerDtor(PrePostHashFixer *this) {
    printf("--- PrePostHashFixer DTOR: \"%s\"...\"%s\"\n", this->m_prePostDollarFixer.m_prePostFixer.pre, this->m_prePostDollarFixer.m_prePostFixer.post);
    ((TextFormatter*)this) -> vptr  = vTablePrePostDollarFixer;
    ((dtor)((TextFormatter*)this) -> vptr[DTOR])(this);
}

void printpphf(const PrePostHashFixer *this, int num, char symbol)
{
    printf("%-60s | ", "[PrePostHashFixer::print(int, char)]");
    printf("-->\n");

    printf("%-60s | ", "[PrePostHashFixer::print(double, char)]");
    printf("%s[%c%.*f]%s\n", this -> m_prePostDollarFixer.m_prePostFixer.pre, symbol, this -> m_precision, (double)num, this -> m_prePostDollarFixer.m_prePostFixer.post);
}

void printpphfd(const PrePostHashFixer *this,long num, char symbol) {
    printf("%-60s | ", "[PrePostHashFixer::print(long, char)]");
    printf("-->\n");

    printf("%-60s | ", "[PrePostHashFixer::print(double, char)]");
    printf("%s[%c%.*f]%s\n", ((PrePostFixer *) this)->pre, symbol, this->m_precision, (double) (num),((PrePostFixer *) this)->post);
}

char getDefaultSymbolpphf(const PrePostHashFixer *this)
{
    return HASH_DEFAULT_SYMBOL;
}

/*//// PrePostFloatDollarFixer Defs ////////////*/

void PrePostFloatDollarFixerCtor(PrePostFloatDollarFixer *this, const char* prefix, const char* postfix)
{
    _Z18PrePostDollarFixer18PrePostDollarFixerFC_18PrePostDollarFixerP4charPK4charPK((PrePostDollarFixer *) this,
                                                                                     prefix, postfix);
    ((TextFormatter*)this) -> vptr = vTablePrePostFloatDollarFixer;

    printf("--- PrePostFloatDollarFixer CTOR: \"%s\"...\"%s\"\n", this->m_prePostDollarFixer.m_prePostFixer.pre, this -> m_prePostDollarFixer.m_prePostFixer.post);
}

void PrePostFloatDollarFixerDtor(PrePostFloatDollarFixer *this)
{
    printf("--- PrePostFloatDollarFixer DTOR: \"%s\"...\"%s\"\n", this->m_prePostDollarFixer.m_prePostFixer.pre, this -> m_prePostDollarFixer.m_prePostFixer.post);
    ((TextFormatter*)this) -> vptr = vTablePrePostDollarFixer;
    ((dtor)((TextFormatter*)this) -> vptr[DTOR])(this);
}

void printppfdff(const PrePostFloatDollarFixer *this, float num)
{
    printf("%-60s | ", "[PrePostFloatDollarFixer::print(float)]");
    printf("-->\n");

    printppfdffc(this, num, STRUDEL_DEFAULT_SYMBOL);
}

void printppfdffc(const PrePostFloatDollarFixer *this, float num, char symbol)
{
    printf("%-60s | ", "[PrePostFloatDollarFixer::print(float, char)]");

    printf("%s%c%.2f%s\n", this -> m_prePostDollarFixer.m_prePostFixer.pre, symbol, num, this -> m_prePostDollarFixer.m_prePostFixer.post);
}

char getDefaultSymbolppfdf(const PrePostFloatDollarFixer *this)
{
    return STRUDEL_DEFAULT_SYMBOL;
}
/*//// PrePostChecker Defs ////////////*/



void PrePostCheckerCtorDefault(PrePostChecker *this)
{
    PrePostFloatDollarFixerCtor((PrePostFloatDollarFixer*)this,  "[[[[" , "]]]]");
   ((TextFormatter*)this) -> vptr = vTablePrePostChecker;

    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", this -> m_prePostFloatDollarFixer.m_prePostDollarFixer.m_prePostFixer.pre, this -> m_prePostFloatDollarFixer.m_prePostDollarFixer.m_prePostFixer.post);
}

void PrePostCheckerDtorDefault(PrePostChecker *this)
{
    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n",  this -> m_prePostFloatDollarFixer.m_prePostDollarFixer.m_prePostFixer.pre, this -> m_prePostFloatDollarFixer.m_prePostDollarFixer.m_prePostFixer.post);

    ((TextFormatter*)this) -> vptr = vTablePrePostFloatDollarFixer;
    ((dtor)((TextFormatter*)this) -> vptr[DTOR])(this);

}
void printThisSymbolUsingFunc(const PrePostChecker *this)
{
    printf("%-60s | ", "[PrePostChecker::printThisSymbolUsingFunc()]");

    printf("Default symbol is %c\n", ((get_default_symbol)((TextFormatter*)this) -> vptr[GET_DEFAULT_SYMBOL])(this));
}

void printThisSymbolDirectly(const PrePostChecker *this)
{
    printf("%-60s | ", "[PrePostChecker::printThisSymbolDirectly()]");

    printf("Default symbol is %c\n", STRUDEL_DEFAULT_SYMBOL);
}

void printDollarSymbolByCastUsingFunc(const PrePostChecker *this)
{
    printf("%-60s | ", "[PrePostChecker::printDollarSymbolByCastUsingFunc()]");

    printf("Default symbol is %c\n", ((get_default_symbol)((TextFormatter*)this) -> vptr[GET_DEFAULT_SYMBOL])(this));
}

void printDollarSymbolByScopeUsingFunc(const PrePostChecker *this)
{
    printf("%-60s | ", "[PrePostChecker::printDollarSymbolByScopeUsingFunc()]");

    printf("Default symbol is %c\n",
           _Z18PrePostDollarFixer16getDefaultSymbolFK_18PrePostDollarFixerPK((PrePostDollarFixer *) this));
}

void printDollarSymbolByCastDirectly(const PrePostChecker *this)
{
    printf("%-60s | ", "[PrePostChecker::printDollarSymbolByCastDirectly()]");

    printf("Default symbol is %c\n", DOLLAR_DEFAULT_SYMBOL);
}

void printDollarSymbolByScopeDirectly(const PrePostChecker *this)
{
    printf("%-60s | ", "[PrePostChecker::printDollarSymbolByScopeDirectly()]");

    printf("Default symbol is %c\n", DOLLAR_DEFAULT_SYMBOL);
}


/*//// Multiplier Defs ////////////*/

void MultiplierDtor(Multiplier *this)
{
    printf("--- Multiplier DTOR: m_times = %d\n", this -> m_times);
    _Z20DefaultTextFormatterFD_20DefaultTextFormatterPk((DefaultTextFormatter *) this);
}

void printMulti(Multiplier *this, const char *text)
{
    int i = 0;

    printf("%-60s | ", "[Multiplier::print(const char*)]");

    for (; i < this  -> m_times; ++i)
    printf("%s", text);
    printf("\n");
}

