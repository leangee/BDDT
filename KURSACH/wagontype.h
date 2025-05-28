#pragma once
#include <string>

enum class WagonType {
    TYPE1,
    TYPE2
};

// Объявляем функцию как inline
inline std::string wagonTypeToString(WagonType type) {
    return (type == WagonType::TYPE1) ? "Тип 1" : "Тип 2";
}