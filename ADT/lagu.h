#ifndef LAGU_H
#define LAGU_H

#include <iostream>
#include <string>

struct Lagu {
    std::string ID_Lagu;
    std::string Judul;
    std::string Artis;
    std::string Genre;
    int Tahun;
    int Durasi;
    std::string Lirik_Sample; 
    std::string GenerateNewID(int& counter);
};

struct Akun {
    std::string username;
    std::string password;
    std::string role; // "Admin" atau "User"
};

typedef Lagu* PointerLagu; 
Lagu InputLaguBaru(int& global_counter);

#endif