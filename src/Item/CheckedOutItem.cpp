#include "CheckedOutItem.h"
#include <stdexcept>
Item &CheckedOutItem::getItem() const {
        if (item == nullptr)
                throw std::runtime_error(
                    "CheckedOutItem: item pointer is null.");
        return *item;
}
int CheckedOutItem::getOriginalShelf() const { return originalShelf; }
int CheckedOutItem::getOriginalCompartment() const {
        return originalCompartment;
}
std::string CheckedOutItem::getNameOfOwner() const { return nameOfOwner; }
std::string CheckedOutItem::getDueDate() const { return dueDate; }
void CheckedOutItem::setItem(const Item &newItem) {
        item = const_cast<Item *>(&newItem);
}
void CheckedOutItem::setOriginalShelf(int shelf) {
        if (shelf < 0)
                throw std::runtime_error(
                    "CheckedOutItem: shelf index cannot be negative.");
        originalShelf = shelf;
}
void CheckedOutItem::setOriginalCompartment(int compartment) {
        if (compartment < 0)
                throw std::runtime_error(
                    "CheckedOutItem: compartment index cannot be negative.");
        originalCompartment = compartment;
}
void CheckedOutItem::setNameOfOwner(const std::string &owner) {
        if (owner.empty())
                throw std::runtime_error(
                    "CheckedOutItem: owner name cannot be empty.");
        nameOfOwner = owner;
}
void CheckedOutItem::setDueDate(const std::string &date) {
        if (date.empty())
                throw std::runtime_error(
                    "CheckedOutItem: due date cannot be empty.");
        dueDate = date;
}
std::ostream &operator<<(std::ostream &os, CheckedOutItem &checkedOutItem) {
        os << "Item: " << checkedOutItem.getItem().getName()
           << ", Owner: " << checkedOutItem.getNameOfOwner()
           << ", Due: " << checkedOutItem.getDueDate();
        return os;
}
