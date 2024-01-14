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

```
El saldo de la cuenta de Yehohnathan es de 5 pesetas
Se ha depositado 10 pesetas en la cuenta de Yehohnathan
La cantidad debe ser positiva y no superar el saldo
```

Como se puede observar, los atributos titular, saldo e interes son privados, por lo que no se pueden acceder directamente desde fuera de la clase. Solo se pueden modificar o consultar mediante los métodos públicos consultarSaldo, depositar y retirar, que implementan la lógica necesaria para validar y actualizar los datos.

4. **Polimorfismo:** Describe el polimorfismo y proporciona ejemplos de polimorfismo de tipo y polimorfismo de operador en C++.

    El polimorfismo es una característica de la programación orientada a objetos que permite que un mismo nombre o símbolo pueda representar diferentes comportamientos según el contexto, somo lo puede ser la sobreescritura de funciones. El polimorfismo facilita la abstracción, la reutilización y la extensibilidad del código, al permitir que un mismo código pueda funcionar con diferentes tipos de datos [3].

    Existen dos tipos principales de polimorfismo en C++: el polimorfismo en tiempo de compilación y el polimorfismo en tiempo de ejecución [3].

- El polimorfismo en tiempo de compilación se resuelve en la fase de compilación, y se basa en la sobrecarga de funciones u operadores. La sobrecarga consiste en definir varias funciones u operadores con el mismo nombre, pero con diferentes parámetros o tipos de retorno. El compilador elige la versión adecuada según los argumentos que se le pasan [3]. Por ejemplo, se tiene el código extraido con ayuda de Copilot:

```cpp
// Sobrecarga de función
// Definimos dos funciones con el mismo nombre, pero con diferentes parámetros
int suma(int a, int b) {
  return a + b;
}

double suma(double a, double b) {
  return a + b;
}

// Llamamos a la función suma con diferentes argumentos
int x = suma(2, 3); // Se llama a la versión que recibe enteros
double y = suma(2.5, 3.5); // Se llama a la versión que recibe reales

// Sobrecarga de operador
// Definimos una clase llamada Vector, que representa un vector matemático
class Vector {

  private:
    double x; // La coordenada x del vector
    double y; // La coordenada y del vector

  public:
    // Constructor de la clase Vector, que recibe las coordenadas como parámetros
    Vector(double x, double y) {
      this->x = x;
      this->y = y;
    }

    // Sobrecargamos el operador + para sumar dos vectores
    Vector operator+(const Vector& v) {
      // Devolvemos un nuevo vector con la suma de las coordenadas
      return Vector(x + v.x, y + v.y);
    }
};

// Creamos dos objetos de la clase Vector
Vector v1(1, 2);
Vector v2(3, 4);

// Sumamos los dos vectores usando el operador +
Vector v3 = v1 + v2; // Se llama al método operator+ de la clase Vector
```

- El polimorfismo en tiempo de ejecución se resuelve en la fase de ejecución, y se basa en la herencia y el enlace dinámico. La herencia consiste en definir nuevas clases a partir de otras ya existentes, reutilizando su código y añadiendo nuevas funcionalidades. El enlace dinámico consiste en que el comportamiento de un objeto depende de su tipo real, y no del tipo de la variable que lo referencia. Para lograr esto, se usa la palabra clave virtual, que indica que el método puede ser redefinido por las clases derivadas [3]. Por ejemplo, se tiene el código extraido con ayuda de Copilot:

```cpp
// Definimos una clase base llamada Figura, que representa una figura geométrica
class Figura {

  protected: // Los atributos protegidos se pueden acceder desde las clases derivadas
    double area; // El área de la figura

  public:
    // Constructor de la clase Figura, que recibe el área como parámetro
    Figura(double a) {
      area = a;
    }
};

// Definimos una clase derivada llamada Circulo, que hereda de la clase Figura
class Circulo : public Figura { // Usamos la palabra clave public para indicar que hereda de Figura

  private: // Los atributos privados solo se pueden acceder desde la misma clase
    double radio; // El radio del círculo

  public:
    // Constructor de la clase Circulo, que recibe el radio como parámetro
    // y llama al constructor de la clase Figura con el área calculada
    Circulo(double r) : Figura(3.14 * r * r) {
      radio = r;
    }

    // Método para mostrar el área del círculo, que redefine el método de la clase Figura
    void mostrarArea() {
      cout << "El área del círculo de radio " << radio << " es " << area << endl;
    }
};

// Definimos una clase derivada llamada Cuadrado, que hereda de la clase Figura
class Cuadrado : public Figura { // Usamos la palabra clave public para indicar que hereda de Figura

  private: // Los atributos privados solo se pueden acceder desde la misma clase
    double lado; // El lado del cuadrado

  public:
    // Constructor de la clase Cuadrado, que recibe el lado como parámetro
    // y llama al constructor de la clase Figura con el área calculada
    Cuadrado(double l) : Figura(l * l) {
      lado = l;
    }

    // Método para mostrar el área del cuadrado, que redefine el método de la clase Figura
    void mostrarArea() {
      cout << "El área del cuadrado de lado " << lado << " es " << area << endl;
    }
};

// Creamos un objeto de la clase Circulo
Circulo c(2);

// Creamos un objeto de la clase Cuadrado
Cuadrado q(3);

// Llamamos al método mostrarArea
c.mostrarArea(); // Se llama al método de la clase Circulo

// Llamamos al método mostrarArea
q.mostrarArea(); // Se llama al método de la clase Cuadrado
```

5. **Abstracción:** ¿Cómo se relaciona la abstracción con la programación orientada a objetos? Proporciona ejemplos de cómo aplicar la abstracción en un contexto de programación.

La abstracción es uno de los conceptos clave de la programación orientada a objetos (POO), que consiste en simplificar la realidad, seleccionando solo las propiedades y comportamientos esenciales de cada objeto, e ignorando los detalles irrelevantes. La abstracción permite crear modelos más organizados, comprensibles y reutilizables del mundo real, al alinear más estrechamente el código con cómo vemos y categorizamos las entidades y los conceptos [4].

Para aplicar la abstracción en un contexto de programación, se pueden seguir los siguientes pasos:

- Identificar el problema o el sistema que se quiere modelar, y los requisitos funcionales y no funcionales que debe cumplir.

- Analizar el dominio del problema o del sistema, y extraer las entidades o los conceptos involucrados, así como sus características y sus relaciones.

- Definir las clases que representan las entidades o los conceptos, y asignarles los atributos y los métodos que definen sus propiedades y sus comportamientos. Seleccionar solo los atributos y los métodos relevantes para el problema o el sistema, y omitir los que no aportan valor o complejidad innecesaria.

- Establecer los niveles de acceso de los atributos y los métodos, usando modificadores como public, private o protected, para controlar qué información se expone y qué información se oculta. Esto se conoce como encapsulamiento, y es una forma de implementar la abstracción.

- Usar la herencia y el polimorfismo para crear jerarquías de clases, y aprovechar el código existente para definir clases más específicas o más generales. Esto permite crear abstracciones de mayor o menor nivel, según el grado de detalle que se quiera manejar.

Un ejemplo, creado utilizando copilot, de cómo aplicar la abstracción en un contexto de programación sería el siguiente:

```cpp
// Supongamos que queremos modelar un sistema de gestión de una clínica veterinaria
// Identificamos algunas entidades o conceptos relevantes: Animal, Cliente, Cita, Veterinario, etc.
// Definimos una clase abstracta llamada Animal, que representa una abstracción de un animal genérico
class Animal {

  protected:    // Los atributos protegidos se pueden acceder desde las clases derivadas
    string nombre;  // El nombre del animal
    string especie; // La especie del animal
    int edad;       // La edad del animal en años

  public:       // Los métodos públicos se pueden acceder desde cualquier parte
    // Constructor de la clase Animal, que recibe el nombre, la especie y la edad como parámetros
    Animal(string n, string e, int a) {
      nombre = n;
      especie = e;
      edad = a;
    }
};

// Definimos una clase derivada llamada Perro, que hereda de la clase Animal
class Perro : public Animal { // Usamos la palabra clave public para indicar que hereda de Animal
  
  private:      // Los atributos privados solo se pueden acceder desde la misma clase
    string raza;    // La raza del perro

  public:       // Los métodos públicos se pueden acceder desde cualquier parte
    // Constructor de la clase Perro, que recibe el nombre, la edad y la raza como parámetros
    // y llama al constructor de la clase Animal con el nombre, la especie "Perro" y la edad
    Perro(string n, int a, string r) : Animal(n, "Perro", a) {
      raza = r;
    }

    // Método para mostrar la información del perro, que redefine el método de la clase Animal
    void mostrarInfo() {
      cout << "Nombre: " << nombre << endl;
      cout << "Especie: " << especie << endl;
      cout << "Edad: " << edad << endl;
      cout << "Raza: " << raza << endl;
    }
};

// Definimos una clase derivada llamada Gato, que hereda de la clase Animal
class Gato : public Animal { // Usamos la palabra clave public para indicar que hereda de Animal

  private:      // Los atributos privados solo se pueden acceder desde la misma clase
    string color;   // El color del gato

  public:       // Los métodos públicos se pueden acceder desde cualquier parte
    // Constructor de la clase Gato, que recibe el nombre, la edad y el color como parámetros
    // y llama al constructor de la clase Animal con el nombre, la especie "Gato" y la edad
    Gato(string n, int a, string c) : Animal(n, "Gato", a) {
      color = c;
    }

    // Método para mostrar la información del gato, que redefine el método de la clase Animal
    void mostrarInfo() {
      cout << "Nombre: " << nombre << endl;
      cout << "Especie: " << especie << endl;
      cout << "Edad: " << edad << endl;
      cout << "Color: " << color << endl;
    }
};

// Creamos un objeto de la clase Perro
Perro perrito("Tini", 1, "Salchicha");

// Creamos un objeto de la clase Gato
Gato gatito("Heroica", 6, "Negro");

// Llamamos al método mostrarInfo
perrito.mostrarInfo();  // Se llama al método de la clase Perro

// Llamamos al método mostrarInfo usando el puntero
gatito.mostrarInfo();   // Se llama al método de la clase Gato
```

6. **Clases y Objetos:** Diferencia entre una clase y un objeto en programación orientada a objetos. Proporciona un ejemplo de cada uno.

Una clase y un objeto son dos conceptos fundamentales de la POO, que se relacionan entre sí de la siguiente manera:

- Una **clase** es una plantilla o un modelo que define las propiedades y los comportamientos comunes de un tipo de dato. Una clase se puede considerar como una abstracción de una entidad o un concepto del mundo real, que encapsula sus características y sus operaciones [5].

- Un **objeto** es una instancia o una copia de una clase, que tiene valores específicos para sus propiedades y puede ejecutar sus comportamientos. Un objeto se puede considerar como una representación concreta de una entidad o un concepto del mundo real, que tiene un estado y un comportamiento propios [5].

Un ejemplo de una clase y un objeto en C++ sería el siguiente:

```cpp
// Definimos una clase llamada Persona, que tiene dos atributos: nombre y edad
class Persona {
  private:  // Los atributos privados solo se pueden acceder desde la misma clase
    string nombre;  // Nomber de la persona
    int edad;       // Edad de la persona

  public:   // Los métodos públicos se pueden acceder desde cualquier parte
    // Constructor de la clase Persona, que recibe el nombre y la edad como parámetros
    Persona(string n, int e) {
      nombre = n;
      edad = e;
    }

    // Método para mostrar los datos de la persona
    void mostrar() {
      cout << "Yehohnathan: " << nombre << endl;
      cout << "Edad: " << edad << endl;
    }
};

// Creamos un objeto de la clase Persona
Persona joven("Yehohnathan", 21);

// Llamamos al método mostrar del objeto
joven.mostrar();
```

En este ejemplo, la clase Persona es una abstracción de una persona genérica, que tiene dos atributos: nombre y edad. El objeto joven es una instancia de la clase Persona, que tiene valores concretos para sus atributos: "Yehohnathan" y 21. El objeto joven puede acceder al método mostrar de la clase Persona, que imprime sus datos por pantalla.

7. **Métodos Virtuales:** Explica la importancia de los métodos virtuales en C++ y cómo se utilizan en la implementación de polimorfismo.

Los métodos virtuales se declaran con la palabra clave virtual en la clase base, y se redefinen en las clases derivadas con la misma firma. Esto indica al compilador que genere código que mire al tipo del objeto apuntado (no del puntero o la referencia) en tiempo de ejecución y use esta información para seleccionar la versión apropiada del método. Son importantes porque permiten aprovechar la herencia y el enlace dinámico, es decir, la posibilidad de que un puntero o una referencia de la clase base pueda apuntar o referenciar a un objeto de la clase derivada, y ejecutar el método adecuado según su tipo real [3].

Un ejemplo uilizando la misma clase Figura y sus clases derivadas visto anteriormente:

```cpp
// Definimos una clase base llamada Figura, que representa una figura geométrica
class Figura {

  protected:    // Los atributos protegidos se pueden acceder desde las clases derivadas
    double area;    // El área de la figura
    string figura;  // Nombre de la figura

  public:       // Los métodos públicos se pueden acceder desde cualquier parte
    // Constructor de la clase Figura, que recibe el área como parámetro
    Figura(double a, string s) {
      area = a;
      string = s;
    }

    // Método virtual para mostrar el área de la figura
    // Al ser virtual, puede ser redefinido por las clases derivadas
    virtual void mostrarArea() {
      cout << "El área de la figura es " << figura << endl;
    }
};

// Definimos una clase derivada llamada Circulo, que hereda de la clase Figura
class Circulo : public Figura { // Usamos la palabra clave public para indicar que hereda de Figura

  private: // Los atributos privados solo se pueden acceder desde la misma clase
    double radio; // El radio del círculo

  public:       // Los métodos públicos se pueden acceder desde cualquier parte
    // Constructor de la clase Circulo, que recibe el radio como parámetro
    // y llama al constructor de la clase Figura con el área calculada
    Circulo(double r) : Figura(3.14 * r * r) {
      radio = r;
    }

    // Método para mostrar el área del círculo, que redefine el método de la clase Figura
    void mostrarArea() {
      cout << "El área del círculo de radio " << radio << " es " << area << endl;
    }
};

// Definimos una clase derivada llamada Cuadrado, que hereda de la clase Figura
class Cuadrado : public Figura { // Usamos la palabra clave public para indicar que hereda de Figura

  private: // Los atributos privados solo se pueden acceder desde la misma clase
    double lado; // El lado del cuadrado

  public:       // Los métodos públicos se pueden acceder desde cualquier parte
    // Constructor de la clase Cuadrado, que recibe el lado como parámetro
    // y llama al constructor de la clase Figura con el área calculada
    Cuadrado(double l) : Figura(l * l) {
      lado = l;
    }

    // Método para mostrar el área del cuadrado, que redefine el método de la clase Figura
    void mostrarArea() {
      cout << "El área del cuadrado de lado " << lado << " es " << area << endl;
    }
};

// Creamos un objeto de la clase Circulo
Circulo c(2);

// Creamos un objeto de la clase Cuadrado
Cuadrado q(3);

// Creamos un puntero de la clase Figura
Figura* f;

// Apuntamos el puntero a un objeto de la clase Circulo
f = &c;
// Llamamos al método mostrarArea usando el puntero
f->mostrarArea(); // Se llama al método de la clase Circulo

// Apuntamos el puntero a un objeto de la clase Cuadrado
f = &q;

// Llamamos al método mostrarArea usando el puntero
f->mostrarArea(); // Se llama al método de la clase Cuadrado
```

En este ejemplo, la clase Figura declara el método mostrarArea como virtual, y las clases Circulo y Cuadrado lo redefinen para mostrar el área de cada figura. Al usar un puntero de la clase Figura para apuntar a objetos de las clases derivadas, se llama al método mostrarArea correspondiente al tipo real del objeto, gracias al uso de métodos virtuales.

8. **Constructores y Destructores:** ¿Cuál es el propósito de un constructor y un destructor en una clase? Proporciona ejemplos de su uso.

Un constructor y un destructor son funciones de miembros especiales de una clase, que se utilizan para construir y destruir objetos de esa clase. El propósito de un constructor es inicializar los atributos de un objeto cuando se crea, asignando memoria si es necesario y ejecutando cualquier otra operación requerida. El propósito de un destructor es liberar los recursos asociados a un objeto cuando se destruye, desasignando memoria si es necesario y ejecutando cualquier otra operación de limpieza [6].

Un ejemplo de uso de un constructor y un destructor en C++ sería el siguiente:

```cpp
// Definimos una clase llamada Punto, que representa un punto en el plano cartesiano
class Punto {

  private:      // Los atributos privados solo se pueden acceder desde la misma clase
    double x;       // La coordenada x del punto
    double y;       // La coordenada y del punto

  public:       // Los métodos públicos se pueden acceder desde cualquier parte
    // Constructor de la clase Punto, que recibe las coordenadas como parámetros
    Punto(double x, double y) {
      // Asignamos los valores de los parámetros a los atributos del objeto
      this->x = x;
      this->y = y;
      // Mostramos un mensaje indicando que se ha creado el objeto
      cout << "Se ha creado el punto" << endl;
    }

    // Destructor de la clase Punto, y es de suma importancia el uso del ~
    ~Punto() {
      // Mostramos un mensaje indicando que se ha destruido el objeto
      cout << "Se ha destruido el punto" << endl;
    }
    
    // Método para mostrar las coordenadas del punto
    void mostrar() {
      cout << "El punto tiene las coordenadas (" << x << ", " << y << ")" << endl;
    }
};

// Creamos un objeto de la clase Punto
Punto p(1, 2); // Se llama al constructor de la clase Punto

// Llamamos al método mostrar del objeto
p.mostrar();
// El objeto sale del ámbito y se destruye
// Se llama al destructor de la clase Punto
```

El resultado de ejecutar este código sería:

```
Se ha creado el punto
El punto tiene las coordenadas (1, 2)
Se ha destruido el punto
```

Como se puede observar, el constructor de la clase Punto se ejecuta cuando se crea el objeto p, y el destructor se ejecuta cuando el objeto p sale del ámbito. El constructor inicializa los atributos x e y con los valores pasados como parámetros, y el destructor no hace nada más que mostrar un mensaje.


9. **Sobrecarga de Operadores:** Explica qué es la sobrecarga de operadores y proporciona un ejemplo de cómo se implementa en C++.

La sobrecarga de operadores es una característica de C++ que permite redefinir el significado y el comportamiento de algunos de los operadores existentes en el lenguaje, para que puedan aplicarse a objetos de clases definidas por el usuario. La sobrecarga de operadores facilita la extensión de las operaciones representadas por los operadores a más tipos de datos, y mejora la legibilidad y la elegancia del código, al permitir que el código se parezca más a las expresiones matemáticas o lógicas.

Para implementar la sobrecarga de operadores en C++, se debe declarar y definir una función especial con el nombre operator x, donde x es el símbolo del operador que se quiere sobrecargar. Esta función puede ser una función miembro o una función global, y debe tener como parámetros los operandos del operador. El compilador elige la versión adecuada de la función según los tipos de los operandos³.

Un ejemplo de cómo se implementa la sobrecarga de operadores en C++ sería el siguiente, con ayuda de copilot:

```cpp
// Definimos una clase llamada Vector, que representa un vector matemático
class Vector {

  private:  // Los atributos privados solo se pueden acceder desde la misma clase
    double x;   // La coordenada x del vector
    double y;   // La coordenada y del vector

  public:   // Los métodos públicos se pueden acceder desde cualquier parte
    // Constructor de la clase Vector, que recibe las coordenadas como parámetros
    Vector(double x, double y) {
      this->x = x;
      this->y = y;
    }

    // Sobrecargamos el operador + para sumar dos vectores
    Vector operator+(const Vector& v) {
      // Devolvemos un nuevo vector con la suma de las coordenadas
      return Vector(x + v.x, y + v.y);
    }

    // Sobrecargamos el operador * para multiplicar un vector por un escalar
    Vector operator*(double k) {
      // Devolvemos un nuevo vector con las coordenadas multiplicadas por el escalar
      return Vector(x * k, y * k);
    }

    // Sobrecargamos el operador << para mostrar un vector por pantalla junto
    // con el uso del ostream que representa un flujo de datos de salida
    friend ostream& operator<<(ostream& os, const Vector& v) {
      // Mostramos el vector con el formato (x, y)
      os << "(" << v.x << ", " << v.y << ")";
      return os;
    }
};

// Creamos dos objetos de la clase Vector
Vector v1(1, 2);
Vector v2(3, 4);

// Sumamos los dos vectores usando el operador +
Vector v3 = v1 + v2; // Se llama al método operator+ de la clase Vector

// Multiplicamos el vector resultante por un escalar usando el operador *
Vector v4 = v3 * 2; // Se llama al método operator* de la clase Vector

// Mostramos los vectores por pantalla usando el operador <<
cout << "v1 = " << v1 << endl; // Se llama a la función operator<< global
cout << "v2 = " << v2 << endl;
cout << "v3 = " << v3 << endl;
cout << "v4 = " << v4 << endl;
```

El resultado de ejecutar este código sería:

```
v1 = (1, 2)
v2 = (3, 4)
v3 = (4, 6)
v4 = (8, 12)
```

Como se puede observar, la clase Vector sobrecarga los operadores +, * y << para definir las operaciones de suma, multiplicación y salida de vectores. Estos operadores se pueden usar con objetos de la clase Vector de la misma forma que se usan con tipos de datos primitivos, lo que hace que el código sea más intuitivo y natural.


10. **Templates:** Describe el concepto de templates en C++. ¿En qué situaciones sería útil utilizar templates?

Los templates o plantillas son una característica de C++ que permite definir clases o funciones genéricas, que pueden operar con diferentes tipos de datos sin tener que repetir el código para cada tipo. Los templates facilitan la programación genérica, es decir, la creación de software que es independiente del tipo de dato y que se adapta a las necesidades del usuario [8].

El concepto de templates se basa en el uso de parámetros de tipo, que son marcadores de posición para los tipos de datos que se usarán en la clase o función. Estos parámetros se especifican entre corchetes angulares (< >) después del nombre de la clase o función, y se pueden usar como si fueran tipos normales en la definición de la clase o función [8]. Por ejemplo:

```cpp
// Definimos un template de clase llamado Par, que representa un par de valores de cualquier tipo
template <typename T1, typename T2>
class Par {

  private:  // Los atributos privados solo se pueden acceder desde la misma clase
    T1 primero; // El primer valor del par
    T2 segundo; // El segundo valor del par

  public:   // Los métodos públicos se pueden acceder desde cualquier parte
    // Constructor de la clase Par, que recibe los valores como parámetros
    Par(T1 p, T2 s) {
      primero = p;
      segundo = s;
    }

    // Método para obtener el primer valor del par
    T1 getPrimero() {
      return primero;
    }

    // Método para obtener el segundo valor del par
    T2 getSegundo() {
      return segundo;
    }
};

// Definimos un template de función llamado maximo, que devuelve el máximo de dos valores de cualquier tipo
template <typename T>
T maximo(T a, T b) {
  return a > b ? a : b;
}
int main() {
    // Creamos una instancia del template de clase Par con los tipos int y string
    Par<int, string> p1(1, "uno");

    // Creamos una instancia del template de función maximo con el tipo double
    double m = maximo<double>(2.5, 3.5);

    return 0;
}
```

En el código anterior, se definen dos templates: uno de clase y otro de función. El template de clase Par tiene dos parámetros de tipo: T1 y T2, que representan los tipos de los valores que forman el par. El template de función maximo tiene un parámetro de tipo: T, que representa el tipo de los valores que se comparan. Estos parámetros se pueden sustituir por cualquier tipo de dato válido en C++, como int, double, string, etc. Además que se muestra formas en las que se pueden crear instancias para el uso de las mismas.

Los templates son útiles en situaciones en las que se quiere escribir código que sea reutilizable, flexible y eficiente, y que no dependa de un tipo de dato específico. Algunos ejemplos de uso de templates son:

- La implementación de estructuras de datos genéricas, como listas, pilas, colas, árboles, etc., que pueden almacenar y manipular elementos de cualquier tipo.

- La implementación de algoritmos genéricos, como los de ordenación, búsqueda, filtrado, etc., que pueden aplicarse a colecciones de elementos de cualquier tipo.

- La implementación de clases o funciones que realizan operaciones matemáticas, lógicas o aritméticas con valores de cualquier tipo.

- La implementación de clases o funciones que realizan operaciones de entrada/salida con valores de cualquier tipo.

11. **Memoria Dinámica:** ¿Qué es la memoria dinámica en C++ y cuándo se utiliza comúnmente?

La memoria dinámica en C++ es una forma de gestionar la memoria que permite reservar y liberar espacio en tiempo de ejecución, es decir, durante la ejecución del programa. La memoria dinámica se utiliza cuando no se conoce de antemano el tamaño o el número de los datos que se van a manejar, o cuando se quiere optimizar el uso de la memoria, evitando desperdiciar o faltar espacio. Las variables que se utilizan en la memoria dinámica se reserva en una zona especial de la memoria llamada heap o montículo, que se diferencia de la pila o stack, donde se almacenan las variables estáticas, es decir, las que se declaran en el programa y tienen un tamaño fijo.

Para reservar memoria dinámica en C++, se usa el operador `new`, que devuelve un puntero al espacio asignado. Para liberar la memoria dinámica, se usa el operador delete, que recibe el puntero al espacio a liberar. Es importante liberar la memoria dinámica que ya no se usa, para evitar fugas de memoria o memory leaks, que pueden causar problemas de rendimiento o errores en el programa.

12. **Diferencia entre `new` y `malloc` en C++:** ¿Cuándo debería utilizar uno sobre el otro?

La diferencia entre `new` y `malloc` en C++ es que `new` es un operador que solo se puede usar en C++, mientras que `malloc` es una función estándar de C que se puede usar tanto en C como en C++ [9]. Ambos sirven para reservar memoria dinámica pero tienen algunas diferencias importantes [9]:

- `new` llama al constructor del objeto que se crea, y `delete` llama al destructor del objeto que se destruye, mientras que `malloc` y `free` solo asignan y liberan la memoria, sin ejecutar ningún código del objeto.

- `new` devuelve un puntero al tipo de dato que se solicita, mientras que `malloc` devuelve un puntero a `void`, que debe ser convertido al tipo adecuado.

- `new` lanza una excepción de tipo `bad_alloc` si no hay suficiente memoria disponible, mientras que `malloc` devuelve un puntero nulo.

- `new` permite sobrecargar su comportamiento mediante el operador de sobrecarga, mientras que `malloc` no lo permite legalmente.

En general, se recomienda usar `new` y `delete` en C++, ya que son más seguros, más flexibles y más eficientes que `malloc` y `free`. Solo se debería usar `malloc` y `free` en C++, cuando haya alguna razón específica para hacerlo, como por ejemplo, cuando se trabaja con código heredado de C, o cuando se necesita una compatibilidad con archivos de cabecera de C [9].

13. **Fuga de Memoria (Memory Leak):** ¿Qué es una fuga de memoria y cómo puede evitarse en programas en C++?

Una fuga de memoria es una situación en la que se reserva memoria dinámica, es decir, memoria que se asigna y se libera en tiempo de ejecución, y no se libera cuando ya no se necesita [10]. Esto provoca que la memoria se desperdicie y que el programa consuma más recursos de los necesarios, lo que puede afectar al rendimiento, la estabilidad y la seguridad del programa.

Para evitar las fugas de memoria en programas en C++, se deben seguir algunas buenas prácticas, como:

- Usar el operador `delete` o `delete []` para liberar la memoria asignada con el operador `new` o `new []`, respectivamente.

- Usar punteros inteligentes, como `unique_ptr`, `shared_ptr` o `weak_ptr`, que gestionan automáticamente la memoria asignada y la liberan cuando el puntero sale de su ámbito o deja de ser referenciado.

- Usar la técnica RAII (Resource Acquisition Is Initialization), que consiste en encapsular la adquisición y liberación de recursos, incluida la memoria, dentro de objetos cuyo tiempo de vida está determinado por el ámbito. Un copcepto parecido al destructor presente en las clases.

- Usar contenedores de la biblioteca estándar, como `vector`, `list` o `map`, que gestionan la memoria de forma interna y evitan la asignación manual de memoria.


14. **Punteros Inteligentes (Smart Pointers):** Explica el concepto de punteros inteligentes y proporciona ejemplos de su uso.

Los punteros inteligentes son una característica de C++ que permite gestionar la memoria dinámica de forma automática y segura, evitando problemas como fugas de memoria, punteros colgantes o accesos inválidos. Los punteros inteligentes son clases que envuelven a un puntero sin formato y se encargan de asignar y liberar la memoria cuando el puntero inteligente se crea o se destruye [11].

Los punteros inteligentes se pueden clasificar en tres tipos principales, según su semántica de propiedad [11]:

- `unique_ptr`: Permite exactamente un único propietario del puntero subyacente. No se puede copiar, solo se puede mover. Se usa para expresar la propiedad exclusiva de un recurso.

- `shared_ptr`: Permite varios propietarios del puntero subyacente. Se puede copiar y mover. Usa un contador de referencias para saber cuántos propietarios hay. Se usa para expresar la propiedad compartida de un recurso.

- `weak_ptr`: Permite acceder al puntero subyacente sin ser propietario. No se puede desreferenciar directamente, solo se puede convertir a un `shared_ptr`. No incrementa el contador de referencias. Se usa para romper ciclos de referencias entre `shared_ptr`.

Un ejemplo de uso de punteros inteligentes en C++ sería el siguiente, haciendo uso de copilot debido a su complejidad:

```cpp
#include <iostream>
#include <memory>       // Para usar los punteros inteligentes
using namespace std;

// Definimos una clase llamada Persona, que tiene un nombre y una edad
class Persona {
  private:
    string nombre;
    int edad;

  public:
    // Constructor de la clase Persona, que recibe el nombre y la edad como parámetros
    Persona(string n, int e) {
      nombre = n;
      edad = e;
      cout << "\nSe ha creado la persona " << nombre << endl;
    }

    // Destructor de la clase Persona
    ~Persona() {
      cout << "\nSe ha destruido la persona " << nombre << endl;
    }

    // Método para mostrar los datos de la persona
    void mostrar() {
      cout << "Nombre: " << nombre << endl;
      cout << "Edad: " << edad << endl;
    }
};

int main() {
  // Creamos un puntero inteligente de tipo unique_ptr que apunta a una persona
  unique_ptr<Persona> p1(new Persona("Juan", 25));

  // Llamamos al método mostrar del objeto apuntado por el puntero inteligente
  p1->mostrar();

  // Creamos otro puntero inteligente de tipo unique_ptr que apunta a otra persona
  unique_ptr<Persona> p2(new Persona("Ana", 23));

  // Llamamos al método mostrar del objeto apuntado por el puntero inteligente
  p2->mostrar();

  // No podemos copiar un unique_ptr, pero podemos transferir su propiedad usando move
  // p1 = p2; daría un error de compilación
  p1 = move(p2); // Esto transfiere la propiedad de p2 a p1, y p2 queda vacío

  // Creamos un puntero inteligente de tipo shared_ptr que apunta a una persona
  shared_ptr<Persona> p3(new Persona("Luis", 27));

  // Llamamos al método mostrar del objeto apuntado por el puntero inteligente
  p3->mostrar();

  // Creamos otro puntero inteligente de tipo shared_ptr que apunta al mismo objeto que p3
  shared_ptr<Persona> p4 = p3; // Esto incrementa el contador de referencias de p3
  
  // Llamamos al método mostrar del objeto apuntado por el puntero inteligente
  p4->mostrar();
  
  // Creamos un puntero inteligente de tipo weak_ptr que apunta al mismo objeto que p3 y p4
  weak_ptr<Persona> p5 = p3; // Esto no incrementa el contador de referencias de p3
  
  // No podemos llamar al método mostrar directamente desde el weak_ptr, tenemos que convertirlo a un shared_ptr
  // p5->mostrar(); daría un error de compilación
  shared_ptr<Persona> p6 = p5.lock(); // Esto crea un shared_ptr a partir del weak_ptr
  
  // Llamamos al método mostrar del objeto apuntado por el puntero inteligente
  p6->mostrar();

  return 0;
}
```

El resultado de ejecutar este código sería:

```
Se ha creado la persona Juan
Nombre: Juan
Edad: 25

Se ha creado la persona Ana
Nombre: Ana
Edad: 23

Se ha destruido la persona Juan

Se ha creado la persona Luis
Nombre: Luis
Edad: 27
Nombre: Luis
Edad: 27
Nombre: Luis
Edad: 27

Se ha destruido la persona Ana

Se ha destruido la persona Luis
```

Como se puede observar, los punteros inteligentes se encargan de llamar al destructor de la persona cuando ya no hay ningún propietario del puntero subyacente, lo que evita tener que usar `delete` manualmente.


15. **Diferencia entre `delete` y `delete[]` en C++:** ¿En qué contexto se utilizaría cada uno?

La diferencia entre `delete` y `delete[]` en C++ es que `delete` se usa para liberar la memoria asignada con `new` para un solo objeto, mientras que `delete[]` se usa para liberar la memoria asignada con `new[]` para un array de objetos. Por ejemplo:

```cpp
int main() {
    // Creamos un puntero a un entero y le asignamos memoria dinámica con new
    int* p = new int;

    // Hacemos algo con el puntero
    *p = 10;

    // Se imprime el contenido del puntero en la terminal
    cout << *p << endl;

    // Liberamos la memoria con delete
    delete p;

    // Creamos un puntero a un array de enteros y le asignamos memoria dinámica con new[],
    // en donde guardaría teóricamente 5 espacios de 4 bytes por ser enteros.
    int* q = new int[5];

    // Hacemos algo con el puntero
    for (int i = 0; i < 5; i++) {
      q[i] = i + 1;

      // Se imprime el contenido del puntero
      cout << q[i] << " ";
    }
    cout << endl;

    // Liberamos la memoria con delete[]
    delete[] q;

    return 0;
}
```

16. **Algoritmos de Ordenamiento:** ¿Qué es un algoritmo de ordenamiento y por qué son importantes en programación?

Un algoritmo de ordenamiento es un conjunto de instrucciones que toma un arreglo o una lista como entrada y organiza los elementos en un orden particular, como numérico o alfabético, ascendente o descendente. Son importantes en programación porque permiten optimizar la búsqueda y el acceso a la información almacenada en bases de datos, listas o matrices, así como facilitar la extensión de otras operaciones a más tipos de datos. 

Algunos ejemplos de algoritmos de ordenamiento son la ordenación por selección (SelectSort), la ordenación por burbuja (BubbleSort), la ordenación por inserción, la ordenación por combinación, la ordenación rápida (QuickSort) y la ordenación por montículo.


17. **Bubble Sort:** Explica el funcionamiento del algoritmo de ordenamiento "Bubble Sort". ¿Cuál es su complejidad temporal en el peor caso?

El algoritmo de ordenamiento Bubble Sort es un método simple que consiste en comparar cada elemento de una lista con el siguiente, e intercambiarlos de posición si están en el orden incorrecto. Este proceso se repite varias veces hasta que no se requieren más intercambios, lo que significa que la lista está ordenada.

La complejidad temporal del algoritmo en el peor caso es de O(n^2), lo que significa que el tiempo de ejecución aumenta cuadráticamente con el tamaño de la lista. Esto ocurre cuando la lista está ordenada de forma inversa, y se requieren el máximo número de comparaciones e intercambios.

![Uso del Bubble Sort](https://www.w3resource.com/w3r_images/bubble-short.png)

18. **QuickSort:** Describe el algoritmo de ordenamiento "QuickSort". ¿Cuál es su ventaja principal sobre otros algoritmos de ordenamiento?

El algoritmo de ordenamiento "QuickSort" es un método basado en la técnica de "divide y vencerás", que consiste en lo siguiente:

- Elegir un elemento de la lista al que llamaremos pivote.

- Particionar la lista en dos sublistas, una con los elementos menores o iguales que el pivote, y otra con los elementos mayores o iguales que el pivote.

- Ordenar recursivamente cada sublista, aplicando el mismo proceso.

- Unir las sublistas ordenadas para obtener la lista final ordenada.

La ventaja principal de QuickSort sobre otros algoritmos de ordenamiento es que es muy rápido y eficiente en el caso promedio, ya que tiene una complejidad temporal de O(n log n) en el mejor de los casos y una complejidad temporal de O(n^2), donde n es el número de elementos de la lista.

![Uso del Quick Sort](https://favtutor.com/resources/images/uploads/mceu_46432632011643441346270.png)

19. **Diferencia entre Ordenamiento Estable e Inestable:** ¿Cuál es la diferencia entre un algoritmo de ordenamiento estable y uno inestable? Proporciona ejemplos de cada uno.

La diferencia entre un algoritmo de ordenamiento estable y uno inestable es que un algoritmo de ordenamiento estable mantiene el orden relativo de los elementos que son iguales según el criterio de ordenación, mientras que un algoritmo de ordenamiento inestable puede alterar ese orden [12]. A continuación se obtiene un ejemplo obtenido con Copilot:

Supongamos que tenemos una lista de personas con su nombre y su edad, y queremos ordenarla por edad de menor a mayor. La lista original sería:

```
Juan, 25
Ana, 23
Luis, 27
Pedro, 25
```

- Si usamos un algoritmo de ordenamiento estable, como la ordenación por inserción, el resultado sería:

```
Ana, 23
Juan, 25
Pedro, 25
Luis, 27
```

Como se puede observar, el orden relativo de Juan y Pedro se ha mantenido, ya que ambos tienen la misma edad y Juan estaba antes que Pedro en la lista original.

- Si usamos un algoritmo de ordenamiento inestable, como la ordenación rápida, el resultado podría ser:

```
Ana, 23
Pedro, 25
Juan, 25
Luis, 27
```

Como se puede observar, el orden relativo de Juan y Pedro se ha alterado, ya que Pedro ha quedado antes que Juan, a pesar de que tenían la misma edad y Juan estaba antes que Pedro en la lista original.

La importancia de la estabilidad de un algoritmo de ordenamiento depende de la aplicación que se le dé. En algunos casos, puede ser irrelevante, pero en otros, puede ser crucial. Por ejemplo, si se quiere ordenar una lista de registros por varios criterios, se debe usar un algoritmo de ordenamiento estable para preservar el orden de los criterios anteriores [12].

20. **Merge Sort:** Habla sobre el algoritmo de ordenamiento "Merge Sort". ¿Cuál es su complejidad temporal y en qué situaciones es preferible su uso?

El algoritmo de ordenamiento "Merge Sort" es un método basado en la técnica de "divide y vencerás", que consiste en lo siguiente [13]:

- Elegir un elemento de la lista al que llamaremos pivote.

- Particionar la lista en dos sublistas, una con los elementos menores o iguales que el pivote, y otra con los elementos mayores que el pivote.

- Ordenar recursivamente cada sublista, aplicando el mismo proceso.

- Unir las sublistas ordenadas para obtener la lista final ordenada.

La complejidad temporal del algoritmo en el caso promedio y en el peor caso es de O(n log n), donde n es el número de elementos de la lista. Esto significa que el tiempo de ejecución aumenta proporcionalmente al producto del número de elementos y el logaritmo del número de elementos [13].

El algoritmo de Merge Sort tiene algunas ventajas sobre otros algoritmos de ordenamiento, como:

- Es un algoritmo estable, es decir, que mantiene el orden relativo de los elementos que son iguales según el criterio de ordenación.

- Es un algoritmo de ordenamiento externo, es decir, que puede ordenar datos que no caben en la memoria principal, usando archivos auxiliares.

- Es un algoritmo fácilmente paralelizable, es decir, que se puede ejecutar en varios procesadores o hilos simultáneamente, aprovechando la división y la unión de las sublistas.

A pesar de poder sonar igual al algoritmo Quick Sort, la diferencia radica en que el merge sort es un algoritmo estable, es decir, que respeta el orden original de los elementos iguales, mientras que el quick sort es un algoritmo inestable, es decir, que puede alterar ese orden. El merge sort requiere más memoria adicional que el quick sort, ya que necesita crear una lista auxiliar para la fusión. El quick sort es más adecuado para ordenar listas pequeñas o casi ordenadas, mientras que el merge sort es más eficiente para ordenar listas grandes o desordenadas [14].

Otra diferencia entre el quick sort y el merge sort es que el quick sort es un algoritmo de ordenamiento que usa un elemento pivote para dividir la lista en dos partes y ordenarlas recursivamente, mientras que el merge sort es un algoritmo de ordenamiento que divide la lista en dos mitades, las ordena por separado y las fusiona [14].

![Uso del Merge Sort](https://th.bing.com/th/id/OIP.0UPWjRHiyYmwJh9N2pDTDQAAAA?rs=1&pid=ImgDetMain)

## Bibliografía:

[1] L. Jiménez, “Principios de la Programación Orientada a Objetos Explicados,” [En línea]. Disponible: https://leojimzdev.com/principios-de-la-programacion-orientada-a-objetos-explicados/. [Accedido: 14-Ene-2024].

[2] D. Lara, “Encapsulamiento en la programación orientada a objetos,” Styde.net, 07 jul. 2015. [En línea]. Disponible: https://styde.net/encapsulamiento-en-la-programacion-orientada-a-objetos/. [Accedido: 14-Ene-2024].

[3] Hektor Docs, “Polimorfismo en clases,” [En línea]. Disponible: https://docs.hektorprofe.net/cpp/11-clases/06-polimorfismo-clases/. [Accedido: 14-Ene-2024].

[4] D. Lara, “¿Qué es la abstracción en la programación orientada a objetos?” Styde.net, 07 jul. 2015. [En línea]. Disponible: https://styde.net/abstraccion-programacion-orientada-a-objetos/. [Accedido: 14-Ene-2024].

[5] The gamedev Traum, “Diferencias entre clase y objeto en programación,” [En línea]. Disponible: https://gamedevtraum.com/es/programacion-informatica/programacion-orientada-a-objetos/diferencia-entre-clase-y-objeto/. [Accedido: 14-Ene-2024].

[6] IBM, “Visión general de constructores y destructores (solo C++),” [En línea]. Disponible: https://www.ibm.com/docs/es/i/7.5?topic=only-overview-constructors-destructors-c. [Accedido: 14-Ene-2024].

[7] Microsoft, “Sobrecarga de operadores,” Microsoft Learn, 12 oct. 2023. [En línea]. Disponible: https://learn.microsoft.com/es-es/cpp/cpp/operator-overloading?view=msvc-170. [Accedido: 14-Ene-2024].

[8] Microsoft, “Plantillas (C++),” Microsoft Learn, 02 abr. 2023. [En línea]. Disponible: https://learn.microsoft.com/es-es/cpp/cpp/templates-cpp?view=msvc-170. [Accedido: 14-Ene-2024].

[9] S. Bhandari, “Diferencia entre Malloc y New,” 11 jun. 2023. [En línea]. Disponible: https://askanydifference.com/es/difference-between-malloc-and-new-with-table/. [Accedido: 14-Ene-2024].

[10] J. Córdova, “¿Cómo puedo detectar fugas de memoria en mi programa en C utilizando DEV C++?” Stack Overflow en español, 28 mar. 2017. [En línea]. Disponible: https://es.stackoverflow.com/questions/58659/cómo-puedo-detectar-fugas-de-memoria-en-mi-programa-en-c-utilizando-dev-c. [Accedido: 14-Ene-2024].

[11] Microsoft, “Punteros inteligentes (C++ moderno)” Microsoft Learn, 16 jun. 2023. [En línea]. Disponible: https://learn.microsoft.com/es-es/cpp/cpp/smart-pointers-modern-cpp?view=msvc-170. [Accedido: 14-Ene-2024].

[12] “Diferencias entre un algoritmo de ordenación y una red neuronal,” 07 jul. 2017. [En línea]. Disponible: https://dsentidades.blogspot.com/2017/07/diferencias-entre-un-algoritmo-de.html. [Accedido: 14-Ene-2024].

[13] DelftStack, “Merge Sort,” [En línea]. Disponible: https://www.delftstack.com/es/tutorial/algorithm/merge-sort/. [Accedido: 14-Ene-2024].

[14] B. Matos, “Merge y Quick Sort: conozca cuál es el mejor algoritmo,” Alura Cursos Online, 24 jun. 2022. [En línea]. Disponible: https://www.aluracursos.com/blog/merge-y-quick-sort-conozca-cual-es-el-mejor-algoritmo. [Accedido: 14-Ene-2024].