#pragma once

class Item {
public:
    virtual ~Item() {}
    virtual void Use() = 0; // Use the item
    virtual void Describe() const = 0; // Describe the item
};