# Makefile para el laboratorio 5

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

# Archivos
MAIN_FILE = prestamo.py

# Objetivo por defecto
all: run

# Compilar y ejecutar el programa
run:
	$(PYTHON) $(MAIN_FILE)

# Por algunon motivo no logra limpiar __pycache__
clean:
	$(RM) $(SRC_DIR)/__pycache__/*.pyc
	$(RMDIR) $(SRC_DIR)/__pycache__