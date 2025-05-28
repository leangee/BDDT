#pragma once
#include "wagon.h"
#include <stack>
#include <vector>

class SortingNode {
private:
    std::stack<Wagon> mainTrack;
    std::stack<Wagon> leftTrack;
    std::stack<Wagon> rightTrack;

public:
    void addWagon(Wagon wagon);
    void sortWagons();
    void displayResults() const;
    void clear();
    std::vector<Wagon> getLeftTrackWagons() const;
    std::vector<Wagon> getRightTrackWagons() const;
};