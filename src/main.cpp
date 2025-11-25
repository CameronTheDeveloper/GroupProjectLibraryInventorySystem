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

        // Ensuring Functionality

        Book *book1 = new Book();
        book1->setName("Book A");
        book1->setDescription("Book A Description");
        book1->setId(1);
        book1->setTitle("Maze Runner");
        book1->setAuthor("James Dashner");
        book1->setCopyrightDate("2009");
        library.addItem(book1, 0, 1);

        Magazine *magazine1 = new Magazine();
        magazine1->setName("Book B");
        magazine1->setDescription("Book B Description");
        magazine1->setId(2);
        magazine1->setEdition("3rd");
        magazine1->setTitleOfMain("New York Times");
        library.addItem(magazine1, 2, 0);

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


        // Failing Functionality
        library.addItem(book1, 20, 3);
        library.addItem(book1, 3, 20);
        CheckedOutItem &checkedOut2 = library.checkOut(3, 3);
        library.swap(0, 1, 3, 3);
        library.swap(4, 4, 3, 3);

        return 0;
}
