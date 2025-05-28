#pragma once
#include <string>

enum class WagonType {
    TYPE1,
    TYPE2
};

// ��������� ������� ��� inline
inline std::string wagonTypeToString(WagonType type) {
    return (type == WagonType::TYPE1) ? "��� 1" : "��� 2";
}