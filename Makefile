# # Compiler
# CXX = g++
# CXXFLAGS = -g -Wall -Wextra
# CXXFLAGS += -std=c++17 -pedantic -pedantic-errors
# CXXFLAGS += -Wfloat-equal -Wredundant-decls -Wshadow -Wconversion

all: complie link

compile: 
	g++ main.cpp -g -Wall -Wextra -std=c++17 -pedantic -pedantic-errors -Wfloat-equal -Wredundant-decls -Wshadow -Wconversion -I"C:/Users/mayav/Documents/Snake Game/External/SFML/include" 

link: 
	g++ main.o -o program -L"C:\Users\mayav\Documents\Snake Game\External\SFML\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lgdi32 -lwinmm -lsfml-main   

clean: 
	rm -f program *.o

# OLD makefile:
# # List .h files here
# HEADERS =

# # List .cpp files here
# PROGRAM_FILES = main.cpp


# # Top of section added to support SFML library  

# # SFML paths
# SFML_INCLUDE = "C:/Users/mayav/Documents/Snake\ Game/External/SFML/include"
# SFML_LIB = "C:/Users/mayav/Documents/Snake\ Game/External/SFML/lib"

# # Add SFML include path to compiler flags
# CXXFLAGS += -I$(SFML_INCLUDE)

# # SFML libraries to link
# LDFLAGS = -L$(SFML_LIB) -lsfml-graphics -lsfml-window -lsfml-system

# # Bottom of section added to support SFML library  


# .PHONY: all
# all: program.exe

# program.exe: $(PROGRAM_FILES) $(HEADERS)
# 	$(CXX) $(CXXFLAGS) $(PROGRAM_FILES) -o $@ $(LDFLAGS)

# .PHONY: clean
# clean:
# 	rm -f program.exe
