#include "railway_system.h"
#include <iostream>
#include <clocale>
#include <limits>
#include <cstdlib>
#include <algorithm>

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef max
#undef max
#endif

void initLocalization() {
#ifdef _WIN32
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
#endif

    setlocale(LC_ALL, "Russian");
}

void displayMenu() {
    std::cout << "\n=== ��������������� ������������� ������� ===";
    std::cout << "\n1. ��������� ������ �� �����";
    std::cout << "\n2. ������ ������ �������";
    std::cout << "\n3. �������� ����������";
    std::cout << "\n4. ��������� ���������� � ����";
    std::cout << "\n5. �������� �������";
    std::cout << "\n6. �����";
    std::cout << "\n�������� ��������: ";
}

void manualInput(RailwaySystem& system) {
    int id, typeInput;
    float weight;
    char choice;

    do {
        std::cout << "\n=== ���������� ������ ===";

        // ���� ID
        std::cout << "\n������� ID ������: ";
        while (!(std::cin >> id) || id <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "������! ������� ������������� ����� ����� ��� ID: ";
        }

        // ���� ����
        std::cout << "������� ��� (0 - ��� 1, 1 - ��� 2): ";
        while (!(std::cin >> typeInput) || (typeInput != 0 && typeInput != 1)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "������! ������� 0 ��� 1: ";
        }
        WagonType type = static_cast<WagonType>(typeInput);

        // ���� ����
        std::cout << "������� ��� ������ (�����): ";
        while (!(std::cin >> weight) || weight <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "������! ������� ������������� ����� ��� ����: ";
        }

        system.addWagon(Wagon(id, type, weight));

        std::cout << "\n����� ������� ��������!";
        std::cout << "\n�������� ��� ���� �����? (y/n): ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (choice == 'y' || choice == 'Y');
}

int main() {
    initLocalization();

    RailwaySystem system;
    int choice;
    bool running = true;

    while (running) {
        displayMenu();

        int maxChoice = 6;
        while (!(std::cin >> choice) || choice < 1 || choice > maxChoice) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "�������� ����. ����������, �������� ����� ���� (1-"
                << maxChoice << "): ";
        }

        try {
            switch (choice) {
            case 1: {
                std::string filename;
                std::cout << "\n������� ��� ����� (��������: data\\input.txt): ";
                std::cin >> filename;
                system.loadFromFile(filename);
                system.processSorting();
                std::cout << "\n������ ������� ��������� � �������������!";
                break;
            }
            case 2:
                manualInput(system);
                system.processSorting();
                break;
            case 3:
                system.displayResults();
                break;
            case 4: {
                std::string filename;
                std::cout << "\n������� ��� ����� ��� ����������: ";
                std::cin >> filename;
                system.saveToFile(filename);
                std::cout << "\n���������� ������� ��������� � ����!";
                break;
            }
            case 5:
                system.clearSystem();
                std::cout << "\n������� �������!";
                break;
            case 6:
                running = false;
                break;
            default:
                std::cout << "\n�������� �����! ����������, ���������� �����.";
            }
        }
        catch (const std::exception& e) {
            std::cerr << "\n������: " << e.what() << std::endl;
        }
    }

    std::cout << "\n������ ��������� ���������. ������� Enter ��� ������...";
    std::cin.ignore();
    std::cin.get();
    return 0;
}