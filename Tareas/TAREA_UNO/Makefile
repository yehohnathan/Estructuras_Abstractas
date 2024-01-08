# Nombre del programa de salida
TARGET = adivina_x.exe

# Objetivo predeterminado
all: build run

# Compilador de C++
CXX = g++

# Opciones de compilación
CXXFLAGS = -Wall -std=c++11

# Directorio de código fuente
SRC_DIR = src

# Lista de archivos fuente
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# Lista de archivos objeto generados a partir de los archivos fuente
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=%.exe)

# Regla para compilar los archivos fuente en archivos objeto
%.exe: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para compilar el programa a partir de los archivos objeto
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Targets adicionales
build: $(TARGET)

run: build
	./$(TARGET)

# Regla para limpiar los archivos generados y dejar solo el código fuente
clean:
	del $(TARGET) $(OBJECTS)
