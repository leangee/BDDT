#include "wagon.h"
#include "wagontype.h"

Wagon::Wagon(int id, WagonType type, float weight)
    : id(id), type(type), weight(weight) {
}

WagonType Wagon::getType() const {
    return type;
}

void Wagon::displayInfo() const {
    std::cout << "Вагон #" << id
        << " | Тип: " << wagonTypeToString(type)
        << " | Вес: " << weight << "т\n";
}

int Wagon::getId() const {
    return id;
}

float Wagon::getWeight() const {
    return weight;
}