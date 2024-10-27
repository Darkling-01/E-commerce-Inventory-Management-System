//
// Created by barra on 10/4/2024.
//

#include "inventory.h"
#include <iostream>
#include <string>

// this allows inserts books to inventory
void Library::insertBook(int ISBN, std::string title, std::string author) {
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
void Library::issueBook(int ISBN) {
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
void Library::depositBook(int ISBN) {
    // code goes here
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

// function to find all books
void Library::findAllIssueBooks() {
    //code here
}

