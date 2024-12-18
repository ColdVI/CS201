/*
/Anıl Keskin
 CS201-3
 2220195
*/
#include <iostream>
#ifndef CS201HW1_SPACEMISSIONMANAGEMENTSYSTEM_H
#define CS201HW1_SPACEMISSIONMANAGEMENTSYSTEM_H

#include "SpaceMissionManagementSystem.h"
#include "Mission.h"
#include "SpaceShip.h"


using namespace std;
class SpaceMissionManagementSystem {
public:
    SpaceMissionManagementSystem();
    ~SpaceMissionManagementSystem();
    void addMission( const string name, const string launchDate, const string
    destination );
    void removeMission( const string name );
    void addSpacecraft( const string name, const string type );
    void removeSpacecraft( const string name );
    void assignSpacecraftToMission( const string spacecraftName, const string
    missionName );
    void dropSpacecraftFromMission( const string spacecraftName );

    void showAllMissions() const;
    void showAllSpacecrafts() const;
    void showMission( const string name ) const;
    void showSpacecraft( const string name ) const;
    void dynamicMission(int operation);
    void dynamicShips( int operation);
private:
    int missionCount;
    int shipCount;
    SpaceShip* ships;
    Mission* missions;
    int missionExist(string name) const;
    int SpacecraftExist(string name) const;

};



#endif //CS201HW1_SPACEMISSIONMANAGEMENTSYSTEM_H
