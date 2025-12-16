#ifndef RECOMEND_H
#define RECOMEND_H

#include "library.h"
#include <string>

// Fungsi untuk mencari lagu di Library Utama yang memiliki genre sama
PointerLagu FindNextSimilarSong(BSTree root, std::string currentGenre, std::string currentID);

#endif