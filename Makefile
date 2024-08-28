# Compiler
CXX = g++
CXXFLAGS = -g -Wall -Wextra
CXXFLAGS += -std=c++17 -pedantic -pedantic-errors
CXXFLAGS += -Wfloat-equal -Wredundant-decls -Wshadow -Wconversion

# List .h files here
HEADERS =

# List .cpp files here
PROGRAM_FILES = main.cpp


# Top of section added to support SFML library  

# SFML paths
SFML_INCLUDE = "C:/Users/mayav/Documents/Snake\ Game/External/SFML/include" -DSFML_STATIC
SFML_LIB = "C:/Users/mayav/Documents/Snake\ Game/External/SFML/lib"

# Add SFML include path to compiler flags
CXXFLAGS += -I$(SFML_INCLUDE)

# SFML libraries to link
LDFLAGS = program.o -o program -L$(SFML_LIB) -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lgdi32 -lwinmm -lsfml-main

# Bottom of section added to support SFML library  


.PHONY: all
all: program.exe

program.exe: $(PROGRAM_FILES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(PROGRAM_FILES) -o $@ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f program.exe *.o
