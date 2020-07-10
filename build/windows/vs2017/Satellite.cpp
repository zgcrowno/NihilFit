#include "Satellite.h"

using namespace nihilFit;

void Satellite::OnCreate()
{
    if (orxConfig_PushSection(GetModelName()))
    {
        m_fRotationSpeed = orxConfig_GetFloat("RotationSpeed");

        orxConfig_PopSection();
    }

    m_spSatelliteTailSpawner = (orxSPAWNER*)_orxStructure_GetPointer(_orxObject_GetStructure(GetOrxObject(), orxSTRUCTURE_ID_SPAWNER), orxSTRUCTURE_ID_SPAWNER);

    orxSpawner_Enable(m_spSatelliteTailSpawner, false);
}

void Satellite::OnDelete()
{

}

orxBOOL Satellite::OnCollide(
    ScrollObject *_poCollider,
    const orxSTRING _zPartName,
    const orxSTRING _zColliderPartName,
    const orxVECTOR &_rvPosition,
    const orxVECTOR &_rvNormal)
{
    SpaceJunk *spaceJunk = dynamic_cast<SpaceJunk*>(_poCollider);
    if (spaceJunk != nullptr && spaceJunk->m_pLastTouchedSatellite != this)
    {
        if (m_bOpen && m_pHeldSpaceJunk == nullptr)
        {
            // Get the Satellite's absolute position.
            orxVECTOR curPos = orxVECTOR_0;
            GetPosition(curPos, true);
            // Set spaceJunk's parent, position and scale as appropriate.
            orxObject_SetParent(spaceJunk->GetOrxObject(), GetOrxObject());
            spaceJunk->SetPosition(curPos, true);
            spaceJunk->SetScale({ 1.0f, 1.0f });
            // Set SpaceJunk's speed to 0, as it will only be moving with the Satellite.
            spaceJunk->SetSpeed(orxVECTOR_0);
            // Ensure spaceJunk is tied to this Satellite.
            m_pHeldSpaceJunk = spaceJunk;
        }
        else if (!m_bOpen)
        {
            // Reflect SpaceJunk about normal.
            /*orxVECTOR curSpaceJunkSpeed = orxVECTOR_0;
            orxVECTOR subtrahend = orxVECTOR_0;
            orxVECTOR reflectionVec = orxVECTOR_0;
            spaceJunk->GetSpeed(curSpaceJunkSpeed);
            float dot = orxVector_2DDot(&curSpaceJunkSpeed, &_rvNormal);
            orxVector_Mulf(&subtrahend, &_rvNormal, 2 * dot);
            orxVector_Sub(&reflectionVec, &curSpaceJunkSpeed, &subtrahend);
            orxVector_Normalize(&reflectionVec, &reflectionVec);
            orxVector_Mulf(&reflectionVec, &reflectionVec, spaceJunk->m_fMovementSpeed);
            spaceJunk->SetSpeed(reflectionVec);*/

            // Simply deflect SpaceJunk in direction of normal.
            orxVECTOR deflectionVec = orxVECTOR_0;
            orxVECTOR negatedNormal = orxVECTOR_0;
            orxVector_Neg(&negatedNormal, &_rvNormal);
            orxVector_Mulf(&deflectionVec, &negatedNormal, spaceJunk->m_fMovementSpeed);
            spaceJunk->SetSpeed(deflectionVec);
        }

        // Set last touched satellite to prevent multiple collisions.
        spaceJunk->m_pLastTouchedSatellite = this;
    }

    return orxTRUE;
}

void Satellite::Update(const orxCLOCK_INFO &_rstInfo)
{
    
}

void Satellite::OpenOrClose()
{
    if (m_pHeldSpaceJunk != nullptr)
    {
        // Set SpaceJunk's speed such that it fires in the vector from the center of the Satellite's planet to the Satellite.
        orxVECTOR curPos = orxVECTOR_0;
        orxVECTOR parentCurPos = orxVECTOR_0;
        orxVECTOR directionVec = orxVECTOR_0;
        orxVECTOR relativeScale = orxVECTOR_0;
        orxOBJECT *parentPlanet = (orxOBJECT*)orxObject_GetParent(GetOrxObject());
        GetPosition(curPos, true);
        orxObject_GetWorldPosition(parentPlanet, &parentCurPos);
        orxVector_Sub(&directionVec, &curPos, &parentCurPos);
        orxVector_Normalize(&directionVec, &directionVec);
        orxVector_Mulf(&directionVec, &directionVec, m_pHeldSpaceJunk->m_fMovementSpeed);
        m_pHeldSpaceJunk->SetSpeed(directionVec);
        // Set SpaceJunk's parent, position and scale as appropriate.
        orxObject_SetParent(m_pHeldSpaceJunk->GetOrxObject(), NihilFit::GetInstance().GetSceneSolarSystem()->GetOrxObject());
        m_pHeldSpaceJunk->SetPosition(curPos, true);
        m_pHeldSpaceJunk->SetScale(m_pHeldSpaceJunk->m_vUnheldScale);
        // We've released the SpaceJunk, so no SpaceJunk is held.
        m_pHeldSpaceJunk = nullptr;
    }

    if (m_bOpen)
    {
        RemoveShader("SH-SatelliteOpen");
    }
    else
    {
        AddShader("SH-SatelliteOpen");
    }

    m_bOpen = !m_bOpen;
}
