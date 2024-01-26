"""
    El manejo de archivos permiten trabajar con archivos y directorios
    mediante objetos. Si se tuviera un "test.txt", para usarlo sería:
        file = open("test.txt", mode) o
        with open("test.txt", mode) as file <- prefrible

    Otros ejemplo de modos:
        file = open("test.txt")         -> Lectura
        file = open("test.txt","w")     -> Escritura
        file = open("test.txt", "r+b")  -> Lectura y escritura en binario
"""
# --- # Modo lectura de archivos convencional # --- #
print("Lectura de archivos sin el bloque with:")
file = open("test.txt", "r")    # Se abre el archivo
read_content = file.read()      # Se leé el archivo
print(read_content)
file.close()                    # Se cierra el archivo

# --- # Modo lectura de archivos con bloque with # --- #
print("\nLectura de archivos sin bloque with:")
with open("test.txt", "r") as file:
    read_content = file.read()  # Leé el archivo
    print(read_content)
# Se cierra solo el archivo

# --- # Modo lectura de archivos con excepciones # --- #
print("\nLectura de archivo con excepciones:")
try:
    file = open("test.txt", "r")
    read_content = file.read()
    print(read_content)
except FileNotFoundError:   # Por si el archivo no existe
    print("Exception: No se encontró el archivo")
finally:    # Para asegurar que el archivo se cierra si o si
    file.close()

# --- # Modo escrita de archivos con bloque with # --- #
print("\nEscritura de archivo con bloque with:")
with open("test2.txt", "w") as file2:
    # Si no existe el test2.txt, se crea y escribe en el
    file2.write("Programar es divertido")
