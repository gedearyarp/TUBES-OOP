#include "../header/item.hpp"
#include <iostream>

using namespace std;

Item::Item()
{
    this->id = -1;
    this->name = "-";
    this->type = "type";
    this->category = "-";
}

Item::Item(int id, string name, string type, string category)
{
    this->id = id;
    this->name = name;
    this->type = type;
    this->category = category;
}

int Item::getId() const
{
    return this->id;
}

string Item::getName() const
{
    return this->name;
}

string Item::getType() const
{
    return this->type;
}

string Item::getCategory() const
{
    return this->category;
}

bool Item::isNothing() const
{
    return (id == -1);
}

int Item::getQuantity() const { return -1; }
int Item::getDurability() const { return -1; }
void Item::setQuantity(int qty) {}
void Item::setDurability(int durability) {}
bool Item::isEmpty() const { return this->id == -1; }
bool Item::isFull() const { return false; }
// TODO THROW invalid class
// JANGAN PAKAI 6 FUNGSI DI ATAS KALAU BUKAN SUBCLASS ITEM

void Item::itemInfo() const
{
    cout << "ID :" << this->id << endl;
    cout << "Name :" << this->name << endl;
    cout << "Type :" << this->type << endl;
}

Tool::Tool() : Item(0, "-", "-", "TOOL")
{
    this->durability = 10;
}

Tool::Tool(int id, string name, int durability) : Item(id, name, "-", "TOOL")
{
    this->durability = durability;
}

Tool::Tool(int id, string name) : Item(id, name, "-", "TOOL")
{
    this->durability = 10;
}

int Tool::getDurability() const
{
    return this->durability;
}

void Tool::setDurability(int durability)
{
    this->durability = durability;
}

int Tool::getQuantity() const
{
    return 1;
}

void Tool::use()
{
    this->durability--;
    if (this->durability <= 0)
    {
        // Ilang dari inventory
    }
}
void Tool::itemInfo() const
{
    Item::itemInfo();
    cout << "Durability :" << this->durability << endl;
}

NonTool::NonTool() : Item(0, "-", "-", "-")
{
    this->quantity = 0;
}

NonTool::NonTool(int id, string name, string type, int quantity) : Item(id, name, type, "NONTOOL")
{
    this->quantity = quantity;
}

bool NonTool::isFull() const
{
    return this->quantity >= 64;
}

bool NonTool::isEmpty() const
{
    return this->id == -1;
}

int NonTool::getQuantity() const
{
    return this->quantity;
}

void NonTool::setQuantity(int qty)
{
    this->quantity = qty;
}

void NonTool::itemInfo() const
{
    Item::itemInfo();
    cout << "Quantity :" << this->quantity << endl;
}