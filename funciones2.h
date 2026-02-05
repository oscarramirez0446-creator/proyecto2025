#define MAX_LINEA 200

struct datos_cliente {
    char nombre[50];
    char apellidos[50];
    struct fecha fecha_nacimiento;
    char rfc[13];
    char teleforo[11];
    char direccion[60];
    int edad;
    int id_viaje;
};

// 1. Buscar pasajero por nombre
void buscar_pasajero() {
    leer_archivo();
    char nombre[50];
    int encontrado = 0;
    printf("Ingrese el nombre del pasajero: ");
    scanf(" %[^\n]", nombre);

    struct datos_cliente pasajero;
    while (fscanf(archivo, "%s %s %d/%d/%d %s %s %s %d %d\n",
        pasajero.nombre, pasajero.apellidos,
        &pasajero.fecha_nacimiento.dia, &pasajero.fecha_nacimiento.mes, &pasajero.fecha_nacimiento.anio,
        pasajero.rfc, pasajero.teleforo, pasajero.direccion, &pasajero.edad, &pasajero.id_viaje) == 10) {
        if (strcmp(nombre, pasajero.nombre) == 0) {
            printf("Pasajero encontrado: %s %s\n", pasajero.nombre, pasajero.apellidos);
            encontrado = 1;
        }
    }
    if (!encontrado) printf("Pasajero no encontrado.\n");
    cerrar_archivo();
}

// 2. Buscar viaje por ID
void buscar_viaje() {
    int id;
    printf("Ingrese el ID del viaje: ");
    scanf("%d", &id);

    leer_archivo();
    struct datos_cliente pasajero;
    int encontrado = 0;

    while (fscanf(archivo, "%s %s %d/%d/%d %s %s %s %d %d\n",
        pasajero.nombre, pasajero.apellidos,
        &pasajero.fecha_nacimiento.dia, &pasajero.fecha_nacimiento.mes, &pasajero.fecha_nacimiento.anio,
        pasajero.rfc, pasajero.teleforo, pasajero.direccion, &pasajero.edad, &pasajero.id_viaje) == 10) {
        if (pasajero.id_viaje == id) {
            printf("Pasajero: %s %s\n", pasajero.nombre, pasajero.apellidos);
            encontrado = 1;
        }
    }
    if (!encontrado) printf("No se encontraron pasajeros en ese viaje.\n");
    cerrar_archivo();
}

// 3. Mostrar lista de pasajeros por viaje
void mostrar_lista_pasajeros() {
    int id;
    printf("Ingrese el ID del viaje: ");
    scanf("%d", &id);

    leer_archivo();
    struct datos_cliente pasajero;
    printf("Pasajeros del viaje %d:\n", id);
    while (fscanf(archivo, "%s %s %d/%d/%d %s %s %s %d %d\n",
        pasajero.nombre, pasajero.apellidos,
        &pasajero.fecha_nacimiento.dia, &pasajero.fecha_nacimiento.mes, &pasajero.fecha_nacimiento.anio,
        pasajero.rfc, pasajero.teleforo, pasajero.direccion, &pasajero.edad, &pasajero.id_viaje) == 10) {
        if (pasajero.id_viaje == id) {
            printf("- %s %s\n", pasajero.nombre, pasajero.apellidos);
        }
    }
    cerrar_archivo();
}

// 4. Capturar pasajero
void capturar_pasajero() {
    struct datos_cliente nuevo;
    printf("Nombre: "); scanf(" %[^\n]", nuevo.nombre);
    printf("Apellidos: "); scanf(" %[^\n]", nuevo.apellidos);
    printf("Fecha nacimiento (dd mm aaaa): "); scanf("%d %d %d", &nuevo.fecha_nacimiento.dia, &nuevo.fecha_nacimiento.mes, &nuevo.fecha_nacimiento.anio);
    printf("RFC: "); scanf(" %s", nuevo.rfc);
    printf("Telefono: "); scanf(" %s", nuevo.teleforo);
    printf("Direccion: "); scanf(" %[^\n]", nuevo.direccion);
    printf("Edad: "); scanf("%d", &nuevo.edad);
    printf("ID del viaje: "); scanf("%d", &nuevo.id_viaje);

    modificar_archivo();
    fprintf(archivo, "%s %s %d/%d/%d %s %s %s %d %d\n",
        nuevo.nombre, nuevo.apellidos,
        nuevo.fecha_nacimiento.dia, nuevo.fecha_nacimiento.mes, nuevo.fecha_nacimiento.anio,
        nuevo.rfc, nuevo.teleforo, nuevo.direccion, nuevo.edad, nuevo.id_viaje);
    cerrar_archivo();
    printf("Pasajero registrado con éxito.\n");
}

// 5. Cancelar pasajero
void cancelar_pasajero() {
    char nombre[50];
    printf("Ingrese el nombre del pasajero a eliminar: ");
    scanf(" %[^\n]", nombre);

    struct datos_cliente lista[500];
    int total = 0;

    leer_archivo();
    struct datos_cliente pasajero;
    while (fscanf(archivo, "%s %s %d/%d/%d %s %s %s %d %d\n",
        pasajero.nombre, pasajero.apellidos,
        &pasajero.fecha_nacimiento.dia, &pasajero.fecha_nacimiento.mes, &pasajero.fecha_nacimiento.anio,
        pasajero.rfc, pasajero.teleforo, pasajero.direccion, &pasajero.edad, &pasajero.id_viaje) == 10) {
        lista[total++] = pasajero;
    }
    cerrar_archivo();

    int encontrados = 0;
    modificar_archivo();
    for (int i = 0; i < total; i++) {
        if (strcmp(lista[i].nombre, nombre) != 0) {
            fprintf(archivo, "%s %s %d/%d/%d %s %s %s %d %d\n",
                lista[i].nombre, lista[i].apellidos,
                lista[i].fecha_nacimiento.dia, lista[i].fecha_nacimiento.mes, lista[i].fecha_nacimiento.anio,
                lista[i].rfc, lista[i].teleforo, lista[i].direccion, lista[i].edad, lista[i].id_viaje);
        } else {
            encontrados++;
        }
    }
    cerrar_archivo();

    if (encontrados > 0) printf("Pasajero eliminado.\n");
    else printf("Pasajero no encontrado.\n");
}

// 6. Modificar reservación
void modificar_reservacion() {
    char nombre[50];
    printf("Ingrese el nombre del pasajero a modificar: ");
    scanf(" %[^\n]", nombre);

    struct datos_cliente lista[500];
    int total = 0, modificado = 0;

    leer_archivo();
    struct datos_cliente pasajero;
    while (fscanf(archivo, "%s %s %d/%d/%d %s %s %s %d %d\n",
        pasajero.nombre, pasajero.apellidos,
        &pasajero.fecha_nacimiento.dia, &pasajero.fecha_nacimiento.mes, &pasajero.fecha_nacimiento.anio,
        pasajero.rfc, pasajero.teleforo, pasajero.direccion, &pasajero.edad, &pasajero.id_viaje) == 10) {
        if (strcmp(pasajero.nombre, nombre) == 0) {
            printf("Nuevo ID de viaje: ");
            scanf("%d", &pasajero.id_viaje);
            modificado = 1;
        }
        lista[total++] = pasajero;
    }
    cerrar_archivo();

    modificar_archivo();
    for (int i = 0; i < total; i++) {
        fprintf(archivo, "%s %s %d/%d/%d %s %s %s %d %d\n",
            lista[i].nombre, lista[i].apellidos,
            lista[i].fecha_nacimiento.dia, lista[i].fecha_nacimiento.mes, lista[i].fecha_nacimiento.anio,
            lista[i].rfc, lista[i].teleforo, lista[i].direccion, lista[i].edad, lista[i].id_viaje);
    }
    cerrar_archivo();

    if (modificado) printf("Reservación modificada.\n");
    else printf("Pasajero no encontrado.\n");
}

// 7. Mostrar lista de viajes según ocupación
void mostrar_lista_viajes_con_porcentaje() {
    int conteo[100] = {0};
    leer_archivo();
    struct datos_cliente pasajero;

    while (fscanf(archivo, "%s %s %d/%d/%d %s %s %s %d %d\n",
        pasajero.nombre, pasajero.apellidos,
        &pasajero.fecha_nacimiento.dia, &pasajero.fecha_nacimiento.mes, &pasajero.fecha_nacimiento.anio,
        pasajero.rfc, pasajero.teleforo, pasajero.direccion, &pasajero.edad, &pasajero.id_viaje) == 10) {
        conteo[pasajero.id_viaje]++;
    }
    cerrar_archivo();

    printf("Viajes según número de pasajeros registrados:\n");
    for (int i = 0; i < 100; i++) {
        if (conteo[i] > 0) {
            printf("Viaje ID %d: %d pasajeros\n", i, conteo[i]);
        }
    }
}

