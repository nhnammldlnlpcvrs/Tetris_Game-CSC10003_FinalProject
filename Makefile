# Compiler
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -I. -Iresource
LDFLAGS := -lraylib

# Detect platform
UNAME_S := $(shell uname -s)

ifeq ($(OS),Windows_NT)  # Windows (MSYS2/MinGW)
    LDLIBS := -lopengl32 -lgdi32 -lwinmm
else ifeq ($(UNAME_S),Darwin)  # macOS
    LDLIBS := -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
else  # Linux
    LDLIBS := -lGL -lm -lpthread -ldl -lrt -lX11
endif

# Source files (only from resource/)
SRC := $(shell find resource -name "*.cpp")
OBJ := $(SRC:.cpp=.o)
TARGET := tetris

# Default target
all: $(TARGET)

# Link target
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ) $(LDFLAGS) $(LDLIBS)

# Compile .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
	rm -f $(OBJ) $(TARGET)