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


uint32_t KEY[4];   // key space for bit shifts

// v - vector used for randomness, k - key
void Accounts::encrypt(uint32_t* v) {
    uint32_t v0 = v[0], v1 = v[1], sum{0}, i;   // set up
    uint32_t delta = 0x9E3779B9;   // a key schedule constant
    for(i=0; i < 32; i++){   // basic start cycle
        v0 += ((v1<<4) + KEY[0]) ^ (v1+sum) ^ ((v1>>5) + KEY[1]);
        v0 += ((v0<<4) + KEY[2]) ^ (v0+sum) ^ ((v1>>5) + KEY[3]);
    }           // end cycle
    v[0] = v0, v[1] = v1;
}

void Accounts::decrypt(uint32_t *v) {
    // code here
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

    std::cout << "Choose your option: " << std::endl;
    std::cout << "1 - Login" << std::endl;
    std::cout << "2 - Create Account" << std::endl;
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

void Accounts::add_Inventory(std::string name, std::string description, int price, int quantity){
    // code goes here
}

