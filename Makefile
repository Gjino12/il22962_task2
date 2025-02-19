# Compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Source files and output executable
SRC = $(wildcard *.cpp)  # Finds all .cpp files in the current directory
OBJ = $(SRC:.cpp=.o)     # Converts .cpp filenames to .o filenames
EXE = main

# Default rule: Build the executable
all: $(EXE)

# Linking the object files to create the final executable
$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXE) $(OBJ)

# Compile each .cpp file into an object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up compiled files
clean:
	rm -f $(OBJ) $(EXE)