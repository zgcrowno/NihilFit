/**
 * @file NihilFit.cpp
 * @date 29-Jun-2020
 */

#define __SCROLL_IMPL__
#include "NihilFit.h"
#undef __SCROLL_IMPL__

#define orxNUKLEAR_IMPL
#include "orxNuklear.h"
#undef orxNUKLEAR_IMPL

#include "Asteroid.h"
#include "OrbitRing.h"
#include "Planet.h"
#include "Satellite.h"
#include "SceneSolarSystem.h"
#include "Star.h"
#include "SolarSystem.h"
#include "SpaceJunk.h"
#include "Sun.h"

using namespace nihilFit;

/** Update function, it has been registered to be called every tick of the core clock
 */
void NihilFit::Update(const orxCLOCK_INFO &_rstInfo)
{
    // Should quit?
    if(orxInput_IsActive("Quit"))
    {
        // Send close event
        orxEvent_SendShort(orxEVENT_TYPE_SYSTEM, orxSYSTEM_EVENT_CLOSE);
    }
}

/** Init function, it is called when all orx's modules have been initialized
 */
orxSTATUS NihilFit::Init()
{
    // Display a small hint in console
    orxLOG("\n* This template project creates a simple scene"
    "\n* You can play with the config parameters in ../data/config/NihilFit.ini"
    "\n* After changing them, relaunch the executable to see the changes.");

    // Display additional Nuklear hint in console
    orxLOG("\n* This template has support for Nuklear.");

    // Initialize Dear ImGui
    orxNuklear_Init();

    // Create the scene
    CreateObject("O-SceneSolarSystem");

    // Done!
    return orxSTATUS_SUCCESS;
}

/** Run function, it should not contain any game logic
 */
orxSTATUS NihilFit::Run()
{
    // Return orxSTATUS_FAILURE to instruct orx to quit
    return orxSTATUS_SUCCESS;
}

/** Exit function, it is called before exiting from orx
 */
void NihilFit::Exit()
{
    // Exits from Nuklear
    orxNuklear_Exit();

    // Let Orx clean all our mess automatically. :)
}

/** BindObjects function, ScrollObject-derived classes are bound to config sections here
 */
void NihilFit::BindObjects()
{
    ScrollBindObject<Asteroid>("O-Asteroid");
    ScrollBindObject<OrbitRing>("O-OrbitRing");
    ScrollBindObject<Planet>("O-Planet");
    ScrollBindObject<Satellite>("O-Satellite");
    ScrollBindObject<SceneSolarSystem>("O-SceneSolarSystem");
    ScrollBindObject<Star>("O-Star");
    ScrollBindObject<SolarSystem>("O-SolarSystem");
    ScrollBindObject<SpaceJunk>("O-SpaceJunk");
    ScrollBindObject<Sun>("O-Sun");
}

/** Bootstrap function, it is called before config is initialized, allowing for early resource storage definitions
 */
orxSTATUS NihilFit::Bootstrap() const
{
    // Add a config storage to find the initial config file
    orxResource_AddStorage(orxCONFIG_KZ_RESOURCE_GROUP, "../data/config", orxFALSE);

    // Return orxSTATUS_FAILURE to prevent orx from loading the default config file
    return orxSTATUS_SUCCESS;
}

std::vector<ScrollObject*> NihilFit::GetSpaceJunk()
{
    std::vector<ScrollObject*> retVal;

    for (SpaceJunk *spaceJunk = GetNextObject<SpaceJunk>(); spaceJunk != nullptr; spaceJunk = GetNextObject<SpaceJunk>(spaceJunk))
    {
        retVal.push_back(spaceJunk);
    }

    return retVal;
}

std::vector<ScrollObject*> NihilFit::GetAsteroids()
{
    std::vector<ScrollObject*> retVal;

    for (Asteroid *asteroid = GetNextObject<Asteroid>(); asteroid != nullptr; asteroid = GetNextObject<Asteroid>(asteroid))
    {
        retVal.push_back(asteroid);
    }

    return retVal;
}

ScrollObject *NihilFit::GetSun()
{
    return GetNextObject<Sun>();
}

ScrollObject *NihilFit::GetSceneSolarSystem()
{
    return GetNextObject<SceneSolarSystem>();
}

/** Main function
 */
int main(int argc, char **argv)
{
    // Execute our game
    NihilFit::GetInstance().Execute(argc, argv);

    // Done!
    return EXIT_SUCCESS;
}
