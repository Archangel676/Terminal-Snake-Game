# Makefile for SFML with MinGW

# Compiler
CXX := g++
CXXFLAGS := -std=c++17 -I"C:/SFML/include"  # Add path to SFML include

# Linker
LDFLAGS := -L"C:/SFML/lib" -lsfml-graphics -lsfml-window -lsfml-system

# Target
TARGET := program.exe

# Source files
SRCS := $(wildcard *.cpp)

# Object files
OBJS := $(SRCS:.cpp=.o)

# Build rules
all: $(TARGET)

$(TARGET): $(OBJS)
    $(CXX) $(OBJS) -o $@ $(LDFLAGS)

%.o: %.cpp
    $(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
    del $(OBJS) $(TARGET)  # Command for Windows
