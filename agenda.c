#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contacto.h"
#include "agenda.h"

Nodo *head = NULL;

void agregar_nuevo_contacto()
{
    char buffer[200];
    printf("Nombre: ");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
    {
        fprintf(stderr, "Error al leer nombre\n");
        return;
    }
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n')
    {
        buffer[len - 1] = '\0';
    }
    char *nombre = malloc(strlen(buffer) + 1);
    if (nombre == NULL)
    {
        fprintf(stderr, "Error: no se pudo asignar memoria para nombre\n");
        return;
    }
    strcpy(nombre, buffer);

    printf("Apellido: ");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
    {
        fprintf(stderr, "Error al leer apellido\n");
        free(nombre);
        return;
    }
    len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n')
    {
        buffer[len - 1] = '\0';
    }
    char *apellido = malloc(strlen(buffer) + 1);
    if (apellido == NULL)
    {
        fprintf(stderr, "Error: no se pudo asignar memoria para apellido\n");
        free(nombre);
        return;
    }
    strcpy(apellido, buffer);

    printf("Teléfono: ");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
    {
        fprintf(stderr, "Error al leer telefono\n");
        free(nombre);
        free(apellido);
        return;
    }
    len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n')
    {
        buffer[len - 1] = '\0';
    }
    char *telefono = malloc(strlen(buffer) + 1);
    if (telefono == NULL)
    {
        fprintf(stderr, "Error: no se pudo asignar memoria para telefono\n");
        free(nombre);
        free(apellido);
        return;
    }
    strcpy(telefono, buffer);

    Nodo *nuevo = malloc(sizeof(Nodo));
    if (nuevo == NULL)
    {
        fprintf(stderr, "Error: no se pudo asignar memoria para el nodo\n");
        free(nombre);
        free(apellido);
        free(telefono);
        return;
    }

    nuevo->dato.nombre = nombre;
    nuevo->dato.apellido = apellido;
    nuevo->dato.telefono = telefono;
    nuevo->tail = head;
    head = nuevo;

    printf("Contacto agregado correctamente\n");
}

void listar_contactos()
{
    if (head == NULL)
    {
        printf("La agenda esta vacia\n");
        return;
    }

    printf("\n--- Lista de contactos ---\n");
    Nodo *actual = head;
    int i = 1;
    while (actual != NULL)
    {
        printf("%d. %s %s - Telefono: %s\n",
               i++,
               actual->dato.nombre,
               actual->dato.apellido,
               actual->dato.telefono);
        actual = actual->tail;
    }
    printf("--------------------------\n");
}

void agenda()
{
    int input_usuario;
    do
    {
        printf("\n--- Agenda de Contactos ---\n");
        printf("-1. Agregar nuevo contacto\n");
        printf("-2. Listar contactos\n");
        printf("-3. Salir\n");
        printf("Elige una opción: ");

        if (scanf("%d", &input_usuario) != 1)
        {
            while (getchar() != '\n')
                ;
            printf("Opción invalida. Intentalo de nuevo\n");
            continue;
        }
        while (getchar() != '\n')
            ;
        switch (input_usuario)
        {
        case 1:
            agregar_nuevo_contacto();
            break;
        case 2:
            listar_contactos();
            break;
        case 3:
        {
            Nodo *actual = head;
            while (actual != NULL)
            {
                Nodo *tail = actual->tail;
                free(actual->dato.nombre);
                free(actual->dato.apellido);
                free(actual->dato.telefono);
                free(actual);
                actual = tail;
            }
            head = NULL;
        }
            printf("Saliendo...\n");
            break;
        default:
            printf("Opcion no valida\n");
        }
    } while (input_usuario != 3);
}