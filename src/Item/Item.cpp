#include "Item.h"
#include <iostream>
#include <string>

// --- Getters Implementation ---

std::string Item::getName() const { return name; }

std::string Item::getDescription() const { return description; }

int Item::getId() const { return id; }

// --- Setters Implementation ---

void Item::setName(const std::string &name) { this->name = name; }

void Item::setDescription(const std::string &description) {
        this->description = description;
}

void Item::setId(int id) { this->id = id; }

// --- Overloaded Stream Operator (Friend Function) ---

// This function needs to be implemented to use the friend declaration.
// It delegates output to the pure virtual print() method for polymorphism.
std::ostream &operator<<(std::ostream &os, const Item *item) {
        // The print() method handles the specific formatting for derived
        // classes.
        item->print();
        return os;
}
