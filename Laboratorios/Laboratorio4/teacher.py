from person import Person


class Teacher(Person):
    # Constructor de la clase, también llama a los atributos de la clase madre
    def __init__(self, name, age, empleyee_id):
        super().__init__(name, age)
        self.empleyee_id = empleyee_id
        self.courses_taught = []

    # Método para agregar los cursos que esta impartiendo el profesor
    def assing_course(self, course):
        self.courses_taught.append(course)

    # Muestra la información de todos los atributos de la clase
    def display_info(self):
        super().display_info()
        print(f"Employee ID: {self.empleyee_id}\
              \nCourses taught: {', '.join(self.courses_taught)}\n")
        # El método join sirve para concatenar elementos de una lista
