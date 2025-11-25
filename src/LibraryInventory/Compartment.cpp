#include "Compartment.h"
#include "../Exceptions.h"
using namespace std;

// Getters
Item *Compartment::getStoredItem() const { return storedItem; }
bool Compartment::getHasOwner() const { return hasOwner; }

Compartment::Compartment() : hasOwner(false), storedItem(nullptr) {}

// Setters
void Compartment::addItem(Item *item) {
        if (hasOwner == false) {
                storedItem = item;
        } else {
                throw CompartmentEmptyException(
                    "Compartment already has an owner");
        }
}

void Compartment::addItem(CheckedOutItem& checkedOutItem) {
        storedItem = checkedOutItem.getItem();
}

Item *Compartment::removeItem() {
        if (isEmpty()) {
                throw CompartmentEmptyException("Compartment is Empty");
        }

        hasOwner = true;
        Item *poppedValue = storedItem;
        storedItem = nullptr;
        return poppedValue;
}
void Compartment::setHasOwner(bool ownerStatus) {
        hasOwner = !hasOwner;
}

bool Compartment::isEmpty() const {
        if (storedItem == nullptr) {
                return true;
        } else {
                return false;
        }
}
