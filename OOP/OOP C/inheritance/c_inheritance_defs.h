#ifndef __CPP2C_INHERITANCE_DEFS_H__
#define __CPP2C_INHERITANCE_DEFS_H__

#include <stdio.h>
#include <string.h>
#include "encapsulation/c_encapsulation_defs.h"


/*Mangling Name:
 *   _Z + length scope name + name scope (G - global) + length name + name + m_type (F (C - ctor , D - dtor / V) + S - static , K - const
 *   _parameters:  length m_type  + m_type + K - const /  P - pointer / R - reference.
*/


//// Materials ////////////

typedef struct Materials
{
    enum Types
    {
        PLASTIC,
        METAL,
        WOOD,
        PAPER,
        OTHER
    };

}Materials;

typedef enum Types Types;

void _Z9Materials9MaterialsFC(Materials *this);
void _Z9Materials9MaterialsFC_9MaterialsP9MaterialsPK(Materials *this, const Materials *other);
const Materials* _Z9Materials10assignment_9MaterialsP9MaterialsPK(Materials *this, const Materials *other);
void Z9Materials9MaterialsFD(Materials *this);


////Material_t////
typedef struct Material_t
{
    Materials m_materials;
    Types m_type;

}Material_t;

////Material_t Defs////
void Z10Material_t10Material_tFD(Material_t *this);

//// PhysicalBox ////////////

typedef struct PhysicalBox
{
    Box m_box;
    Material_t m_material;

}PhysicalBox;

//// PhysicalBox Defs ////////////

void _Z11PhysicalBox11PhysicalBoxFC_11PhysicalBoxP6double6double6double14MaterialsTypes(PhysicalBox *this, double l, double w, double h, Types t);

void _Z11PhysicalBox11PhysicalBoxFC_11PhysicalBoxP6double6double6double(PhysicalBox *this, double l, double w, double h); ///??????????????????????// not implement ---
void _Z11PhysicalBox11PhysicalBoxFC_14MaterialsTypes(PhysicalBox *this, Types t);
void _Z11PhysicalBox11PhysicalBoxFC_11PhysicalBoxP11PhysicalBoxPK(PhysicalBox *this, const PhysicalBox *other);
void _Z11PhysicalBox11PhysicalBoxFD(PhysicalBox *this);

const PhysicalBox* _Z11PhysicalBox10assignmentF_11PhysicalBoxP11PhysicalBoxPK(PhysicalBox *this, const PhysicalBox const* other);
void _Z11PhysicalBox6printpFK_11PhysicalBoxPK(const PhysicalBox *this);


//// WeightBox ////////////

typedef struct WeightBox
{
    Box m_box;
    double weight;

}WeightBox;

void _Z9WeightBox9WeightBoxFC_9WeightBoxP6double6double6double6double(WeightBox *this, double l, double w, double h, double wgt);
void _Z9WeightBox9WeightBoxFC_9WeightBoxP9WeightBoxPK(WeightBox *this, const WeightBox* other);
void _Z9WeightBox9WeightBoxFD(WeightBox *this);

const WeightBox * _Z9WeightBox10assignmentF_9WeightBoxP9WeightBoxPK(WeightBox *this, const WeightBox const* other);

void _Z9WeightBox6printwFK_9WeightBoxPK(const WeightBox *this);


//// WeightBox Defs ////////////

#endif // __CPP2C_INHERITANCE_DEFS_H__


