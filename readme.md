# Tarea 2: Agenda de Contactos

### Cree una agenda de contactos que almacene de cada contacto los siguientes datos:
    -Nombre
    -Apellido
    -Telefono

### La agenda tendra las siguentes funcionalidad:
    -Agregar nuevo contacto
    -Listar todos los contactos

### Archivos que se espera recibir:
    -contacto.h
    -agenda.h
    -agenda.c
    -main.c
    -Makefile

**Objetivo de aprendizaje**: Practicar la gestion de memoria dinamica con las funciones **malloc** y
**free** asi como practicar el concepto de punteros en C
_____________________________________________________

## contacto.h
Este solo llevara el struct



```C
//cualquiera de las dos esta bien
//simplemente por tener mejor legibilidad
//char* nombre
//char *nombre

typedef struct{
    char* nombre;
    char* apellido;
    char* telefono;
}contacto;
```
## agenda.h
La declaracion de las funciones para agenda.c

```C
void agregar_nuevo_contacto();
void listar_contactos();
void agenda();
```

## lista enlazada
Definimos nuestro propio tipo de dato para la lista enlaza
```c
typedef struct Nodo {
    contacto dato;
    struct Nodo* tail;
} Nodo;

// para que sea accesible por todas las funciones
Nodo* head = NULL;
```

## agregar_nuevo_contacto
Esta funcion agrega un nuevo contacto y lo agrega a la lista

creamos un "buffer" de memoria de 200 caracteres para los inputs

`fgets` mejor manipulacion a `gets` o `scanf` para la cadena de caracteres y permite espacios 

```c
//eliminar saltos de linea de la funcion fgets
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n')
    {
        buffer[len - 1] = '\0';
    }
```


`size_t` evitamos las converciones implicitas de tipos ya que `strlen` devuelve size_t

`fprintf` para el stderr y mostrar errores con el stdio.h 
`strcpy` para copiar del buffer a la variable que se ejecute al momento
por ejemplo :
la informacion anadida por el usuario con fgets lo copia en la variable apellido
`strcpy(apellido, buffer);`

## listar_contactos
muestra la lista de contactos almacenado en la lista enlaza


## agenda
este  seria el menu, donde el usuario proporcionara los datos y donde tambien se limpiaran los datos usados en memoria una vez sea cerrado el programa
