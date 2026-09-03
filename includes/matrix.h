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
        void drawFinderPattern(int topRow, int topCol);
        Module get(int row, int col) const;
        
        int size() const;
        void print() const;

    private:
        int size_;
        std::vector<std::vector<Module>> grid_;
};