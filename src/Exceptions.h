#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

class CompartmentNotFoundException : public std::runtime_error {
        public:
                CompartmentNotFoundException(const std::string &message)
                    : std::runtime_error(message) {}
};

class CompartmentEmptyException : public std::runtime_error {
        public:
                CompartmentEmptyException(const std::string &message)
                    : std::runtime_error(message) {}
};

class ShelfNotFoundException : public std::runtime_error {
        public:
                ShelfNotFoundException(const std::string &message)
                    : std::runtime_error(message) {}
};

#endif
