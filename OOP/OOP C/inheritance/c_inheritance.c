#include "c_inheritance_defs.h"


void doMaterials()
{
    struct MatTest { Materials mat; Material_t mat_t;};
    Materials mat;
    Material_t mat1, mat2;

    printf("\n--- Start doMaterials() ---\n\n");

    printf("Size of Materials: %lu\n", sizeof(Materials) +1);
    printf("Size of mat: %lu\n", sizeof(mat) + 1);
    printf("Size of Materials::Types: %lu\n", sizeof(Types));
    printf("Size of Material_t: %lu\n", sizeof(Material_t));

    printf("Size of Materials + Material_t: %lu\n", sizeof(struct MatTest) * 2);

    mat1.m_type = OTHER;
    {
        const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
        printf("Material created, set to %s\n", names[mat1.m_type]);
    }

    mat2.m_type = METAL;
    {
        const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
        printf("Material created, set to %s\n", names[mat2.m_type]);
    }

    printf("\n--- End doMaterials() ---\n\n");

    Z10Material_t10Material_tFD(&mat2);
    Z10Material_t10Material_tFD(&mat1);
    Z9Materials9MaterialsFD(&mat);

}

void doPhysicalBox()
{
    PhysicalBox pb1, pb2, pb3, pb4;
    printf("\n--- Start doPhysicalBox() ---\n\n");

    _Z11PhysicalBox11PhysicalBoxFC_11PhysicalBoxP6double6double6double14MaterialsTypes(&pb1, 8, 6, 4, PLASTIC);
    _Z11PhysicalBox11PhysicalBoxFC_14MaterialsTypes(&pb2, WOOD);
    _Z11PhysicalBox11PhysicalBoxFC_11PhysicalBoxP6double6double6double(&pb3, 7, 7, 7);
    
    printf("\npb4 is copy-constructed from pb1\n");

    _Z11PhysicalBox11PhysicalBoxFC_11PhysicalBoxP11PhysicalBoxPK(&pb4, &pb1);
    _Z11PhysicalBox6printpFK_11PhysicalBoxPK(&pb4);
    _Z11PhysicalBox6printpFK_11PhysicalBoxPK(&pb1);
    printf("pb4 %s pb1\n", ((pb4.m_box.length == pb1.m_box.length && pb4.m_box.width == pb1.m_box.width && pb4.m_box.height == pb4.m_box.height)&& pb4.m_material.m_type == pb1.m_material.m_type) ? "equals" : "does not equal");

    printf("\npb4 is copy-assigned from pb3\n");
    _Z11PhysicalBox10assignmentF_11PhysicalBoxP11PhysicalBoxPK(&pb4, &pb3);
    _Z11PhysicalBox6printpFK_11PhysicalBoxPK(&pb4);
    _Z11PhysicalBox6printpFK_11PhysicalBoxPK(&pb3);
    printf("pb4 %s pb3\n", ((pb4.m_box.length == pb3.m_box.length && pb4.m_box.width == pb3.m_box.width && pb4.m_box.height == pb3.m_box.height) && pb4.m_material.m_type == pb3.m_material.m_type) ? "equals" : "does not equal");

    printf("\n--- End doPhysicalBox() ---\n\n");
    _Z11PhysicalBox11PhysicalBoxFD(&pb4);
    _Z11PhysicalBox11PhysicalBoxFD(&pb3);
    _Z11PhysicalBox11PhysicalBoxFD(&pb2);
    _Z11PhysicalBox11PhysicalBoxFD(&pb1);
}

void doWeightBox()
{
    WeightBox pw1, pw2, pw3, pw4;

    printf("\n--- Start doWeightBox() ---\n\n");

    _Z9WeightBox9WeightBoxFC_9WeightBoxP6double6double6double6double(&pw1, 8, 6, 4, 25);
    _Z9WeightBox9WeightBoxFC_9WeightBoxP6double6double6double6double(&pw2, 1, 2, 3, 0.0);
    _Z9WeightBox9WeightBoxFC_9WeightBoxP6double6double6double6double(&pw3, 10, 20, 30, 15);
    
    printf("\npw4 is copy-constructed from pw1\n");

    _Z9WeightBox9WeightBoxFC_9WeightBoxP9WeightBoxPK(&pw4, &pw1);
    _Z9WeightBox6printwFK_9WeightBoxPK(&pw4);
    _Z9WeightBox6printwFK_9WeightBoxPK(&pw1);
    printf("pw4 %s pw1\n", ((pw4.m_box.length == pw1.m_box.length && pw4.m_box.width == pw1.m_box.width && pw4.m_box.height == pw1.m_box.height) && pw4.weight == pw1.weight) ? "equals" : "does not equal");

    printf("\npw4 is copy-assigned from pw3\n");

    _Z9WeightBox10assignmentF_9WeightBoxP9WeightBoxPK(&pw4, &pw3);
    _Z9WeightBox6printwFK_9WeightBoxPK(&pw4);
    _Z9WeightBox6printwFK_9WeightBoxPK(&pw3);
    printf("pw4 %s pw3\n", ((pw4.m_box.length == pw3.m_box.length && pw4.m_box.width == pw3.m_box.width && pw4.m_box.height == pw3.m_box.height)  && pw4.weight == pw3.weight) ? "equals" : "does not equal");

    printf("\n--- End doWeightBox() ---\n\n");
    _Z9WeightBox9WeightBoxFD(&pw4);
    _Z9WeightBox9WeightBoxFD(&pw3);
    _Z9WeightBox9WeightBoxFD(&pw2);
    _Z9WeightBox9WeightBoxFD(&pw1);
}





/*int main()
{
    _Z3Box3BoxFC_3boxP6double6double6double(&largeBox, 10, 20, 30);

    printf("\n--- Start main() ---\n\n");

    doMaterials();

    doPhysicalBox();

    doWeightBox();

    printf("\n--- End main() ---\n\n");

    _Z3Box3boxFD_3boxP(&largeBox);


}*/
