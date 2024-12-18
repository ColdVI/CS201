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

Mission::Mission() {
    assignNumber = 0;
}

Mission::Mission(const string missionName, const string date, const string destination) {
    assignNumber = 0;
    shipsAssigned = nullptr;
    name = missionName;
    ldate = date;
    ldestination = destination;

}

Mission::~Mission() {
    delete[] shipsAssigned;
    assignNumber= 0;
}

string Mission::getName() {
    return name;
}

string Mission::getDate() {
    return ldate;
}

string Mission::getDestination() {
    return ldestination;
}

void Mission::setName(string name) {

}

void Mission::setDate(string date) {

}

void Mission::setDestination(string destination) {

}

void Mission::setAvailability(const bool state) {

}

void Mission::toString() {
    cout << "Mission: " << getName() << ", Launch Date: " << getDate() << ", Destination: " << getDestination() <<
         ", Assigned Spacecraft Count: " << getAssignNumber() << endl;
}

bool Mission::isAvailable() {
    return false;
}

int Mission::getAssignNumber() {

    return assignNumber;
}

void Mission::dynamicArray(int op) {

    if(op == -1){
        string* temp = new string[getAssignNumber()+1];
        for (int i = 0; i < assignNumber; ++i) {
            temp[i] = shipsAssigned[i];
        }
        delete[] shipsAssigned;
        shipsAssigned = temp;
        assignNumber++;
    }

    else{
        int j{0};
        string* temp = new string[getAssignNumber()-1];
        for (int i = 0; i < getAssignNumber(); ++i) {
            if( i != op){
                temp[j++] = shipsAssigned[i];

            }
        }

        delete[] shipsAssigned;
        shipsAssigned = temp;
        assignNumber--;

    }
}

void Mission::changeAssignNumber(int x) {
    assignNumber += x;

}

string *Mission::getShipAssigned() {
    return shipsAssigned;
}

void Mission::assignShip(std::string spaceShip) {
    dynamicArray(-1);
    shipsAssigned[assignNumber-1] = spaceShip;


}

void Mission::deleteShip(std::string spaceShip) {
    int j{0};
    if(assignNumber == 1){
        delete[] shipsAssigned;
        shipsAssigned = nullptr;
        assignNumber = 0;
    }
    else {
        std::string *temp = new string[getAssignNumber() - 1];
        for (int i = 0; i < assignNumber; ++i) {
            if (shipsAssigned[i] != spaceShip)
                temp[j++] = shipsAssigned[i];

        }
        delete[] shipsAssigned;
        shipsAssigned = temp;
        assignNumber--;
    }

}

void Mission::printMissionProperties() {
    cout << "Mission:" <<endl;
    cout << "  Name: " << getName() << endl;
    cout << "  Launch Date: " << getDate()<< endl;
    cout << "  Destination: " << getDestination()<< endl;
    cout << "  Assigned Spacecrafts:" << endl;
    if(assignNumber == 0)
        cout <<  "    None" << endl;
    else{
        for (int i = 0; i < assignNumber; ++i) {
            cout<< "  - " <<shipsAssigned[i]<< endl;

        }
    }


}
