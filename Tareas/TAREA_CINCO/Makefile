# Makefile para la tarea 5

# Detectar el sistema operativo
ifeq ($(OS),Windows_NT)
    # Comandos para Windows
    PYTHON = python
    RM = del /Q
    RMDIR = rmdir /Q /S
else
    # Comandos para Linux (ajustar según sea necesario)
    PYTHON = python3
    RM = rm -f
    RMDIR = rm -rf
endif

# Directorios
SRC_DIR = src

# Archivos
MAIN_FILE_CSV = Manejo_CSV.py
MAIN_FILE_CALIFICACIONES = Calificaciones.py

# Objetivo por defecto
all: run

# Compilar y ejecutar el programa
run: run_csv run_calificaciones

run_csv:
	$(PYTHON) $(SRC_DIR)/$(MAIN_FILE_CSV)

run_calificaciones:
	$(PYTHON) $(SRC_DIR)/$(MAIN_FILE_CALIFICACIONES)

# Por algún motivo no logra limpiar __pycache__
clean:
	$(RM) $(SRC_DIR)/__pycache__/*.pyc
	$(RMDIR) $(SRC_DIR)/__pycache__
