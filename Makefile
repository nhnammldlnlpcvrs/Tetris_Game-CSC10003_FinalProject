# Compiler
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -I. -Iresource
LDFLAGS := -lraylib

# Detect OS for platform-specific libraries
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
    LDLIBS := -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
else
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
