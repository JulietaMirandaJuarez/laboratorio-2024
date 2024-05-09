#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JUGADORES 100
#define MAX_NOMBRE 50

void guardarDatos();
void buscarPorApellidoNombre();
void ordenar();

int main() {
    int opcion;
    
    do {
        printf("\n\t                    --- MENU ---                       \n");
        printf("\t ______________________________________________________\n");
        printf("\t|                                                      |\n");
        printf("\t|  1. Ingresar datos de jugadores                      |\n");
        printf("\t|  2. Mostrar los 10 mejores jugadores                 |\n");
        printf("\t|  3. Buscar por nombre y apellido                     |\n");
        printf("\t|  4. Salir                                            |\n");
        printf("\t|______________________________________________________|\n");
        printf("\t Ingrese su opcion: ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
                guardarDatos();
                break;
            case 2:
                ordenar();
                break;
            case 3:
                buscarPorApellidoNombre();
                break;
            case 4:
                printf("\t Saliendo del programa...\n");
                break;
            default:
                printf("\t Opcion no valida. Por favor, ingrese una opcion del 1 al 4.\n");
                break;
        }
    } while (opcion != 4);
    
    return 0;
}

void guardarDatos() {
    char nombre[MAX_NOMBRE];
    char apellido[MAX_NOMBRE];
    int puntaje;

    printf("\t Ingrese el nombre: ");
    scanf("%s", nombre);
    printf("\t Ingrese el apellido: ");
    scanf("%s", apellido);
    printf("\t Ingrese el puntaje: ");
    scanf("%d", &puntaje);

    // Convertir nombre y apellido a minúsculas
    int longitud = strlen(nombre);
    int longitud2 = strlen(apellido);
    int x;

    for (x = 0; x < longitud; x++) {
        if (nombre[x] >= 'A' && nombre[x] <= 'Z') {
            nombre[x] = nombre[x] + 32;
        }
    }
    for (x = 0; x < longitud2; x++) {
        if (apellido[x] >= 'A' && apellido[x] <= 'Z') {
            apellido[x] = apellido[x] + 32;
        }
    }

    FILE *archivo = fopen("datosEj6.txt", "a"); // Abrir archivo en modo append
    if (archivo == NULL) {
        printf("\t Error al abrir el archivo.\n");
        return;
    }

    fprintf(archivo, "%s|%s|%d\n", nombre, apellido, puntaje);

    fclose(archivo);
    printf("\t Datos guardados correctamente.\n");
}

void buscarPorApellidoNombre() {
    char apellidoBusqueda[MAX_NOMBRE];
    char nombreBusqueda[MAX_NOMBRE];
    
    FILE *archivo = fopen("datosEj6.txt", "r");
    if (archivo == NULL) {
        printf("\t Error al abrir el archivo.\n");
        return;
    }

    char datos[100][100];
    int numDatos = 0;

    char nombre[MAX_NOMBRE];
    char apellido[MAX_NOMBRE];
    int puntaje;
    
    while (fscanf(archivo, "%[^|]|%[^|]|%d\n", nombre, apellido, puntaje) != EOF) {
        strcpy(datos[numDatos], apellido);
        strcat(datos[numDatos], "|");
        strcat(datos[numDatos], nombre);
        strcat(datos[numDatos], "|");
        sprintf(datos[numDatos] + strlen(datos[numDatos]), "%d", puntaje);
        numDatos++;
    }
    
    fclose(archivo);

    printf("\t Ingrese el Nombre a buscar: ");
    scanf("%s", nombreBusqueda);
    printf("\t Ingrese el Apellido a buscar: ");
    scanf("%s", apellidoBusqueda);
    
    for (int i = 0; i < numDatos; i++) {
        sscanf(datos[i], "%[^|]|%[^|]|%d", apellido, nombre, puntaje);
        if (strcmp(apellido, apellidoBusqueda) == 0 && strcmp(nombre, nombreBusqueda) == 0) {
            printf("\n\t Nombre: %s\n", nombre);
            printf("\t Apellido: %s\n", apellido);
            printf("\t Puntaje: %d\n", puntaje);
        }
    }
}

void ordenar() {
    FILE *archivo = fopen("datosEj6.txt", "r");
    if (archivo == NULL) {
        printf("\t Error al abrir el archivo.\n");
        return;
    }

    char vecNombres[MAX_JUGADORES][MAX_NOMBRE];
    char vecApellidos[MAX_JUGADORES][MAX_NOMBRE];
    int vecPuntajes[MAX_JUGADORES];
    int numDatos = 0;

    char nombre[MAX_NOMBRE];
    char apellido[MAX_NOMBRE];
    int puntaje;
    
    while (fscanf(archivo, "%[^|]|%[^|]|%d\n", nombre, apellido, &puntaje) != EOF && numDatos < MAX_JUGADORES) {
        strcpy(vecNombres[numDatos], nombre);
        strcpy(vecApellidos[numDatos], apellido);
        vecPuntajes[numDatos] = puntaje;
        numDatos++;
    }

    fclose(archivo);

    for (int i = 0; i < numDatos - 1; i++) {
        for (int j = i + 1; j < numDatos; j++) {
            if (vecPuntajes[i] < vecPuntajes[j]) {
                int tempPuntaje = vecPuntajes[i];
                vecPuntajes[i] = vecPuntajes[j];
                vecPuntajes[j] = tempPuntaje;

                char tempNombre[MAX_NOMBRE];
                strcpy(tempNombre, vecNombres[i]);
                strcpy(vecNombres[i], vecNombres[j]);
                strcpy(vecNombres[j], tempNombre);

                char tempApellido[MAX_NOMBRE];
                strcpy(tempApellido, vecApellidos[i]);
                strcpy(vecApellidos[i], vecApellidos[j]);
                strcpy(vecApellidos[j], tempApellido);
            }
        }
    }

    printf("\n\t Los 10 mejores jugadores:\n");
    for (int i = 0; i < 10 && i < numDatos; i++) {
        printf("\n\t Nombre: %s\n", vecNombres[i]);
        printf("\t Apellido: %s\n", vecApellidos[i]);
        printf("\t Puntaje: %d\n", vecPuntajes[i]);
    }
}

