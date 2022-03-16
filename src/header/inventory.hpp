#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include "item.hpp"
#include <bits/stdc++.h>

using namespace std;

class Slot {
    private:
        Item item;
        int quantity;
    public:
        Slot(Item item, int qty);

        void addItemSlot(int qty);
        void discardItemSlot(int qty);

        int getQuantity();
        Item getItem();
};

class Inventory {
    private:
        Slot slot[3][9];
        int slotUsed;
    public:
        Inventory();

        void showInventory();
        void give(string itemName, int itemQty);
        void discard(string slotId, int itemQty);
        void move(string srcSlot, int itemQty, string* destSlot);

        void moveItoC(string srcSlot, string* destSlot);
        void moveItoI(string srcSlot, string destSlot);
        void moveCtoI(string srcSlot, string destSlot);

        void exportFile();

        bool isFull();
};

#endif
