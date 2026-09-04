#include <iostream>
#include "encoder.h"

int main() {
    BitBuffer buffer = encodeByteMode("HELLO");
    std::cout << "Total bits: " << buffer.size() << "\n";
    return 0;
}