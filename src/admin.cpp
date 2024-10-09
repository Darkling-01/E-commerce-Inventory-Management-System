//
// Created by barra on 10/4/2024.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>
#include <fstream>

#include "admin.h"


void Admin::admin_menu() {
    Admin admin;
    std::unordered_map<std::string, std::function<void()>> action;
    std::string command;

    action["1"] = [&admin](){
        admin.login();
    };

    action["2"] = [&admin](){
        admin.createAccount();
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

void Admin::createAccount(){
    std::ofstream OStream;  // a temporary file to save accounts. A testing ground
    OStream.open("Accounts", std::ofstream::out | std::ofstream::app);

    // check if file open successfully
    if(!OStream){
        std::cout << "Failed to open file" << std::endl;
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

void Admin::login(){
    std::string usrname;
    std::string passwd;

    std::cout << "Admin Username:";
    std::cin >> usrname;
    std::cout << "Admin Password:";
    std::cin >> passwd;

}

void Admin::add_Inventory(std::string name, std::string description, int price, int quantity){
    // code goes here
}

