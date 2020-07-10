#pragma once

#include "NihilFit.h"
#include "SpaceJunk.h"

namespace nihilFit
{
    // Using virtual inheritance for ScrollMod to prevent member ambiguity errors when also inheriting from InputHandler.
    class Satellite : public ScrollObject
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
        bool m_bOpen;
        float m_fRotationSpeed;
        orxSPAWNER *m_spSatelliteTailSpawner;
        SpaceJunk *m_pHeldSpaceJunk;

        void OpenOrClose();
    };
}
