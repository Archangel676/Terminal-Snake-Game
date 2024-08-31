# Compiler
CXX = g++
CXXFLAGS = -g -Wall -Wextra
CXXFLAGS += -std=c++17 -pedantic -pedantic-errors
CXXFLAGS += -Wfloat-equal -Wredundant-decls -Wshadow -Wconversion

# List .h files here
HEADERS =

# List .cpp files here
PROGRAM_FILES = main.cpp


# # Top of section added to support SFML library  

# # SFML paths
# SFML_INCLUDE = "C:/Users/mayav/Documents/Snake\ Game/External/SFML/include"
# SFML_LIB = "C:/Users/mayav/Documents/Snake\ Game/External/SFML/lib"

# # Add SFML include path to compiler flags
# CXXFLAGS += -I$(SFML_INCLUDE)

# # SFML libraries to link
# LDFLAGS = -L$(SFML_LIB) -lsfml-graphics -lsfml-window -lsfml-system

# # Bottom of section added to support SFML library  


.PHONY: all
all: program.exe

program.exe: $(PROGRAM_FILES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(PROGRAM_FILES) -o $@ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f program.exe



# all: compile link

# compile: 
# 	g++ main.cpp -g -Wall -Wextra -std=c++17 -pedantic -pedantic-errors -Wfloat-equal -Wredundant-decls -Wshadow -Wconversion 

# link: 
# 	g++ main.o -o program -L"C:\Users\mayav\Documents\Snake Game\External\SFML\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lgdi32 -lwinmm -lsfml-main   

# clean: 
# 	rm -f program *.o
###########################################################


#example Readme.md file for github
# Snake Game

# This repository contains a simple Snake game created for educational purposes. 

# ## About

# This project was developed to practice game development techniques and to learn more about programming and game design. The code is based on various tutorials and resources available online.

# ## Attribution

# The code and assets used in this project are not original and are based on publicly available resources. The purpose of this project is to practice and understand game development concepts.
#Assets are mine tho
#BoostMyTool - SFML Setup in Visual Studio Code | Create C/C++ Applications using SFML + VSCode + MinGW-w64
#NVitanovic - C++ Tutorial - Simple Snake Game (Parts 1, 2, amd 3)

# ## License

# This project is provided for educational purposes only and is not intended for commercial use. Feel free to use or modify it for your personal learning.


# OLD makefile:

# Compiler
# CXX = g++
# CXXFLAGS = -g -Wall -Wextra
# CXXFLAGS += -std=c++17 -pedantic -pedantic-errors
# CXXFLAGS += -Wfloat-equal -Wredundant-decls -Wshadow -Wconversion

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
