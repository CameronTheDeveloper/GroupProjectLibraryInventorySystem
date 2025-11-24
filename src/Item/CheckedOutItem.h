#ifndef CHECKEDOUTITEM_H
#define CHECKEDOUTITEM_H

#include "Item.h"

class CheckedOutItem {
        public:
                // Getters
                Item& getItem() const;
                int getOriginalShelf() const;
                int getOriginalCompartment() const;
                std::string getNameOfOwner() const;
                std::string getDueDate() const;

                // Setters
                void setItem(const Item &newItem);
                void setOriginalShelf(int shelf);
                void setOriginalCompartment(int compartment);
                void setNameOfOwner(const std::string &owner);
                void setDueDate(const std::string &date);

                friend std::ostream &operator<<(std::ostream &os, const CheckedOutItem& checkedOutItem);

        private:
                Item *item;
                int originalShelf;
                int originalCompartment;
                std::string nameOfOwner;
                std::string dueDate;
};

#endif
