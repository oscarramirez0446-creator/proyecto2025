#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100
#define prods 100
#define sale 1000

typedef struct _empleado {
    int id_empleado;
    char nombre[50], telefono[15], direccion[40];
    char correo[30], puesto[20];
    float sueldo_base;
    char turno[20];
    int comision;
} Empleado;

typedef struct _producto {
    char Nombre[20];
    float Precio;
    float Precio_lista;
    char Descripcion[30];
    int Id_producto;
    int Cantidad;
} Producto;

typedef struct _fecha{
	int dia;
	int mes;
	int anio;
}fecha;

typedef struct _ventas{
	int id_ventas;
	int id_emp;
	int id_prod;
	int cantidad;
	float totalvent;
	fecha fecha_vent;
}Ventas;



int mostrarEmpleado(Empleado trabajador[TAM], int cont_emp) {
    int i;
    for (i = 0; i < cont_emp; i++) {
        printf("\nid del empleado %d", trabajador[i].id_empleado);
        printf("\nnombre del empleado %s", trabajador[i].nombre);
        printf("\ntelefono %s", trabajador[i].telefono);
        printf("\nimpuesto %.2f", trabajador[i].sueldo_base);
        printf("\nTurno %s", trabajador[i].turno);
        printf("\n---------------------------------------------------------------------------------");
    }
    return 0;
}

int modificarEmpleado(Empleado trabajador[TAM], int index) {
    printf("Dame el nombre del empleado: ");
    fflush(stdin);
    fgets(trabajador[index].nombre, 50, stdin);

    printf("\nNumero de telefono: ");
    fflush(stdin);
    fgets(trabajador[index].telefono, 15, stdin);

    printf("\nEscribe la direccion: ");
    fflush(stdin);
    fgets(trabajador[index].direccion, 40, stdin);

    printf("\n¿Que puesto tiene el empleado?: ");
    fflush(stdin);
    fgets(trabajador[index].puesto, 20, stdin);

    printf("\nSueldo base: ");
    scanf("%f", &trabajador[index].sueldo_base);

    printf("\n¿Que turno tiene?: ");
    fflush(stdin);
    fgets(trabajador[index].turno, 20, stdin);

    printf("\nComision del trabajador: ");
    scanf("%d", &trabajador[index].comision);

    return 0;
}

int buscarEmpleado(Empleado trabajador[TAM], int cont_emp, char nom[50]) {
    int i;
	for (i = 0; i < cont_emp; i++) 
        if (strcmp(trabajador[i].nombre, nom) == 0)
            return i;
    
    return -1;
}

int buscarID_Empleado(Empleado trabajador[TAM], int cont_emp, int id) {
		int i;  
    for (i = 0; i < cont_emp; i++) {
        if (trabajador[i].id_empleado == id)
            return i;
    }
    return -1;
}

void eliminarEmpleado(Empleado trabajador[TAM], int *cont_emp, int id) {
    int i = id;
    while (i < *cont_emp - 1) {
        trabajador[i] = trabajador[i + 1];
        i++;
    }
    (*cont_emp)--;
}

int mostrar_empleado(Empleado trabajador[TAM], int cont_emp) {
    int i;  
	if (cont_emp == 0) {
        printf("\nNo hay empleados registrados.\n");
        return 0;
    }

    for (i = 0; i < cont_emp; i++) {
        printf("\nID: %d\n", trabajador[i].id_empleado);
        printf("Nombre: %s", trabajador[i].nombre);
        printf("Telefono: %s", trabajador[i].telefono);
        printf("Dirección: %s", trabajador[i].direccion);
        printf("Puesto: %s", trabajador[i].puesto);
        printf("Sueldo base: %.2f\n", trabajador[i].sueldo_base);
        printf("Turno: %s", trabajador[i].turno);
        printf("Comision: %d\n", trabajador[i].comision);
    }

    return 0;
}

void CapturaEmpleado(Empleado trabajador[TAM], int *cont_emp) {
    printf("Dame el nombre del empleado: ");
    fflush(stdin);
    fgets(trabajador[*cont_emp].nombre, 50, stdin);

    printf("\nNumero de telefono: ");
    fflush(stdin);
    fgets(trabajador[*cont_emp].telefono, 15, stdin);

    printf("\nEscribe la direccion: ");
    fflush(stdin);
    fgets(trabajador[*cont_emp].direccion, 40, stdin);

    printf("\n¿Que puesto tiene el empleado?: ");
    fflush(stdin);
    fgets(trabajador[*cont_emp].puesto, 20, stdin);

    printf("\nSueldo base: ");
    scanf("%f", &trabajador[*cont_emp].sueldo_base);

    printf("\n¿Que turno tiene?: ");
    fflush(stdin);
    fgets(trabajador[*cont_emp].turno, 20, stdin);

    printf("\nComision del trabajador: ");
    scanf("%d", &trabajador[*cont_emp].comision);

    if (*cont_emp == 0)
        trabajador[*cont_emp].id_empleado = 12345;
    else
        trabajador[*cont_emp].id_empleado = trabajador[*cont_emp - 1].id_empleado + 1;

    (*cont_emp)++;
}

int menu_empleado() {
    int op;
    system("cls");
    printf("\n\t--MENU EMPLEADO--\t\n");
    printf("\n1. Capturar"
           "\n2. Mostrar"
           "\n3. Consultar"
           "\n4. Consultar ventas empleado"
           "\n5. Eliminar empleado"
           "\n6. Modificar empleado"
           "\n7. Regresar al menu principal\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &op);
    return op;
}

// ============ FUNCIONES DE PRODUCTO ============

int mostrarProducto(Producto prod[prods], int cont_prod) {
    int i;  
	for (i = 0; i < cont_prod; i++) {
        printf("\nid del producto %d", prod[i].Id_producto);
        printf("\nnombre del producto %s", prod[i].Nombre);
        printf("\nPrecio %.2f", prod[i].Precio);
        printf("\nPrecio de lista %.2f", prod[i].Precio_lista);
        printf("\nCantidad disponible %d", prod[i].Cantidad);
        printf("\n---------------------------------------------------------------------------------");
    }
    return 0;
}

int modificarProducto(Producto prod[prods], int index) {
    printf("\nDame el nombre del producto: ");
    fflush(stdin);
    fgets(prod[index].Nombre, 20, stdin);

    printf("\nPrecio de venta: ");
    scanf("%f", &prod[index].Precio);

    printf("\nPrecio de lista: ");
    scanf("%f", &prod[index].Precio_lista);

    printf("\nDescripcion del producto: ");
    fflush(stdin);
    fgets(prod[index].Descripcion, 30, stdin);

    printf("\nCantidad disponible: ");
    scanf("%d", &prod[index].Cantidad);

    return 0;
}

int buscarProducto(Producto prod[prods], int cont_prod, char nom[50]) {
    int i;  
	for (i = 0; i < cont_prod; i++) {
        if (strcmp(prod[i].Nombre, nom) == 0)
            return i;
    }
    return -1;
}

int buscarID_producto(Producto prod[prods], int cont_prod, int id) {
    int i;  
	for ( i = 0; i < cont_prod; i++) {
        if (prod[i].Id_producto == id)
            return i;
    }
    return -1;
}

void eliminarProducto(Producto prod[prods], int *cont_prod, int id) {
    int i = id;
    while (i < *cont_prod - 1) {
        prod[i] = prod[i + 1];
        i++;
    }
    (*cont_prod)--;
}

int mostrar_producto(Producto prod[prods], int cont_prod) {
   int i;  
    if (cont_prod == 0) {
        printf("\nNo hay productos registrados.\n");
        return 0;
    }

    for ( i = 0; i < cont_prod; i++) {
        printf("\nID: %d\n", prod[i].Id_producto);
        printf("Nombre producto: %s", prod[i].Nombre);
        printf("Precio: %.2f\n", prod[i].Precio);
        printf("Precio de lista: %.2f\n", prod[i].Precio_lista);
        printf("Descripcion: %s", prod[i].Descripcion);
        printf("Cantidad disponible: %d\n", prod[i].Cantidad);
    }

    return 0;
}

void CapturProducto(Producto prod[prods], int *cont_prod) {
    printf("Dame el nombre del producto: ");
    fflush(stdin);
    fgets(prod[*cont_prod].Nombre, 20, stdin);

    printf("\nPrecio de venta: ");
    scanf("%f", &prod[*cont_prod].Precio);

    printf("\nPrecio de lista: ");
    scanf("%f", &prod[*cont_prod].Precio_lista);

    printf("\nDescripcion del producto: ");
    fflush(stdin);
    fgets(prod[*cont_prod].Descripcion, 30, stdin);

    printf("\nCantidad disponible: ");
    scanf("%d", &prod[*cont_prod].Cantidad);

    if (*cont_prod == 0)
        prod[*cont_prod].Id_producto = 1000;
    else
        prod[*cont_prod].Id_producto = prod[*cont_prod - 1].Id_producto + 1;

    (*cont_prod)++;
}

int menu_Producto() {
    int op;
    system("cls");
    printf("\n\t--MENU PRODUCTO--\t\n");
    printf("\n1. Capturar"
           "\n2. Mostrar"
           "\n3. Consultar"
           "\n4. Consultar ventas producto"
           "\n5. Eliminar producto"
           "\n6. Modificar producto"
           "\n7. Regresar al menu principal\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &op);
    return op;
}
int menu_ventas() {
    int op;
    system("cls");
    printf("\n\t--Ventas--\t\n");
    printf("\n1. Mostar"
           "\n2. Capturar");
    printf("Seleccione una opcion: ");
    scanf("%d", &op);
    return op;
}

//----------Registro de ventas--------

float calcularTotal(Producto prod, int cantidad) {
    return prod.Precio * cantidad;
}

void registrarVenta(Ventas venta, Producto productos[prods], id_emp,id_prod,id_ventas, int *cont_ven) {
 int id, cant;
 venta[*cont_ven].id_emp = id_emp;
 printf("Dame el id del producto");
 scanf("%d", &id);
 int indice = buscarProducto(prod,cont_prod, id)
 if(indice != -1)
 venta[*cont_ven].id_prod = id;
 printf("Cuantos productos quieres comprar ");
 scanf("%d", &cant);
 if (cant > 0 && cant<= prod[indice].cantidad){
 	venta[cont_ven].cantidad = cant;
	 prod[cont_prod].cantidad -=cant;	
	  }
	  printf("Escribe la fecha dia/Mes/anio ");
	  scanf("%d/%s/%d", &venta[*cont_ven].fecha_vent.dia,&venta[*cont_ven].fecha_vent.mes,&venta[*cont_ven].fecha_vent.anio);
	  venta[cont_ven].totalvent = cant *prod[indice].Precio;
	  *cont_ven = cont_vent+1;
}
 
 
 
 
 /*   int idProducto, idEmpleado;

    printf("Ingrese el ID del empleado: ");
    scanf("%d", &idEmpleado);

    if (idEmpleado < 0 || idEmpleado >= totalEmpleados) {
        printf("Empleado no encontrado.\n");
        return;
    }

    printf("Ingrese el ID del producto: ");
    scanf("%d", &idProducto);

    if (idProducto < 0 || idProducto >= totalProductos) {
        printf("Producto no encontrado.\n");
        return;
    }

    printf("Ingrese la cantidad: ");
    scanf("%d", &venta->cantidad);

    if (venta->cantidad > productos[idProducto].Cantidad) {
        printf("Cantidad insuficiente en inventario.\n");
        return;
    }

    venta->totalvent = calcularTotal(productos[idProducto], venta->cantidad);

    venta->id_emp = idEmpleado;
    venta->id_prod = idProducto;

    productos[idProducto].Cantidad -= venta->cantidad;

    venta->id_ventas = *cont_ven;
    (*cont_ven)++;

    printf("Ingrese la fecha de la venta (DD MM YYYY): ");
    scanf("%d %d %d", &venta->fecha_vent.dia, &venta->fecha_vent.mes, &venta->fecha_vent.anio);

    printf("Venta registrada con exito.\n");
    printf("Producto: %s\n", productos[idProducto].Nombre);
    printf("Cantidad: %d\n", venta->cantidad);
    printf("Total: %.2f\n", venta->totalvent);
    printf("Fecha: %02d/%02d/%d\n", venta->fecha_vent.dia, venta->fecha_vent.mes, venta->fecha_vent.anio);
}*/

void registrarVenta(Ventas venta[], Producto productos[], int cont_prod, int id_emp, int *cont_ven) {
    int id, cant, indice;

    venta[*cont_ven].id_emp = id_emp;

    printf("Dame el id del producto: ");
    scanf("%d", &id);

    indice = buscarProducto(productos, cont_prod, id);

    if (indice != -1) {
        venta[*cont_ven].id_prod = id;

        printf("¿Cuántos productos quieres comprar?: ");
        scanf("%d", &cant);

        if (cant > 0 && cant <= productos[indice].cantidad) {
            venta[*cont_ven].cantidad = cant;
            productos[indice].cantidad -= cant;

            printf("Escribe la fecha (dia mes anio): ");
            scanf("%d %s %d", 
                  &venta[*cont_ven].fecha_vent.dia,
                  venta[*cont_ven].fecha_vent.mes,
                  &venta[*cont_ven].fecha_vent.anio);

            venta[*cont_ven].totalvent = cant * productos[indice].Precio;
            (*cont_ven)++;
        } else {
            printf("Cantidad no válida o insuficiente.\n");
        }
    } else {
        printf("Producto no encontrado.\n");
    }
}


void Consulta_ventaEmpleado(Ventas venta[], int i, int idEmpleado){
	int cont_venta;
	for(cont_venta =0; cont_venta< i; cont_venta++)
	if (venta[cont_venta].id_emp == idEmpleado){
		mostarVentas(venta, cont_venta);
	}
	
}
