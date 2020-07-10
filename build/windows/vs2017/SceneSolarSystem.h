#pragma once

#include "NihilFit.h"
#include "Phase.h"
#include "Planet.h"
#include "SolarSystem.h"

namespace nihilFit
{
    // Using virtual inheritance for ScrollMod to prevent member ambiguity errors when also inheriting from InputHandler.
    class SceneSolarSystem : public ScrollObject
    {
    protected:
        //! Called on object creation
        virtual void OnCreate();
        //! Called on object deletion
        virtual void OnDelete();
        //! Called on object collision
        virtual orxBOOL OnCollide(
            ScrollObject *_poCollider,
            const orxSTRING _zPartName,
            const orxSTRING _zColliderPartName,
            const orxVECTOR &_rvPosition,
            const orxVECTOR &_rvNormal);
        //! Called on clock update
        virtual void Update(const orxCLOCK_INFO &_rstInfo);
    public:
        Phase m_ePhase;
        float m_fPrologueLength;
        float m_fPhaseOneLength;
        float m_fPhaseTwoLength;
        float m_fPhaseFiveLength;
        float m_fEpilogueLength;
        float m_fPhaseTime;
        float m_fPhaseOneSpaceJunkSpawnInterval;
        float m_fPhaseTwoSpaceJunkSpawnInterval;
        float m_fPhaseThreeSpaceJunkSpawnInterval;
        float m_fPhaseFourSpaceJunkSpawnInterval;
        float m_fPhaseFiveSpaceJunkSpawnInterval;
        float m_fSpaceJunkSpawnTime;
        float m_fMinShootingStarSpawnInterval;
        float m_fMaxShootingStarSpawnInterval;
        float m_fShootingStarSpawnTime;
        float m_fPhaseOneSetUpLength;
        float m_fPhaseTwoSetUpLength;
        float m_fPhaseThreeSetUpLength;
        float m_fPhaseFourSetUpLength;
        float m_fPhaseFiveSetUpLength;
        float m_fSetUpTime;
        float m_fPrologueSolarSystemLerpStartTime;
        orxVECTOR m_vMaxShootingStarSpeed;
        SolarSystem *m_pSolarSystem;
        ScrollObject *m_pStarSpawner;

        void IncrementPhase();
        void SpawnSpaceJunk();
        void SetUpPhase();
        void SelectPlanetLeft();
        void SelectPlanetRight();
        void HandleShootingStars();
        void HandleInput();
    };
}
