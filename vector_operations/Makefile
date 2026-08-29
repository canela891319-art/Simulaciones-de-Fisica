CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -I../comun/include -Iinclude
LDLIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Archivos fuente
SRCS = src/main.c ../comun/src/math1.c ../comun/src/physics.c ../comun/src/rendering.c ../comun/src/interaction.c

# Convierte cada ruta .c a un .o dentro de la carpeta build/
# Ejemplo: src/main.c -> build/main.o
#          ../comun/src/physics.c -> build/physics.o
OBJS = $(addprefix build/, $(notdir $(SRCS:.c=.o)))

# Directorio y nombre del ejecutable final
TARGET = bin/simulador

all: create_dirs $(TARGET)

# Crea las carpetas bin/ y build/ si no existen
create_dirs:
	@mkdir -p bin build

# Vinculación: une los .o de build/ para crear bin/simulador
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDLIBS)

# Compilación de main.c local
build/main.o: src/main.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compilación de los módulos comunes
build/%.o: ../comun/src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpieza total de bin/ y build/
clean:
	rm -rf build