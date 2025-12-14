//playlist.h
#ifndef DLL_PLAYLIST_H
#define DLL_PLAYLIST_H
#include "lagu.h"

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

#endif