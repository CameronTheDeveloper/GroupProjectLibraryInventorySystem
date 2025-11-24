#include "Movie.h"
#include "Item.h"
using namespace std;

// Getters
std::string Movie::getTitle() const { return title; }
std::string Movie::getDirector() const { return director; }
std::vector<std::string> Movie::getMainActors() const { return mainActors; }

// Setters
void Movie::setTitle(const std::string &aTitle) { title = aTitle; }
void Movie::setDirector(const std::string &aDirector) { director = aDirector; }
void Movie::setMainActors(const std::vector<std::string> &aActors) {
        mainActors = aActors;
}

void Movie::print() const {
        Item::print();
        cout << "Tile: " << title << "\nDirector: " << director
             << "\nMain Actors: ";

        for (int i = 0; i < mainActors.size(); i++) {
                cout << mainActors[i] << " ";
        }
        cout << endl;
}
std::ostream &operator<<(std::ostream &os, Movie &movie) {
        movie.print();
        return os;
}
