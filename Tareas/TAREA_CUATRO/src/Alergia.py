class Alergia:
    """
    Clase que representa las alergias y sus códigos asociados.

    Los códigos de alergias son atributos privados de la clase y se asignan
    valores numéricos únicos a cada alergia. Estos códigos se utilizan para
    identificar las alergias de una persona.
    """

    def __init__(self):
        """
        Constructor de la clase Alergia.

        Inicializa los códigos y nombres de alergias como atributos protegidos
        tipo tupla de un diccionario. Además de un atributo que almacena el
        nombre de la alergia que se desea consultar.
        """
        # Se crea el diccionario, el cual es un atributo privado
        self._alergias = {
            "huevos": ("Huevos", 1),
            "cacahuetes": ("Cacahuetes", 2),
            "mariscos": ("Mariscos", 4),
            "fresas": ("Fresas", 8),
            "tomates": ("Tomates", 16),
            "chocolate": ("Chocolate", 32),
            "polen": ("Polen", 64),
            "gatos": ("Gatos", 128),
            "sardinas": ("Sardinas", 256),
            "gluten": ("Gluten", 512),
            "huevo": ("Huevo", 1024),
            "nueces": ("Nueces", 2048),
            "leche": ("Leche", 4096),
            "soja": ("Soja", 8192),
            "miel": ("Miel", 16384),
            "pina": ("Piña", 32768),
            "ajo": ("Ajo", 65536),
            "maiz": ("Maíz", 131072),
            "kiwi": ("Kiwi", 262144),
            "menta": ("Menta", 524288),
            "gambas": ("Gambas", 1048576),
            "apio": ("Apio", 2097152),
            "pescado": ("Pescado", 4194304),
            "manzanas": ("Manzanas", 8388608),
            "cilantro": ("Cilantro", 16777216),
            "aguacate": ("Aguacate", 33554432),
            "zanahorias": ("Zanahorias", 67108864),
            "berenjenas": ("Berenjenas", 134217728),
            "lentejas": ("Lentejas", 268435456),
            "almendras": ("Almendras", 536870912),
            "canela": ("Canela", 1073741824),
            "altramuces": ("Altramuces", 2147483648),
            "mantequilla": ("Mantequilla", 4294967296),
            "pepino": ("Pepino", 8589934592),
            "cangrejo": ("Cangrejo", 17179869184),
            "almejas": ("Almejas", 34359738368),
            "anacardos": ("Anacardos", 68719476736),
            "coliflor": ("Coliflor", 137438953472),
            "pimienta": ("Pimienta", 274877906944),
            "arandanos": ("Arándanos", 549755813888),
            "pera": ("Pera", 1099511627776),
            "cerveza": ("Cerveza", 2199023255552),
            "guisantes": ("Guisantes", 4398046511104),
            "ciruelas": ("Ciruelas", 8796093022208),
            "trigo": ("Trigo", 17592186044416),
            "higos": ("Higos", 35184372088832),
            "centeno": ("Centeno", 70368744177664),
            "pistachos": ("Pistachos", 140737488355328),
            "cangrejo_de_rio": ("Cangrejo de río", 281474976710656),
            "col": ("Col", 562949953421312)
        }

    def imprimir_informacion_completa(self):
        """
        Método que imprime la información completa de todas las alergias.

        El método muestra en la consola los nombres y códigos de todas las
        alergias disponibles en el registro.
        """
        print("\nA continuación se muestras todas las alergias, existentes",
              "en el registro, y su valor asociado:")
        for nombre, (alergia, codigo) in self._alergias.items():
            print(f"{alergia}: {codigo}")

    def imprimir_alergia(self, alergia_nombre=None):
        """
        Método que imprime la información de una alergia específica.

        :param alergia_nombre: Nombre de la alergia a imprimir.
        """
        try:
            # Esto significa que no se ingresó nada cuando se utilizó el método
            # por ende hay un error
            if alergia_nombre is None:
                raise ValueError("Debe proporcionar el nombre de la alergia.")

            # Esto se debe a que se ingresó algo distinto a un str, que era lo
            # esperado
            if not isinstance(alergia_nombre, str):
                raise TypeError("No se ingreso el nombre de una alergia")

            # Intenta convertir a minúsculas si es una cadena
            alergia_nombre = alergia_nombre.lower()

            # Almacena el valor asociado al dicionario en la variable alergia
            alergia = self._alergias.get(alergia_nombre)

            # Si el nombre ingresado si existe, imprime la info de la alergia.
            if alergia:
                print(f"\n{alergia[0]}: valor asociado {alergia[1]}")
            else:
                print("\nNo se encontró información para la alergia:",
                      alergia_nombre)

        except TypeError as e:
            print(f"Error: {e}")
        except ValueError as e:
            print(f"Error: {e}")
