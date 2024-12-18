/*
Anil Keskin
Sec3
22201915
*/
#pragma once
#include "LinkedList.h"
#include "Playlist.h"
#ifndef USER_H
#define USER_H
class User {
public:
    int userId;
    std::string name;
    LinkedList<Playlist> playlists; 

    User(const User &other);

    User(int userId, const std::string name);
    User(int usedId);
    ~User();
    void print();
    bool addPlaylist(Playlist playlist);
    bool removePlaylist(const Playlist playlistId);
    void printPlaylists() const;
    LinkedList<Playlist> getPlaylists() const;

    int getId() const;
    std::string getName() const;
    bool operator==(const User& other) const;

};
#endif