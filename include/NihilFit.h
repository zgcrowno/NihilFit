/**
 * @file NihilFit.h
 * @date 29-Jun-2020
 */

#ifndef __NihilFit_H__
#define __NihilFit_H__

#define __NO_SCROLLED__
#include "Scroll.h"
#include <vector>

/** Game Class
 */
class NihilFit : public Scroll<NihilFit>
{
public:
    std::vector<ScrollObject*> GetSpaceJunk();
    std::vector<ScrollObject*> GetAsteroids();
    ScrollObject *GetSun();
    ScrollObject *GetSceneSolarSystem();

private:

                orxSTATUS       Bootstrap() const;

                void            Update(const orxCLOCK_INFO &Info);

                orxSTATUS       Init();
                orxSTATUS       Run();
                void            Exit();
                void            BindObjects();


private:
};

#endif // __NihilFit_H__
