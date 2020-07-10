#include "Planet.h"

using namespace nihilFit;

void Planet::OnCreate()
{
    if (orxConfig_PushSection(GetModelName()))
    {
        m_fRotationSpeed = orxConfig_GetFloat("RotationSpeed");
        orxConfig_GetVector("MinPos", &m_vMinPos);
        orxConfig_GetVector("MaxPos", &m_vMaxPos);

        orxConfig_PopSection();
    }

    m_pSatellite = static_cast<Satellite*>(GetOwnedChild());
}

void Planet::OnDelete()
{

}

orxBOOL Planet::OnCollide(
    ScrollObject *_poCollider,
    const orxSTRING _zPartName,
    const orxSTRING _zColliderPartName,
    const orxVECTOR &_rvPosition,
    const orxVECTOR &_rvNormal)
{
    return orxTRUE;
}

void Planet::Update(const orxCLOCK_INFO &_rstInfo)
{
    
}
