#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


// Archivo global
FILE *archivo;

// Funciones de archivo
void leer_archivo() {
    archivo = fopen("pasajeros.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para lectura.\n");
        exit(1);
    }
}

void modificar_archivo() {
    archivo = fopen("pasajeros.txt", "a");  // Abrimos en modo agregar
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para modificar.\n");
        exit(1);
    }
}

void cerrar_archivo() {
    if (archivo != NULL) {
        fclose(archivo);
        archivo = NULL;
    }
}

//General
void presentar() {

    printf(""
           "Nombre: Orozco Cruz Judith Thyphereth\n\n"
           "C%cdigo: 224786633\n"
           "Nombre: Castellanos Galindo Diego Francisco\n\n"
           "C%cdigo: 224785491\n"
           "Nombre: Ramirez Perez Oscar Emiliano\n\n"
           "C%cdigo: 221504467\n\n"
           "Materia: Programaci%cn Estructurada\n"
           "Secci%cn: D07\n"
           "N%cmero de pr%cctica: Proyecto Final\n"
           "Fecha de entrega: -/-/2025\n", 162, 162, 162, 162, 162, 163, 160);
        printf("**********************************************\n");
}

//Estructuras
struct fecha {
    int dia;
    int mes;
    int anio;
} ;

struct datos_cliente{
    char nombre[50];
    char apellidos[50];
    struct fecha fecha_nacimiento;
    char rfc[13];
    char teleforo[11];
    char direccion[60];
    int edad;
    char viaje[60];
    int descuento;
    struct fecha fecha_registro;
};

struct datos_viajes{
    char destino[60];
    char fecha[10];
    float costo;
    int pasajeros;
    int lugares;
};


void mayusculas(char *texto) {
    int cantidad = strlen(texto);

    for (int i = 0; i < cantidad; i++) {
        texto[i] = toupper(texto[i]);
    }

    if (cantidad > 0 && texto[cantidad - 1] == '\n') {
        texto[cantidad - 1] = '\0';
    }
}

void minusculas(char *texto) {
    int cantidad = strlen(texto);

    for (int i = 0; i < cantidad; i++) {
        texto[i] = tolower(texto[i]);
    }

    if (cantidad > 0) {
        texto[0] = toupper(texto[0]);
    }

    if (cantidad > 0 && texto[cantidad - 1] == '\n') {
        texto[cantidad - 1] = '\0';
    }
}

void fin_linea (char *texto) {
    int cantidad = strlen(texto);

    if (cantidad > 0 && texto[cantidad - 1] == '\n') {
        texto[cantidad - 1] = '\0';
    }
}

void calcularRFC(struct datos_cliente *usuario, int x) {

    // Copia la primera letra del primer apellido
    usuario[x].rfc[0] = usuario[x].apellidos[0];

    // Buscar la posición del espacio entre apellidos
    int espacio = 0;
    while (usuario[x].apellidos[espacio] != ' ' && usuario[x].apellidos[espacio] != '\0') {
        espacio++;
    }

    // Buscar la primera vocal del primer apellido
    for (int i = 1; i < espacio; i++) {
        char c = tolower(usuario[x].apellidos[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            usuario[x].rfc[1] = usuario[x].apellidos[i];
            break;
        }
    }

    // Copia la primera letra del segundo apellido
    usuario[x].rfc[2] = usuario[x].apellidos[espacio + 1];

    // Copia la primera letra del nombre
    usuario[x].rfc[3] = usuario[x].nombre[0];

    // Año de nacimiento: últimos dos dígitos
    char year[5];
    snprintf(year, sizeof(year), "%04d", usuario[x].fecha_nacimiento.anio);
    usuario[x].rfc[4] = year[2];
    usuario[x].rfc[5] = year[3];

    // Mes de nacimiento
    if (usuario[x].fecha_nacimiento.mes >= 10) {
        usuario[x].rfc[6] = (usuario[x].fecha_nacimiento.mes / 10) + '0';
        usuario[x].rfc[7] = (usuario[x].fecha_nacimiento.mes % 10) + '0';
    } else {
        usuario[x].rfc[6] = '0';
        usuario[x].rfc[7] = usuario[x].fecha_nacimiento.mes + '0';
    }

    // Día de nacimiento
    if (usuario[x].fecha_nacimiento.dia >= 10) {
        usuario[x].rfc[8] = (usuario[x].fecha_nacimiento.dia / 10) + '0';
        usuario[x].rfc[9] = (usuario[x].fecha_nacimiento.dia % 10) + '0';
    } else {
        usuario[x].rfc[8] = '0';
        usuario[x].rfc[9] = usuario[x].fecha_nacimiento.dia + '0';
    }

    // Caracteres genéricos 
    usuario[x].rfc[10] = 'X';
    usuario[x].rfc[11] = 'X';
    usuario[x].rfc[12] = 'X';
    usuario[x].rfc[13] = '\0';

    mayusculas(usuario[x].rfc);
}

//Cliente
//AQUI FALTA QUE SE MUESTRE EL MENU DE OPCIONES DE VIAJE PRIMERO Y QUE EN LUGAR DE PREGUNTAR LA DIRECCION YA LA TOME DE LO QUE ELIGIO (ESTARIA PADRE QUE CON LO DE GOTOXY LOS DEJARAMOS ELEGIR SU ASIENTO DE LOS DISPONIBLES PERO NO SE QUE TAN COMPLICADO SEA)

void reservar(struct datos_cliente *cliente, int *x) {
    int idx = *x;  // índice actual

    printf("\nIngrese su nombre: ");
    getchar();  // Limpiar buffer
    fgets(cliente[idx].nombre, 50, stdin);
    minusculas(cliente[idx].nombre);

    printf("\nIngrese su apellidos completo: ");
    // No hace falta otro getchar: el fgets anterior consumió el '\n'
    fgets(cliente[idx].apellidos, 50, stdin);
    minusculas(cliente[idx].apellidos);

    printf("Fecha de nacimiento dia (dd): ");
    scanf("%d", &cliente[idx].fecha_registro.dia);
    printf("Fecha de nacimiento mes (mm): ");
    scanf("%d", &cliente[idx].fecha_registro.mes);
    printf("Fecha de nacimiento year (aaaa): ");
    scanf("%d", &cliente[idx].fecha_registro.anio);

    // Calcular y mostrar RFC
    calcularRFC(cliente, idx);
    printf("RFC: %s\n", cliente[idx].rfc);

    printf("Telefono: ");
    fgets(cliente[idx].teleforo, 11, stdin);
    minusculas(cliente[idx].teleforo);

    printf("Direccion: ");
    getchar();
    fgets(cliente[idx].direccion, 60, stdin);
    minusculas(cliente[idx].direccion);

    printf("Edad: ");
    scanf("%d", &cliente[idx].edad);

    printf("Destino del viaje: ");
    getchar();
    fgets(cliente[idx].viaje, 60, stdin);
    minusculas(cliente[idx].viaje);

    cliente[idx].descuento = (cliente[idx].edad >= 60) ? 15 : 0;

    printf("Fecha de registro (dd/mm/aaaa): ");
    scanf("%2d/%2d/%4d", &cliente[idx].fecha_registro.dia, &cliente[idx].fecha_registro.mes, &cliente[idx].fecha_registro.anio);

    modificar_archivo(); // Llamamos a la función para modificar el archivo
    fwrite(cliente, sizeof(*cliente), idx+1, archivo);
    cerrar_archivo();     // Cerramos el archivo

    printf("\nReserva realizada correctamente\n");

    (*x)++; // Incrementar contador de clientes
}


void ya_tiene_reserva(){

    int opcion;

    do {
        printf("En qu? le puedo ayudar?\n");
        printf("1. Ver detalles de mi reserva");
        printf("2. Modificar reserva");
        printf("3. Cancelar reserva");
        printf("\nSeleccione una opci%cn: ", 162);
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                //datos_reserva();
                break;
            case 2:
               // modificar_reserva();
                break;
            case 3:
                //cancelar_reserva();
                break;
            default:
                printf("\nOpci%cn no valida, vuelva a intentar\n", 162);
        }
    } while (opcion != 2);
}

//Cliente con reserva
void datos_reserva(){

    char rfc[13];
    struct datos_cliente cliente; // Llamamos a la estructura
    int encontrado = 0;

    printf("Ingrese su RFC para buscar su reserva: ");
    scanf("%s", rfc);

    leer_archivo();
    while (fread(&cliente, sizeof(cliente), 1, archivo)) {
        if (strcmp(cliente.rfc, rfc) == 0) {
            printf("\nReserva encontrada:\n");
            printf("Nombre: %s %s\nDestino: %s\nFecha Registro: %s\n", cliente.nombre, cliente.apellidos , cliente.viaje, cliente.fecha_registro);
            encontrado = 1;
            break;
        }
    }
    cerrar_archivo(); // Cerramos el archivo

    if (!encontrado)
        printf("No se encontr%c ninguna reserva con ese RFC\n", 162);
}

void modificar_reserva(){

}

void cancelar_reserva(){

}

//Trabajador
void buscar_viaje(){

    char destino[60];
    struct datos_cliente cliente; // Llamamos a la estructura
    int encontrado = 0;

    printf("Ingrese el destino a buscar: ");
    getchar();
    fgets(destino, 60, stdin);
    destino[strcspn(destino, "\n")] = 0;

    leer_archivo();
    while (fread(&cliente, sizeof(cliente), 1, archivo)) {
        if (strcmp(cliente.viaje, destino) == 0) {
            printf("Pasajero: %s %s \n", cliente.nombre, cliente.apellidos);
            encontrado = 1;
        }
    }
    cerrar_archivo(); // Cerramos el archivo

    if (!encontrado)
        printf("No se encontraron pasajeros para ese destino\n");
}

void buscar_pasajero(){

    char nombre[60];
    struct datos_cliente cliente; // Llamamos a la estructura
    int encontrado = 0;

    printf("Ingrese el nombre del pasajero: ");
    getchar();
    fgets(nombre, 60, stdin);
    nombre[strcspn(nombre, "\n")] = 0;

    leer_archivo();
    while (fread(&cliente, sizeof(cliente), 1, archivo)) {
        if (strstr(cliente.nombre, nombre) != NULL) {
            printf("Pasajero encontrado: %s, Viaje: %s\n", cliente.nombre, cliente.viaje);
            encontrado = 1;
        }
    }
    cerrar_archivo(); // Cerramos el archivo

    if (!encontrado)
        printf("No se encontr%c ning?n pasajero con ese nombre\n", 162);
}

void mostrar_lista_pasajeros_viaje(){

    char destino[60];
    struct datos_cliente cliente; // Llamamos a la estructura
    int count = 0;

    printf("Ingrese el destino del viaje para listar pasajeros: ");
    getchar();
    fgets(destino, 60, stdin);
    destino[strcspn(destino, "\n")] = 0;

    leer_archivo();
    while (fread(&cliente, sizeof(cliente), 1, archivo)) {
        if (strcmp(cliente.viaje, destino) == 0) {
            printf("Pasajero: %s, Edad: %d\n", cliente.nombre, cliente.edad);
            count++;
        }
    }
    cerrar_archivo(); // Cerramos el archivo

    if (count == 0)
        printf("No se encontraron pasajeros para ese viaje\n");
}

void capturar_pasajero(){

    struct datos_cliente cliente; // Llamamos a la estructura

    modificar_archivo(); // Llamamos a la funci?n para modificar el archivo

    printf("\nIngrese el nombre completo del pasajero: ");
    fflush(stdin);
    fgets(cliente.nombre, 60, stdin);
    cliente.nombre[strcspn(cliente.nombre, "\n")] = '\0';

    printf("Ingrese la fecha de nacimiento (DD/MM/AAAA): ");
    scanf("%s", cliente.fecha_nacimiento);

    printf("Ingrese el RFC: ");
    scanf("%s", cliente.rfc);

    printf("Ingrese el tel%cfono: ", 160);
    scanf("%s", cliente.teleforo);

    printf("Ingrese la direcci%cn: ", 162);
    fflush(stdin);
    fgets(cliente.direccion, 60, stdin);
    cliente.direccion[strcspn(cliente.direccion, "\n")] = '\0';

    printf("Ingrese la edad: ");
    scanf("%d", &cliente.edad);

    printf("Ingrese el destino del viaje: ");
    fflush(stdin);
    fgets(cliente.viaje, 60, stdin);
    cliente.viaje[strcspn(cliente.viaje, "\n")] = '\0';

    printf("Ingrese el descuento (0 si no aplica): ");
    scanf("%d", &cliente.descuento);

    printf("Ingrese la fecha de registro: ");
    scanf("%s", cliente.fecha_registro);

    fwrite(&cliente, sizeof(cliente), 1, archivo); // Escribimos los datos del cliente en el archivo

    cerrar_archivo(); // Cerramos el archivo

    printf("Pasajero capturado con %cxito\n", 160);
}

void cancelar_pasajero(){

}

void lista_viajes_30_50_80_100(){

}

void modificar_pasajero(){

}
