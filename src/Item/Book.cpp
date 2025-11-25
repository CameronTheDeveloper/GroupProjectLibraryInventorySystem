#include "Book.h"
#include "Item.h"
using namespace std;

// Getters
std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
std::string Book::getCopyrightDate() const { return copyrightDate; }

// Setters
void Book::setTitle(const std::string &aTitle) { title = aTitle; }
void Book::setAuthor(const std::string &aAuthor) { author = aAuthor; }
void Book::setCopyrightDate(const std::string &aCopyrightDate) {
        copyrightDate = aCopyrightDate;
}

void Book::print() const {
        cout << "\nTitle: " << title << "\nAuthor: " << author
             << "\nCopyright Date: " << copyrightDate << endl;
}

std::ostream &operator<<(std::ostream &os, Book &book) {
        book.print();
        return os;
}
