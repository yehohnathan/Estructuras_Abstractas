# -------------- # Se importa la librería para servicios web # -------------- #
import requests

# --------------------------------------------------------------------------- #
print("====================================================================" +
      "====================================================================")
print("Ejemplo 1: lo más básico que se puede hacer con un request")
# Se conecta a una url específica para practicar request
response = requests.get('https://jsonplaceholder.typicode.com/todos/1')
print("Tipo:", type(response))
print("Respuesta:", response)               # Respuesta 200, todo bien
print("Respuesta text:", response.text)     # Diccionario obtenido

# Usando métodos mágicos, todo lo que venía en response se pasa como un
# un diccionarió.
print("Respuesta:", response.__dict__)


# --------------------------------------------------------------------------- #
print("====================================================================" +
      "====================================================================")
print("\nEjemplo 2: usando request en una página html (www.google.com)")
url = "https://www.google.com"
response = requests.get(url)
print(response.text)    # Responde en formato html


# ------------------------------- Ejemplo GET ------------------------------- #
print("====================================================================" +
      "====================================================================")
print("\nEjemplo 3: usando el método get")
# Se crea un payload con cierta información
payload = {'clave1': 'valor1', 'clave2': 'valor2'}
# Obtiene la información, como ejemplo para autentificar a un usuario según lo
# del payload
response = requests.get('https://ejemplo.com/ruta', params=payload)
print(response.text)

# ------------------------------- Ejemplo POST ------------------------------ #
print("====================================================================" +
      "====================================================================")
print("\nEjemplo 4: usando el método post")
# Lo que cambia es params por get
payload = {'usuario': 'juan', 'contrasena': 'secreta'}
response = requests.post('https://ejemplo.com/login', data=payload)
print(response.text)

print("====================================================================" +
      "====================================================================")
print("\nEjemplo 5: usando el método post en formato JSON")
payload = {'usuario': 'juan', 'contrasena': 'secreta'}
# Para que sea json
response = requests.post('https://ejemplo.com/login', json=payload)
print(response.text)


# --------------------------- Manejo de Respuesta --------------------------- #
print("====================================================================" +
      "====================================================================")
print("\nEjemplo 6: manejo de respuestas")
response = requests.get('https://jsonplaceholder.typicode.com/todos/1')
# Formas de preguntar por información
print(response.status_code)
print(response.headers)
print(response.json())      # Si la respuesta es JSON


# ---------------------------- Manejo de Errores ---------------------------- #
print("====================================================================" +
      "====================================================================")
print("\nEjemplo 7: manejo de errores")
# Manejo de excepciones si no hay un 200
try:
    response = requests.get('https://ejemplo.com/pagina-inexistente')
    response.raise_for_status()  # Genera una excepción si hay un error HTTP
    print(response.text)
except requests.exceptions.HTTPError as e:
    print(f"Error HTTP: {e}")

# ----------------------- Ejemplo Complejo de Request ----------------------- #
print("====================================================================" +
      "====================================================================")
print("\nEjemplo 8: ejemplo completo de request")
# Paso 1: Realizar una solicitud para obtener datos de usuarios
users_response = requests.get('https://jsonplaceholder.typicode.com/users')
users_data = users_response.json()

# Paso 2: Realizar una solicitud para obtener datos de publicaciones
posts_response = requests.get('https://jsonplaceholder.typicode.com/posts')
posts_data = posts_response.json()

# Paso 3: Procesar los datos para obtener información relevante
# Un diccionario para almacenar las publicaciones de cada usuario
user_posts = {}

for user in users_data:
    user_posts[user['id']] = []

for post in posts_data:
    user_id = post.get('userId')  # Usar .get() para evitar KeyError
    if user_id in user_posts:
        user_posts[user_id].append({
            'title': post['title'],
            'body': post['body']
        })

# Paso 4: Mostrar los resultados
for user_id, posts in user_posts.items():
    user = next((user for user in users_data if user['id'] == user_id), None)
    if user:
        print(f"\nPublicaciones de {user['name']} ({user['email']}):\n")
        for post in posts:
            print(f"Title: {post['title']}\nBody: {post['body']}\n")
    else:
        print(f"No se encontraron datos para el usuario con ID {user_id}")
