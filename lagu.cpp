// lagu.cpp
#include "lagu.h"
#include <iostream>
#include <limits>
#include <sstream>
#include <iomanip>
#include <string>

std::string GenerateNewID(int& counter) {
    counter++; // Tingkatkan counter global

    std::string prefix = "L"; // Prefix default untuk lagu baru
    
    // Menggunakan stringstream untuk format angka menjadi 3 digit (misal 7 -> 007)
    std::stringstream ss;
    ss << prefix << std::setw(3) << std::setfill('0') << counter;
    
    return ss.str();
}
Lagu InputLaguBaru(int& global_counter) { 
    Lagu newLagu;
    std::string input;
    bool valid = false;

    std::cout << "\n--- INPUT LAGU BARU ---" << std::endl;

    //Auto Increment ID Lagu
    newLagu.ID_Lagu = GenerateNewID(global_counter); // ID dibuat otomatis
    std::cout << "ID Lagu: " << newLagu.ID_Lagu << std::endl;

    //Input Judul Lagu
    while (!valid) {
        std::cout << "Masukkan Judul Lagu: ";
        std::getline(std::cin, input);
        if (!input.empty()) {
            newLagu.Judul = input;
            valid = true;
        } else {
            std::cout << "Judul Lagu tidak boleh kosong. Silakan ulangi." << std::endl;
        }
    }
    
    //Input Artis
    valid = false;
    while (!valid) {
        std::cout << "Masukkan Nama Artis/Penyanyi: ";
        std::getline(std::cin, input);
        if (!input.empty()) {
            newLagu.Artis = input;
            valid = true;
        } else {
            std::cout << "Nama Artis/Penyanyi tidak boleh kosong. Silakan ulangi." << std::endl;
        }
    }

    //Input Genre
    valid = false;
    while (!valid) {
        std::cout << "Masukkan Genre: ";
        std::getline(std::cin, input);
        if (!input.empty()) {
            newLagu.Genre = input;
            valid = true;
        } else {
            std::cout << "Genre tidak boleh kosong. Silakan ulangi." << std::endl;
        }
    }

    //Input Durasi (dengan validasi angka > 0)
    newLagu.Durasi = 0;
    while (newLagu.Durasi <= 0) {
        std::cout << "Masukkan Durasi (detik, > 0): ";
        if (!(std::cin >> newLagu.Durasi)) {
            std::cout << "Input tidak valid. Masukkan angka." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (newLagu.Durasi <= 0) {
             std::cout << "Durasi harus lebih dari 0 detik." << std::endl;
        }
    }
    // Membersihkan buffer setelah cin
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    newLagu.Tahun = 0;
    newLagu.Lirik_Sample = "(Lirik belum diinput untuk lagu baru ini)"; 
    
    return newLagu;
}