#ifndef CONTACTO_H
#define CONTACTO_H

typedef struct
{
    char *nombre;
    char *apellido;
    char *telefono;
} contacto;

typedef struct Nodo
{
    contacto dato;
    struct Nodo *tail;
} Nodo;

#endif