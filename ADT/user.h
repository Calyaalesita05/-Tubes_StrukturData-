#ifndef USER_H
#define USER_H

#include <string>
#include "playlist.h"

struct User {
    std::string username;
    std::string password;
    std::string namaLengkap;
    Playlist playlistUser;
};

bool LoginUser(User users[], int jumlahUser, int &indexUser);

#endif