### Expresiones regulares

Las expresiones regulares (también conocidas como regex o regexp) son patrones utilizados para buscar y manipular cadenas de texto de una manera más flexible y poderosa. Permiten realizar búsquedas de patrones dentro de texto, validar cadenas, realizar sustituciones y mucho más.


`Caracteres literales:` Los caracteres que no son especiales coinciden literalmente con sí mismos. Por ejemplo, el carácter a en una expresión regular coincidirá con la letra "a" en el texto.

`Punto (.)`: El punto coincide con cualquier carácter, excepto un salto de línea. Por ejemplo, la expresión regular ca. coincidirá con "cat", "car", "cap", etc.

`Asterisco (*)`: El asterisco representa cero o más repeticiones del elemento anterior. Por ejemplo, la expresión regular ca*t coincidirá con "ct", "cat", "caat", "caa...t", etc.

`Más (+)`: El más representa una o más repeticiones del elemento anterior. Por ejemplo, la expresión regular ca+t coincidirá con "cat", "caat", "caa...t", etc., pero no coincidirá con "ct".

`Interrogación (?)`: La interrogación indica que el elemento anterior es opcional (puede estar presente una vez o no estar presente en absoluto). Por ejemplo, la expresión regular colou?r coincidirá con "color" y "colour".

`Corchetes ([])`: Los corchetes se utilizan para especificar un conjunto de caracteres permitidos en esa posición. Por ejemplo, [aeiou] coincidirá con cualquier vocal en el texto.

`Rango en corchetes (-)`: Dentro de los corchetes, se puede especificar un rango de caracteres utilizando el guión. Por ejemplo, [a-z] coincidirá con cualquier letra minúscula, y [0-9] coincidirá con cualquier dígito.

`Negación en corchetes (^)`: Si un carácter ^ aparece como primer carácter dentro de los corchetes, significa que se niega el conjunto de caracteres. Por ejemplo, [^0-9] coincidirá con cualquier carácter que no sea un dígito.

`Grupos (())`: Los paréntesis se utilizan para agrupar elementos en subexpresiones. Esto permite aplicar cuantificadores a grupos enteros y capturar subcadenas coincidentes. Por ejemplo, (ab)+ coincidirá con "ab", "abab", "ababab", etc., y capturará "ab" como grupo coincidente.

`Alternancia (|)`: El símbolo pipe | se utiliza para expresar alternativas. Por ejemplo, apple|banana coincidirá con "apple" o "banana".

`Anclas (^ y \$)`: El carácter ^ se usa para indicar que la coincidencia debe comenzar al principio de la cadena, mientras que el carácter $ se usa para indicar que la coincidencia debe terminar al final de la cadena. Por ejemplo, ^abc coincidirá solo si la cadena comienza con "abc", y xyz\$ coincidirá solo si la cadena 
termina con "xyz".

`Escape (\)`: Si deseas buscar un carácter especial de expresión regular como un carácter literal, debes escaparlo con una barra invertida \. Por ejemplo, \. coincidirá con un punto literal en el texto.

***Anchor:***
| Sintaxis | Descripción                                      | Patrón de ejemplo | Coincidencias de ejemplo | No coincidencias de ejemplo |
|----------|--------------------------------------------------|-------------------|--------------------------|-----------------------------|
| ^        | coincide con el inicio de la línea               | ^r                | rabbit, raccoon          | parrot, ferret              |
| $        | coincide con el final de la línea                | t$                | rabbit foot, star        | trap                        |
| \A       | coincide con el inicio de la línea               | \Ar               | rabbit, raccoon          | parrot, ferret              |
| \Z       | coincide con el final de la línea                | \t\Z              | rabbit foot              | trap, star                  |
| \b       | coincide con caracteres al inicio o final de una palabra | \bfox\b       | the red fox ran, the fox ate | foxtrot, foxskin scarf     |
| \B       | coincide con caracteres en medio de otros caracteres no espaciales | \Bee\B | trees beef               | bee tree                    |


***Matching types:***
| Sintaxis | Descripción                            | Patrón de ejemplo | Coincidencias de ejemplo | No coincidencias de ejemplo |
|----------|----------------------------------------|-------------------|--------------------------|-----------------------------|
| `.`      | cualquier cosa excepto un salto de línea | `c.e`            | clean, cheap             | acert, cent                 |
| `\d`     | coincide con un dígito                 | `\d`              | 6060-842, 2b*2b          | two, ---                    |
| `\D`     | coincide con un no dígito              | `\D`              | The 5 cats ate 12 Angry men | 52, 10032                |
| `\w`     | coincide con caracteres de palabra     | `wee\w`           | trees, bee4              | The bee eels eat meat       |
| `\W`     | coincide con caracteres que no son de palabra | `\Wbat\W`     | at bat Swing the bat fast | wombat, bat53              |
| `\s`     | coincide con un espacio en blanco      | `\sfox\s`         | the fox ate, his fox ran | it’s the fox. foxfur        |
| `\S`     | coincide con un no espacio en blanco   | `\see\S`          | trees beef               | the bee stung The tall tree |
| metacarácter | escapa un metacarácter para coincidir con el metacarácter | `\.\` | The cat ate. 2^3 | the cat ate 23             |


***Character classes:***
| Sintaxis | Descripción                        | Patrón de ejemplo | Coincidencias de ejemplo | No coincidencias de ejemplo |
|----------|------------------------------------|-------------------|--------------------------|-----------------------------|
| [xy]     | coincide con varios caracteres     | gr[ea]y           | gray, grey               | green, greek                |
| [x-y]    | coincide con un rango de caracteres| [a-e]             | amber, brand             | fox, join                   |
| [^xy]    | no coincide con varios caracteres  | gr[^ea]y          | green, greek             | gray, grey                  |
| [^_-]    | coincide con metacaracteres dentro de una clase de caracteres | 4[^_*-*]/\d | 4*3, 4.2 | 44, 23 |


***Repetition:***
| Sintaxis | Descripción                           | Patrón de ejemplo | Coincidencias de ejemplo | No coincidencias de ejemplo |
|----------|---------------------------------------|-------------------|--------------------------|-----------------------------|
| `x*`     | coincide cero o más veces             | `ar*x0`           | cacao, carrot            | arugula, artichoke          |
| `x+`     | coincide una o más veces              | `re+`             | green, tree              | trap, ruined                |
| `x?`     | coincide cero o una vez               | `ro?a`            | roast, rant              | root, rear                  |
| `x{m}`   | coincide exactamente m veces          | `\we{2}\w`        | deer, seer               | red, enter                  |
| `x{m,}`  | coincide m o más veces                | `\2{3},\4`        | 671-2224, 222224         | 224, 123                    |
| `x{m,n}` | coincide entre m y n veces            | `\12{1},\3\3`     | 1234, 1222384            | 15335, 122223               |
| `x*?, x+?, etc.` | coincide el número mínimo de veces - conocido como cuantificador perezoso | `re+?` | tree, freeeee | trout, roasted             |


***Capturing, alternation & backreferences:***
| Sintaxis    | Descripción                           | Patrón de ejemplo          | Coincidencias de ejemplo | No coincidencias de ejemplo |
|-------------|---------------------------------------|----------------------------|--------------------------|-----------------------------|
| (x)         | capturar un patrón                    | (iss)+                     | Mississippi, missed      | mist, persist               |
| (?:x)       | crear un grupo sin captura            | (?:ab)(cd)                 | abcd (Grupo 1: cd)       | acbd                        |
| (?<name>x)  | crear un grupo de captura con nombre  | (?<first>\d)(?<second>\d)  | 1325 (first:1, second:3) | 2, hello                    |
| (x\|y)      | coincidir varios patrones alternativos| (re\|ba)                   | red, banter              | rant, bear                  |
| \n          | referenciar capturas previas donde n es el índice del grupo comenzando en 1 | (b)(\\w*)\\1 | blob, bribe | bear, bring                |

***Lookahead:***
| Sintaxis | Descripción                                                  | Patrón de ejemplo | Coincidencias de ejemplo | No coincidencias de ejemplo |
|----------|--------------------------------------------------------------|-------------------|--------------------------|-----------------------------|
| (?=x)    | Busca hacia adelante los siguientes caracteres sin usarlos... | an(?=an)          | banana                   | band                        |
| (?!x)    | Busca hacia adelante los siguientes caracteres para no...      | ai(?!n)           | fail, brail              | faint, train                |
| (?<=x)   | Mira los caracteres anteriores para una coincidencia sin...   | (?<=tr)a          | trail                    | bear                        |
| (?!<x)   | Mira los caracteres anteriores para no coincidir con...       | (?!tr)a           | bear                     | trail                       |


***Literal matches and modifiers:***
| Sintaxis       | Descripción                                                  | Patrón de Ejemplo   | Coincidencias de Ejemplo | No Coincidencias de Ejemplo |
|----------------|--------------------------------------------------------------|---------------------|--------------------------|-----------------------------|
| `\Qx\E`        | Coincide exactamente con 'x' de principio a fin              | `\Qtell\E`          | tell                     | I’ll tell you this          |
|                |                                                              | `\Q\d\E`            | \d                       | I have 5 coins              |
| `(?:i)x(?-i)`  | Establece la cadena de regex para que no distinga mayúsculas | `(?:i)te(?-i)`      | sTep, tEach              | Trench, bear                |
| `(?:x)x(?-x)`  | La regex ignora los espacios en blanco                       | `(?:x)t a p(?-x)`   | tap, tapdance            | c a t, rot a potato         |
| `(?:s)x(?-s)`  | Activa el modo DOTALL, donde el '.' incluye el símbolo '\n'  | `(?:s)first and...` | first and Second and...  | first and second and...     |
| `(?:m)x(?-m)`  | Cambia '^' y '$' para ser el final de la línea               | `^eat and sleep$`   | eat and sleep, ^eat...   | ^treat and sleep, ^eat...   |


***Unicode:***

| Sintaxis | Descripción                                  | Patrón de Ejemplo      | Coincidencias de Ejemplo | No Coincidencias de Ejemplo |
|----------|----------------------------------------------|------------------------|--------------------------|-----------------------------|
| \X       | Coincide con grafemas                        | \u0000@gmail           | @gmail www.email@gmail   | gmail @aol                  |
| \X\X     | Coincide con caracteres especiales como...  | \u00e8 o \u0065\u0300   | è                        | e                           |
