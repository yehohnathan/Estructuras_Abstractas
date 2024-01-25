from student import Student
from teacher import Teacher
from course import Course

# Se instancias los objetos de la clase Student:
# "se les asigna los atributos esperados"
student1 = Student("Yehohnathan", 21, "C04879")
student2 = Student("Maria", 28, "B5149")

# Se instancias los objetos de la clase Teacher:
# "se les asigna los atributos esperados"
teacher1 = Teacher("Jorge Romero", 65, "123456")
teacher2 = Teacher("Luis Diego Marin", 61, "555555")

# Se instancias los objetos de la clase Curso
course1 = Course("IE0217", "DSA")
course2 = Course("IE0323", "CD1")

# Se le asignan cursos con el método de la clase Studen, y lo que hay dentro
# de dicho método se le asigna un atributo de de course1 y course2
student1.enroll_courses(course1.course_name)
student1.enroll_courses(course2.course_name)

# Se le asigna el curso impartirá cada profesor
teacher1.assing_course(course1.course_name)
teacher2.assing_course(course2.course_name)

# Se muestra el contenido de los atributos de cada clase:
student1.display_info()
student2.display_info()     # student2 no tiene atributos de cursos
teacher1.display_info()
teacher2.display_info()
