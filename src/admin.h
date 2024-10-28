//
// Created by barra on 10/16/2024.
//

#ifndef E_COMMERCE_INVENTORY_MANAGEMENT_SYSTEM_ADMIN_H
#define E_COMMERCE_INVENTORY_MANAGEMENT_SYSTEM_ADMIN_H

#include <string>

struct Book{
    std::string name;
    int ISBN{0};
    std::string title;
    std::string author;
    bool isIssued;
    Book* Next;
};


class Admin{
public:
    // constructor
    Admin(){
        head == nullptr;
    }

    void adminMenu();
    // function to insert book
    void insertBook(int ISBN, std::string title, std::string author);
    void issueBook(int ISBN);
    void depositBook(int ISBN);

private:
    Book* head;
};

#endif //E_COMMERCE_INVENTORY_MANAGEMENT_SYSTEM_ADMIN_H
