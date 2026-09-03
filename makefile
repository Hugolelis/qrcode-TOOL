CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -g -Iincludes

TARGET := build/qrcode
SOURCE := ${wildcard src/*.cpp}

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(SOURCE)
	mkdir -p build
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf build