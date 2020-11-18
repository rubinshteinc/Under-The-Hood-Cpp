#include <stdio.h>
#include "c_encapsulation_defs.h"


int flag88 = 0;
int flag99 = 0;


void thisFunc()
{
    static Box box99;
    if(flag99 == 2){
        _Z3Box3boxFD_3boxP(&box99);
        return;
    }
    printf("\n--- thisFunc() ---\n\n");
    if(!flag99){
        _Z3Box3BoxFC_3boxP6double6double6double(&box99, 99, 99, 99);
        flag99++;
    }
    Z3Box14AssignmentMultF_3BoxKP6double(&box99,10);

}

void thatFunc()
{
    static Box box88;
    if(flag88 == 2){
        _Z3Box3boxFD_3boxP(&box88);
        return;
    }

    printf("\n--- thatFunc() ---\n\n");
    if(!flag88){
        _Z3Box3BoxFC_3boxP6double6double6double(&box88, 88, 88, 88);
        flag88++;
    }

    Z3Box14AssignmentMultF_3BoxKP6double(&box88,10);
}

void doBoxes()
{
    Box b1, b2, b3, b4;
    printf("\n--- Start doBoxes() ---\n\n");


    _Z3Box3BoxFC_3BoxP6double(&b1, 3);
    _Z3Box3BoxFC_3boxP6double6double6double(&b2, 4, 5, 6);

    printf("b1 volume: %f\n", b1.width * b1.length * b1.height);
    printf("b2 volume: %f\n", b2.width * b2.length * b2.height);

    Z3Box14AssignmentMultF_3BoxKP6double(&b1,1.5);
    Z3Box14AssignmentMultF_3BoxKP6double(&b2,0.5);


    printf("b1 volume: %f\n", b1.width * b1.length * b1.height);
    printf("b2 volume: %f\n", b2.width * b2.length * b2.height);

    _Z3Box3BoxFC_3BoxP3BoxP(&b3, &b2);
    _Z3Box3BoxFC_3BoxP3BoxP(&b4, &b3);
    Z3Box14AssignmentMultF_3BoxKP6double(&b4, 3);

    printf("b3 %s b4\n", (b1.length == b2.length && b1.width == b2.width && b1.height == b2.height) ? "equals" : "does not equal");

    Z3Box14AssignmentMultF_3BoxKP6double(&b3,1.5);
    Z3Box14AssignmentMultF_3BoxKP6double(&b4,0.5);

    printf("Now, b3 %s b4\n",(b3.length == b4.length && b3.width == b4.width && b3.height == b4.height) ? "equals" : "does not equal");

    printf("\n--- End doBoxes() ---\n\n");

    _Z3Box3boxFD_3boxP(&b4);
    _Z3Box3boxFD_3boxP(&b3);
    _Z3Box3boxFD_3boxP(&b2);
    _Z3Box3boxFD_3boxP(&b1);
}


void doShelves()
{
    Box aBox, b, b1;
    Shelf aShelf;

    printf("\n--- start doShelves() ---\n\n");

    _Z3Box3BoxFC_3BoxP6double(&aBox, 5);


    _Z5Shelf5ShelfFc_5ShelfP(&aShelf);

    _Z5Shelf5printF_5ShelfKP(&aShelf);
    _Z5Shelf6setBoxF_5ShelfP3int3BoxKP(&aShelf, 1, &largeBox);
    _Z5Shelf6setBoxF_5ShelfP3int3BoxKP(&aShelf, 0, &aBox);

    _Z5Shelf5printF_5ShelfKP(&aShelf);
    _Z1G7messageV =  "This is the total volume on the shelf:";
    _Z5Shelf5printF_5ShelfKP(&aShelf);
    _Z1G7messageV =  "Shelf's volume:";
    _Z5Shelf5printF_5ShelfKP(&aShelf);

    _Z3Box3BoxFC_3boxP6double6double6double(&b, 2, 4, 6);
    _Z5Shelf6setBoxF_5ShelfP3int3BoxKP(&aShelf, 1, &b);
    _Z3Box3boxFD_3boxP(&b);

    _Z3Box3BoxFC_3BoxP6double(&b1, 2);
    _Z5Shelf6setBoxF_5ShelfP3int3BoxKP(&aShelf, 2, &b1);
    _Z3Box3boxFD_3boxP(&b1);
    _Z5Shelf5printF_5ShelfKP(&aShelf);

    printf("\n--- end doShelves() ---\n\n");

    _Z3Box3boxFD_3boxP(&aShelf.boxes[2]);
    _Z3Box3boxFD_3boxP(&aShelf.boxes[1]);
    _Z3Box3boxFD_3boxP(&aShelf.boxes[0]);
    _Z3Box3boxFD_3boxP(&aBox);

}

/*int main()
{
    _Z3Box3BoxFC_3boxP6double6double6double(&largeBox, 10, 20, 30);

    printf("\n--- Start main() ---\n\n");


    doBoxes();

    thisFunc();
    thisFunc();
    thisFunc();
    thatFunc();
    thatFunc();

    doShelves();

    printf("\n--- End main() ---\n\n");

    flag88 = 2;
    thatFunc();
    flag99 = 2;
    thisFunc();
    _Z3Box3boxFD_3boxP(&largeBox);


    return 0;
}*/