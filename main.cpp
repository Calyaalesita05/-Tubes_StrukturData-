#include <iostream>
#include <limits>
#include <string>
#include "library.h"
#include "lagu.h"
#include "playlist.h"

BSTree LibraryUtama = nullptr;
int ID_Counter = 6;
Playlist playlistUser;

void InitLibrary(BSTree& root) {
    Lagu l1 = {"B002", "Darling", "Seventeen", "Pop", 2022, 191,
               "You know, without you, I'm so lonely..."};
    Lagu l2 = {"C003", "Anything", "Adrianne Lenker", "Indie", 2023, 198,
               "And I don't wanna talk about anythin'..."};
    Lagu l3 = {"D004", "Loosing Us", "Raisa Anggiani", "Pop", 2023, 215,
               "Why would I come back to you..."};
    Lagu l4 = {"E005", "Jatuh Hati", "Raisa", "Pop", 2013, 277,
               "Ku terpikat pada tuturmu..."};
    Lagu l5 = {"F006", "Just a Friend to You", "Meghan Trainor", "Pop", 2014, 158,
               "When you say I'm just a friend to you..."};

    InsertLagu(root, l1);
    InsertLagu(root, l2);
    InsertLagu(root, l3);
    InsertLagu(root, l4);
    InsertLagu(root, l5);
}

void CariLaguMenu() {
    std::string id;
    std::cout << "\n--- CARI LAGU ---\n";
    std::cout << "Masukkan ID Lagu: ";
    std::getline(std::cin, id);

    NodeBST* node = FindLagu(LibraryUtama, id);
    if (node == nullptr) {
        std::cout << "Lagu tidak ditemukan.\n";
    } else {
        std::cout << "Judul : " << node->data.Judul << std::endl;
        std::cout << "Artis : " << node->data.Artis << std::endl;
        std::cout << "Genre : " << node->data.Genre << std::endl;
        std::cout << "Durasi: " << node->data.Durasi << " detik\n";
    }
}

void KelolaPlaylistMenu() {
    std::string id;
    std::cout << "\n--- KELOLA PLAYLIST ---\n";
    std::cout << "Masukkan ID Lagu yang ingin ditambahkan ke playlist: ";
    std::getline(std::cin, id);

    NodeBST* laguNode = FindLagu(LibraryUtama, id);
    if (laguNode == nullptr) {
        std::cout << "Lagu tidak ditemukan di Library.\n";
        return;
    }

    InsertLaguKePlaylist(playlistUser, &laguNode->data);
}

void PutarLaguMenu() {
    if (playlistUser.current == nullptr) {
        std::cout << "Playlist kosong. Tambahkan lagu terlebih dahulu.\n";
        return;
    }

    int pilihan;
    bool keluar = false;

    while (!keluar) {
        // tampilkan lagu yang siap diputar
        std::cout << "\n=== PUTAR LAGU ===\n";
        std::cout << "Judul : " << playlistUser.current->laguPtr->Judul << std::endl;
        std::cout << "Artis : " << playlistUser.current->laguPtr->Artis << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "\n--- LIRIK ---\n";
        std::cout << playlistUser.current->laguPtr->Lirik_Sample << std::endl;

        std::cout << "\n--- KONTROL PEMUTARAN ---\n";
        std::cout << "1. Lagu Berikutnya\n";
        std::cout << "2. Lagu Sebelumnya\n";
        std::cout << "3. Kembali ke Menu User\n";
        std::cout << "Pilih: ";

        if (!(std::cin >> pilihan)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (pilihan) {
            case 1:
                NextLagu(playlistUser);
                break;
            case 2:
                if (playlistUser.current->prev == nullptr) {
                    std::cout << "Tidak ada lagu sebelumnya.\n";
                } else {
                    PrevLagu(playlistUser);
                }
                break;
            case 3:
                keluar = true;
                break;
            default:
                std::cout << "Pilihan tidak valid.\n";
        }
    }
}

void MenuUser() {
    CreatePlaylist(playlistUser);

    int pilih;
    do {
        std::cout << "\n=== MENU USER ===\n";
        std::cout << "1. Cari Lagu di Library\n";
        std::cout << "2. Kelola Playlist Saya\n";
        std::cout << "3. Putar Lagu\n";
        std::cout << "4. Kembali\n";
        std::cout << "Pilih: ";

        if (!(std::cin >> pilih)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (pilih == 1) CariLaguMenu();
        else if (pilih == 2) KelolaPlaylistMenu();
        else if (pilih == 3) PutarLaguMenu();

    } while (pilih != 4);
}

// ================= LOGIN =================
const int MAX_AKUN = 2;
Akun DaftarAkun[MAX_AKUN] = {
    {"admin", "admin123", "Admin"},
    {"user", "user123", "User"}
};

std::string ProsesLogin() {
    std::string u, p;
    std::cout << "\n--- LOGIN ---\n";
    std::cout << "Username: ";
    std::getline(std::cin, u);
    std::cout << "Password: ";
    std::getline(std::cin, p);

    for (int i = 0; i < MAX_AKUN; i++) {
        if (DaftarAkun[i].username == u && DaftarAkun[i].password == p) {
            std::cout << "Login berhasil sebagai " << DaftarAkun[i].role << "!\n";
            return DaftarAkun[i].role;
        }
    }
    std::cout << "Login gagal.\n";
    return "";
}

// ================= ADMIN =================
void MenuAdmin() {
    int pilih;
    std::string id;

    do {
        std::cout << "\n=== MENU ADMIN ===\n";
        std::cout << "1. Tambah Lagu\n";
        std::cout << "2. Lihat Semua Lagu\n";
        std::cout << "3. Ubah Lagu\n";
        std::cout << "4. Hapus Lagu\n";
        std::cout << "5. Kembali\n";
        std::cout << "Pilih: ";

        std::cin >> pilih;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (pilih == 1) {
            Lagu baru = InputLaguBaru(ID_Counter);
            InsertLagu(LibraryUtama, baru);
        } else if (pilih == 2) {
            DisplayInOrder(LibraryUtama);
        } else if (pilih == 3) {
            std::cout << "ID Lagu: ";
            std::getline(std::cin, id);
            UpdateLagu(LibraryUtama, id);
        } else if (pilih == 4) {
            std::cout << "ID Lagu: ";
            std::getline(std::cin, id);
            DeleteLagu(LibraryUtama, id);
        }

    } while (pilih != 5);
}

// ================= MAIN =================
int main() {
    InitLibrary(LibraryUtama);

    int pilih;
    std::string role;

    do {
        std::cout << "\n=== APLIKASI PEMUTAR MUSIK ===\n";
        std::cout << "1. Login\n";
        std::cout << "2. Keluar\n";
        std::cout << "Pilih: ";

        std::cin >> pilih;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (pilih == 1) {
            role = ProsesLogin();
            if (role == "Admin") MenuAdmin();
            else if (role == "User") MenuUser();
        }

    } while (pilih != 2);

    std::cout << "Terima kasih.\n";
    return 0;
}