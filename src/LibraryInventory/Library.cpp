#include "Library.h"

void Library::printCheckedOut() const
{
        std::cout << "----------\nChecked Out\n----------\n\n";
        for (const CheckedOutItem& item : checkedOutItems)
        {
                std::cout << item << "\n";
        }
}

void Library::printStorage() const
{
        std::cout << "----------\nLibrary\n----------\n\n";
        for (int i = 0; i < 10; ++i)
        {
                std::cout << "Shelf " << (i + 1) << ":\n" << shelves[i] << "\n";
        }
}

void Library::addItem(Item *item, const int shelfIndex, const int compartmentIndex)
{
        try
        {
                (*this)[shelfIndex][compartmentIndex].addItem(item);
        }
        catch (const std::exception& e)
        {
                std::cout << "Compartment Does Not Exist.\n";
        }
}

void Library::swap(int itemOneShelfIndex, int itemOneCompIndex,
                   int itemTwoShelfIndex, int itemTwoCompIndex)
{
        Compartment *compartment1 = nullptr;
        Compartment *compartment2 = nullptr;

        try
        {
                compartment1 = &(*this)[itemOneShelfIndex][itemOneCompIndex];
                compartment2 = &(*this)[itemTwoShelfIndex][itemTwoCompIndex];
        }
        catch (const std::exception& e)
        {
                std::cout << "Compartment not found.\n";
                return;
        }

        Item *item1;
        Item *item2;

        try
        {
                item1 = compartment1->removeItem();
                item2 = compartment2->removeItem();
        }
        catch (const std::exception& e)
        {
                std::cout << "One of the items do not exist.\n";
                return;
        }

        compartment1->setHasOwner(false);
        compartment2->setHasOwner(false);

        compartment1->addItem(item2);
        compartment2->addItem(item1);
}

CheckedOutItem& Library::checkOut(const int shelfIndex, const int compartmentIndex)
{
        CheckedOutItem checkedOutItem;
        try {
                checkedOutItem.setItem((*this)[shelfIndex][compartmentIndex].removeItem());
        }
        catch (std::exception e)
        {
                std::cout << "Error checking out item.";
                return checkedOutItem;
        }
        checkedOutItem.setOriginalShelf(shelfIndex);
        checkedOutItem.setOriginalCompartment(compartmentIndex);
        checkedOutItems.push_back(checkedOutItem);
        return checkedOutItems[checkedOutItems.size()-1];
}

void Library::checkIn(CheckedOutItem& checkedOutItem)
{
        int shelfIndex  = checkedOutItem.getOriginalShelf();
        int compartmentIndex = checkedOutItem.getOriginalCompartment();

        (*this)[shelfIndex][compartmentIndex].addItem(checkedOutItem);
        for (int i = 0; i < checkedOutItems.size(); ++i)
        {
                if (checkedOutItems[i].getItem()->getId() == checkedOutItem.getItem()->getId())
                {
                        checkedOutItems.erase(checkedOutItems.begin() + i);
                        return;
                }
        }
}

Shelf& Library::operator[](int index)
{
        if (index < 0 || index >= 10)
        {
                throw ShelfNotFoundException("Shelf does not exist.");
        }
        else
        {
                return shelves[index];
        }
}
