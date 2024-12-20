/*
Anil Keskin
Sec3
22201915
*/
#include "LinkedList.h"
#include "Song.h"
#ifndef PLAYLIST_H
#define PLAYLIST_H
class Playlist {
public:
    int playlistId;
    LinkedList<Song> songIds; 

    Playlist(int playlistId);
    ~Playlist();
    void print();
    bool addSong(Song* song);
    bool removeSong(Song* song);
    void printSongs() const;
    int getId() const;
    bool operator==(const Playlist& other) const;
};
#endif