CC = gcc
CFLAGS = -Wall -g

TARGET = examen6

SRCS = main.c colaLineal.c colaCircular.c pilaEstatica.c

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)


clean:
	rm -f $(TARGET)