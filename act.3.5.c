#include <libreria.h>

typedef struct _empleado {
    int id_empleado;
    char nombre[50], telefono[15], direccion[40];
    char correo[30], puesto[20];
    float sueldo_base;
    char turno[20];
    int comision;
} Empleado;



int main() {
    Empleado trabajador[TAM];
    int cont_emp = 0;
    int op;
    
    do {
        printf("\n\t--MENU PRINCIPAL--\t\n");
        printf("1. Empleados\n"
               "2. Productos\n"
               "3. Ventas\n"
               "4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &op);
        
        switch(op) {
            case 1:
                do {
                    int op_emp = menu_empleado();
                    switch(op_emp) {
                        case 1:
                            if (cont_emp < TAM) {
                                CapturaEmpleado(trabajador, &cont_emp);  // Pasamos la dirección de cont_emp
                            } else {
                                printf("No hay espacio para más empleados.\n");
                            }
                            break;
                        case 2:
                            mostrar_empleado(trabajador, cont_emp);
                            break;
                        case 7:
                            // Opción para regresar al menú principal
                            printf("Regresando al menú principal...\n");
                            break;  // Salir del submenú de empleados
                        default:
                            printf("Opción no válida.\n");
                            break;
                    }
                } while (op != 7);  // Este bucle se repetirá hasta que se elija "Regresar al menú principal"
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida.\n");
                break;
        }
    } while(op != 4);
    
    return 0;
}

