#include "Shelf.h"
#include "../Exceptions.h"
#include <iterator>

Compartment& Shelf::operator[](size_t index) {
        if (index >= 15) {
                throw CompartmentNotFoundException("Invalid compartment number");
        }
        else return compartments[index];
}

std::ostream& operator<<(std::ostream& os, const Shelf& shelf) {
        for (size_t i = 0; i < std::size(shelf.compartments); ++i) {
                os << "Compartment " << i << ": ";
                if (shelf.compartments[i].isEmpty()) os << "Empty";
                else os << *(shelf.compartments[i].getStoredItem());                    // call Item::operator<< with the item stored at compartment i
                os << "\n";
        }
        return os;
}
