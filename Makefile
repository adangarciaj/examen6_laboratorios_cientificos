# Compilador y advertencias para que el código quede limpio
CC = gcc
CFLAGS = -Wall -Wextra

# El nombre de tu programa final
TARGET = examen6

# Todos los archivos .c que creaste para las estructuras
SRCS = main.c cola_lineal.c cola_circular.c pila_estatica.c

# Regla principal para compilar todo junto
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# Regla para borrar el ejecutable cuando quieras limpiar la carpeta
clean:
	rm -f $(TARGET)