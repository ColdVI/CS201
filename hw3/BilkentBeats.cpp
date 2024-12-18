/*
Anil Keskin
Sec3
22201915
*/
#include "BilkentBeats.h"
#include <string>
#include "User.h"
#include "Song.h"
#include "Playlist.h"
#include "LinkedList.h"
#include <iostream>

BilkentBeats::BilkentBeats() {}

BilkentBeats::~BilkentBeats() {
    
    Node<User>* currentUser = users.headptr;
    while (currentUser != nullptr) {
        User* user = currentUser->getPointItem();  

        
        Node<Playlist>* currentPlaylist = user->playlists.headptr;
        while (currentPlaylist != nullptr) {
            
            
            currentPlaylist = currentPlaylist->next;
        }
        currentUser = currentUser->next;
    }
}


void BilkentBeats::addUser(const int userId, const std::string userName) {
    User* newUser = new User(userId, userName);
    if (users.exists(*newUser)) {
        delete newUser;
        std::cout << "Cannot add user. There is already a user with ID " << userId << "." << std::endl;
        return;
    }
    users.insertSorted(*newUser);
    std::cout << "Added user " << userId << "." << std::endl;
    delete newUser;
}

void BilkentBeats::removeUser(const int userId) {
    User removeUs(userId);
    //User* dummyUser = new User(userId, "");
    if (users.remove(removeUs)) {
       // delete dummyUser;
        std::cout << "Removed user " << userId << "." << std::endl;
    } else {
       // delete dummyUser;
        std::cout << "Cannot remove user. There is no user with ID " << userId << "." << std::endl;
    }
}

void BilkentBeats::printUsers() const {
    if (users.isEmpty()) {
        std::cout << "There are no users to show." << std::endl;
        return;
    }

    std::cout << "Users in the system:" << std::endl;
    Node<User>* current = users.getNodeAt(0);


    while (current != nullptr) {


        current->getItem().print();
        current = current->getNext();

    }
}

void BilkentBeats::addSong(const int songID, const std::string songName, const std::string artists) {
    Song* newSong = new Song(songID, songName, artists);
    if (songs.exists(*newSong)) {
        delete newSong;  
        std::cout << "Cannot add song. BilkentBeats already contains song " << songID << "." << std::endl;
        return;
    }
    songs.insertSorted(*newSong);
    delete newSong;
    std::cout << "Added song " << songID << "." << std::endl;
}

void BilkentBeats::removeSong(const int songId) {
    Song tempSong(songId, "", "");
    if (!songs.exists(tempSong)) {
        std::cout << "Cannot remove song. There is no song with ID " << songId << "." << std::endl;
        return;
    }

    
    Node<User>* currentUser = users.headptr;
    while (currentUser != nullptr) {
        User* user = currentUser->getPointItem();
        Node<Playlist>* currentPlaylist = user->playlists.headptr;

        while (currentPlaylist != nullptr) {
            Playlist* playlist = currentPlaylist->getPointItem();
            if (playlist->songIds.exists(tempSong)) {
                playlist->songIds.remove(tempSong);
            }
            currentPlaylist = currentPlaylist->getNext();
        }
        currentUser = currentUser->getNext();
    }

   
    songs.remove(tempSong);
    std::cout << "Removed song " << songId << "." << std::endl;
    delete currentUser;
}

void BilkentBeats::printSongs() const {
    if (songs.isEmpty()) {
        std::cout << "Cannot print songs. There is no song in the music library." << std::endl;
        return;
    }
    std::cout << "Music Library:" << std::endl;
    songs.print();
}

void BilkentBeats::addPlaylist(const int userId, const int playlistId) {
    User tempUser(userId, "");
    Node<User>* userNode = users.find(tempUser);

    if (!userNode) {
        std::cout << "Cannot add playlist. There is no user with ID " << userId << "." << std::endl;
        return;
    }

    Playlist tempPlaylist(playlistId);

   
    Node<User>* current = users.headptr;
    while (current != nullptr) {
        if (current->getItem().getPlaylists().exists(tempPlaylist)) {
            std::cout << "Cannot add playlist. There is a user having a playlist with ID " << playlistId << "." << std::endl;
            return;
        }
        current = current->getNext();
    }

    Playlist* newPlaylist = new Playlist(playlistId);
    User* t_user = userNode->getPointItem();

    try {
        User* newUser = new User(t_user->getId(), t_user->getName());

        Node<Playlist>* tmp = t_user->playlists.headptr;
        while (tmp != nullptr) {
            newUser->addPlaylist(tmp->getItem());
            tmp = tmp->getNext();
        }

        users.remove(tempUser);
        newUser->playlists.insertSorted(*newPlaylist);
        users.insertSorted(*newUser);

        delete newPlaylist;  
        delete newUser;      
        delete tmp;
        delete current;


        std::cout << "Added playlist " << playlistId << " to user " << userId << "." << std::endl;
    }
    catch (...) {
        delete newPlaylist;  
        throw; 
    }
}

void BilkentBeats::removePlaylist(const int userId, const int playlistId) {
    
    User tempUser(userId, "");
    Node<User>* userNode = users.find(tempUser);

    if (!userNode) {
        std::cout << "Cannot remove playlist. There is no user with ID " << userId << "." << std::endl;
        return;
    }

    
    Playlist tempPlaylist(playlistId);
    User* user = userNode->getPointItem();

    if (!user->playlists.exists(tempPlaylist)) {
        std::cout << "Cannot remove playlist. User " << userId << " does not have a playlist with ID " << playlistId << "." << std::endl;
        return;
    }

    
    int userid = user->getId();
    std::string name = user->getName();
    User* newUser = new User(userid, name);

   
    Node<Playlist>* currentPlaylist = user->playlists.headptr;
    while (currentPlaylist != nullptr) {
        Playlist playlist = currentPlaylist->getItem();
        if (playlist.getId() != playlistId) {
            newUser->addPlaylist(playlist);
        }
        currentPlaylist = currentPlaylist->getNext();
    }

   
    users.remove(tempUser);
    users.insertSorted(*newUser);
    delete newUser;
    delete currentPlaylist;



    std::cout << "Removed playlist " << playlistId << " from user " << userId << "." << std::endl;
}

void BilkentBeats::addSongToPlaylist(const int playlistId, const int songId) {
    
    Song tempSong(songId, "", "");
    Node<Song>* songNode = songs.find(tempSong);
    if (!songNode) {
        std::cout << "Cannot add song. There is no song with ID " << songId << "." << std::endl;
        return;
    }

    
    Playlist tempPlaylist(playlistId);
    bool playlistFound = false;

   
    Node<User>* currentUser = users.headptr;
    while (currentUser != nullptr && !playlistFound) {
        User* user = currentUser->getPointItem();
        Node<Playlist>* playlistNode = user->playlists.find(tempPlaylist);

        if (playlistNode) {
            
            Playlist* targetPlaylist = playlistNode->getPointItem();

         
            if (targetPlaylist->songIds.exists(tempSong)) {
                std::cout << "Cannot add song. The playlist already contains song " << songId << "." << std::endl;
                return;
            }

           
            targetPlaylist->songIds.insert(songNode->getItem());
            playlistFound = true;
            std::cout << "Added song " << songId << " to playlist " << playlistId << "." << std::endl;
        }
        currentUser = currentUser->getNext();
    }

    if (!playlistFound) {
        std::cout << "Cannot add song. There is no playlist with ID " << playlistId << "." << std::endl;
    }

}

void BilkentBeats::removeSongFromPlaylist(const int playlistId, const int songId) {
    
    Song tempSong(songId, "", "");
    Playlist tempPlaylist(playlistId);
    bool playlistFound = false;

    
    Node<User>* currentUser = users.headptr;
    while (currentUser != nullptr && !playlistFound) {
        User* user = currentUser->getPointItem();
        Node<Playlist>* playlistNode = user->playlists.find(tempPlaylist);

        if (playlistNode) {
            
            Playlist* targetPlaylist = playlistNode->getPointItem();

           
            if (!targetPlaylist->songIds.exists(tempSong)) {
                std::cout << "Cannot remove song. There is no song " << songId << " in playlist " << playlistId << "." << std::endl;
                return;
            }

            
            targetPlaylist->songIds.remove(tempSong);
            playlistFound = true;
            std::cout << "Removed song " << songId << " from playlist " << playlistId << "." << std::endl;
        }
        currentUser = currentUser->getNext();
    }

    if (!playlistFound) {
        std::cout << "Cannot remove song. There is no playlist with ID " << playlistId << "." << std::endl;
    }
}

void BilkentBeats::printSongsInPlaylist(const int playlistId) const {
    Playlist tempPlaylist(playlistId);

    
    for (int i = 0; i < users.getLength(); i++) {
        User currentUser = users.getNodeAt(i)->getItem();
        Node<Playlist>* playlistNode = currentUser.playlists.find(tempPlaylist);

        if (playlistNode) {
            
            Playlist playlist = playlistNode->getItem();
            if (playlist.songIds.isEmpty()) {
                std::cout << "There are no songs to show in playlist " << playlistId << "." << std::endl;
            } else {
                std::cout << "Songs in playlist " << playlistId << ":" << std::endl;
                playlist.printSongs();
            }
            return;
        }
    }

    
    std::cout << "Cannot print songs. There is no playlist with ID " << playlistId << "." << std::endl;
}
