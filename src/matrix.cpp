#include "matrix.h"

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