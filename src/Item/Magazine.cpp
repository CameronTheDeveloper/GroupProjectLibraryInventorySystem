
#include "Magazine.h"
#include "Item.h"
using namespace std;

std::string Magazine::getEdition() const { return edition; }
std::string Magazine::getTitleOfMain() const { return titleOfMain; }

// Setters
void Magazine::setEdition(const std::string &aEdition) { edition = aEdition; }
void Magazine::setTitleOfMain(const std::string &aTitle) {
        titleOfMain = aTitle;
}

void Magazine::print() const {
        Item::print();
        cout << "Edition: " << edition << "\nTitle of Magazine: " << titleOfMain
             << endl;
}
std::ostream &operator<<(std::ostream &os, Magazine &magazine) {
        magazine.print();
        return os;
}
