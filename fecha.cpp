#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstring>  // Para strcpy

using namespace std;

struct Product {
    char dateOfSale[11];
    // Otros miembros de la estructura Product pueden ser añadidos aquí
    // Por ejemplo:
    // char descripcion[100];
};

struct Fecha{
    char fecha[11];
};

Fecha obtenerFechaActual() {
    time_t t = time(NULL);  // Obtener el tiempo actual
    struct tm *f = localtime(&t);  // Convertir a estructura tm para la hora local

    Fecha aux;
    snprintf(aux.fecha, sizeof(aux.fecha), "%02d/%02d/%04d", f->tm_mday, f->tm_mon + 1, f->tm_year + 1900);

    return aux;
}

int main() {
    // Crear una instancia de Product
    Product producto;

    // Obtener la fecha actual
    Fecha fechaActual = obtenerFechaActual();

    // Copiar la fecha formateada al miembro dateOfSale de la estructura Product
    strcpy(producto.dateOfSale, fechaActual.fecha);

    // Verificar el contenido (comentado porque no se quiere mostrar nada):
    // cout << "Fecha de venta: " << producto.dateOfSale << endl;
    cout << producto.dateOfSale<< endl;
    return 0;
}
