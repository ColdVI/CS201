/*
/Anıl Keskin
 CS201-3
 2220195
*/

#ifndef CS201HW1_MISSION_H
#define CS201HW1_MISSION_H


#include <iostream>
#include <string>
#include "SpaceShip.h"

class Mission {
public:
    Mission();
    Mission(const std::string missionName, const std::string date, const std::string destination);
    ~Mission();

    std::string getName();
    std::string getDate();
    std::string getDestination();
    int getAssignNumber();


    void setName(std::string name) ;
    void setDate(std::string date) ;
    void setDestination(std::string destination) ;
    void setAvailability(const bool state) ;
    void toString() ;
    bool isAvailable() ;
    void dynamicArray(int op);
    void changeAssignNumber(int x);
    void assignShip(std::string name);
    std::string* getShipAssigned();
    void deleteShip(std::string spaceShip);
    void printMissionProperties();

private:
    std::string name;
    std::string ldestination;
    std::string ldate;
    int assignNumber;

    std::string* shipsAssigned;
};


#endif //CS201HW1_MISSION_H
