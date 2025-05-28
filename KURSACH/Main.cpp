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
    std::cout << "\n=== Железнодорожная сортировочная система ===";
    std::cout << "\n1. Загрузить данные из файла";
    std::cout << "\n2. Ввести данные вручную";
    std::cout << "\n3. Показать результаты";
    std::cout << "\n4. Сохранить результаты в файл";
    std::cout << "\n5. Очистить систему";
    std::cout << "\n6. Выход";
    std::cout << "\nВыберите действие: ";
}

void manualInput(RailwaySystem& system) {
    int id, typeInput;
    float weight;
    char choice;

    do {
        std::cout << "\n=== Добавление вагона ===";

        // Ввод ID
        std::cout << "\nВведите ID вагона: ";
        while (!(std::cin >> id) || id <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка! Введите положительное целое число для ID: ";
        }

        // Ввод типа
        std::cout << "Введите тип (0 - Тип 1, 1 - Тип 2): ";
        while (!(std::cin >> typeInput) || (typeInput != 0 && typeInput != 1)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка! Введите 0 или 1: ";
        }
        WagonType type = static_cast<WagonType>(typeInput);

        // Ввод веса
        std::cout << "Введите вес вагона (тонны): ";
        while (!(std::cin >> weight) || weight <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка! Введите положительное число для веса: ";
        }

        system.addWagon(Wagon(id, type, weight));

        std::cout << "\nВагон успешно добавлен!";
        std::cout << "\nДобавить еще один вагон? (y/n): ";
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
            std::cout << "Неверный ввод. Пожалуйста, выберите пункт меню (1-"
                << maxChoice << "): ";
        }

        try {
            switch (choice) {
            case 1: {
                std::string filename;
                std::cout << "\nВведите имя файла (например: data\\input.txt): ";
                std::cin >> filename;
                system.loadFromFile(filename);
                system.processSorting();
                std::cout << "\nДанные успешно загружены и отсортированы!";
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
                std::cout << "\nВведите имя файла для сохранения: ";
                std::cin >> filename;
                system.saveToFile(filename);
                std::cout << "\nРезультаты успешно сохранены в файл!";
                break;
            }
            case 5:
                system.clearSystem();
                std::cout << "\nСистема очищена!";
                break;
            case 6:
                running = false;
                break;
            default:
                std::cout << "\nНеверный выбор! Пожалуйста, попробуйте снова.";
            }
        }
        catch (const std::exception& e) {
            std::cerr << "\nОшибка: " << e.what() << std::endl;
        }
    }

    std::cout << "\nРабота программы завершена. Нажмите Enter для выхода...";
    std::cin.ignore();
    std::cin.get();
    return 0;
}