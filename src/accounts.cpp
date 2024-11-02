//
// Created by barra on 10/4/2024.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>
#include <fstream>
#include <stdint.h>

#include "accounts.h"

// k - key space for bit shifts
// v - vector used for randomness
void Accounts::encrypt(uint32_t v[2], const uint32_t k[4]) {

    uint32_t v0 = v[0], v1 = v[1], sum{0}, i;   // set up
    uint32_t delta = 0x9E3779B9;   // a key schedule constant
    uint32_t k0=k[0], k1=k[1], k2=k[2], k3=k[3];
    for(i=0; i < 32; i++){   // basic start cycle
        sum += delta;
        v0 += ((v1<<4) + k0) ^ (v1+sum) ^ ((v1>>5) + k1);
        v1 += ((v0<<4) + k2) ^ (v0+sum) ^ ((v0>>5) + k3);
    }           // end cycle
    v[0] = v0; v[1] = v1;
}

void Accounts::decrypt(uint32_t v[2], const uint32_t k[4]) {

    uint32_t v0 = v[0], v1 = v[1], sum{}, i;
    uint32_t delta = 0x9E3779B9;
    uint32_t k0=k[0], k1=k[1], k2=k[2], k3=k[3];
    for(i=0; i < 32; i++){
        v1 -= ((v0<<4) + k2) ^ (v0+sum) ^ ((v1>>5) + k3);
        v0 -= ((v1<<4) + k0) ^ (v1+sum) ^ ((v1>>5) + k1);
        sum -= delta;
    }
    v[0] = v0; v[1] = v1;

}

void Accounts::encrypt_password(const std::string &password, const uint32_t *k) {
    // ensure we have enough space for data
    uint32_t v[2] = {0, 0};
    // postponed this part
}

void Accounts::accounts_menu() {

    Accounts acc;

    std::unordered_map<std::string, std::function<void()>> action;
    std::string command;

    action["1"] = [&acc](){
        acc.login();
    };

    action["2"] = [&acc](){
        acc.createAccount();
    };

    /* action["3"] = [&acc](){
        acc.credentials_Recovery();
    };
    */

    std::cout << "Choose your option: " << std::endl;
    std::cout << "1 - Login" << std::endl;
    std::cout << "2 - Add Account" << std::endl;
    std::cout << "2 - Forgot Password/Username" << std::endl;

    std::cin >> command;

    auto it = action.find(command);
    if(it != action.end())
        it->second();
    else
        std::cout << "No Command Found" << std::endl;
}

void Accounts::createAccount(){

    std::ofstream OStream;  // a temporary file to save accounts. A testing ground
    OStream.open("Accounts", std::ofstream::out | std::ofstream::app);

    // check if file open successfully
    if(!OStream){
        // cerr is used for error messages because it is unbuffered,
        // means outputs messages immediately
        std::cerr << "Failed to open file" << std::endl;
    }

    std::cout << "Choose Username: " << std::endl;
    std::cin >> usrname;
    std::cout << "Choose Passwd: " << std::endl;
    std::cin >> passwd;

    // writes to the file
    OStream << usrname << std::endl;
    OStream << passwd << std::endl;

    OStream.close();   // close the file when done
}

void Accounts::login(){

    std::string usrname;
    std::string passwd;

    std::cout << "Admin Username:";
    std::cin >> usrname;
    std::cout << "Admin Password:";
    std::cin >> passwd;


}

void Accounts::login_user_account() {
    // code here
}

void Accounts::account_guide() {
    // create a loop to display all lines of account_guide.txt
    std::string guide_text;
    std::ifstream readGuide("../info/account_guide.txt");

    while(std::getline(readGuide, guide_text)){
        std::cout << guide_text;
    }

    readGuide.close();
}

