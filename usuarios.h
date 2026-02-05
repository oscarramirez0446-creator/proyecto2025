#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

void cliente(){

    int opcion;

    do {
        printf("Bienvenido, usted ya cuenta con una reserva?\n");
        printf("1. Quiero reservar");
        printf("2. Ya tengo una reserva");
        printf("\nSeleccione una opci%cn: ", 162);
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                //reservar();
                break;
            case 2:
                ya_tiene_reserva();
                break;
            default:
                printf("\nOpci%cn no valida, vuelva a intentar\n", 162);
        }
    } while (opcion != 2);
    }

void trabajador(){

    int opcion;

    do {
        printf("\n\nMenu Principal:\n\n");
        printf("1. Buscar un viaje\n");
        printf("2. Buscar un pasajero por nombre\n");
        printf("3. Mostrar la lista de pasajeros por viaje\n");
        printf("4. Capturar pasajeros\n");
        printf("5. Cancelar o eliminar a alg?n pasajero\n");
        printf("6. Mostrar lista de viajes que no han completado un porcentaje de pasajeros (30%, 50%, 80% y 100%)\n");
        printf("7. Modificar reservaci%cn\n", 162);
        printf("8. Regresar al usuario\n");
        printf("\nSeleccione una opci%cn: ", 162);
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                buscar_viaje();
                break;
            case 2:
                buscar_pasajero();
                break;
            case 3:
                mostrar_lista_pasajeros_viaje();
                break;
            case 4:
                capturar_pasajero();
                break;
            case 5:
                cancelar_pasajero();
                break;
            case 6:
                lista_viajes_30_50_80_100();
                break;
            case 7:
                printf("\nSalio del programa\n");
                break;
            case 8:
                modificar_pasajero();
                break;
            default:
                printf("\nOpci%cn no valida, vuelva a intentar\n", 162);
        }
    } while (opcion != 8);
    }
