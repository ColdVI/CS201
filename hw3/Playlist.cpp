/*
Anil Keskin
Sec3
22201915
*/
#include "Playlist.h"
#include <iostream>

Playlist::Playlist(int playlistId) : playlistId(playlistId) {}

Playlist::~Playlist() {
   
    songIds.clear();
}


void Playlist::print() {
    std::cout << "Playlist id: " << playlistId << std::endl;
}

bool Playlist::addSong(Song* song) {
    if (song != nullptr && !songIds.exists(*song)) {
        Song *newSong = new Song(*song);
        songIds.insert(*newSong); 
        return true;
    }
    return false;
}

bool Playlist::removeSong(Song* song) {
    if (song != nullptr) {
        return songIds.remove(*song);
    }

    return false;
}


void Playlist::printSongs() const {
    if (songIds.isEmpty()) {
        return;  
    }

    Node<Song>* current = songIds.getNodeAt(0);
    while (current != nullptr) {
        Song song = current->getItem();
        std::cout <<"Song " <<song.songId << " : " << song.name << " - " << song.artist << std::endl;
        current = current->getNext();
    }
}

int Playlist::getId() const {
    return playlistId;
}

bool Playlist::operator==(const Playlist &other) const {
    return playlistId == other.playlistId;
}
