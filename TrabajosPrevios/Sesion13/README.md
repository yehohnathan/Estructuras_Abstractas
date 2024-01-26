## Excepciones:

| Tipo de Error         | Descripción                                                     |
|-----------------------|-------------------------------------------------------------------|
| AssertionError        | Se produce cuando falla una declaración `assert`.                 |
| AttributeError        | Se produce cuando falla una asignación o referencia de atributo.  |
| EOFError              | Se produce cuando la función `input()` llega a una condición de fin de archivo. |
| FloatingPointError    | Se produce cuando falla una operación de punto flotante.          |
| GeneratorExit         | Se produce cuando se llama al método `close()` de un generador.   |
| ImportError           | Se produce cuando no se encuentra el módulo importado.            |
| IndexError            | Se produce cuando el índice de una secuencia está fuera de rango.  |
| KeyError              | Se produce cuando no se encuentra una clave en un diccionario.     |
| KeyboardInterrupt    | Se produce cuando el usuario presiona la tecla de interrupción (`Ctrl+C` o `Delete`). |
| MemoryError           | Se produce cuando una operación se queda sin memoria.              |
| NameError             | Se produce cuando no se encuentra una variable en el ámbito local o global. |

| Tipo de Error         | Descripción                                                     |
|-----------------------|-----------------------------------------------------------------|
| NotImplementedError  | Se lanza por métodos abstractos.                                |
| OSError              | Se lanza cuando una operación del sistema causa un error relacionado con el sistema. |
| OverflowError        | Se lanza cuando el resultado de una operación aritmética es demasiado grande para ser representado. |
| ReferenceError       | Se lanza cuando se utiliza un proxy de referencia débil para acceder a un referente recogido por el recolector de basura. |
| RuntimeError         | Se lanza cuando un error no cae bajo ninguna otra categoría.    |
| StopIteration        | Se lanza por la función `next()` para indicar que no hay más elementos para ser devueltos por el iterador. |
| SyntaxError          | Se lanza por el analizador cuando se encuentra un error de sintaxis. |
| IndentationError     | Se lanza cuando hay una indentación incorrecta.                 |
| TabError             | Se lanza cuando la indentación consiste en pestañas y espacios inconsistentes. |
| SystemError          | Se lanza cuando el intérprete detecta errores internos.         |

| Tipo de Error         | Descripción                                                     |
|-----------------------|-----------------------------------------------------------------|
| SystemExit            | Se lanza por la función `sys.exit()`.                           |
| TypeError             | Se lanza cuando una función o operación se aplica a un objeto de tipo incorrecto. |
| UnboundLocalError     | Se lanza cuando se hace referencia a una variable local en una función o método, pero no se ha asignado ningún valor a esa variable. |
| UnicodeError          | Se lanza cuando se produce un error de codificación o decodificación relacionado con Unicode. |
| UnicodeEncodeError    | Se lanza cuando se produce un error relacionado con Unicode durante la codificación. |
| UnicodeDecodeError    | Se lanza cuando se produce un error relacionado con Unicode durante la decodificación. |
| UnicodeTranslateError | Se lanza cuando se produce un error relacionado con Unicode durante la traducción. |
| ValueError            | Se lanza cuando una función recibe un argumento del tipo correcto pero con un valor inapropiado. |
| ZeroDivisionError     | Se lanza cuando el segundo operando de una operación de división o módulo es cero. |

## Manejo de archivos:
### Modos:

| Mode | Description |
|------|-------------|
| r    | Open a file for reading. (default) |
| w    | Open a file for writing. Creates a new file if it does not exist or truncates the file if it exists. |
| x    | Open a file for exclusive creation. If the file already exists, the operation fails. |
| a    | Open a file for appending at the end of the file without truncating it. Creates a new file if it does not exist. |
| t    | Open in text mode. (default) |
| b    | Open in binary mode. |
| +    | Open a file for updating (reading and writing) |

### Escribir archivos:

| Method     | Description |
|------------|-------------|
| `close()`    | Closes an opened file. It has no effect if the file is already closed. |
| `detach()`   | Separates the underlying binary buffer from the `TextIOBase` and returns it. |
| `fileno()`   | Returns an integer number (file descriptor) of the file. |
| `flush()`    | Flushes the write buffer of the file stream. |
| `isatty()`   | Returns `True` if the file stream is interactive. |
| `read(n)`    | Reads at most `n` characters from the file. Reads till end of file if it is negative or `None`. |
| `readable()` | Returns `True` if the file stream can be read from. |
| `readline(n=-1)`  | Reads and returns one line from the file, reads in at most `n` bytes if specified.
| `readlines(n=-1)` | Reads and returns a list of lines from the file. Reads in at most `n` bytes/characters if specified. |
| `seek(offset, from=SEEK_SET)` | Changes the file position to `offset` bytes, in reference to `from` (start, current, end). |
| `seekable()`   | Returns `True` if the file stream supports random access. |
| `tell()`       | Returns an integer that represents the current position of the file's object. |
| `truncate(size=None)` | Resizes the file stream to `size` bytes. If size is not specified, resizes to current location. |
| `writable()`   | Returns True if the file stream can be written to. |
| `write(s)`     | Writes the string s to the file and returns the number of characters written. |
| `writelines(lines)`  | Writes a list of lines to the file.|
