#ifndef LIBRARY_H
#define LIBRARY_H

#include "../Item/CheckedOutItem.h"
#include "Shelf.h"
#include "../Exceptions.h"
#include <vector>

class Library
{
        public:
                void printCheckedOut() const;
                void printStorage() const;
                void addItem(Item *item, const int shelfIndex, const int compartmentIndex);
                void swap(int itemOneShelfIndex, int itemOneCompIndex,
                          int itemTwoShelfIndex, int itemTwoCompIndex);
                CheckedOutItem &checkOut(const int shelfIndex,
                                         const int compartmentIndex);
                void checkIn(CheckedOutItem &checkedOutItem);
                Shelf &operator[](int index);

        private:
                Shelf shelves[10];
                std::vector<CheckedOutItem> checkedOutItems;
};

#endif
