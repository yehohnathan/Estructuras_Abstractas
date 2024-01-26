"""
    Uso del módulo "import os" para el uso de directiorios
"""
import os

# Método para mostrar el directorio en donde se encuentra el programa
print(f"El directorio de programa se encuentra en: {os.getcwd()}")

# Método para cmabiar de directorio:
# os.chdir('C:\\Python33') -> equivalente a un cd de UNIX

# Método para eliminar un file
# os.remove("myfile.txt")

# Método para eliminar un directorio/carpeta
# os.rmdir(ejemplo) -> elimnaria la carpeta "ejemplo"

# Método que muestra todos los sub directorios del directorio actual
print(f"\nTodos los directorios actuales:\n{os.listdir()}")

# Método que muestra los directorios de una ubicación en específico
# os.listdir('C:\\')

# Método para crear un directorio
try:
    os.mkdir('test')
except FileExistsError:
    print("\nException: El directorio ya existe")

# Método para cambiar nombre de un directorio
# os.rename('test', new_one)
