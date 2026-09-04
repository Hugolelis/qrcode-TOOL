CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -g -Iincludes

TARGET := build/qrcode

# library sources: the QR logic itself (no main here)
LIB_SOURCES := $(wildcard src/*.cpp)
# app sources: just the entry point
APP_SOURCES := bin/main.cpp

SOURCE := $(LIB_SOURCES) $(APP_SOURCES)

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(SOURCE)
	mkdir -p build
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf build