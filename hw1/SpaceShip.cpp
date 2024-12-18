/*
/Anıl Keskin
 CS201-3
 2220195
*/
#include <iostream>
#include <string>
#include "SpaceShip.h"
#include "Mission.h"
using namespace std;
SpaceShip::SpaceShip() {

}

SpaceShip::SpaceShip(string name, string type) {
this->name = name;
this->type = type;
mission_number = 0;
}

SpaceShip::~SpaceShip() {
mission_number = 0;
}

string SpaceShip::getName() {
    return name;
}

string SpaceShip::getType() {
    return type;
}

int SpaceShip::getMissionNumber() const {
    return mission_number;
}

void SpaceShip::toString() {
    string status;
    if(isAvailable())
        status = "Available";
    else
        status = "Assigned";

    cout << "Spacecraft: " << getName() << ", Type: " << getType() << ", Status: " << status << endl;
}

bool SpaceShip::isAvailable() const {
    if( getMissionNumber() == 1)
        return false;
    else
        return true;
}

void SpaceShip::changeMissionNumber(int x) {
    mission_number += x;

}

void SpaceShip::setMission(string mission) {
    this->mission = mission;

}

string SpaceShip::getMission() {
    return mission;
}




void SpaceShip::printSpacecraftProperties() {
    string status;
    if(isAvailable())
        status = "Available";
    else
        status = "Assigned";
    cout<< "Spacecraft: " << getName() << ", Type: " << getType() << ", Status: " << status << endl;

}
