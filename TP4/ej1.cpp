#include <stdio.h>
#include <string.h>

void guardarDatos();
void buscarPorDNI();

int main() {
    int opcion;
    
    do {
        printf("\n\t                    --- MENU ---                       \n");
        printf("\t ______________________________________________________\n");
        printf("\t|                                                      |\n");
        printf("\t|  1. Ingresar datos de personas y guardar en archivo  |\n");
        printf("\t|  2. Buscar por DNI                                   |\n");
        printf("\t|  3. Salir                                            |\n");
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
                printf("\t Saliendo del programa...\n");
                break;
        }
    } while (opcion != 3);
    
    return 0;
}

void guardarDatos() {
    char nombre[50];
    char apellido[50];
    char dni[50];
    FILE *archivo = fopen("datos.txt", "a"); // Abrir archivo en modo append
    
    if (archivo == NULL) {
        printf("\t Error al abrir el archivo.\n");
        return;
    }
    
    printf("\t Ingrese el nombre: ");
    scanf("%s", nombre);
    printf("\t Ingrese el apellido: ");
    scanf("%s", apellido);
    printf("\t Ingrese el DNI: ");
    scanf("%s", dni);
    
    int longitud = strlen(nombre);
    int longitud2 = strlen(apellido);
    int x;
    
    for (x = 0; x < longitud; x++) { // Colocar mayuscula al nombre
                if (x == 0 || nombre[x - 1] == ' ') {
                    if (nombre[x] >= 'a' && nombre[x] <= 'z') {
                        nombre[x] = nombre[x] - 32;
                    }
                } else {
                    if (nombre[x] >= 'A' && nombre[x] <= 'Z'){
                        nombre[x] = nombre[x] + 32;
                    }
                }
            }
            
    for (x = 0; x < longitud2; x++) { // Colocar mayuscula al apellido
                if (x == 0 || apellido[x - 1] == ' ') {
                    if (apellido[x] >= 'a' && apellido[x] <= 'z') {
                        apellido[x] = apellido[x] - 32;
                    }
                } else {
                    if (apellido[x] >= 'A' && apellido[x] <= 'Z'){
                        apellido[x] = apellido[x] + 32;
                    }
                }
            }
    
    
    fprintf(archivo, "%s|%s|%s\n", nombre, apellido, dni); // Guardar datos separados por '|'
    
    fclose(archivo);
    printf("\t Datos guardados correctamente.\n");
}

void buscarPorDNI() {
    char dniBusqueda[50];
    printf("\t Ingrese el DNI a buscar: ");
    scanf("%s", dniBusqueda);
    
    FILE *archivo = fopen("datos.txt", "r");
    if (archivo == NULL) {
        printf("\t Error al abrir el archivo.\n");
        return;
    }
    
    char dni[50];
    char nombre[50];
    char apellido[50];
    int encontrado = 0;
    
    while (fscanf(archivo, "%[^|]|%[^|]|%[^\n]\n", nombre, apellido, dni) != EOF) {
        if (strcmp(dni, dniBusqueda) == 0) {
            printf("\t Nombre: %s\n", nombre);
            printf("\t Apellido: %s\n", apellido);
            encontrado = 1;
        }
    }
    
    if (encontrado==0) {
        printf("DNI no encontrado.\n");
    }
    
    fclose(archivo);
}

