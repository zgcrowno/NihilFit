#include "SceneSolarSystem.h"
#include "SpaceJunk.h"

#define EARTH_INDEX 2
#define VENUS_INDEX 1

using namespace nihilFit;

void SceneSolarSystem::OnCreate()
{
    if (orxConfig_PushSection(GetModelName()))
    {
        m_ePhase = static_cast<Phase>(orxConfig_GetU32("Phase"));
        m_fPrologueLength = orxConfig_GetFloat("PrologueLength");
        m_fPhaseOneLength = orxConfig_GetFloat("PhaseOneLength");
        m_fPhaseTwoLength = orxConfig_GetFloat("PhaseTwoLength");
        m_fPhaseFiveLength = orxConfig_GetFloat("PhaseFiveLength");
        m_fEpilogueLength = orxConfig_GetFloat("EpilogueLength");
        m_fPhaseOneSpaceJunkSpawnInterval = orxConfig_GetFloat("PhaseOneSpaceJunkSpawnInterval");
        m_fPhaseTwoSpaceJunkSpawnInterval = orxConfig_GetFloat("PhaseTwoSpaceJunkSpawnInterval");
        m_fPhaseThreeSpaceJunkSpawnInterval = orxConfig_GetFloat("PhaseThreeSpaceJunkSpawnInterval");
        m_fPhaseFourSpaceJunkSpawnInterval = orxConfig_GetFloat("PhaseFourSpaceJunkSpawnInterval");
        m_fPhaseFiveSpaceJunkSpawnInterval = orxConfig_GetFloat("PhaseFiveSpaceJunkSpawnInterval");
        m_fMinShootingStarSpawnInterval = orxConfig_GetFloat("MinShootingStarSpawnInterval");
        m_fMaxShootingStarSpawnInterval = orxConfig_GetFloat("MaxShootingStarSpawnInterval");
        m_fPhaseOneSetUpLength = orxConfig_GetFloat("PhaseOneSetUpLength");
        m_fPhaseTwoSetUpLength = orxConfig_GetFloat("PhaseTwoSetUpLength");
        m_fPhaseThreeSetUpLength = orxConfig_GetFloat("PhaseThreeSetUpLength");
        m_fPhaseFourSetUpLength = orxConfig_GetFloat("PhaseFourSetUpLength");
        m_fPhaseFiveSetUpLength = orxConfig_GetFloat("PhaseFiveSetUpLength");
        m_fPrologueSolarSystemLerpStartTime = orxConfig_GetFloat("PrologueSolarSystemLerpStartTime");
        orxConfig_GetVector("MaxShootingStarSpeed", &m_vMaxShootingStarSpeed);

        orxConfig_PopSection();
    }

    for (ScrollObject *child = GetOwnedChild(); child != nullptr; child = child->GetOwnedSibling())
    {
        SolarSystem *solarSystem = dynamic_cast<SolarSystem*>(child);
        if (solarSystem != nullptr)
        {
            m_pSolarSystem = solarSystem;
        }
        else if (!orxString_Compare("O-StarSpawner", child->GetModelName()))
        {
            m_pStarSpawner = child;
        }
    }

    switch (m_ePhase)
    {
    case Phase::Prologue:
        AddTrack("TT-Prologue");
        break;
    case Phase::One:
        // Create a background of static stars.
        for (int i = 0; i < 50; i++)
        {
            ScrollObject *staticStar = NihilFit::GetInstance().CreateObject("O-StaticStar");
            orxObject_SetOwner(staticStar->GetOrxObject(), GetOrxObject());
        }
        // Make used satellites visible.
        for (OrbitRing *orbitRing : m_pSolarSystem->m_cOrbitRings)
        {
            if (!orxString_Compare(orbitRing->GetModelName(), "O-OrbitRingEarth"))
            {
                orxObject_SetAlpha(orbitRing->m_pPlanet->m_pSatellite->GetOrxObject(), 1.0f);
            }
        }
        break;
    case Phase::Two:
        // Create a background of static stars.
        for (int i = 0; i < 50; i++)
        {
            ScrollObject *staticStar = NihilFit::GetInstance().CreateObject("O-StaticStar");
            orxObject_SetOwner(staticStar->GetOrxObject(), GetOrxObject());
        }
        // Make used satellites visible.
        for (OrbitRing *orbitRing : m_pSolarSystem->m_cOrbitRings)
        {
            if (!orxString_Compare(orbitRing->GetModelName(), "O-OrbitRingEarth")
                || !orxString_Compare(orbitRing->GetModelName(), "O-OrbitRingVenus"))
            {
                orxObject_SetAlpha(orbitRing->m_pPlanet->m_pSatellite->GetOrxObject(), 1.0f);
            }
        }
        break;
    case Phase::Three:
        // Create a background of static stars.
        for (int i = 0; i < 50; i++)
        {
            ScrollObject *staticStar = NihilFit::GetInstance().CreateObject("O-StaticStar");
            orxObject_SetOwner(staticStar->GetOrxObject(), GetOrxObject());
        }
        // Make used satellites visible.
        for (OrbitRing *orbitRing : m_pSolarSystem->m_cOrbitRings)
        {
            if (!orxString_Compare(orbitRing->GetModelName(), "O-OrbitRingEarth")
                || !orxString_Compare(orbitRing->GetModelName(), "O-OrbitRingVenus")
                || !orxString_Compare(orbitRing->GetModelName(), "O-OrbitRingMercury"))
            {
                orxObject_SetAlpha(orbitRing->m_pPlanet->m_pSatellite->GetOrxObject(), 1.0f);
            }
        }
        break;
    case Phase::Four:
        // Create a background of static stars.
        for (int i = 0; i < 50; i++)
        {
            ScrollObject *staticStar = NihilFit::GetInstance().CreateObject("O-StaticStar");
            orxObject_SetOwner(staticStar->GetOrxObject(), GetOrxObject());
        }
        // Make used satellites visible.
        for (OrbitRing *orbitRing : m_pSolarSystem->m_cOrbitRings)
        {
            if (!orxString_Compare(orbitRing->GetModelName(), "O-OrbitRingEarth")
                || !orxString_Compare(orbitRing->GetModelName(), "O-OrbitRingVenus")
                || !orxString_Compare(orbitRing->GetModelName(), "O-OrbitRingMercury")
                || !orxString_Compare(orbitRing->GetModelName(), "O-OrbitRingJupiter"))
            {
                orxObject_SetAlpha(orbitRing->m_pPlanet->m_pSatellite->GetOrxObject(), 1.0f);
            }
        }
        break;
    case Phase::Five:
        // Create a background of static stars.
        for (int i = 0; i < 50; i++)
        {
            ScrollObject *staticStar = NihilFit::GetInstance().CreateObject("O-StaticStar");
            orxObject_SetOwner(staticStar->GetOrxObject(), GetOrxObject());
        }
        // Make used satellites visible.
        for (OrbitRing *orbitRing : m_pSolarSystem->m_cOrbitRings)
        {
            if (!orxString_Compare(orbitRing->GetModelName(), "O-OrbitRingEarth")
                || !orxString_Compare(orbitRing->GetModelName(), "O-OrbitRingVenus")
                || !orxString_Compare(orbitRing->GetModelName(), "O-OrbitRingMercury")
                || !orxString_Compare(orbitRing->GetModelName(), "O-OrbitRingJupiter"))
            {
                orxObject_SetAlpha(orbitRing->m_pPlanet->m_pSatellite->GetOrxObject(), 1.0f);
            }
        }
        break;
    case Phase::Epilogue:
        break;
    }

    m_pStarSpawner->Enable(false);
}

void SceneSolarSystem::OnDelete()
{

}

orxBOOL SceneSolarSystem::OnCollide(
    ScrollObject *_poCollider,
    const orxSTRING _zPartName,
    const orxSTRING _zColliderPartName,
    const orxVECTOR &_rvPosition,
    const orxVECTOR &_rvNormal)
{
    return orxTRUE;
}

void SceneSolarSystem::Update(const orxCLOCK_INFO &_rstInfo)
{
    HandleInput();

    switch (m_ePhase)
    {
    case Phase::Prologue:
        // Increment time spent in phase.
        m_fPhaseTime += _rstInfo.fDT;
        orxCLAMP(m_fPhaseTime, 0, m_fPrologueLength);

        // Handle ShootingStar behavior.
        HandleShootingStars();

        if (m_fPhaseTime >= m_fPrologueLength)
        {
            IncrementPhase();
        }
        else
        {
            // Do something?
        }
        break;
    case Phase::One:
        if (m_fSetUpTime <= m_fPhaseOneSetUpLength)
        {
            // Increment time spent setting up.
            m_fSetUpTime += _rstInfo.fDT;

            SetUpPhase();
        }
        else
        {
            // Increment time spent in phase.
            m_fPhaseTime += _rstInfo.fDT;
            orxCLAMP(m_fPhaseTime, 0, m_fPhaseOneLength);
            // Increment time since spawning SpaceJunk.
            m_fSpaceJunkSpawnTime += _rstInfo.fDT;

            if (m_fPhaseTime >= m_fPhaseOneLength && NihilFit::GetInstance().GetSpaceJunk().size() == 0)
            {
                IncrementPhase();
            }
            else
            {
                if (m_fSpaceJunkSpawnTime >= m_fPhaseOneSpaceJunkSpawnInterval && m_fPhaseTime <= m_fPhaseOneLength)
                {
                    SpawnSpaceJunk();
                }
            }
        }
        break;
    case Phase::Two:
        if (m_fSetUpTime <= m_fPhaseTwoSetUpLength)
        {
            // Increment time spent setting up.
            m_fSetUpTime += _rstInfo.fDT;

            SetUpPhase();
        }
        else
        {
            // Increment time spent in phase.
            m_fPhaseTime += _rstInfo.fDT;
            orxCLAMP(m_fPhaseTime, 0, m_fPhaseTwoLength);
            // Increment time since spawning SpaceJunk.
            m_fSpaceJunkSpawnTime += _rstInfo.fDT;

            if (m_fPhaseTime >= m_fPhaseTwoLength && NihilFit::GetInstance().GetSpaceJunk().size() == 0)
            {
                IncrementPhase();
            }
            else
            {
                if (m_fSpaceJunkSpawnTime >= m_fPhaseTwoSpaceJunkSpawnInterval && m_fPhaseTime <= m_fPhaseTwoLength)
                {
                    SpawnSpaceJunk();
                }
            }
        }
        break;
    case Phase::Three:
        if (m_fSetUpTime <= m_fPhaseThreeSetUpLength)
        {
            // Increment time spent setting up.
            m_fSetUpTime += _rstInfo.fDT;

            SetUpPhase();
        }
        else
        {
            // Increment time since spawning SpaceJunk.
            m_fSpaceJunkSpawnTime += _rstInfo.fDT;

            if (NihilFit::GetInstance().GetAsteroids().size() == 0 && NihilFit::GetInstance().GetSpaceJunk().size() == 0)
            {
                IncrementPhase();
            }
            else if (NihilFit::GetInstance().GetAsteroids().size() != 0)
            {
                if (m_fSpaceJunkSpawnTime >= m_fPhaseThreeSpaceJunkSpawnInterval)
                {
                    SpawnSpaceJunk();
                }
            }
        }
        break;
    case Phase::Four:
        if (m_fSetUpTime <= m_fPhaseFourSetUpLength)
        {
            // Increment time spent setting up.
            m_fSetUpTime += _rstInfo.fDT;

            SetUpPhase();
        }
        else
        {
            // Increment time since spawning SpaceJunk.
            m_fSpaceJunkSpawnTime += _rstInfo.fDT;

            if (NihilFit::GetInstance().GetSun() == nullptr && NihilFit::GetInstance().GetSpaceJunk().size() == 0)
            {
                IncrementPhase();
            }
            else if (NihilFit::GetInstance().GetSun() != nullptr)
            {
                if (m_fSpaceJunkSpawnTime >= m_fPhaseFourSpaceJunkSpawnInterval)
                {
                    SpawnSpaceJunk();
                }
            }
        }
        break;
    case Phase::Five:
        // Handle ShootingStar behavior.
        HandleShootingStars();

        if (m_fSetUpTime <= m_fPhaseFiveSetUpLength)
        {
            // Increment time spent setting up.
            m_fSetUpTime += _rstInfo.fDT;

            SetUpPhase();
        }
        else
        {
            // Increment time spent in phase.
            m_fPhaseTime += _rstInfo.fDT;
            orxCLAMP(m_fPhaseTime, 0, m_fPhaseFiveLength);
            // Increment time since spawning SpaceJunk.
            m_fSpaceJunkSpawnTime += _rstInfo.fDT;

            if (m_fPhaseTime >= m_fPhaseFiveLength && NihilFit::GetInstance().GetSpaceJunk().size() == 0)
            {
                IncrementPhase();
            }
            else
            {
                if (m_fSpaceJunkSpawnTime >= m_fPhaseFiveSpaceJunkSpawnInterval && m_fPhaseTime <= m_fPhaseFiveLength)
                {
                    SpawnSpaceJunk();
                }
            }
        }
        break;
    case Phase::Epilogue:
        if (m_fPhaseTime >= m_fEpilogueLength)
        {
            IncrementPhase();
        }
        break;
    }
}

void SceneSolarSystem::IncrementPhase()
{
    // Reset phase time.
    m_fPhaseTime = 0;
    // Reset set up time.
    m_fSetUpTime = 0;

    switch (m_ePhase)
    {
    case Phase::Prologue:
    {
        m_ePhase = Phase::One;

        // Add set up track.
        AddTrack("TT-PhaseOne");

        // Disable star spawner.
        m_pStarSpawner->Enable(false);
    }
        break;
    case Phase::One:
        m_ePhase = Phase::Two;

        // Add set up track.
        AddTrack("TT-PhaseTwo");

        break;
    case Phase::Two:
        m_ePhase = Phase::Three;

        // Add set up track.
        AddTrack("TT-PhaseThree");

        break;
    case Phase::Three:
        m_ePhase = Phase::Four;

        // Add set up track.
        AddTrack("TT-PhaseFour");

        break;
    case Phase::Four:
        m_ePhase = Phase::Five;

        // Add set up track.
        AddTrack("TT-PhaseFive");

        break;
    case Phase::Five:
        m_ePhase = Phase::Epilogue;

        // Add set up track.
        AddTrack("TT-Epilogue");

        break;
    case Phase::Epilogue:
        m_ePhase = Phase::Prologue;

        // Add set up track.
        AddTrack("TT-Prologue");

        break;
    }
}

void SceneSolarSystem::SpawnSpaceJunk()
{
    // Reset SpaceJunk spawn time.
    m_fSpaceJunkSpawnTime = 0;

    // Ensure that spawned SpaceJunk targets random planet.
    if (orxConfig_PushSection("O-SpaceJunk"))
    {
        orxVECTOR randomPlanetPos = orxVECTOR_0;
        Planet *randomPlanet;
        if (m_ePhase >= Phase::Four)
        {
            randomPlanet = m_pSolarSystem->m_cOrbitRings.at(orxMath_GetRandomU32(0, m_pSolarSystem->m_cOrbitRings.size() - 1))->m_pPlanet;
        }
        else if (m_ePhase >= Phase::Three)
        {
            randomPlanet = m_pSolarSystem->m_cOrbitRings.at(orxMath_GetRandomU32(0, EARTH_INDEX))->m_pPlanet;
        }
        else if (m_ePhase >= Phase::Two)
        {
            randomPlanet = m_pSolarSystem->m_cOrbitRings.at(orxMath_GetRandomU32(VENUS_INDEX, EARTH_INDEX))->m_pPlanet;
        }
        else if (m_ePhase >= Phase::One)
        {
            randomPlanet = m_pSolarSystem->m_cOrbitRings.at(EARTH_INDEX)->m_pPlanet;
        }
        randomPlanet->GetPosition(randomPlanetPos);
        orxConfig_SetVector("Dest", &randomPlanetPos);

        orxConfig_PopSection();
    }

    // Spawn SpaceJunk, and set its owner to this.
    ScrollObject *spaceJunk = NihilFit::GetInstance().CreateObject("O-SpaceJunk");
    orxObject_SetOwner(spaceJunk->GetOrxObject(), GetOrxObject());

    // Generate new random SpaceJunk spawn interval.
    if (orxConfig_PushSection(GetModelName()))
    {
        m_fPhaseOneSpaceJunkSpawnInterval = orxConfig_GetFloat("PhaseOneSpaceJunkSpawnInterval");

        orxConfig_PopSection();
    }
}

void SceneSolarSystem::SetUpPhase()
{
    switch (m_ePhase)
    {
    case Phase::One:
        break;
    case Phase::Two:
        if (orxConfig_PushSection(GetModelName()))
        {
            if (orxConfig_GetBool("LerpSolarSystem"))
            {
                orxVECTOR size = orxVECTOR_0;
                GetSize(size);
                orxVECTOR phaseOnePos = { m_pSolarSystem->m_vPhaseOnePos.fX * size.fX, m_pSolarSystem->m_vPhaseOnePos.fY * size.fY };
                orxVECTOR phaseTwoPos = { m_pSolarSystem->m_vPhaseTwoPos.fX * size.fX, m_pSolarSystem->m_vPhaseTwoPos.fY * size.fY };
                orxVECTOR phaseOneScale = {};
                orxVECTOR phaseTwoScale = {};
                orxVECTOR solarSystemPos = orxVECTOR_0;
                orxVECTOR solarSystemScale = orxVECTOR_0;
                orxVector_Lerp(&solarSystemPos, &phaseOnePos, &phaseTwoPos, m_fPhaseTime / m_fPhaseTwoSetUpLength);
                orxVector_Lerp(&solarSystemScale, &phaseOneScale, &phaseTwoScale, m_fSetUpTime / m_fPhaseTwoSetUpLength);
                m_pSolarSystem->SetPosition(solarSystemPos, true);
                m_pSolarSystem->SetScale(solarSystemScale);
            }

            orxConfig_PopSection();
        }
        break;
    case Phase::Three:
        break;
    case Phase::Four:
        break;
    case Phase::Five:
        break;
    }
}

void SceneSolarSystem::SelectPlanetLeft()
{
    if (m_ePhase >= Phase::Four)
    {

        if (m_pSolarSystem->m_iSelectedOrbitRingIndex > 0)
        {
            m_pSolarSystem->m_iSelectedOrbitRingIndex--;
        }
        else
        {
            m_pSolarSystem->m_iSelectedOrbitRingIndex = m_pSolarSystem->m_cOrbitRings.size() - 1;
        }
    }
    else if (m_ePhase >= Phase::Three)
    {
        if (m_pSolarSystem->m_iSelectedOrbitRingIndex > 0)
        {
            m_pSolarSystem->m_iSelectedOrbitRingIndex--;
        }
        else
        {
            m_pSolarSystem->m_iSelectedOrbitRingIndex = EARTH_INDEX;
        }
    }
    else if (m_ePhase >= Phase::Two)
    {
        if (m_pSolarSystem->m_iSelectedOrbitRingIndex > VENUS_INDEX)
        {
            m_pSolarSystem->m_iSelectedOrbitRingIndex--;
        }
        else
        {
            m_pSolarSystem->m_iSelectedOrbitRingIndex = EARTH_INDEX;
        }
    }

    m_pSolarSystem->m_pSelectedOrbitRing = m_pSolarSystem->m_cOrbitRings.at(m_pSolarSystem->m_iSelectedOrbitRingIndex);
}

void SceneSolarSystem::SelectPlanetRight()
{
    if (m_ePhase >= Phase::Four)
    {
        if (m_pSolarSystem->m_iSelectedOrbitRingIndex < m_pSolarSystem->m_cOrbitRings.size() - 1)
        {
            m_pSolarSystem->m_iSelectedOrbitRingIndex++;
        }
        else
        {
            m_pSolarSystem->m_iSelectedOrbitRingIndex = 0;
        }
    }
    else if (m_ePhase >= Phase::Three)
    {
        if (m_pSolarSystem->m_iSelectedOrbitRingIndex < EARTH_INDEX)
        {
            m_pSolarSystem->m_iSelectedOrbitRingIndex++;
        }
        else
        {
            m_pSolarSystem->m_iSelectedOrbitRingIndex = 0;
        }
    }
    else if (m_ePhase >= Phase::Two)
    {
        if (m_pSolarSystem->m_iSelectedOrbitRingIndex < EARTH_INDEX)
        {
            m_pSolarSystem->m_iSelectedOrbitRingIndex++;
        }
        else
        {
            m_pSolarSystem->m_iSelectedOrbitRingIndex = VENUS_INDEX;
        }
    }

    m_pSolarSystem->m_pSelectedOrbitRing = m_pSolarSystem->m_cOrbitRings.at(m_pSolarSystem->m_iSelectedOrbitRingIndex);
}

void SceneSolarSystem::HandleShootingStars()
{
    if (m_ePhase == Phase::Prologue)
    {
        // Set all ShootingStars' speeds based on progress through prologue.
        orxVECTOR shootingStarSpeed = orxVECTOR_0;
        orxVector_Mulf(&shootingStarSpeed, &m_vMaxShootingStarSpeed, orxCLAMP(1 - (m_fPhaseTime / m_fPrologueLength), 0, 1));
        for (ScrollObject *obj = NihilFit::GetInstance().GetNextObject(); obj != nullptr; obj = NihilFit::GetInstance().GetNextObject(obj))
        {
            if (!orxString_Compare("O-Star", obj->GetModelName()))
            {
                obj->SetSpeed(shootingStarSpeed);
            }
        }
    }
    else if (m_ePhase == Phase::Five)
    {
        // Do something.
    }
}

void SceneSolarSystem::HandleInput()
{
    if (m_ePhase != Phase::Prologue && m_ePhase != Phase::Epilogue)
    {
        if (m_ePhase >= Phase::One)
        {
            orxVECTOR selectedSatPos = orxVECTOR_0;
            m_pSolarSystem->m_pSelectedOrbitRing->m_pPlanet->m_pSatellite->GetPosition(selectedSatPos);

            if (orxInput_IsActive("SatelliteMoveClockwise"))
            {
                orxVector_2DRotate(&selectedSatPos, &selectedSatPos, m_pSolarSystem->m_pSelectedOrbitRing->m_pPlanet->m_pSatellite->m_fRotationSpeed);

                m_pSolarSystem->m_pSelectedOrbitRing->m_pPlanet->m_pSatellite->SetPosition(selectedSatPos);

                orxSpawner_Enable(m_pSolarSystem->m_pSelectedOrbitRing->m_pPlanet->m_pSatellite->m_spSatelliteTailSpawner, true);
            }
            else if (orxInput_IsActive("SatelliteMoveCounterClockwise"))
            {
                orxVector_2DRotate(&selectedSatPos, &selectedSatPos, -m_pSolarSystem->m_pSelectedOrbitRing->m_pPlanet->m_pSatellite->m_fRotationSpeed);

                m_pSolarSystem->m_pSelectedOrbitRing->m_pPlanet->m_pSatellite->SetPosition(selectedSatPos);

                orxSpawner_Enable(m_pSolarSystem->m_pSelectedOrbitRing->m_pPlanet->m_pSatellite->m_spSatelliteTailSpawner, true);
            }
            else
            {
                orxSpawner_Enable(m_pSolarSystem->m_pSelectedOrbitRing->m_pPlanet->m_pSatellite->m_spSatelliteTailSpawner, false);
            }
        }
        if (m_ePhase >= Phase::Two)
        {
            if (orxInput_HasBeenActivated("SelectPlanetLeft"))
            {
                SelectPlanetLeft();
            }
            else if (orxInput_HasBeenActivated("SelectPlanetRight"))
            {
                SelectPlanetRight();
            }
        }
        if (m_ePhase >= Phase::Three)
        {
            if (orxInput_HasBeenActivated("GrabRelease"))
            {
                m_pSolarSystem->m_pSelectedOrbitRing->m_pPlanet->m_pSatellite->OpenOrClose();
            }
        }
        if (m_ePhase >= Phase::Four)
        {
            orxVECTOR selectedPlanetPos = orxVECTOR_0;
            m_pSolarSystem->m_pSelectedOrbitRing->m_pPlanet->GetPosition(selectedPlanetPos);

            if (orxInput_IsActive("PlanetMoveDown"))
            {
                orxVECTOR rotatedVector = *orxVector_2DRotate(&selectedPlanetPos, &selectedPlanetPos, m_pSolarSystem->m_pSelectedOrbitRing->m_pPlanet->m_fRotationSpeed);

                orxVector_Clamp(&selectedPlanetPos, &selectedPlanetPos, &m_pSolarSystem->m_pSelectedOrbitRing->m_pPlanet->m_vMinPos, &m_pSolarSystem->m_pSelectedOrbitRing->m_pPlanet->m_vMaxPos);

                m_pSolarSystem->m_pSelectedOrbitRing->m_pPlanet->SetPosition(selectedPlanetPos);
            }
            else if (orxInput_IsActive("PlanetMoveUp"))
            {
                orxVECTOR rotatedVector = *orxVector_2DRotate(&selectedPlanetPos, &selectedPlanetPos, -m_pSolarSystem->m_pSelectedOrbitRing->m_pPlanet->m_fRotationSpeed);

                orxVector_Clamp(&selectedPlanetPos, &selectedPlanetPos, &m_pSolarSystem->m_pSelectedOrbitRing->m_pPlanet->m_vMinPos, &m_pSolarSystem->m_pSelectedOrbitRing->m_pPlanet->m_vMaxPos);

                m_pSolarSystem->m_pSelectedOrbitRing->m_pPlanet->SetPosition(selectedPlanetPos);
            }
        }
        if (m_ePhase >= Phase::Five)
        {
            // Do something.
        }
    }
    else
    {
        // Do something.
    }
}
