// Modificar el programa anterior de manera que se puedan realizar búsquedas por apellido y por nombre a la vez.

#include <stdio.h>
#include <string.h>

void guardarDatos();
void buscarPorDNI();
void buscarPorApellidoNombre();

int main() {
    int opcion;
    
    do {
        printf("\n\t                    --- MENU ---                       \n");
        printf("\t ______________________________________________________\n");
        printf("\t|                                                      |\n");
        printf("\t|  1. Ingresar datos de personas y guardar en archivo  |\n");
        printf("\t|  2. Buscar por DNI                                   |\n");
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
                buscarPorDNI();
                break;
            case 3:
            	buscarPorApellidoNombre();
            	break;
            case 4:
                printf("\t Saliendo del programa...\n");
                break;
            }
    } while (opcion != 4);
    
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
    
    int longitud = strlen(nombre);
    int longitud2 = strlen(apellido);
    int x;

    for(x=0;x<longitud;x++){
				if(nombre[x]>='A' && nombre[x]<='Z'){
					nombre[x]=nombre[x]+32;
				}
			}
	for(x=0;x<longitud2;x++){
				if(apellido[x]>='A' && apellido[x]<='Z'){
					apellido[x]=apellido[x]+32;
				}
			}
			

    FILE *archivo = fopen("datosEj2.txt", "a"); // Abrir archivo en modo append
    
    if (archivo == NULL) {
        printf("\t Error al abrir el archivo.\n");
        return;
    }
    
    fprintf(archivo, "%s|%s|%s\n", nombre, apellido, dni); // Guardar datos separados por '|'
    
    fclose(archivo);
    printf("\t Datos guardados correctamente.\n");
}

void buscarPorDNI() {
    char dniBusqueda[50];
    printf("\t Ingrese el DNI a buscar: ");
    scanf("%s", dniBusqueda);
    
    FILE *archivo = fopen("datosEj2.txt", "r");
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
    
    if (encontrado == 0) {
        printf("\t DNI no encontrado.\n");
    }
    
    fclose(archivo);
}

void buscarPorApellidoNombre() {
    char apellidoBusqueda[50];
    char nombreBusqueda[50];
    
       
    FILE *archivo = fopen("datosEj2.txt", "r");
    if (archivo == NULL) {
        printf("\t Error al abrir el archivo.\n");
        return;
    }
    
    
    printf("\t Ingrese el Nombre a buscar: ");
    scanf("%s", nombreBusqueda);
    printf("\t Ingrese el Apellido a buscar: ");
    scanf("%s", apellidoBusqueda);
    
    int longitud = strlen(nombreBusqueda);
    int longitud2 = strlen(apellidoBusqueda);
    int x;
    
    for(x=0;x<longitud;x++){
				if(nombreBusqueda[x]>='A' && nombreBusqueda[x]<='Z'){
					nombreBusqueda[x]=nombreBusqueda[x]+32;		
				}
			}
	for(x=0;x<longitud2;x++){
				if(apellidoBusqueda[x]>='A' && apellidoBusqueda[x]<='Z'){
					apellidoBusqueda[x]=apellidoBusqueda[x]+32;		
				}
			}

    char dni[50];
    char nombre[50];
    char apellido[50];
    int encontrado = 0;
    
    
    while (fscanf(archivo, "%[^|]|%[^|]|%[^\n]\n", nombre, apellido, dni) != EOF) {
        if (strcmp(apellido, apellidoBusqueda) == 0 && strcmp(nombre, nombreBusqueda) == 0) {
            printf("\n\t Nombre: %s\n", nombre);
            printf("\t Apellido: %s\n", apellido);
            printf("\t DNI: %s\n", dni);
            encontrado = 1;
        }
    }
    
    if (encontrado==0) {
        printf("\t No se encontraron personas con el Apellido '%s' y Nombre '%s'.\n", apellidoBusqueda, nombreBusqueda);
    }
    
    fclose(archivo);
}
