# options
CXX := c++
BUILD := ./build
EXE := $(BUILD)/program

SRC += $(wildcard src/*.cpp)

# imgui
SRC += imgui/imgui.cpp imgui/imgui_draw.cpp
SRC += imgui/imgui_tables.cpp imgui/imgui_widgets.cpp

# imgui + SDL + GL
SRC += imgui/backends/imgui_impl_sdl2.cpp imgui/backends/imgui_impl_opengl3.cpp
CXXFLAGS += -lGL $(shell sdl2-config --cflags --libs)
CXXFLAGS += -Iimgui -Iimgui/backends

CXXFLAGS += -std=c++14

OBJ := $(SRC)
OBJ := $(patsubst src/%.cpp,$(BUILD)/src_%.o,$(OBJ))
OBJ := $(patsubst imgui/%.cpp,$(BUILD)/imgui_%.o,$(OBJ))

$(BUILD)/src_%.o: src/%.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

$(BUILD)/imgui_%.o: imgui/%.cpp
	mkdir -p $(shell dirname $@)
	$(CXX) -c $< -o $@ $(CXXFLAGS)

$(EXE):
	$(CXX) $(OBJ) -o $< $(CXXFLAGS)

build: $(EXE)

run: build
	exec $(BUILD)/program

clean:
	rm -r $(BUILD)

.PHONY: build run clean prepare
