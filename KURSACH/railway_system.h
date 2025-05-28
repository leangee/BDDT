#pragma once
#include "sorting_node.h"
#include <vector>
#include <string>

class RailwaySystem {
private:
    SortingNode sortingNode;
    std::vector<Wagon> wagons;

public:
    void loadFromFile(const std::string& filename);
    void addWagon(Wagon wagon);
    void processSorting();
    void displayResults() const;
    void clearSystem();
    void saveToFile(const std::string& filename) const;
};