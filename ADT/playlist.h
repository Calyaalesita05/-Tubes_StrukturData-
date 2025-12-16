#ifndef PLAYLIST_MUSIC_APP_H
#define PLAYLIST_MUSIC_APP_H

#include "lagu.h"
#include <string>

struct NodeDLL {
    PointerLagu laguPtr;
    NodeDLL* next;
    NodeDLL* prev;
};

struct Playlist {
    NodeDLL* first;
    NodeDLL* last;
    NodeDLL* current;
};

void CreatePlaylist(Playlist& P);
void InsertLaguKePlaylist(Playlist& P, PointerLagu pLagu);
void NextLagu(Playlist& P);
void PrevLagu(Playlist& P);
void DeleteLaguFromPlaylist(Playlist& P, std::string idLagu);

#endif