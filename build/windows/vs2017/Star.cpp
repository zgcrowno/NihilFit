#include "Star.h"

using namespace nihilFit;

void Star::OnCreate()
{
    
}

void Star::OnDelete()
{

}

orxBOOL Star::OnCollide(
    ScrollObject *_poCollider,
    const orxSTRING _zPartName,
    const orxSTRING _zColliderPartName,
    const orxVECTOR &_rvPosition,
    const orxVECTOR &_rvNormal)
{
    if (!orxString_Compare(_zColliderPartName, "BP-SpaceJunkKillWall"))
    {
        SetLifeTime(0);
    }

    return orxTRUE;
}

void Star::Update(const orxCLOCK_INFO &_rstInfo)
{

}
