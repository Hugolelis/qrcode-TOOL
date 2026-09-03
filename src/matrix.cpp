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