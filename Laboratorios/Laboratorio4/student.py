from person import Person


class Student(Person):
    # Constructor de la clase, también llama a los atributos de la clase madre
    def __init__(self, name, age, student_id):
        super().__init__(name, age)
        self.student_id = student_id
        self.courses = []

    # Método para agregar los cursos que esta llevando el estudiante
    def enroll_courses(self, course):
        self.courses.append(course)

    # Muestra la información de todos los atributos de la clase
    def display_info(self):
        super().display_info()
        print(f"Student ID: {self.student_id}\
              \nCourses: {', '.join(self.courses)}\n")
        # El método join sirve para concatenar elementos de una lista
