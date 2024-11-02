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
        // admin.insertBook();
    };

    action["2"] = [&admin](){
        // admin.issueBook();
    };

    std::cout << "Admin Menu" << std::endl;
    std::cout << "1 - Add Book" << std::endl;
    std::cout << "2 - Issue Book" << std::endl;
    std::cout << "3 - Deposit Book" << std::endl;

}


// this allows inserts books to inventory
void Admin::insertBook(int ISBN, std::string title, std::string author) {
    Book* newBook = new Book;
    newBook->ISBN = ISBN;
    newBook->title = title;
    newBook->author = author;

    newBook->isIssued = false;
    newBook->Next = nullptr;

    newBook->Next = head;
    head = newBook;
    std::cout << "Book inserted successfully" << std::endl;
}


// function to issue a book
void Admin::issueBook(int ISBN) {
    Book* current = head;
    while(current != nullptr){
        if(current->ISBN == ISBN){
            if(!current -> isIssued){
                current->isIssued = true;
                std::cout << "Book is issue successfully" << std::endl;
            }
            else{
                std::cout << "Book is already issued" << std::endl;
            }
            // used to exit the void function by returning nothing
            return;

        }
        current = current->Next;
    }
    std::cout << "Book not found" << std::endl;
}

// deposit book
void Admin::depositBook(int ISBN) {
    Book* current = head;
    while(current != nullptr){
        if(current->ISBN == ISBN){
            if(!current -> isIssued){
                current->isIssued = false;
                std::cout << "Book is issue successfully" << std::endl;
            }
            else{
                std::cout << "Book is not issued" << std::endl;
            }
            return;
        }
        current = current->Next;
    }
    std::cout << "Book not found" << std::endl;

}
