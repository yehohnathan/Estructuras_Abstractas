# Tarea2: Teoría y aplicación en código de POO

## Código para tienda especializada en materiales de entretenimiento
### Intrucciones de ejecución:

## Parte teórica:
### Conceptos de programación orientada a objetos:

1. **Conceptos Fundamentales:** Define qué es la programación orientada a objetos y explica sus principios fundamentales.

    La programación orientada a objetos (POO) es un paradigma de programación que se basa en la organización de datos y comportamientos en estructuras llamadas "objetos". Estos objetos representan entidades o conceptos del mundo real, y tienen características (atributos) y comportamientos (métodos) que los definen y diferencian. La POO permite crear software más organizado, reutilizable y fácil de entender, al alinear más estrechamente el código con cómo vemos y categorizamos el mundo real [1].

    Los principios fundamentales de la POO son [1]:

    - **Abstracción:** Consiste en simplificar la realidad, seleccionando solo las propiedades y comportamientos esenciales de cada objeto, e ignorando los detalles irrelevantes. La abstracción facilita el diseño del software, al reducir la complejidad y mantener el enfoque en la funcionalidad clave.

    - **Encapsulamiento:** Consiste en ocultar los detalles de implementación de cada objeto, y exponer solo una interfaz pública que defina cómo interactuar con él. El encapsulamiento protege la integridad de los datos, al evitar el acceso o la modificación no autorizada de los atributos internos. También favorece la modularidad y el bajo acoplamiento, al permitir cambiar el funcionamiento interno de un objeto sin afectar al resto del sistema. Se suele separar en miembros: `private`, `public` y `protected`.

    - **Herencia:** Consiste en establecer una relación jerárquica entre clases, de forma que una clase hija herede las propiedades y métodos de una clase padre, y pueda añadir o modificar los suyos propios. La herencia permite reutilizar el código existente, al evitar la repetición de atributos y métodos comunes. También facilita la especialización y la generalización, al permitir definir clases más específicas a partir de clases más generales.

    - **Polimorfismo:** Consiste en la capacidad de un objeto de comportarse de diferentes formas según el contexto, manteniendo la misma interfaz. El polimorfismo permite aprovechar la herencia, al permitir que un objeto de una clase hija pueda ser tratado como un objeto de una clase padre, y ejecutar el método adecuado según su tipo real. También mejora la flexibilidad y la extensibilidad, al permitir añadir nuevas clases sin modificar el código existente.


2. **Herencia:** Explica el concepto de herencia en programación orientada a objetos y proporciona un ejemplo práctico.

    La herencia, como se explicó anteriormente, es uno de los principios fundamentales de la programación orientada a objetos, que permite definir nuevas clases a partir de otras ya existentes, reutilizando su código y añadiendo nuevas funcionalidades. La herencia establece una relación jerárquica entre clases, de forma que una clase hija hereda las propiedades y métodos de una clase madre, y puede modificarlos o ampliarlos según sus necesidades [1].

    Un ejemplo práctico de herencia en la vida real sería el siguiente:

    Cuando se entra a una universidad nos registramos con los datos que el estado tiene de nosotros, como lo es nuestro nombre y edad, en este caso omitiendo el genero y lugar de nacimiento. Cuando entramos a la universidad no es necesario ingresar los datos mencionados, ya el estado los tiene, pero si es importante incluir otro nuevos que utilizará para identificarnos como el carnet y la carrera que estamos cursando; estos datos no apareceran en el estado ya que no son necesarios.

    Interpretando el ejemplo como un código de C++:

```cpp
// Definimos una clase base llamada Persona, que tiene dos atributos: nombre y edad
class Persona {
  
  protected:    // Los atributos protegidos se pueden acceder desde las clases derivadas
    string nombre;
    int edad;

  public:       // Los métodos públicos se pueden acceder desde cualquier parte
    // Constructor de la clase Persona, que recibe el nombre y la edad como parámetros
    Persona(string n, int e) {
      nombre = n;
      edad = e;
    }
    
    // Método para mostrar los datos de la persona
    void mostrar() {
      cout << "Nombre: " << nombre << endl;
      cout << "Edad: " << edad << endl;
    }
};

// Definimos una clase derivada llamada Estudiante, que hereda de la clase Persona
// y tiene un atributo adicional: carrera
class Estudiante : public Persona { // Usamos la palabra clave public para indicar que hereda de Persona
  
  private:      // Los atributos privados solo se pueden acceder desde la misma clase
    string carrera;
    string carnet;

  public:       // Los métodos públicos se pueden acceder desde cualquier parte
    // Constructor de la clase Estudiante, que recibe el nombre, la edad y la carrera como parámetros
    // y llama al constructor de la clase Persona con los dos primeros
    Estudiante(string n, int e, string c, string c2) : Persona(n, e) {
      carrera = c;
      carnet = c2;
    }
    
    // Método para mostrar los datos del estudiante, que sobreescribe el método de la clase Persona
    // y llama al método de la clase base con la palabra clave super
    void mostrar() {
      super.mostrar(); // Llamamos al método mostrar de la clase Persona
      cout << "Carrera: " << carrera << endl; // Mostramos el atributo carrera
      cout << "Carnet: " << carnet << endl; // Mostramos el atributo carnet
    }
};

// Creamos un objeto de la clase Persona
Persona p1("Leidy", 22);
// Creamos un objeto de la clase Estudiante
Estudiante e1("Yehohnathan", 21, "Ing. Electrica", "C04879");
// Mostramos los datos de ambos objetos
p1.mostrar();
e1.mostrar();
```

    El resultado de ejecutar este código sería:

```
Nombre: Leidy
Edad: 22
Nombre: Yehohnathan
Edad: 21
Carrera: Ing. Electrica
Carnet: C04879
```

    Como se puede observar, la clase Estudiante hereda los atributos nombre y edad, y el método mostrar de la clase Persona, y además define su propio atributo carrera y modifica el método mostrar para incluirlo. De esta forma, se aprovecha el código existente y se evita la repetición innecesaria. 

3. **Encapsulamiento:** ¿Qué es el encapsulamiento en OOP y por qué es importante? Proporciona ejemplos de cómo se implementa en C++.

    El encapsulamiento es otro de los principios fundamentales de la programación orientada a objetos, que consiste en ocultar los detalles de implementación de cada objeto, y exponer solo una interfaz pública que defina cómo interactuar con él. El encapsulamiento permite [2]:

    - Proteger los datos de manipulaciones no autorizadas.
    - Facilitar el mantenimiento del código al aislar cambios internos.
    - Promover la modularidad y la reutilización del código.
    - Permitir implementar lógica de validación y control de acceso.

    En C++, el encapsulamiento se implementa mediante el uso de modificadores de acceso, que son palabras clave que indican el nivel de visibilidad de los atributos y métodos de una clase. Los modificadores de acceso más comunes son [2]:

    - **public:** Los atributos y métodos públicos se pueden acceder desde cualquier parte del código, incluso desde fuera de la clase. Este es el nivel más bajo de encapsulamiento, y se usa para definir la interfaz pública de la clase.
    - **private:** Los atributos y métodos privados solo se pueden acceder desde dentro de la misma clase. Este es el nivel más alto de encapsulamiento, y se usa para ocultar los detalles internos de la clase.
    - **protected:** Los atributos y métodos protegidos se pueden acceder desde dentro de la misma clase o desde sus clases derivadas. Este es un nivel intermedio de encapsulamiento, y se usa para permitir la herencia entre clases.

    Un ejemplo de cómo se implementa el encapsulamiento en la vida real:

    En el caso que se desea sacar una tarjeta de crédito el banco nos registra dentro de su sistema web con los datos del titular de la cuenta, nosotros, el saldo actual de la cuenta y los intereses que va a ir generando la tarjeta de crédito conforme la usamos; estos 3 datos deben ser privados solo podrán ser modificados por el banco con una posible autorización del titular. 
    
    Cuando vamos a un cajero y queremos ver el estado de nuestra cuenta o depositar dinero, lo podemos hacer sin problemas pero nunca vamos a poder cambiar el nombre del titular, los intereses o modificar el saldo a no ser que se haga un deposito o se sustraiga dinero de una compra. También hay una carga de intereses, supongamos del 10%, de no pagar la tarjeta a tiempo, esto no puede ser modificado por el titular de ninguna forma de no pagar.

    Interpretando el ejemplo como un código de C++:  

```cpp
// Definimos una clase llamada CuentaBancaria, que tiene tres atributos y tres métodos
class CuentaBancaria {

  private:      // Los atributos privados solo se pueden acceder desde la misma clase
    string titular;     // El nombre del titular de la cuenta
    double saldo;       // El saldo actual de la cuenta
    double interes;     // El interes de la tarjeta de crédito

  public:       // Los métodos públicos se pueden acceder desde cualquier parte del código

    // Constructor de la clase CuentaBancaria, que recibe el titular, el saldo y el interés como parámetros
    CuentaBancaria(string t, double s, double i) {
      titular = t;
      saldo = s;
      interes = i;
    }

    // Método para consultar el saldo de la cuenta
    double consultarSaldo() {
      return saldo;
    }
    
    // Método para depositar una cantidad en la cuenta
    void depositar(double cantidad) {
      // Validamos que la cantidad sea positiva
      if (cantidad > 0) {
        // Actualizamos el saldo
        saldo += cantidad;
        // Mostramos un mensaje de confirmación
        cout << "Se ha depositado " << cantidad << " pesetas en la cuenta de " << titular << endl;
      } else {
        // Mostramos un mensaje de error
        cout << "La cantidad debe ser positiva" << endl;
      }

    }
    // Método para retirar una cantidad de la cuenta
    void retirar(double cantidad) {
      // Validamos que la cantidad sea positiva y no supere el saldo
      if (cantidad > 0 && cantidad <= saldo) {
        // Actualizamos el saldo
        saldo -= cantidad;
        // Mostramos un mensaje de confirmación
        cout << "Se ha retirado " << cantidad << " pesetas de la cuenta de " << titular << endl;
      } else {
        // Mostramos un mensaje de error
        cout << "La cantidad debe ser positiva y no superar el saldo" << endl;
      }
    }
};

// Creamos un objeto de la clase CuentaBancaria
CuentaBancaria c1("Yehohnathan", 5, 0.1);

// Consultamos el saldo de la cuenta
cout << "El saldo de la cuenta de " << c1.titular << " es de " << c1.consultarSaldo() << "pesetas">> << endl;

// Depositamos 10 en la cuenta
c1.depositar(10);

// Retiramos 20 de la cuenta
c1.retirar(20);
```

El resultado de ejecutar este código sería:

```
El saldo de la cuenta de Yehohnathan es de 5 pesetas
Se ha depositado 10 pesetas en la cuenta de Yehohnathan
La cantidad debe ser positiva y no superar el saldo
```

    Como se puede observar, los atributos titular, saldo e interes son privados, por lo que no se pueden acceder directamente desde fuera de la clase. Solo se pueden modificar o consultar mediante los métodos públicos consultarSaldo, depositar y retirar, que implementan la lógica necesaria para validar y actualizar los datos.

4. **Polimorfismo:** Describe el polimorfismo y proporciona ejemplos de polimorfismo de tipo y polimorfismo de operador en C++.

5. **Abstracción:** ¿Cómo se relaciona la abstracción con la programación orientada a objetos? Proporciona ejemplos de cómo aplicar la abstracción en un contexto de programación.

6. **Clases y Objetos:** Diferencia entre una clase y un objeto en programación orientada a objetos. Proporciona un ejemplo de cada uno.

7. **Métodos Virtuales:** Explica la importancia de los métodos virtuales en C++ y cómo se utilizan en la implementación de polimorfismo.

8. **Constructores y Destructores:** ¿Cuál es el propósito de un constructor y un destructor en una clase? Proporciona ejemplos de su uso.

9. **Sobrecarga de Operadores:** Explica qué es la sobrecarga de operadores y proporciona un ejemplo de cómo se implementa en C++.

10. **Templates:** Describe el concepto de templates en C++. ¿En qué situaciones sería útil utilizar templates?

11. **Memoria Dinámica:** ¿Qué es la memoria dinámica en C++ y cuándo se utiliza comúnmente?

12. **Diferencia entre `new` y `malloc` en C++:** ¿Cuándo debería utilizar uno sobre el otro?

13. **Fuga de Memoria (Memory Leak):** ¿Qué es una fuga de memoria y cómo puede evitarse en programas en C++?

14. **Punteros Inteligentes (Smart Pointers):** Explica el concepto de punteros inteligentes y proporciona ejemplos de su uso.

15. **Diferencia entre `delete` y `delete[]` en C++:** ¿En qué contexto se utilizaría cada uno?

16. **Algoritmos de Ordenamiento:** ¿Qué es un algoritmo de ordenamiento y por qué son importantes en programación?

17. **Bubble Sort:** Explica el funcionamiento del algoritmo de ordenamiento "Bubble Sort". ¿Cuál es su complejidad temporal en el peor caso?

18. **QuickSort:** Describe el algoritmo de ordenamiento "QuickSort". ¿Cuál es su ventaja principal sobre otros algoritmos de ordenamiento?

19. **Diferencia entre Ordenamiento Estable e Inestable:** ¿Cuál es la diferencia entre un algoritmo de ordenamiento estable y uno inestable? Proporciona ejemplos de cada uno.

20. **Merge Sort:** Habla sobre el algoritmo de ordenamiento "Merge Sort". ¿Cuál es su complejidad temporal y en qué situaciones es preferible su uso?

## Bibliografía:

[1] L. Jiménez, “Principios de la Programación Orientada a Objetos Explicados,” [En línea]. Disponible: https://leojimzdev.com/principios-de-la-programacion-orientada-a-objetos-explicados/. [Accedido: 14-Ene-2024].

[2] D. Lara, “Encapsulamiento en la programación orientada a objetos,” Styde.net, 07 jul. 2015. [En línea]. Disponible: https://styde.net/encapsulamiento-en-la-programacion-orientada-a-objetos/. [Accedido: 14-Ene-2024].