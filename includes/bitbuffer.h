#pragma once
#include <vector>
#include <cstdint>

class BitBuffer 
{
    public:
        void appendBits(uint32_t value, int numBIts);
        int size() const;
        bool at(int index) const;

        private:
            std::vector<bool> bits_;
};