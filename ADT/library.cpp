#include "library.h"
#include <iostream>
#include <string>
#include <limits>

// --- Fungsi Helper untuk BST ---

NodeBST* findMin(NodeBST* node) {
    NodeBST* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// --- Implementasi Fungsi Library (BST) ---

NodeBST* createNewNode(Lagu newLagu) {
    NodeBST* newNode = new NodeBST;
    newNode->data = newLagu;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void InsertLagu(BSTree& root, Lagu newLagu) {
    if (root == nullptr) {
        root = createNewNode(newLagu);
        std::cout << "Lagu '" << newLagu.Judul << "' berhasil ditambahkan ke Library." << std::endl;
        return;
    }

    // Menggunakan ID sebagai kunci untuk BST
    if (newLagu.ID_Lagu < root->data.ID_Lagu) {
        InsertLagu(root->left, newLagu);
    } else if (newLagu.ID_Lagu > root->data.ID_Lagu) {
        InsertLagu(root->right, newLagu);
    } else {
        std::cout << "ERROR: Lagu dengan ID " << newLagu.ID_Lagu << " sudah ada." << std::endl;
    }
}

void DisplayInOrder(BSTree root) {
    if (root != nullptr) {
        DisplayInOrder(root->left);
        std::cout << "ID: " << root->data.ID_Lagu 
                  << " | Judul: " << root->data.Judul
                  << " | Artis: " << root->data.Artis 
                  << " | Genre: " << root->data.Genre 
                  << " | Durasi: " << root->data.Durasi << "s"
                  << std::endl;
        DisplayInOrder(root->right);
    }
}

NodeBST* FindLagu(BSTree root, std::string id) {
    if (root == nullptr || root->data.ID_Lagu == id) {
        return root;
    }

    if (id < root->data.ID_Lagu) {
        return FindLagu(root->left, id);
    } else {
        return FindLagu(root->right, id);
    }
}

// Implementasi DeleteLaguNode BST
BSTree DeleteLaguNode(BSTree root, std::string id) {
    if (root == nullptr) {
        return root;
    }
    if (id < root->data.ID_Lagu) {
        root->left = DeleteLaguNode(root->left, id);
    } else if (id > root->data.ID_Lagu) {
        root->right = DeleteLaguNode(root->right, id);
    } else {
        if (root->left == nullptr) {
            NodeBST* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            NodeBST* temp = root->left;
            delete root;
            return temp;
        }
        NodeBST* temp = findMin(root->right);
        root->data = temp->data;
        root->right = DeleteLaguNode(root->right, temp->data.ID_Lagu);
    }
    return root;
}

// Fungsi pembungkus untuk Hapus Lagu
void DeleteLagu(BSTree& root, std::string id) {
    if (FindLagu(root, id) == nullptr) {
        std::cout << "Lagu dengan ID " << id << " tidak ditemukan." << std::endl;
        return;
    }
    root = DeleteLaguNode(root, id);
    std::cout << "Lagu dengan ID " << id << " berhasil dihapus dari Library." << std::endl;
    // NOTE: PENTING! Implementasi DeleteLaguFromAllPlaylists harus dipanggil dari main.cpp
}

// Fungsi untuk Ubah Data Lagu
void UpdateLagu(BSTree root, std::string id) {
    NodeBST* laguNode = FindLagu(root, id);
    if (laguNode == nullptr) {
        std::cout << "Lagu dengan ID " << id << " tidak ditemukan." << std::endl;
        return;
    }

    std::cout << "\n--- UBAH DATA LAGU (ID: " << id << ") ---" << std::endl;
    std::cout << "Data saat ini: Judul: " << laguNode->data.Judul << ", Artis: " << laguNode->data.Artis << ", Genre: " << laguNode->data.Genre << std::endl;

    std::string input;
    int intInput;

    std::cout << "Masukkan Judul Baru (Kosongkan untuk tetap): ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, input);
    if (!input.empty()) {
        laguNode->data.Judul = input;
    }

    std::cout << "Masukkan Artis Baru (Kosongkan untuk tetap): ";
    std::getline(std::cin, input);
    if (!input.empty()) {
        laguNode->data.Artis = input;
    }

    std::cout << "Masukkan Genre Baru (Kosongkan untuk tetap): ";
    std::getline(std::cin, input);
    if (!input.empty()) {
        laguNode->data.Genre = input;
    }

    std::cout << "Masukkan Durasi Baru (detik, 0 untuk tetap): ";
    if (!(std::cin >> intInput)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else if (intInput > 0) {
        laguNode->data.Durasi = intInput;
    }

    std::cout << "Data lagu berhasil diperbarui!" << std::endl;
}