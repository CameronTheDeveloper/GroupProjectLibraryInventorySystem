#ifndef SHELF_H
#define SHELF_H

#include "Compartment.h"
#include <iostream>

class Shelf {
        public:
                Compartment &operator[](size_t index);
                friend std::ostream& operator<<(std::ostream& os, const Shelf& shelf);

        private:
                Compartment compartments[15];
};

#endif
