# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g

# Target executable
TARGET = main

# Source files
SRCS = main.cpp graph.cpp algorithms.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

VALGRIND_FLAGS=--leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./$(TARGET)

# Rule to link object files into the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

valgrind: $(TARGET)
	valgrind $(VALGRIND_FLAGS)

# Clean rule to remove generated files
clean:
	rm $(TARGET) $(OBJS) *.txt
