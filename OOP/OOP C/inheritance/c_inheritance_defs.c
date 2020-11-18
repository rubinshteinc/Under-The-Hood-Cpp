#include "inheritance/c_inheritance_defs.h"




/////Material////
void _Z9Materials9MaterialsFC(Materials *this){}

void _Z9Materials9MaterialsFC_9MaterialsP9MaterialsPK(Materials *this, const Materials *other){
    memcpy(this, other, sizeof(Materials));
}

const Materials* _Z9Materials10assignment_9MaterialsP9MaterialsPK(Materials *this, const Materials *other)
{
    *this  = *other;
    return this;
}

void Z9Materials9MaterialsFD(Materials *this){}

/////Material_t////

void Z10Material_t10Material_tFD(Material_t *this)
{
}


//// PhysicalBox Defs ////////////

void _Z11PhysicalBox11PhysicalBoxFC_11PhysicalBoxP6double6double6double(PhysicalBox *this, double l, double w, double h)
{
    _Z3Box3BoxFC_3boxP6double6double6double((Box*)this, l, w, h);
    this -> m_material.m_type = OTHER;

    {
        const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
        printf("Material created, set to %s\n", names[this -> m_material.m_type]);
    }

    _Z11PhysicalBox6printpFK_11PhysicalBoxPK(this);
}

void _Z11PhysicalBox11PhysicalBoxFC_11PhysicalBoxP6double6double6double14MaterialsTypes(PhysicalBox *this, double l, double w, double h, Types t)
{
	_Z3Box3BoxFC_3boxP6double6double6double((Box*)this, l, w, h);
    this -> m_material.m_type = t;
    {
        const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
        printf("Material created, set to %s\n", names[this -> m_material.m_type]);

    }
    _Z11PhysicalBox6printpFK_11PhysicalBoxPK(this);
}


void _Z11PhysicalBox11PhysicalBoxFC_14MaterialsTypes(PhysicalBox *this, Types t)
{
	_Z3Box3BoxFC_3BoxP6double((Box*)this, 1);
    this -> m_material.m_type = t;
    {
        const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
        printf("Material created, set to %s\n", names[this -> m_material.m_type]);

    }
    _Z11PhysicalBox6printpFK_11PhysicalBoxPK(this);
}

void _Z11PhysicalBox11PhysicalBoxFC_11PhysicalBoxP11PhysicalBoxPK(PhysicalBox *this, const PhysicalBox *other)
{
    _Z3Box3BoxFC_3BoxP3BoxP((Box*)this, (Box*)other);
    memcpy(this + sizeof(Box), other + sizeof(Box), sizeof(PhysicalBox) - sizeof(Box));
}


void _Z11PhysicalBox11PhysicalBoxFD(PhysicalBox *this)
{
    {
        const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
        printf("PhysicalBox dtor, %f x %f x %f, %s; ", this -> m_box.length, this -> m_box.width, this -> m_box.height, names[this -> m_material.m_type]);
    }
    _Z3Box3boxFD_3boxP((Box*)this);
}

const PhysicalBox* _Z11PhysicalBox10assignmentF_11PhysicalBoxP11PhysicalBoxPK(PhysicalBox *this, const PhysicalBox const *other)
{
    memcpy(this, other, sizeof(PhysicalBox));
    return this;
}


void _Z11PhysicalBox6printpFK_11PhysicalBoxPK(const PhysicalBox *this)
{
    {
        const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
        printf("PhysicalBox, made of %s; ", names[this -> m_material.m_type]);
    }
    _Z3Box5printF_3BoxKP((Box*)this);
}


/// WeightBox Defs ////////////

void _Z9WeightBox9WeightBoxFC_9WeightBoxP6double6double6double6double(WeightBox *this, double l, double w, double h, double wgt)
{
    _Z3Box3BoxFC_3boxP6double6double6double((Box*)this,l, w, h);
    this -> weight = wgt;
    _Z9WeightBox6printwFK_9WeightBoxPK(this);
}

void _Z9WeightBox9WeightBoxFC_9WeightBoxP9WeightBoxPK(WeightBox *this, const WeightBox *other)
{
    _Z3Box3BoxFC_3BoxP6double((Box*)this, 1);
    this -> weight = other -> weight;

    _Z9WeightBox6printwFK_9WeightBoxPK(this);
}

void _Z9WeightBox9WeightBoxFD(WeightBox *this)
{
    printf("Destructing WeightBox; ");
    _Z9WeightBox6printwFK_9WeightBoxPK(this);
	_Z3Box3boxFD_3boxP((Box*)this);
}

const WeightBox* _Z9WeightBox10assignmentF_9WeightBoxP9WeightBoxPK(WeightBox *this, const WeightBox const* other)
{
//    memcpy(this + sizeof(Box), other + sizeof(Box), sizeof(WeightBox) - sizeof(Box));
    this -> weight = other -> weight;
    return this;
}

void _Z9WeightBox6printwFK_9WeightBoxPK(const WeightBox *this)
{
    printf("WeightBox, weight: %f; ", this -> weight);
    _Z3Box5printF_3BoxKP((Box*)this);
}


