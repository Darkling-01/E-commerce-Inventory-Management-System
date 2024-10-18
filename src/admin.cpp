//
// Created by barra on 10/16/2024.
//

#include "admin.h"
#include <unordered_map>
#include <functional>
#include <string>
#include <iostream>


void Admin::adminMenu() {
    Admin admin;

    std::unordered_map<std::string, std::function<void()>> action;
    std::string command;

    action["1"] = [&admin]() {
        admin.addItems();
    };

    action["2"] = [&admin](){
        admin.deleteItems();
    };

    std::cout << "Admin Menu" << std::endl;
    std::cout << "1 - Add Item(s)" << std::endl;
    std::cout << "2 - Delete Item(s)" << std::endl;

    // create linked lists

}