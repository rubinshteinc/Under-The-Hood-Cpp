#include "c_encapsulation_defs.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>



void _Z3Box3BoxFC_3BoxP6double(Box *this, double dim)
{
    this -> length = dim;
    this -> width = dim;
    this -> height = dim;
    _Z3Box5printF_3BoxKP(this);
}

void _Z3Box3BoxFC_3boxP6double6double6double(Box *this, double l, double w, double h)
{
    this -> length = l;
    this -> width = w;
    this -> height = h;
    _Z3Box5printF_3BoxKP(this);
}

void _Z3Box3boxFD_3boxP(Box *this)
{
    printf("Box destructor, %f x %f x %f\n", this -> width, this -> height, this -> length);
}

void _Z3Box3BoxFC_3BoxP3BoxP(Box *this, Box *other){
    memcpy(this, other, sizeof(Box));
}

Box* _Z3Box10assignmentF_3BoxP3BoxKP(Box *this, const Box *other)
{
    memcpy(this, other, sizeof(*this));

    return this;

}

void Z3Box14AssignmentMultF_3BoxKP6double(Box *this, double mult)
{
    this -> width *= mult;
    this -> height *= mult;
    this -> length *= mult;

}

void _Z3Box5printF_3BoxKP(const Box *this)
{
    printf("Box: %f x %f x %f\n", this -> length, this -> width, this -> height);
}


//// Shelf ////////////

const char *_Z1G7messageV = "The total volume held on the shelf is";

void _Z5Shelf5ShelfFc_5ShelfP(Shelf *this){
    int i = 0;
    for (; i < 3; ++i){
        _Z3Box3BoxFC_3BoxP6double(&this->boxes[i], 1);
    }
}

void _Z5Shelf6setBoxF_5ShelfP3int3BoxKP(Shelf *this, int index, const Box* dims)
{
    this -> boxes[index].height = dims ->height;
    this -> boxes[index].width = dims ->width;
    this -> boxes[index].length = dims ->length;

}

double _Z5Shelf9getVolumeF_5ShelfKP(const Shelf * this)
{
    double vol = 0;
    size_t i = 0;
    for (;i < 3; ++i)
        vol += (this -> boxes[i].length * this -> boxes[i].width * this -> boxes[i].height);

    return vol;
}


void _Z5Shelf5printF_5ShelfKP(const Shelf *this)
{
    printf("%s %f\n", _Z1G7messageV, _Z5Shelf9getVolumeF_5ShelfKP(this));
}



