#include "sorting_node.h"
#include <algorithm>
#include "wagontype.h"

void SortingNode::addWagon(Wagon wagon) {
    mainTrack.push(wagon);
}

void SortingNode::sortWagons() {
    while (!mainTrack.empty()) {
        Wagon current = mainTrack.top();
        mainTrack.pop();

        if (current.getType() == WagonType::TYPE1) {
            leftTrack.push(current);
        }
        else {
            rightTrack.push(current);
        }
    }
}

void SortingNode::displayResults() const {
    if (leftTrack.empty() && rightTrack.empty())
    {
        std::cout << "\nДанные отсутствуют. Сортировка невозможна." << std::endl;
        return;
    }

    std::cout << "\n=== Результаты сортировки ===" << std::endl;

    std::cout << "\nЛевый путь (" << wagonTypeToString(WagonType::TYPE1) << "):" << std::endl;
    auto left = leftTrack;
    while (!left.empty()) {
        left.top().displayInfo();
        left.pop();
    }

    std::cout << "\nПравый путь (" << wagonTypeToString(WagonType::TYPE2) << "):" << std::endl;
    auto right = rightTrack;
    while (!right.empty()) {
        right.top().displayInfo();
        right.pop();
    }
}

void SortingNode::clear() {
    while (!mainTrack.empty()) mainTrack.pop();
    while (!leftTrack.empty()) leftTrack.pop();
    while (!rightTrack.empty()) rightTrack.pop();
}

std::vector<Wagon> SortingNode::getLeftTrackWagons() const {
    std::vector<Wagon> result;
    auto temp = leftTrack;
    while (!temp.empty()) {
        result.push_back(temp.top());
        temp.pop();
    }
    std::reverse(result.begin(), result.end());
    return result;
}

std::vector<Wagon> SortingNode::getRightTrackWagons() const {
    std::vector<Wagon> result;
    auto temp = rightTrack;
    while (!temp.empty()) {
        result.push_back(temp.top());
        temp.pop();
    }
    std::reverse(result.begin(), result.end());
    return result;
}