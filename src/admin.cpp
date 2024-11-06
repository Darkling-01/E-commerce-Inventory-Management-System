//
// Created by barra on 10/16/2024.
//

#include "admin.h"
#include <unordered_map>
#include <functional>
#include <string>
#include <iostream>

// implement a method to return back to previous action

void Admin::adminMenu() {
    Admin admin;
    std::string command;

    int ISBN{0};
    std::string title, author;

    std::cout << "Admin Menu" << std::endl;
    std::cout << "- Insert Book" << std::endl;
    std::cout << "- Issue Book" << std::endl;
    std::cout << "- Deposit Book" << std::endl;

    std::cin >> command;

    if(command == "Insert Book"){
        std::cout << "Enter ISBN: ";
        std::cin >> ISBN;

        std::cout << "Title: ";
        std::cin >> title;

        std::cout << "Author: ";
        std::cin >> author;

        admin.insertBook(ISBN, title, author);
    }
    else if(command == "Issue Book"){
        std::cout << "Enter ISBN: ";
        std::cin >> ISBN;
    }
    else if(command == "Deposit Book"){
        std::cout << "Enter ISBN: ";
        std::cin >> ISBN;
    }
    else{
        std::cout << "No command" << std::endl;
    }

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
