# Get Next Line

`get_next_line` es una función en C que lee cualquier archivo dado, una línea a la vez. El objetivo de este proyecto es profundizar en la gestión de entrada/salida en C utilizando llamadas al sistema `read` y aprender sobre la gestión de memoria dinámica y estructuras de datos.

## Descripción

Este proyecto es parte de la currícula de [42 School](https://www.42.fr/). Consiste en escribir una función que devuelve una línea leída desde un descriptor de archivo, sin devolver el carácter de nueva línea.

### Características

- Gestiona múltiples descriptores de archivo.
- Lee de manera eficiente grandes volúmenes de datos.
- Trata de manera efectiva los errores y la gestión de memoria.

## Uso

### Prerrequisitos

Necesitarás un compilador de C como GCC para compilar el proyecto.

### Compilación

Compila el código fuente con:

```bash
gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -o get_next_line
Asegúrate de ajustar BUFFER_SIZE al número de caracteres que deseas leer por operación de read.

Ejecución
Para ejecutar el programa, simplemente usa:

./get_next_line
Ejemplo de Uso
Suponiendo que tienes un archivo llamado file.txt, puedes leer este archivo de la siguiente manera:

int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL) {
    printf("%s", line);
    free(line);
}
close(fd);
Contribuciones
Las contribuciones son lo que hacen a la comunidad de código abierto un lugar increíble para aprender, inspirar y crear. Cualquier contribución que hagas será muy apreciada.
