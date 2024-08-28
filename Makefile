# Compiler
CXX = g++
CXXFLAGS = -g -Wall -Wextra -std=c++17 -pedantic -pedantic-errors -Wfloat-equal -Wredundant-decls -Wshadow -Wconversion

# SFML paths
SFML_INCLUDE = C:/Users/mayav/Documents/Snake\ Game/External/SFML/include
SFML_LIB = C:/Users/mayav/Documents/Snake\ Game/External/SFML/lib

# Add SFML include path to compiler flags
CXXFLAGS += -I$(SFML_INCLUDE)

# SFML libraries to link
LDFLAGS = -L$(SFML_LIB) -lsfml-graphics -lsfml-window -lsfml-system

# List .h files here
HEADERS =

# List .cpp files here
PROGRAM_FILES = main.cpp

# Object files
OBJS = $(PROGRAM_FILES:.cpp=.o)

.PHONY: all
all: program.exe

# Build target
program.exe: $(OBJS) $(HEADERS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# Compile .cpp files to .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	del *.exe
	del *.o
