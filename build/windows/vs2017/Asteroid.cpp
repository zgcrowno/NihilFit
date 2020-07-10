#include "Asteroid.h"

using namespace nihilFit;

void Asteroid::OnCreate()
{
    if (orxConfig_PushSection(GetModelName()))
    {
        m_fRotationSpeed = orxConfig_GetFloat("RotationSpeed");
        m_fTopAngle = orxConfig_GetFloat("TopAngle");
        m_fBottomAngle = orxConfig_GetFloat("BottomAngle");

        orxConfig_PopSection();
    }
}

void Asteroid::OnDelete()
{

}

orxBOOL Asteroid::OnCollide(
    ScrollObject *_poCollider,
    const orxSTRING _zPartName,
    const orxSTRING _zColliderPartName,
    const orxVECTOR &_rvPosition,
    const orxVECTOR &_rvNormal)
{
    return orxTRUE;
}

void Asteroid::Update(const orxCLOCK_INFO &_rstInfo)
{
    // Rotate Asteroid about its orbit ring's center.
    orxVECTOR curPos = orxVECTOR_0;
    GetPosition(curPos);
    orxVector_2DRotate(&curPos, &curPos, m_fRotationSpeed);
    SetPosition(curPos);
    // Teleport Asteroid to the beginning of its orbit once it exits the screen (its angle exceeds a certain amount).
    float angleFromParent = GetAngleFromParent();
    if (angleFromParent >= m_fBottomAngle)
    {
        orxVector_2DRotate(&curPos, &curPos, m_fTopAngle - angleFromParent);
        SetPosition(curPos);
    }
}

const float Asteroid::GetAngleFromParent() const
{
    orxVECTOR curPos = orxVECTOR_0;
    orxVECTOR parentPos = orxVECTOR_0;
    orxVECTOR parentToSelfVec = orxVECTOR_0;
    orxOBJECT *parent = (orxOBJECT*)orxObject_GetParent(GetOrxObject());
    GetPosition(curPos, true);
    orxObject_GetWorldPosition(parent, &parentPos);
    orxVector_Sub(&parentToSelfVec, &curPos, &parentPos);
    return atan2f(parentToSelfVec.fY, parentToSelfVec.fX);
}
