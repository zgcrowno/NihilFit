#include "Sun.h"

using namespace nihilFit;

void Sun::OnCreate()
{
    
}

void Sun::OnDelete()
{

}

orxBOOL Sun::OnCollide(
    ScrollObject *_poCollider,
    const orxSTRING _zPartName,
    const orxSTRING _zColliderPartName,
    const orxVECTOR &_rvPosition,
    const orxVECTOR &_rvNormal)
{
    return orxTRUE;
}

void Sun::Update(const orxCLOCK_INFO &_rstInfo)
{

}
