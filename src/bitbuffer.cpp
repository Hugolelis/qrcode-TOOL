#include "bitbuffer.h"

void BitBuffer::appendBits(uint32_t value, int numBits)
{
    // Walk from the most significant bit down to the least significant one
    for (int i = numBits - 1; i >= 0; --i)
    {
        bool bit = (value >> i) & 1;
        bits_.push_back(bit);
    }
}

int BitBuffer::size() const 
{
    return static_cast<int>(bits_.size());
}

bool BitBuffer::at(int index) const 
{
    return bits_[index];
}