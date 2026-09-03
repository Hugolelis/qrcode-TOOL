#include "matrix.h"
#include <iostream>

Matrix::Matrix(int size)
    : size_(size), grid_(size, std::vector<Module>(size, Module::UNSET)) {}

void Matrix::set(int row, int col, Module value) 
{
    grid_[row][col] = value;
}

Module Matrix::get(int row, int col) const 
{
    return grid_[row][col];
}

int Matrix::size() const 
{
    return size_;
}

void Matrix::print() const 
{
    for (int r = 0; r < size_; ++r) {
        for (int c = 0; c < size_; ++c) {
            std::cout << (get(r, c) == Module::DARK ? "██" : "  ");
        }
        std::cout << '\n';
    }
}

void Matrix::drawFinderPattern(int topRow, int topCol) 
{
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 7; ++j) {
            bool isOuterRing = (i == 0 || i == 6 || j == 0 || j == 6);
            bool isCenter    = (i >= 2 && i <= 4 && j >= 2 && j <= 4);
            Module m = (isOuterRing || isCenter) ? Module::DARK : Module::LIGHT;
            set(topRow + i, topCol + j, m);
        }
    }
}

void Matrix::drawSeparators() 
{
    for (int i = 0; i < 8; ++i) {
        // around the top-left finder
        set(7, i, Module::LIGHT);
        set(i, 7, Module::LIGHT);

        // around the top-right finder
        set(7, size_ - 1 - i, Module::LIGHT);
        set(i, size_ - 8, Module::LIGHT);

        // around the bottom-left finder
        set(size_ - 8, i, Module::LIGHT);
        set(size_ - 1 - i, 7, Module::LIGHT);
    }
}

void Matrix::drawTimingPatterns() 
{
    for (int i = 8; i <= size_ - 9; ++i) {
        Module m = (i % 2 == 0) ? Module::DARK : Module::LIGHT;
        set(6, i, m);   // horizontal timing pattern (row 6)
        set(i, 6, m);   // vertical timing pattern (column 6)
    }
}

void Matrix::drawDarkModule() 
{
    // Formula: (4 * version + 9, 8). Version 1 -> (13, 8)
    set(13, 8, Module::DARK);
}

void Matrix::drawFunctionPatterns() 
{
    drawFinderPattern(0, 0);
    drawFinderPattern(0, size_ - 7);
    drawFinderPattern(size_ - 7, 0);
    drawSeparators();
    drawTimingPatterns();
    drawDarkModule();
}