#ifndef SHELF_H
#define SHELF_H

#include "Compartment.h"
#include <iostream>

class Shelf {
        public:
<<<<<<< HEAD
                Compartment findCompartment(int index) const;

                Compartment &operator[](int index);
                friend std::ostream& operator<<(std::ostream &os, const Shelf& shelf);
=======
                Compartment &operator[](size_t index);
                friend std::ostream& operator<<(std::ostream& os, const Shelf& shelf);
>>>>>>> 86f4787eb85cbeb5450060fdf831e054133d8b24

        private:
                Compartment compartments[15];
};

#endif
