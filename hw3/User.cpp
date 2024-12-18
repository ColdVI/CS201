/*
Anil Keskin
Sec3
22201915
*/
#include "User.h"
#include <iostream>
User::User(const User& other)
        : userId(other.userId), name(other.name), playlists(other.playlists) {
}



User::User(int userId, const std::string name)
        : userId(userId), name(name), playlists() {  
}

User::User(int userId)
    : userId(userId), name(""), playlists() {  
}
/*
User::~User() {
    
    Node<Playlist*>* current = playlists.headptr;
    while (current != nullptr) {
        delete current->getItem();
        current = current->getNext();
    }

    }*/
User::~User() {
  
    playlists.clear();
}



void User::print() {
    std::cout << "User ID : " << userId << ", Name : " << name;

    
    if (playlists.isEmpty()) {
        std::cout << ", Playlist IDs : None";
    } else {
        std::cout << ", Playlist IDs : [";

       
        Node<Playlist>* current = playlists.getNodeAt(0);
        bool isFirst = true;

        while (current != nullptr) {
            if (!isFirst) {
                std::cout << ",";
            }
            std::cout << current->getItem().playlistId;
            isFirst = false;
            current = current->getNext();
        }
        std::cout << "]";
    }
    std::cout << std::endl;
}

bool User::addPlaylist(Playlist playlist) {
    if (!playlists.exists(playlist)) {

        playlists.insertSorted(playlist); 
        return true;
    }
return false;
}

bool User::removePlaylist(Playlist playlistId) {

    Playlist* dummyPtr = &playlistId;
    if (playlists.exists(*dummyPtr)) {
        Node<Playlist>* node = playlists.find(*dummyPtr);
        if (node != nullptr) {
            Playlist toDelete = node->getItem();
            playlists.remove(*dummyPtr);

            return true;
        }
    }
    return false;
}

void User::printPlaylists() const {
    if (playlists.isEmpty()) {
        std::cout << "Playlist IDs: None" << std::endl;
        return;
    }
    std::cout << "Playlist IDs: [";
    playlists.print();
    std::cout << "]" << std::endl;
}

LinkedList<Playlist> User::getPlaylists() const {
    return playlists;
}

int User::getId() const {
    return userId;
}

std::string User::getName() const {
    return name;
}

bool User::operator==(const User &other) const {
    return userId == other.userId;

}


