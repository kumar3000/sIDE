# Compiler and Flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g
CPPFLAGS = -Iinclude -Iinclude/imgui -Iinclude/imgui/backends

# Libraries (Windows: replace -lGL with -lopengl32)
LIBS = -lglfw -lGL -ldl

# Target executable
TARGET = bin/main

# Source files (all ImGui core, ImGui backends, GLAD, and your app)
IMGUI = include/imgui
SRCS = $(wildcard src/*.c src/*.cpp) \
       $(wildcard $(IMGUI)/*.cpp) \
       $(IMGUI)/backends/imgui_impl_glfw.cpp \
       $(IMGUI)/backends/imgui_impl_opengl3.cpp

# Build Rule
all:
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $(TARGET) $(SRCS) $(LIBS)

# Clean Rule
clean:
	rm -f $(TARGET)
