#pragma once
#include <vector>
#include <cstdint>


enum class Module :  uint8_t 
{
    UNSET = 0,
    LIGHT = 1,
    DARK = 2
};

class Matrix
{
    public:
        explicit Matrix(int size);

        void set(int row, int col, Module value);
        Module get(int row, int col) const;
        int size() const;

    private:
        int size_;
        std::vector<std::vector<Module>> grid_;
};