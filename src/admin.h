//
// Created by barra on 10/4/2024.
//

#ifndef E_COMMERCE_INVENTORY_MANAGEMENT_SYSTEM_ADMIN_H
#define E_COMMERCE_INVENTORY_MANAGEMENT_SYSTEM_ADMIN_H

#include <string>

class Admin{
public:
    void validation(std::string checkPasswd, std::string checkUsername){
        passwd = checkPasswd;
        passwd = checkUsername;
    }

    void admin_account();

private:
    std::string passwd;
    std::string username;
};

#endif //E_COMMERCE_INVENTORY_MANAGEMENT_SYSTEM_ADMIN_H
