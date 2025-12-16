#include "recomend.h"

// Fungsi Helper untuk In-Order Traversal (Rekursif)
// Mengambil lagu yang cocok dengan id yang berbeda
PointerLagu FindSimilarSongRecursive(NodeBST* node, std::string currentGenre, std::string currentID) {
    if (node == nullptr) {
        return nullptr;
    }

    // Cek di Subtree Kiri
    PointerLagu found = FindSimilarSongRecursive(node->left, currentGenre, currentID);
    if (found != nullptr) {
        return found;
    }

    // Cek Node Saat Ini (Root)
    // Pastikan Genre cocok dan bukan lagu yang sedang dimainkan
    if (node->data.Genre == currentGenre && node->data.ID_Lagu != currentID) {
        return &node->data;
    }

    // Cek di Subtree Kanan
    return FindSimilarSongRecursive(node->right, currentGenre, currentID);
}

// Fungsi utama rekomendasi
PointerLagu FindNextSimilarSong(BSTree root, std::string currentGenre, std::string currentID) {
    if (root == nullptr) {
        return nullptr;
    }
    
    // Panggil helper rekursif
    return FindSimilarSongRecursive(root, currentGenre, currentID);
}