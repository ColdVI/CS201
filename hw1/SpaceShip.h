/*
/Anıl Keskin
 CS201-3
 2220195
*/

#ifndef CS201HW1_SPACESHIP_H
#define CS201HW1_SPACESHIP_H
#include <iostream>
#include <string>
#include "Mission.h"



class SpaceShip {
public:
SpaceShip();
SpaceShip(std::string name, std::string type);
~SpaceShip();

    std::string getName();
    std::string getType();
int getMissionNumber() const;
void changeMissionNumber(int x);
void setMission(std::string mission);
std::string getMission();

void toString();
bool isAvailable() const;
void setAvailable(bool b);
void printSpacecraftProperties();
private:
    std::string mission;

    std::string name;
    std::string type;
    int mission_number;
};


#endif //CS201HW1_SPACESHIP_H
