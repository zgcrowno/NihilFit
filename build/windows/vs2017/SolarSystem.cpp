#include "SolarSystem.h"

using namespace nihilFit;

void SolarSystem::OnCreate()
{
    if (orxConfig_PushSection("O-SolarSystem"))
    {
        orxConfig_GetVector("ProloguePos", &m_vProloguePos);
        orxConfig_GetVector("PhaseOnePos", &m_vPhaseOnePos);
        orxConfig_GetVector("PhaseTwoPos", &m_vPhaseTwoPos);
        orxConfig_GetVector("PhaseTwoScale", &m_vPhaseTwoScale);

        orxConfig_PopSection();
    }

    for (ScrollObject *child = GetOwnedChild(); child != nullptr; child = child->GetOwnedSibling())
    {
        Sun *sun = dynamic_cast<Sun*>(child);
        if (sun != nullptr)
        {
            m_pSun = sun;
        }
        else
        {
            OrbitRing *orbitRing = dynamic_cast<OrbitRing*>(child);
            if (orbitRing != nullptr)
            {
                m_cOrbitRings.push_back(orbitRing);
            }
        }
    }

    // Earth is selected by default.
    m_iSelectedOrbitRingIndex = 2;
    m_pSelectedOrbitRing = m_cOrbitRings.at(m_iSelectedOrbitRingIndex);
}

void SolarSystem::OnDelete()
{

}

orxBOOL SolarSystem::OnCollide(
    ScrollObject *_poCollider,
    const orxSTRING _zPartName,
    const orxSTRING _zColliderPartName,
    const orxVECTOR &_rvPosition,
    const orxVECTOR &_rvNormal)
{
    return orxTRUE;
}

void SolarSystem::Update(const orxCLOCK_INFO &_rstInfo)
{

}
