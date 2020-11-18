#include "c_polymorphism_defs.h"
#include <stdlib.h>
void doPrePostFixer()
{
    PrePostFixer angleBrackets;
    printf("\n--- start doPrePostFixer() ---\n\n");

    _Z12PrePostFixer12PrePostFixerFC_12PrePostFixerP4charPK4charPK(&angleBrackets, "<<< ", " >>>");
    _Z12PrePostFixer5printFK_12PrePostFixerPK4charPK(&angleBrackets, "Hello World!");
    _Z12PrePostFixer5printFK_12PrePostFixerPK4long4char(&angleBrackets, -777, '\0');
    _Z12PrePostFixer5printFK_12PrePostFixerPK4long4char(&angleBrackets, 350, '#');
    _Z12PrePostFixer5printFK_12PrePostFixerPK4long4char(&angleBrackets, (long int) (3.14), '\0');

    printf("\n--- end doPrePostFixer() ---\n\n");
    _Z12PrePostFixer12PrePostFixerFD_12PrePostFixerP(&angleBrackets);
}

void doPrePostDollarFixer()
{
    PrePostDollarFixer asterisks;
    printf("\n--- start doPrePostDollarFixer() ---\n\n");

    _Z18PrePostDollarFixer18PrePostDollarFixerFC_18PrePostDollarFixerP4charPK4charPK(&asterisks, "***** ", " *****");
    _Z18PrePostDollarFixer5printFK_18PrePostDollarFixerPK3int4char(&asterisks, -777, DOLLAR_DEFAULT_SYMBOL);
    _Z18PrePostDollarFixer5printFK_18PrePostDollarFixerPK3int4char(&asterisks, 350, '#');
    _Z18PrePostDollarFixer5printFK_18PrePostDollarFixerPK6double4char(&asterisks, 3.14f, DOLLAR_DEFAULT_SYMBOL);

    printf("\n--- end doPrePostDollarFixer() ---\n\n");
    _Z18PrePostDollarFixer18PrePostDollarFixerFD_18PrePostDollarFixerP(&asterisks);
}

void doPrePostChecker()
{
    PrePostChecker check;

    printf("\n--- start doPrePostChecker() ---\n\n");

    PrePostFloatDollarFixerCtor((PrePostFloatDollarFixer*)&check,  "[[[[" , "]]]]");
    ((TextFormatter*)&check) -> vptr = vTablePrePostChecker;
    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", check.m_prePostFloatDollarFixer.m_prePostDollarFixer.m_prePostFixer.pre, check.m_prePostFloatDollarFixer.m_prePostDollarFixer.m_prePostFixer.post);

    printThisSymbolUsingFunc(&check);
    printThisSymbolDirectly(&check);
    printDollarSymbolByCastDirectly(&check);
    printDollarSymbolByScopeDirectly(&check);
    printDollarSymbolByCastUsingFunc(&check);
    printDollarSymbolByScopeUsingFunc(&check);

    printf("\n--- end doPrePostChecker() ---\n\n");
    PrePostCheckerDtorDefault(&check);
}

void doPrePostFloatDollarFixer()
{
    PrePostFloatDollarFixer hashes;
    PrePostDollarFixer hashes2;
    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");

    PrePostFloatDollarFixerCtor(&hashes, "### ", " ###");
    printppfdff(&hashes, -777);
    printppfdffc(&hashes, 350, '#');
    printppfdff(&hashes, 3.14f);

    _Z18PrePostDollarFixer18PrePostDollarFixerFC_18PrePostDollarFixerP18PrePostDollarFixerPK(&hashes2,
                                                                                             (PrePostDollarFixer *) &hashes);

    _Z18PrePostDollarFixer5printFK_18PrePostDollarFixerPK6double4char(&hashes2, 7.5, DOLLAR_DEFAULT_SYMBOL);
    _Z18PrePostDollarFixer5printFK_18PrePostDollarFixerPK3int4char(&hashes2, 100, DOLLAR_DEFAULT_SYMBOL);

    printf("\n--- end doPrePostFloatDollarFixer() ---\n\n");
    _Z18PrePostDollarFixer18PrePostDollarFixerFD_18PrePostDollarFixerP(&hashes2);
    PrePostFloatDollarFixerDtor(&hashes);

}

void runAsPrePostFixerRef(const PrePostFixer* pp)
{
    printf("\n--- start runAsPrePostFixerRef() ---\n\n");

    ((print_long_char)((TextFormatter*)pp) -> vptr [PRINT_LONG_CHAR])(pp, 123, '\0');

    printf("\n--- end runAsPrePostFixerRef() ---\n\n");

}

void runAsPrePostDollarFixerRef(const PrePostDollarFixer* pp)
{
    printf("\n--- start runAsPrePostDollarFixerRef() ---\n\n");

    _Z18PrePostDollarFixer5printFK_18PrePostDollarFixerPK3int4char(pp, 123, DOLLAR_DEFAULT_SYMBOL);

    printf("\n--- end runAsPrePostDollarFixerRef() ---\n\n");

}

void runAsPrePostDollarFixerObj(PrePostDollarFixer pp)
{
    printf("\n--- start runAsPrePostDollarFixerObj() ---\n\n");

    _Z18PrePostDollarFixer5printFK_18PrePostDollarFixerPK3int4char(&pp, 123, DOLLAR_DEFAULT_SYMBOL);

    printf("\n--- end runAsPrePostDollarFixerObj() ---\n\n");

    _Z18PrePostDollarFixer18PrePostDollarFixerFD_18PrePostDollarFixerP(&pp);
}

void runAsPrePostHashFixerRef(const PrePostHashFixer* pp)
{
    printf("\n--- start runAsPrePostHashFixerRef() ---\n\n");

    printpphf(pp, 123, HASH_DEFAULT_SYMBOL);

    printf("\n--- end runAsPrePostHashFixerRef() ---\n\n");
}

void doMultiplier()
{
    Multiplier m1, m2, m3, m4;
    printf("\n--- start doMultiplier() ---\n\n");

    _Z20DefaultTextFormatter20DefaultTextFormatterFC_20DefaultTextFormatterP((DefaultTextFormatter *) &m1);
    ((TextFormatter*)&m1) -> vptr = vTableMultiplier;
    m1.m_times = 3;
    printf("--- Multiplier CTOR: times = %d\n", m1.m_times);

    _Z20DefaultTextFormatter20DefaultTextFormatterFC_20DefaultTextFormatterP((DefaultTextFormatter *) &m2);
    ((TextFormatter*)&m2) -> vptr = vTableMultiplier;
    m2.m_times = 5;
    printf("--- Multiplier CTOR: times = %d\n", m2.m_times);

    DefaultTextFormatterCopyCtor((DefaultTextFormatter*)&m3, (DefaultTextFormatter*)&m1);
    m3.m_times = m1.m_times;
    ((TextFormatter*)&m3) -> vptr = vTableMultiplier;

    DefaultTextFormatterCopyCtor((DefaultTextFormatter*)&m4, (DefaultTextFormatter*)&m2);
    m4.m_times = m2.m_times;
    ((TextFormatter*)&m4) -> vptr = vTableMultiplier;

    printMulti(&m1, "abc ");
    printMulti(&m2, "abc ");
    printMulti(&m3, "abc ");
    printMulti(&m4, "abc ");

    printf("\n--- end doMultiplier() ---\n\n");

    MultiplierDtor(&m4);
    MultiplierDtor(&m3);
    MultiplierDtor(&m2);
    MultiplierDtor(&m1);
}

void doFormatterArray()
{
    int i = 0;

    DefaultTextFormatter formatters[3];
    PrePostDollarFixer f1;
    Multiplier f2;
    PrePostChecker f3;

    printf("\n--- start doFormatterArray() ---\n\n");

    _Z18PrePostDollarFixer18PrePostDollarFixerFC_18PrePostDollarFixerP4charPK4charPK(&f1, "!!! ", " !!!");
    DefaultTextFormatterCopyCtor(&formatters[0], (DefaultTextFormatter*)&f1);
    _Z18PrePostDollarFixer18PrePostDollarFixerFD_18PrePostDollarFixerP(&f1);


    _Z20DefaultTextFormatter20DefaultTextFormatterFC_20DefaultTextFormatterP((DefaultTextFormatter *) &f2);
    ((TextFormatter*)&f2) -> vptr = vTableMultiplier;
    f2.m_times = 4;
    printf("--- Multiplier CTOR: times = %d\n", f2.m_times);
    DefaultTextFormatterCopyCtor(&formatters[1], (DefaultTextFormatter*)&f2);
    MultiplierDtor(&f2);

    PrePostCheckerCtorDefault(&f3);
    DefaultTextFormatterCopyCtor(&formatters[2], (DefaultTextFormatter*)&f3);
    PrePostCheckerDtorDefault(&f3);

    for (; i < 3; ++i)
        _Z20DefaultTextFormatter5printFK_20DefaultTextFormatterPK4charPK(&formatters[i], "Hello World!");

    printf("\n--- end doFormatterArray() ---\n\n");

    _Z20DefaultTextFormatterFD_20DefaultTextFormatterPk(&formatters[2]);
    _Z20DefaultTextFormatterFD_20DefaultTextFormatterPk(&formatters[1]);
    _Z20DefaultTextFormatterFD_20DefaultTextFormatterPk(&formatters[0]);

}

void doFormatterPtrs()
{    int i = 0;
    DefaultTextFormatter* pfmt[3];
    PrePostDollarFixer *f1;
    Multiplier *f2;
    PrePostChecker *f3;

    printf("\n--- start doFormatterPtrs() ---\n\n");

    f1 = (void*)malloc(sizeof(PrePostDollarFixer));
    _Z18PrePostDollarFixer18PrePostDollarFixerFC_18PrePostDollarFixerP4charPK4charPK(f1, "!!! ", " !!!");
    pfmt[0] = (DefaultTextFormatter *)f1;

    f2 = (void*)malloc(sizeof(Multiplier));
    _Z20DefaultTextFormatter20DefaultTextFormatterFC_20DefaultTextFormatterP((DefaultTextFormatter *) f2);
    ((TextFormatter*)f2) -> vptr = vTableMultiplier;
    f2 -> m_times = 4;
    printf("--- Multiplier CTOR: times = %d\n", f2 -> m_times);
    pfmt[1] = (DefaultTextFormatter*)f2;

    f3 = (void*)malloc(sizeof(PrePostChecker));
    PrePostCheckerCtorDefault(f3);
    pfmt[2] = (DefaultTextFormatter*)f3;

    for (; i < 3; ++i)
        ((print_const_char)((TextFormatter*)pfmt[i]) -> vptr[PRINT_CONST_CHAR])(pfmt[i], "Hello World!");

    PrePostCheckerDtorDefault((PrePostChecker *)pfmt[2]);
    free(pfmt[2]);

    MultiplierDtor((Multiplier *)pfmt[1]);
    free(pfmt[1]);

    _Z18PrePostDollarFixer18PrePostDollarFixerFD_18PrePostDollarFixerP((PrePostDollarFixer *) pfmt[0]);
    free(pfmt[0]);

    printf("\n--- end doFormatterPtrs() ---\n\n");
}

void doFormatterDynamicArray()
{
    int i = 0;
    DefaultTextFormatter* formatters;

    printf("\n--- start doFormatterDynamicArray() ---\n\n");

    formatters = generateFormatterArray();

    for (; i < 3; ++i)
        ((print_const_char)((TextFormatter*)&formatters[i]) -> vptr[PRINT_CONST_CHAR])(&formatters[i], "Hello World!");


    for (i = 2; i >= 0; --i){
        _Z20DefaultTextFormatterFD_20DefaultTextFormatterPk(&formatters[i]);
    }
    free(formatters);

    printf("\n--- start doFormatterDynamicArray() ---\n\n");
}

int main()
{

    PrePostHashFixer hfix;
    PrePostDollarFixer temp;

    printf("\n--- Start main() ---\n\n");


    doPrePostFixer();
    doPrePostDollarFixer();
    doPrePostFloatDollarFixer();
    doPrePostChecker();

    PrePostHashFixerCtor(&hfix, 4);
    runAsPrePostFixerRef((PrePostFixer*)&hfix);
    runAsPrePostDollarFixerRef((PrePostDollarFixer*)&hfix);
    _Z18PrePostDollarFixer18PrePostDollarFixerFC_18PrePostDollarFixerP18PrePostDollarFixerPK(&temp,
                                                                                             (const PrePostDollarFixer *) &hfix);
    runAsPrePostDollarFixerObj(temp);
    runAsPrePostHashFixerRef(&hfix);

    doMultiplier();

    doFormatterArray();
    doFormatterPtrs();
    doFormatterDynamicArray();

    printf("\n--- End main() ---\n\n");

    PrePostHashFixerDtor(&hfix);

    return 0;
}
