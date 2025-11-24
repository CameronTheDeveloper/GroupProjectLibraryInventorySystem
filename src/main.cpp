#include "Item/Book.h"
#include "Item/CheckedOutItem.h"
#include "LibraryInventory/Compartment.h"
#include "Exceptions.h"
#include "Item/Item.h"
#include "LibraryInventory/Library.h"
#include "Item/Magazine.h"
#include "Item/Movie.h"
#include "LibraryInventory/Shelf.h"
#include <iostream>
using namespace std;

int main() {

        Library library(5);

        Book *book1 = new Book();
        book1->setName("Book A");
        book1->setDescription("Book A Description");
        book1->setId(1);
        book1->setTitle("Maze Runner");
        book1->setAuthor("James Dashner");
        book1->setCopyrightDate("2009");
        library.addItem(book1, 0, 1);

        Book *book2 = new Book();
        book2->setName("Book B");
        book2->setDescription("Book B Description");
        book2->setId(2);
        book2->setTitle("Hunger Games");
        book2->setAuthor("Suzanne Collins");
        book2->setCopyrightDate("2008");
        library.addItem(book2, 2, 0);

        library.printStorage();


        CheckedOutItem& checkedOut1 = library.checkOut(0, 1);
        checkedOut1.setNameOfOwner("Jaden");
        checkedOut1.setDueDate("11/25/2025");
        library.printStorage();
        library.printCheckedOut();


        library.checkIn(checkedOut1);
        library.printStorage();
        library.printCheckedOut();


        library.swap(0, 1, 2, 0);
        library.printStorage();
        library.printCheckedOut();

        return 0;
}
