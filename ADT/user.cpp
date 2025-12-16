#include "user.h"
#include <iostream>
#include <string>

bool LoginUser(User users[], int jumlahUser, int &indexUser){
    std::string uname, pass;
    std::cout << "\n--- LOGIN USER ---\nUsername: ";
    std::getline(std::cin, uname);
    std::cout << "Password: ";
    std::getline(std::cin, pass);

    for(int i=0;i<jumlahUser;i++){
        if(users[i].username==uname && users[i].password==pass){
            std::cout << "Login berhasil! Selamat datang, " << users[i].namaLengkap << "\n";
            indexUser = i;
            return true;
        }
    }
    std::cout << "Username/Password salah.\n";
    return false;
}