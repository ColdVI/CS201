/*
/Anıl Keskin
 CS201-3
 2220195
*/

#include "SpaceMissionManagementSystem.h"

SpaceMissionManagementSystem::SpaceMissionManagementSystem() {
missionCount = 0;
shipCount = 0;
    ships = new SpaceShip[shipCount];
     missions = new Mission[missionCount];
}

SpaceMissionManagementSystem::~SpaceMissionManagementSystem() {
delete[] ships;
delete[] missions;
}

void SpaceMissionManagementSystem::addMission(const string name, const string launchDate, const string destination) {
 if(missionExist(name) != -1){
    cout << "Cannot add mission. Mission " << name << " already exists." << endl;
 }
 else{
     dynamicMission(-1);
     missions[missionCount-1] = Mission(name, launchDate, destination);

     cout << "Added mission " << name << "." << endl;
 }
}

void SpaceMissionManagementSystem::removeMission(const string name) {
    int i = missionExist(name);
if(i == -1) {
    cout << "Cannot remove mission. Mission " << name << " does not exist." << endl;
}
else
{
    /*Forcefull dropAssignment of spacecrafts */ //------------------------
    int v = missions[i].getAssignNumber();

    for (int j = 0; j <v ; j++) {

        string shipn = (missions[i].getShipAssigned())[0];

        int z = SpacecraftExist(shipn);

        ships[z].changeMissionNumber(-1);

        missions[i].deleteShip(shipn);

    }


    //----------------------------------------------
    dynamicMission(i);
    cout << "Removed mission " << name <<"." << endl;
}

}

void SpaceMissionManagementSystem::addSpacecraft(const string name, const string type) {
int i = SpacecraftExist(name);
if(i != -1){
    cout << "Cannot add spacecraft. Spacecraft " << name << " already exists." << endl;
}
else{
    dynamicShips(-1);
    ships[shipCount-1] = SpaceShip(name, type);
    cout << "Added spacecraft " << name << "." << endl;
}
}

void SpaceMissionManagementSystem::removeSpacecraft(const string name) {
int i = SpacecraftExist(name);
if(i == -1){
    cout << "Cannot remove spacecraft. Spacecraft " << name<< " does not exist." << endl;

}
else{
    if(ships[i].getMissionNumber() != 0){
        cout << "Cannot remove spacecraft. Spacecraft " << name<< " is assigned to a mission." << endl;
    }
    else{
        dynamicShips(i);
        cout << "Removed spacecraft " << name <<"."<< endl;
    }
}

}

void SpaceMissionManagementSystem::assignSpacecraftToMission(const string spacecraftName, const string missionName) {
int i = SpacecraftExist(spacecraftName);
int j = missionExist(missionName);

if(i == -1){
    cout<< "Cannot assign spacecraft. Spacecraft " <<spacecraftName << " does not exist." << endl;

}
else if( j == -1 ){
    cout<< "Cannot assign spacecraft. Mission " <<missionName << " does not exist." << endl;
}
else if ( ships[i].getMissionNumber() != 0){
    cout << "Cannot assign spacecraft. Spacecraft " << spacecraftName << " is already assigned to mission " << ships[i].getMission() << "." << endl;
}
else{
    ships[i].changeMissionNumber(1);
    missions[j].assignShip(ships[i].getName());
    ships[i].setMission(missionName);
    cout << "Assigned spacecraft " << spacecraftName << " to mission " << missionName << "." << endl;

}
}

void SpaceMissionManagementSystem::dropSpacecraftFromMission(const string spacecraftName) {
    int i = SpacecraftExist(spacecraftName);


    if(i == -1){
        cout<< "Cannot drop spacecraft. Spacecraft " <<spacecraftName << " does not exist." << endl;

    }
    else {
        if (ships[i].getMissionNumber() == 0) {
            cout << "Cannot drop spacecraft. Spacecraft " << spacecraftName << " is not assigned to any mission." << endl;
        } else {
            ships[i].changeMissionNumber(-1);


            cout << "Dropped spacecraft " << spacecraftName << " from mission " << ships[i].getMission() << "." << endl;
            int j = missionExist(ships[i].getMission());
            missions[j].deleteShip(ships[i].getName());


        }
    }

}


void SpaceMissionManagementSystem::showAllMissions() const {
cout << "Missions in the space mission management system:" << endl;
if(missionCount == 0) {
    cout << "None" << endl;
}
else{
        for (int i = 0; i < missionCount; ++i) {
           missions[i].toString();
        }

}


}

void SpaceMissionManagementSystem::showAllSpacecrafts() const {
    cout << "Spacecrafts in the space mission management system:" << endl;
    if(shipCount == 0) {
        cout << "None" << endl;
    }
    else{
        for (int i = 0; i < shipCount; ++i) {
            ships[i].toString();
        }

    }
}

void SpaceMissionManagementSystem::showMission(const string name) const {
int j = missionExist(name);
if(j == -1){
        cout<< "Cannot show mission. Mission " << name << " does not exist." << endl;
    }
else if(j != -1){
    missions[j].printMissionProperties();
}
}

void SpaceMissionManagementSystem::showSpacecraft(const string name) const {
    int i = SpacecraftExist(name);
    if(i == -1){
        cout<< "Cannot show spacecraft. Spacecraft " << name << " does not exist." << endl;
    }
    else if(i != -1){
        ships[i].printSpacecraftProperties();
    }
}


int SpaceMissionManagementSystem::missionExist(string name) const {
    for (int i = 0; i < missionCount ; i++){
        if (missions[i].getName() == name){
            return i;
        }
    }
    return -1;
}

int SpaceMissionManagementSystem::SpacecraftExist(string name) const {
    for (int i = 0; i < shipCount ; i++){
        if (ships[i].getName() == name){

            return i;
        }
    }
    return -1;
}


void SpaceMissionManagementSystem::dynamicMission(int operation) {
/* operation -1 means upgrading size otherwise means downwarding size by one and operation is index of element to be removed*/

    if(operation == -1){
        Mission* temp = new Mission[missionCount+1];
        for (int i = 0; i < missionCount; ++i) {
            temp[i] = missions[i];
        }
        delete[] missions;
        missions = temp;
        missionCount++;
    }

    else{
        int j{0};
    Mission* temp = new Mission[missionCount-1];
        for (int i = 0; i < missionCount; ++i) {
            if( i != operation){
                temp[j++] = missions[i];

            }
        }
            delete[] missions;
            missions = temp;
            missionCount--;


    }

}

void SpaceMissionManagementSystem::dynamicShips(int operation) {
/* operation -1 means upgrading size otherwise means downwarding size by one and operation is index of element to be removed*/

    if(operation == -1){
        SpaceShip* temp = new SpaceShip[shipCount+1];
        for (int i = 0; i < shipCount; ++i) {
            temp[i] = ships[i];
        }
        delete[] ships;
        ships = temp;
        shipCount++;
    }

    else{
        int j{0};
        SpaceShip* temp = new SpaceShip[shipCount-1];
        for (int i = 0; i < shipCount; ++i) {
            if( i != operation){
                temp[j] =  ships[i];
                j++;
            }
        }
            delete[] ships;
            ships = temp;
            shipCount--;


    }

}
