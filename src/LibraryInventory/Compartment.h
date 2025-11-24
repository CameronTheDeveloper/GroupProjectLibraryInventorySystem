#ifndef COMPARTMENT_H
#define COMPARTMENT_H

#include "../Item/Item.h"
#include "../Item/CheckedOutItem.h"

class Compartment {
        public:
                Compartment();
                // Getters
                Item *getStoredItem() const;
                bool getHasOwner() const;

                // Setters
                void addItem(Item *item);
                void addItem(CheckedOutItem &checkedOutItem);
                Item *removeItem();
                void setHasOwner(bool ownerStatus);

                bool isEmpty() const;

        private:
                Item *storedItem;
                bool hasOwner;
};

#endif
