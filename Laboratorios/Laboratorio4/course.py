class Course():
    # Contructor:
    def __init__(self, course_code, course_name):
        self.course_code = course_code
        self.course_name = course_name

    def display_info(self):
        print(f"Course code: {self.course_code}\
              \nCourse name: {self.course_name}\n")
