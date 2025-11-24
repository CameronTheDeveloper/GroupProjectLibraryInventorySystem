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

        Library library;

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




        //Library myLib;
        //cout << "ADDING 3 SHELVES WITH 15 COMPARTMENTS ";
        //    try {
        //        myLib.addShelf(Shelf()); // shelf 1
        //        myLib.addShelf(Shelf()); // shelf 2
        //        myLib.addShelf(Shelf()); // shelf 3
        //        cout << "Shelves added successfully.\n";
        //} catch (exception &e) {
        //        cout << "Error adding shelves: " << e.what() << endl;
        //}
        //cout << "ADDING ITEMS ";
        //    Book *book1 = new Book();
        //book1->setName("Book A");
        //book1->setTitle("Book A Title");
        //book1->setAuthor("Author A");
        //book1->setCopyrightDate("2001");
        //Movie *movie1 = new Movie();
        //movie1->setName("Movie B");
        //movie1->setTitle("Movie B Title");
        //movie1->setDirector("Director B");
        //movie1->setMainActors({"Actor 1", "Actor 2"});
        //Magazine *mag1 = new Magazine();
        //mag1->setName("Magazine C");
        //mag1->setEdition("Edition C");
        //mag1->setTitleOfMain("Main Article C");
        //try {
        //        myLib.addItem(book1);
        //        myLib.addItem(movie1);
        //        myLib.addItem(mag1);
        //        cout << "Items added successfully.\n";
        //} catch (exception &e) {
        //        cout << "Error adding items: " << e.what() << endl;
        //}
        //cout << "PRINT STORAGE";
        //try {
        //        myLib.printStorage();
        //} catch (exception &e) {
        //        cout << "Error printing storage: " << e.what() << endl;
        //}
        //cout << "CHECKOUT DEMO";
        //CheckedOutItem c1;
        //c1.setItem(book1);
        //c1.setOriginalShelf(0);
        //c1.setOriginalCompartment(0);
        //c1.setNameOfOwner("Alice");
        //c1.setDueDate("2025-12-01");
        //// mark as checked out
        //myLib[0][0].setHasOwner(true);
        //cout << "PRINT CHECKED OUT ITEMS";
        //myLib.printCheckedOut();
        //cout << " SWAP ITEMS";
        //try {
        //        myLib.swap(*book1, *movie1);
        //        cout << "Swapped Book A and Movie B successfully.\n";
        //} catch (exception &e) {
        //        cout << "Swap error: " << e.what() << endl;
        //}
        //cout << "CHECK IN DEMO";
        //myLib.checkIn(c1);
        //cout << "STORAGE AFTER CHECK IN";
        //myLib.printStorage();
        //cout << OPERATOR[] TESTS ";
        //    try {
        //        Shelf &shelf0 = myLib[0];
        //        Shelf &shelf1 = myLib[1];
        //        Shelf &shelf2 = myLib[2];
        //        cout << "Accessed all 3 shelves successfully.\n";
        //} catch (exception &e) {
        //        cout << "Index error: " << e.what() << endl;
        //}
        //cout << TRYING BAD INDEXES ";
        //    try {
        //        myLib[-1];
        //} catch (exception &e) {
        //        cout << "myLib[-1] -> " << e.what() << endl;
        //}
        //try {
        //        myLib[1000];
        //} catch (exception &e) {
        //        cout << "myLib[1000] -> " << e.what() << endl;
        //}
        //cout << “TRYING NESTED BAD INDEX ";
        //    try {
        //        myLib[0][9999]; // accessing nonexistent compartment
        //} catch (exception &e) {
        //        cout << "myLib[0][9999] -> " << e.what() << endl;
        //}
        //cout << "PRINT CHECKED OUT ITEMS INDIVIDUALLY";
        //cout << c1 << endl;
        //cout << "CLEANUP";
        //delete book1;
        //delete movie1;
        //delete mag1;
        return 0;
}
