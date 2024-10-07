//
// Created by barra on 10/4/2024.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>

#include "admin.h"


void Admin::admin_menu() {
    Admin admin;
    std::unordered_map<std::string, std::function<void()>> action;
    std::string command;

    action["1"] = [&admin](){

        std::string usrname;
        std::string passwd;

        std::cout << "Admin Username:";
        std::cin >> usrname;
        std::cout << "Admin Password:";
        std::cin >> passwd;

        admin.validation(usrname, passwd);
    };

    action["2"] = [&admin](){

    };

    std::cout << "Choose your option: " << std::endl;
    std::cout << "1 - Login" << std::endl;
    std::cin >> command;

    auto it = action.find(command);
    if(it != action.end())
        it->second();
    else
        std::cout << "No Command Found" << std::endl;
}

void Admin::CreateAccount(){
    // code goes here
}

void Admin::Add_inventory(std::string name, std::string description, int price, int quantity){
    // code goes here
}

