//
// Created by barra on 10/4/2024.
//

#ifndef E_COMMERCE_INVENTORY_MANAGEMENT_SYSTEM_INVENTORY_H
#define E_COMMERCE_INVENTORY_MANAGEMENT_SYSTEM_INVENTORY_H

#include <string>

struct Book{
    std::string name;
    int ISBN{0};
    std::string title;
    std::string author;
    bool isIssued;
    Book* Next;
};

class Library{
public:
    // constructor
    Library(){
        head == nullptr;
    }

    // function to insert book
    void insertBook(int ISBN, std::string title, std::string author){

    }

private:
    Book* head;
};



#endif //E_COMMERCE_INVENTORY_MANAGEMENT_SYSTEM_INVENTORY_H
