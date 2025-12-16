#include "playlist.h"
#include <iostream>

void CreatePlaylist(Playlist& P) {
    P.first = nullptr;
    P.last = nullptr;
    P.current = nullptr;
    std::cout << "Playlist baru berhasil dibuat." << std::endl;
}

NodeDLL* createNewNodeDLL(PointerLagu pLagu) {
    NodeDLL* newNode = new NodeDLL;
    newNode->laguPtr = pLagu;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void InsertLaguKePlaylist(Playlist& P, PointerLagu pLagu) {
    if (pLagu == nullptr) {
        std::cout << "ERROR: Lagu tidak ditemukan di Library Utama. Gagal ditambahkan." << std::endl;
        return;
    }

    NodeDLL* newNode = createNewNodeDLL(pLagu);

    if (P.first == nullptr) {
        P.first = newNode;
        P.last = newNode;
        P.current = newNode;
    } else {
        P.last->next = newNode;
        newNode->prev = P.last;
        P.last = newNode;
    }
    std::cout << "Lagu '" << pLagu->Judul << "' berhasil ditambahkan ke Playlist." << std::endl;
}

void NextLagu(Playlist& P) {
    if (P.current == nullptr) {
        std::cout << "Playlist kosong atau tidak ada lagu yang sedang diputar." << std::endl;
        return;
    }
    
    if (P.current->next != nullptr) {
        P.current = P.current->next;
        std::cout << "-> Memutar lagu berikutnya: " << P.current->laguPtr->Judul << std::endl;
    } else {
        std::cout << "Akhir Playlist. Kembali ke awal." << std::endl;
        P.current = P.first;
        if (P.current != nullptr) {
             std::cout << "-> Memutar lagu: " << P.current->laguPtr->Judul << std::endl;
        }
    }
}

void PrevLagu(Playlist& P) {
    if (P.current == nullptr) {
        std::cout << "Playlist kosong atau tidak ada lagu yang sedang diputar." << std::endl;
        return;
    }

    if (P.current->prev != nullptr) {
        P.current = P.current->prev;
        std::cout << "<- Memutar lagu sebelumnya: " << P.current->laguPtr->Judul << std::endl;
    } else {
        std::cout << "Awal Playlist. Tidak ada lagu sebelumnya." << std::endl;
    }
}

void DeleteLaguFromPlaylist(Playlist& P, std::string idLagu) {
    NodeDLL* current = P.first;
    NodeDLL* temp;
    bool deleted = false;

    while (current != nullptr) {
        // Cek apakah PointerLagu merujuk ke Lagu yang ID-nya ingin dihapus
        if (current->laguPtr->ID_Lagu == idLagu) {
            temp = current; // Simpan node yang akan dihapus

            // Update pointer di Playlist (P.current, P.first, P.last)
            if (current == P.current) {
                // Jika lagu yang sedang diputar dihapus, pindah ke lagu berikutnya (atau null jika akhir)
                P.current = current->next; 
            }
            if (current == P.first) {
                P.first = current->next;
            }
            if (current == P.last) {
                P.last = current->prev;
            }

            // Memperbaiki link tetangga (logika DLL standard delete)
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            }
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            }

            // Pindah ke node berikutnya sebelum menghapus temp
            current = current->next;
            
            // Hapus node DLL (bukan data lagu di Library)
            delete temp;
            deleted = true;
        } else {
            // Lanjut ke node berikutnya jika ID tidak cocok
            current = current->next;
        }
    }

    if (deleted) {
        std::cout << "Lagu ID " << idLagu << " berhasil disinkronisasi dan dihapus dari Playlist.\n";
    }
}