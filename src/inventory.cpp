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

