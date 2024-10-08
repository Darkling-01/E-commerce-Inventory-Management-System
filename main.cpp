#include <iostream>
#include <unordered_map>
#include <functional>

#include "src/accounts.h"


int main() {
    Accounts acc;
    std::string command;

    std::unordered_map<std::string, std::function<void()>> actions;

    actions["admin"] = [&acc](){
        acc.accounts_menu();
    };

    std::cout << "Welcome to ECIM System" << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cin >> command;

    auto it = actions.find(command);
    if(it != actions.end()){
        it->second();  // call the corresponding lambda
    }
    else{
        std::cout << "No Command Found" << std::endl;
    }

    return 0;
}
