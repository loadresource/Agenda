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
este solo llevara el struct

```C
typedef struct{
    char* nombre;
    char* apellido;
    char* telefono;
}contacto;
```
## agenda.h
la declaracion de las funciones

```C
void agregar_nuevo_contacto();
void listar_contactos();
void agenda();
```





