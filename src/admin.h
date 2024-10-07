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
        usrname = checkUsername;
    }


    void admin_menu();
    void CreateAccount();
    void Add_inventory(std::string name, std::string description, int price, int quantity);

private:
    std::string passwd;
    std::string usrname;
};

#endif //E_COMMERCE_INVENTORY_MANAGEMENT_SYSTEM_ADMIN_H
