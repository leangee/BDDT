#pragma once
#include <iostream>
#include "wagontype.h"

class Wagon {
private:
    int id;
    WagonType type;
    float weight;

public:
    Wagon(int id, WagonType type, float weight);
    WagonType getType() const;
    void displayInfo() const;
    int getId() const;
    float getWeight() const;
};