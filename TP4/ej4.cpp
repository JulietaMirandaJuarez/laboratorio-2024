// Guardar Los cambios en un archivo con nombre pertinente sin modificar el original
// y pudiendo tener acceso a los mismos
#include <stdio.h>
#include <string.h>

void guardarDatos();
void buscarPorDNI();
void buscarPorApellidoNombre();
void ordenarPorNombreApellido();
void ordenarPorDNI();

int main() {
    int opcion;
    
    do {
        printf("\n\t                    --- MENU ---                       \n");
        printf("\t ______________________________________________________\n");
        printf("\t|                                                      |\n");
        printf("\t|  1. Ingresar datos de personas y guardar en archivo  |\n");
        printf("\t|  2. Buscar por DNI                                   |\n");
        printf("\t|  3. Buscar por nombre y apellido                     |\n");
        printf("\t|  4. Ordenar por nombre y apellido                    |\n");
        printf("\t|  5. Ordenar por DNI                                  |\n");
        printf("\t|  6. Salir                                            |\n");
        printf("\t|______________________________________________________|\n");
        printf("\t Ingrese su opcion: ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
                guardarDatos();
                break;
            case 2:
                buscarPorDNI();
                break;
            case 3:
                buscarPorApellidoNombre();
                break;
            case 4:
                ordenarPorNombreApellido();
                break;
            case 5:
                ordenarPorDNI();
                break;
            case 6:
                printf("\t Saliendo del programa...\n");
                break;
            
        }
    } while (opcion != 6);
    
    return 0;
}

void guardarDatos() {
    char nombre[50];
    char apellido[50];
    char dni[50];

    printf("\t Ingrese el nombre: ");
    scanf("%s", nombre);
    printf("\t Ingrese el apellido: ");
    scanf("%s", apellido);
    printf("\t Ingrese el DNI: ");
    scanf("%s", dni);

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

    // Abrir archivo en modo lectura para comprobar si el DNI ya existe
    FILE *archivoLectura = fopen("datosEj4.txt", "r");
    if (archivoLectura == NULL) {
        printf("\t Error al abrir el archivo.\n");
        return;
    }

    char dniExistente[50];
    while (fscanf(archivoLectura, "%*[^|]|%*[^|]|%[^\n]\n", dniExistente) != EOF) {
        if (strcmp(dni, dniExistente) == 0) {
            fclose(archivoLectura);
            printf("\t Ya existe una persona con el DNI ingresado.\n");
            return;
        }
    }
    fclose(archivoLectura);

    // Si el DNI no existe, guardar los datos en el archivo
    FILE *archivoEscritura = fopen("datosEj4.txt", "a"); // Abrir archivo en modo append
    if (archivoEscritura == NULL) {
        printf("\t Error al abrir el archivo.\n");
        return;
    }

    fprintf(archivoEscritura, "%s|%s|%s\n", nombre, apellido, dni); // Guardar datos separados por '|'

    fclose(archivoEscritura);
    printf("\t Datos guardados correctamente.\n");
}

void buscarPorDNI() {
    char dniBusqueda[50];
    printf("\t Ingrese el DNI a buscar: ");
    scanf("%s", dniBusqueda);
    
    FILE *archivo = fopen("datosEj4.txt", "r");
    if (archivo == NULL) {
        printf("\t Error al abrir el archivo.\n");
        return;
    }

    char datos[100][50]; // Almacenar datos
    int encontrado = 0;
    int numDatos = 0;

    char dni[50];
    char nombre[50];
    char apellido[50];
    
    while (fscanf(archivo, "%[^|]|%[^|]|%[^\n]\n", nombre, apellido, dni) != EOF) {
        strcpy(datos[numDatos], dni);
        strcat(datos[numDatos], "|");
        strcat(datos[numDatos], nombre);
        strcat(datos[numDatos], "|");
        strcat(datos[numDatos], apellido);
        numDatos++;
    }
    
    fclose(archivo);

    // Mostrar datos
    for (int i = 0; i < numDatos; i++) {
        sscanf(datos[i], "%[^|]|%[^|]|%[^\n]", dni, nombre, apellido);
        if (strcmp(dni, dniBusqueda) == 0) {
            printf("\t Nombre: %s\n", nombre);
            printf("\t Apellido: %s\n", apellido);
            encontrado = 1;
        }
    }
    
    if (encontrado == 0) {
        printf("\t DNI no encontrado.\n");
    }
}

void buscarPorApellidoNombre() {
    char apellidoBusqueda[50];
    char nombreBusqueda[50];
    
    FILE *archivo = fopen("datosEj4.txt", "r");
    if (archivo == NULL) {
        printf("\t Error al abrir el archivo.\n");
        return;
    }

    char datos[100][50]; // Almacenar datos
    int encontrado = 0;
    int numDatos = 0;

    char dni[50];
    char nombre[50];
    char apellido[50];
    
    while (fscanf(archivo, "%[^|]|%[^|]|%[^\n]\n", nombre, apellido, dni) != EOF) {
        strcpy(datos[numDatos], apellido);
        strcat(datos[numDatos], "|");
        strcat(datos[numDatos], nombre);
        strcat(datos[numDatos], "|");
        strcat(datos[numDatos], dni);
        numDatos++;
    }
    
    fclose(archivo);

    // Mostrar datos
    printf("\t Ingrese el Nombre a buscar: ");
    scanf("%s", nombreBusqueda);
    printf("\t Ingrese el Apellido a buscar: ");
    scanf("%s", apellidoBusqueda);
    
    for (int i = 0; i < numDatos; i++) {
        sscanf(datos[i], "%[^|]|%[^|]|%[^\n]", apellido, nombre, dni);
        if (strcmp(apellido, apellidoBusqueda) == 0 && strcmp(nombre, nombreBusqueda) == 0) {
            printf("\n\t Nombre: %s\n", nombre);
            printf("\t Apellido: %s\n", apellido);
            printf("\t DNI: %s\n", dni);
            encontrado = 1;
        }
    }
    
    if (encontrado == 0) {
        printf("\t No se encontraron personas con el Apellido '%s' y Nombre '%s'.\n", apellidoBusqueda, nombreBusqueda);
    }
}

void ordenarPorNombreApellido() {
    char opcionOrden;
    printf("\t Ordenar por:\n");
    printf("\t a. Ascendente\n");
    printf("\t b. Descendente\n");
    printf("\t Ingrese su opcion: ");
    scanf(" %c", &opcionOrden);

    FILE *archivo = fopen("datosEj4.txt", "r");
    if (archivo == NULL) {
        printf("\t Error al abrir el archivo.\n");
        return;
    }

    char datos[100][50]; // Almacenar datos
    int numDatos = 0;

    char dni[50];
    char nombre[50];
    char apellido[50];

    // Leer datos del archivo y almacenarlos en una matriz
    while (fscanf(archivo, "%[^|]|%[^|]|%[^\n]\n", nombre, apellido, dni) != EOF) {
        strcpy(datos[numDatos], nombre);
        strcat(datos[numDatos], "|");
        strcat(datos[numDatos], apellido);
        strcat(datos[numDatos], "|");
        strcat(datos[numDatos], dni);
        numDatos++;
    }

    fclose(archivo);

    // Ordenar los datos según la opción seleccionada
    if (opcionOrden == 'a' || opcionOrden == 'A') { // Ascendente
        for (int i = 0; i < numDatos - 1; i++) {
            for (int j = i + 1; j < numDatos; j++) {
                if (strcmp(datos[i], datos[j]) > 0) {
                    char temp[50];
                    strcpy(temp, datos[i]);
                    strcpy(datos[i], datos[j]);
                    strcpy(datos[j], temp);
                }
            }
        }
    } else if (opcionOrden == 'b' || opcionOrden == 'B') { // Descendente
        for (int i = 0; i < numDatos - 1; i++) {
            for (int j = i + 1; j < numDatos; j++) {
                if (strcmp(datos[i], datos[j]) < 0) {
                    char temp[50];
                    strcpy(temp, datos[i]);
                    strcpy(datos[i], datos[j]);
                    strcpy(datos[j], temp);
                }
            }
        }
    } else {
        printf("\t Opcion no valida. Por favor, ingrese 'a' o 'b'.\n");
        return;
    }

    // Mostrar datos ordenados
    for (int i = 0; i < numDatos; i++) {
        sscanf(datos[i], "%[^|]|%[^|]|%[^\n]", nombre, apellido, dni);
        printf("\n\t Nombre: %s\n", nombre);
        printf("\t Apellido: %s\n", apellido);
        printf("\t DNI: %s\n\n", dni);
    }
}

void ordenarPorDNI() {
    char opcionOrden;
    printf("\t Ordenar por:\n");
    printf("\t a. Ascendente\n");
    printf("\t b. Descendente\n");
    printf("\t Ingrese su opcion: ");
    scanf(" %c", &opcionOrden);

    FILE *archivo = fopen("datosEj4.txt", "r");
    if (archivo == NULL) {
        printf("\t Error al abrir el archivo.\n");
        return;
    }

    char datos[100][50]; // Almacenar datos
    int numDatos = 0;

    char dni[50];
    char nombre[50];
    char apellido[50];

    // Leer datos del archivo y almacenarlos en una matriz
    while (fscanf(archivo, "%[^|]|%[^|]|%[^\n]\n", nombre, apellido, dni) != EOF) {
        strcpy(datos[numDatos], nombre);
        strcat(datos[numDatos], "|");
        strcat(datos[numDatos], apellido);
        strcat(datos[numDatos], "|");
        strcat(datos[numDatos], dni);
        numDatos++;
    }

    fclose(archivo);

    // Ordenar los datos según la opción seleccionada
    if (opcionOrden == 'a' || opcionOrden == 'A') { // Ascendente
        for (int i = 0; i < numDatos - 1; i++) {
            for (int j = i + 1; j < numDatos; j++) {
                int dni1, dni2;
                sscanf(datos[i], "%*[^|]|%*[^|]|%d", &dni1);
                sscanf(datos[j], "%*[^|]|%*[^|]|%d", &dni2);
                if (dni1 > dni2) {
                    char temp[50];
                    strcpy(temp, datos[i]);
                    strcpy(datos[i], datos[j]);
                    strcpy(datos[j], temp);
                }
            }
        }
    } else if (opcionOrden == 'b' || opcionOrden == 'B') { // Descendente
        for (int i = 0; i < numDatos - 1; i++) {
            for (int j = i + 1; j < numDatos; j++) {
                int dni1, dni2;
                sscanf(datos[i], "%*[^|]|%*[^|]|%d", &dni1);
                sscanf(datos[j], "%*[^|]|%*[^|]|%d", &dni2);
                if (dni1 < dni2) {
                    char temp[50];
                    strcpy(temp, datos[i]);
                    strcpy(datos[i], datos[j]);
                    strcpy(datos[j], temp);
                }
            }
        }
    } else {
        printf("\t Opcion no valida. Por favor, ingrese 'a' o 'b'.\n");
        return;
    }

    // Mostrar datos ordenados
    for (int i = 0; i < numDatos; i++) {
        sscanf(datos[i], "%[^|]|%[^|]|%[^\n]", nombre, apellido, dni);
        printf("\n\t Nombre: %s\n", nombre);
        printf("\t Apellido: %s\n", apellido);
        printf("\t DNI: %s\n\n", dni);
    }
}

