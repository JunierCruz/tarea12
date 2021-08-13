
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_CONTACTOS 200

void main()
{
    printf("Programa lista de contactos\n");
    char nombre[MAX_CONTACTOS][20];
    char direcion[MAX_CONTACTOS][20];
    char telefono[MAX_CONTACTOS][10];
    int last_index = 0;
    
    //Para actualizar
    bool flag = false;
    char nombre_remplazar[20];
    char nombre_nuevo[20];
    char telefono_nuevo[20];
    char direccion_nuevo[20];
    
    int opcion;
    while(1){
        printf("Menu\n");
        printf("1- Agregar contacto\n");
        printf("2- Listar contactos\n");
        printf("3- Modificar contactos\n");
        printf("4- Eliminar contactos\n");
        printf("5- Salir\n");
        printf("Seleccione una opcion\n");
        scanf("%i", &opcion);
        
        switch(opcion){
            case 1:
            if(last_index >= MAX_CONTACTOS){
                printf("Maxima capacidad alcanzada:\n");
            }else{
                printf("Introduzca los datos:\n\n");
                printf("Nombre: ");
                scanf("%s",nombre[last_index]);
                printf("Direcion: ");
                scanf("%s",direcion[last_index]);
                printf("Telefono: ");
                scanf("%s",telefono[last_index]);
                last_index +=1;
            }
            
            
            printf("Contacto agregado...\n\n");
            break;
             
            case 2:
            printf("Lista de contactos\n\n");
           
            for (int i = 0; i <last_index ; i++) {
                printf("%s: %s, %s \n",nombre[i], direcion[i],telefono[i] );
            }
            printf("\n\n");
            break;
            
            case 3:
            printf("Introduzca el nombre del contacto que va a modificar: \n");
            scanf("%s", nombre_remplazar);
            for (int i = 0; i < last_index; i++) {
                if(strcmp(nombre[i], nombre_remplazar) == 0){
                    printf("Contacto encontrado, introduzca los nuevos datos: \n");
                    printf("Nombre: ");
                    scanf("%s",nombre_nuevo);
                    printf("Direcion: ");
                    scanf("%s",direccion_nuevo);
                    printf("Telefono: ");
                    scanf("%s",telefono_nuevo);
                    strcpy(nombre[i],nombre_nuevo );
                    strcpy(direcion[i],direccion_nuevo );
                    strcpy(telefono[i],telefono_nuevo );
                    printf("Contacto actualizado... \n\n");
                    flag = true;
                }
            }
            
            if(!flag) printf("No se encontro el nombre...\n\n");
            break;
            
            case 4:
            
             printf("Introduzca el nombre del contacto que va a eliminar: \n");
            scanf("%s", nombre_remplazar);
            for (int i = 0; i < last_index; i++) {
                if(strcmp(nombre[i], nombre_remplazar) == 0){
                    for (int j = i; j < last_index-1; j++) {
                        strcpy(nombre[i],nombre[i+1] );
                        strcpy(direcion[i],direcion[i+1] );
                        strcpy(telefono[i],telefono[i+1] );
                    }
                    last_index -= 1;
                    printf("Contacto eliminado... \n\n");
                    flag = true;
                }
            }
            
            if(!flag) printf("No se encontro el nombre...\n\n");
            break;
            
            case 5:
            
            return;
            break;
            
            default:
            printf("Opcion no valida...\n\n");
        }
        
    }

    
}
