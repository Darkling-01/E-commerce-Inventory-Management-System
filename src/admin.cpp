//
// Created by barra on 10/4/2024.
//

#include "admin.h"
#include <iostream>
#include <string>


void Admin::admin_account() {
    std::string username;
    std::string password;

    std::cout << "Admin Username: ";
    std::cin >> username;
    std::cout << "Admin Password: ";
    std::cin >> password;

    Admin::validation(passwd, username);


}

