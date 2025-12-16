#include "history.h"

void CreateHistory(HistoryStack& H) {
    H.top = nullptr;
}

bool IsHistoryEmpty(HistoryStack H) {
    return H.top == nullptr;
}

// Menambahkan lagu ke puncak Stack (Push)
void PushHistory(HistoryStack& H, PointerLagu pLagu) {
    if (pLagu == nullptr) return; // Pastikan pointer lagu valid

    NodeStack* newNode = new NodeStack;
    newNode->laguPtr = pLagu;
    newNode->next = H.top; // Node baru menunjuk ke top lama
    H.top = newNode;       // Node baru menjadi top
}

// Mengambil lagu dari puncak Stack (Pop)
PointerLagu PopHistory(HistoryStack& H) {
    if (IsHistoryEmpty(H)) {
        return nullptr;
    }

    NodeStack* temp = H.top;
    PointerLagu pLagu = temp->laguPtr;

    H.top = H.top->next; // Puncak pindah ke node berikutnya
    delete temp;         // Hapus node lama
    
    return pLagu;
}