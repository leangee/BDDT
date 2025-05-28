#include <fstream>
#include <stdexcept>
#include "railway_system.h"
#include "wagontype.h"

void RailwaySystem::loadFromFile(const std::string& filename) {
    clearSystem();

    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Не удалось открыть файл");
    }

    int id, type;
    float weight;
    while (file >> id >> type >> weight) {
        addWagon(Wagon(id, static_cast<WagonType>(type), weight));
    }
}

void RailwaySystem::addWagon(Wagon wagon) {
    wagons.push_back(wagon);
    sortingNode.addWagon(wagon);
}

void RailwaySystem::processSorting() {
    sortingNode.sortWagons();
}

void RailwaySystem::displayResults() const {
    sortingNode.displayResults();
}

void RailwaySystem::clearSystem() {
    wagons.clear();
    sortingNode.clear();
}

void RailwaySystem::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) {
        throw std::runtime_error("Не удалось создать файл");
    }

    auto left = sortingNode.getLeftTrackWagons();
    auto right = sortingNode.getRightTrackWagons();

    file << "Левый путь (" << wagonTypeToString(WagonType::TYPE1) << "):\n";
    for (const auto& wagon : left) {
        file << wagon.getId() << " " << static_cast<int>(wagon.getType())
            << " " << wagon.getWeight() << "\n";
    }

    file << "\nПравый путь (" << wagonTypeToString(WagonType::TYPE2) << "):\n";
    for (const auto& wagon : right) {
        file << wagon.getId() << " " << static_cast<int>(wagon.getType())
            << " " << wagon.getWeight() << "\n";
    }
}