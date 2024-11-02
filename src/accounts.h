//
// Created by barra on 10/4/2024.
//

#ifndef E_COMMERCE_INVENTORY_MANAGEMENT_SYSTEM_ACCOUNTS_H
#define E_COMMERCE_INVENTORY_MANAGEMENT_SYSTEM_ACCOUNTS_H

#include <string>
#include <stdint.h>


class Accounts{
public:
    void validation(std::string checkPasswd, std::string checkUsername){
        passwd = checkPasswd;
        usrname = checkUsername;
    }

    void encrypt(uint32_t v[2], const uint32_t k[4]);
    void decrypt(uint32_t v[2], const uint32_t k[4]);
    void encrypt_password(const std::string& password, const uint32_t k[4]);
    void accounts_menu();
    void createAccount();
    void login();
    // void credentials_Recovery();

    // user accounts
    void login_user_account();
    void account_guide();

private:
    std::string passwd;
    std::string usrname;
};

#endif //E_COMMERCE_INVENTORY_MANAGEMENT_SYSTEM_ACCOUNTS_H
