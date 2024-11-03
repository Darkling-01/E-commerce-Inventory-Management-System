#include <iostream>
#include <unordered_map>
#include <functional>

#include "src/accounts.h"


int main() {
    Accounts acc;
    std::string command;

    std::unordered_map<std::string, std::function<void()>> actions;

    actions["Admin"] = [&acc](){
        acc.accounts_menu();
    };

    actions["User"] = [&acc](){
        acc.login_user_account();
    };

    actions["Guide"] = [&acc](){
        acc.account_guide();
    };

    actions["Exit"] = [&acc](){
        std::cout << "Logged out..." << std::endl;
        return EXIT_SUCCESS;
    };
    do{
        std::cout << "Welcome to ECIM System" << std::endl;
        std::cout << "-----------------------" << std::endl;
        std::cout << "Admin" << std::endl;
        std::cout << "User" << std::endl;
        std::cout << "Guide" << std::endl;
        std::cout << "Exit" << std::endl;

        std::cin >> command;
        std::cout << std::endl;

        auto it = actions.find(command);
        if(it != actions.end()){
            it->second();  // call the corresponding lambda
        }
        else{
            std::cout << "No Command Found" << std::endl;
        }

    }while(command != "Exit");

    return 0;
}
