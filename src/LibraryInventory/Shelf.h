#ifndef SHELF_H
#define SHELF_H

#include "Compartment.h"
#include <iostream>

class Shelf {
        public:
                Compartment findCompartment(int index) const;

                Compartment &operator[](int index);
                friend std::ostream& operator<<(std::ostream &os, const Shelf& shelf);

        private:
                Compartment compartments[15];
};

#endif
