#ifndef UNDER_THE_HOODIN_HERITANCE_C_POLYMORPHISM_DEFS_H
#define UNDER_THE_HOODIN_HERITANCE_C_POLYMORPHISM_DEFS_H

#include <stdio.h>


/*Mangling Name:
 *   _Z + length scope name + name scope (G - global) + length name + name + m_type (F (C - ctor , D - dtor / V) + S - static , K - const
 *   _parameters:  length m_type  + m_type + K - const /  P - pointer / R - reference.
*/

int next_id;

extern const char DOLLAR_DEFAULT_SYMBOL;
extern const char HASH_DEFAULT_SYMBOL;
extern const char STRUDEL_DEFAULT_SYMBOL;


enum VTABLE{DTOR, PRINT_CONST_CHAR, PRINT_LONG_CHAR, GET_DEFAULT_SYMBOL};

typedef void*(*ptrToFunc)(void*);
typedef void (*print_long_char)(const void* , long, char) ;
typedef void (*print_const_char)(const void *, const char *);
typedef void (*dtor)(void*);
typedef char (*get_default_symbol)(const void*);

extern void*(*vTableTextFormatter[2])(void*);
extern void* (*vTableDefaultTextFormatter[2])(void*);
extern void*(*vTablePrePostFixer[4])(void*);
extern void*(*vTablePrePostDollarFixer[4])(void*);
extern void*(*vTablePrePostHashFixer[4])(void*);
extern void*(*vTablePrePostFloatDollarFixer[4])(void*);
extern void*(*vTablePrePostChecker[4])(void*);
extern void*(*vTableMultiplier[2])(void*);



/*//// TextFormatter ////////////*/
typedef struct TextFormatter
{
    void*(**vptr)(void*);

}TextFormatter;

/*///// TextFormatter Defs ///////////*/

void _Z13TextFormatter13TextFormatterFD_13TextFormatterP(TextFormatter *this);


/*/// DefaultTextFormatter ///////////*/

typedef struct DefaultTextFormatter
{
    TextFormatter m_textFormatter;
    int m_id;

}DefaultTextFormatter;

DefaultTextFormatter* generateFormatterArray();

void _Z20DefaultTextFormatter20DefaultTextFormatterFC_20DefaultTextFormatterP(DefaultTextFormatter *this);
void _Z20DefaultTextFormatter20DefaultTextFormatterFC_20DefaultTextFormatterP20DefaultTextFormatterPK(DefaultTextFormatter *this, const DefaultTextFormatter *other);
const DefaultTextFormatter* _Z20DefaultTextFormatter10assignmentF_20DefaulttextFormatterP20DefaultTextFormatterPK(DefaultTextFormatter *this, const DefaultTextFormatter *other);
void _Z20DefaultTextFormatterFD_20DefaultTextFormatterPk(DefaultTextFormatter *this);

void _Z20DefaultTextFormatter5printFK_20DefaultTextFormatterPK4charPK(const DefaultTextFormatter *this, const char* text);


/*/// PrePostFixer ///////////*/

typedef struct PrePostFixer     /*public DefaultTextFormatter*/
{
    DefaultTextFormatter m_defaultTextFormatter;
    const char* pre;
    const char* post;

}PrePostFixer;

/*/// PrePostFixer Defs ///////////*/

void _Z12PrePostFixer12PrePostFixerFC_12PrePostFixerP4charPK4charPK(PrePostFixer *this, const char* prefix, const char* postfix);
void _Z12PrePostFixer12PrePostFixerFD_12PrePostFixerP(PrePostFixer *this);
void _Z12PrePostFixer12PrePostFixerFC_12PrePostFixerP12PrePostFixerPK(PrePostFixer *this, const PrePostFixer *other);    /*///inline///*/

void _Z12PrePostFixer5printFK_12PrePostFixerPK4charPK(const PrePostFixer *this, const char* text);
void _Z12PrePostFixer5printFK_12PrePostFixerPK4long4char(const PrePostFixer *this, long num, char symbol);
char _Z12PrePostFixer16getDefaultSymbolFK_12PrePostFixerPK(const PrePostFixer *this) ;


/*/// PrePostDollarFixer ///////////*/

typedef struct PrePostDollarFixer       /*public PrePostFixer*/
{
    PrePostFixer m_prePostFixer;

}PrePostDollarFixer;

void _Z18PrePostDollarFixer18PrePostDollarFixerFC_18PrePostDollarFixerP4charPK4charPK(PrePostDollarFixer *this, const char* prefix, const char* postfix);
void _Z18PrePostDollarFixer18PrePostDollarFixerFC_18PrePostDollarFixerP18PrePostDollarFixerPK(PrePostDollarFixer *this, const PrePostDollarFixer *other);
void _Z18PrePostDollarFixer18PrePostDollarFixerFD_18PrePostDollarFixerP(PrePostDollarFixer *this);

void _Z18PrePostDollarFixer5printFK_18PrePostDollarFixerPK3int4char(const PrePostDollarFixer *this, int num, char symbol);
void _Z18PrePostDollarFixer5printFK_18PrePostDollarFixerPK4long4char(const PrePostDollarFixer *this, long num, char symbol);
void _Z18PrePostDollarFixer5printFK_18PrePostDollarFixerPK6double4char(const PrePostDollarFixer *this, double num, char symbol);
char _Z18PrePostDollarFixer16getDefaultSymbolFK_18PrePostDollarFixerPK(const PrePostDollarFixer *this);




/*/// PrePostHashFixer //////////*/

    typedef struct PrePostHashFixer     /*public PrePostDollarFixer*/
{
    PrePostDollarFixer m_prePostDollarFixer;
    int m_precision;

}PrePostHashFixer;

/*/// PrePostHashFixer Defs ///////////*/

void PrePostHashFixerCtor(PrePostHashFixer *this, int prc);
void PrePostHashFixerDtor(PrePostHashFixer *this);

void printpphf(const PrePostHashFixer *this, int num, char symbol);
void printpphfd(const PrePostHashFixer *this,long num, char symbol);
char getDefaultSymbolpphf(const PrePostHashFixer *this);


/*/// PrePostFloatDollarFixer ///////////*/


typedef struct PrePostFloatDollarFixer      /*public PrePostDollarFixer*/
{
    PrePostDollarFixer m_prePostDollarFixer;

}PrePostFloatDollarFixer;

/*/// PrePostFloatDollarFixer Defs ///////////*/

void PrePostFloatDollarFixerCtor(PrePostFloatDollarFixer *this, const char* prefix, const char* postfix);
void PrePostFloatDollarFixerDtor(PrePostFloatDollarFixer *this);

void printppfdff(const PrePostFloatDollarFixer *this, float num);
void printppfdffc(const PrePostFloatDollarFixer *this, float num, char symbol);
char getDefaultSymbolppfdf(const PrePostFloatDollarFixer *this);


/*/// PrePostChecker ///////////*/

typedef struct PrePostChecker
{
    PrePostFloatDollarFixer m_prePostFloatDollarFixer;


}PrePostChecker;

/*// PrePostChecker defs //////////*/

void PrePostCheckerCtorDefault(PrePostChecker *this);
void PrePostCheckerDtorDefault(PrePostChecker *this);

void printThisSymbolUsingFunc(const PrePostChecker *this);
void printThisSymbolDirectly(const PrePostChecker *this);
void printDollarSymbolByCastUsingFunc(const PrePostChecker *this);
void printDollarSymbolByScopeUsingFunc(const PrePostChecker *this);
void printDollarSymbolByCastDirectly(const PrePostChecker *this);
void printDollarSymbolByScopeDirectly(const PrePostChecker *this);


/*/// Multiplier ///////////*/

typedef struct Multiplier       /*public DefaultTextFormatter*/
{
    DefaultTextFormatter m_defaultTextFormatter;
    int m_times;

}Multiplier;

/*/// Multiplier Defs ///////////*/

void MultiplierDtor(Multiplier *this);
void printMulti(Multiplier *this, const char *text);


#endif /*/UNDER_THE_HOODIN_HERITANCE_C_POLYMORPHISM_DEFS_H*/
