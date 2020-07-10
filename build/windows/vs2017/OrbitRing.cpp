#include "OrbitRing.h"

using namespace nihilFit;

void OrbitRing::OnCreate()
{
    m_pPlanet = static_cast<Planet*>(GetOwnedChild());
}

void OrbitRing::OnDelete()
{

}

orxBOOL OrbitRing::OnCollide(
    ScrollObject *_poCollider,
    const orxSTRING _zPartName,
    const orxSTRING _zColliderPartName,
    const orxVECTOR &_rvPosition,
    const orxVECTOR &_rvNormal)
{
    return orxTRUE;
}

void OrbitRing::Update(const orxCLOCK_INFO &_rstInfo)
{

}
