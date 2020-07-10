#include "SpaceJunk.h"

using namespace nihilFit;

void SpaceJunk::OnCreate()
{
    if (orxConfig_PushSection(GetModelName()))
    {
        m_fMovementSpeed = orxConfig_GetFloat("MovementSpeed");
        orxConfig_GetVector("Dest", &m_vDest);
        orxConfig_GetVector("UnheldScale", &m_vUnheldScale);

        orxConfig_PopSection();
    }

    orxVECTOR curPos = orxVECTOR_0;
    orxVECTOR direction = orxVECTOR_0;
    orxVECTOR speed = orxVECTOR_0;
    GetPosition(curPos);
    orxVector_Sub(&direction, &m_vDest, &curPos);
    orxVector_Normalize(&direction, &direction);
    orxVector_Mulf(&speed, &direction, m_fMovementSpeed);
    SetSpeed(speed);
}

void SpaceJunk::OnDelete()
{

}

orxBOOL SpaceJunk::OnCollide(
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
    else if (!orxString_Compare(_zColliderPartName, "BP-Planet"))
    {

    }
    else if (!orxString_Compare(_zColliderPartName, "BP-Asteroid"))
    {
        // Kill both the SpaceJunk and the Asteroid.
        SetLifeTime(0.0f);
        _poCollider->SetLifeTime(0.0f);
    }

    return orxTRUE;
}

void SpaceJunk::Update(const orxCLOCK_INFO &_rstInfo)
{
    
}
