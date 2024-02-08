# Makefile para la tarea 5

# Se utiliza para detectar el sistema operativo
ifeq ($(OS),Windows_NT)
    # Establece los comandos para Windows
    RM = del /Q
    EXE_EXTENSION = .exe
else
    # Establece los comandos para Linux/Unix
    RM = rm -f
    EXE_EXTENSION =
endif

# Compilador de C++
CPP_COMPILER = g++

# Archivos
CPP_SOURCE = src/ejecutor.cpp
EXE_FILE = ejecutor$(EXE_EXTENSION)

# Regla por defecto
all: compile run

# Compilación del programa C++
compile:
	$(CPP_COMPILER) $(CPP_SOURCE) -o $(EXE_FILE)

# Ejecución del programa
run:
	./$(EXE_FILE)

# Limpiar los archivos generados
clean:
	$(RM) $(EXE_FILE)
	$(RM) src/__pycache__/
