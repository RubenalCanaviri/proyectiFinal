#include "callFunctions.h"
#include <iostream>

using namespace std;

void menuPrincipal(){

    system("cls");

    int opcion;

    do
    {

        cout << "\t SISTEMA DE GESTION DE BEBIDAS ";
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "\t \t 1. Clientes.";
        cout << endl;
        cout << endl;
        cout << "\t \t 7. Administrador.";
        cout << endl;
        cout << "\t \t 9. Cerrar Programa.";
        cout << endl;
        cout << endl;
        cout << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            menuClienteLogin();
            break;
        case 7:
            menuAdministradorLogin();
            break;
        case 9:
            cout << "\t CERRANDO EL PROGRAMA." << endl;
            exit(0);
        default:
            cout << "Opcion no valida. Intente de nuevo.\n";
        }
        
    } while (opcion != 3);

}


void menuClienteLogin(){

    system("cls");

    int opcion;

    do
    {

        cout << "\t SISTEMA DE GESTION DE BEBIDAS   ";
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "\t \t 1. Ingreso usuario.";
        cout << endl;
        cout << endl;
        cout << "\t \t 2. Registrarse como usuario nuevo.";
        cout << endl;
        cout << "\t \t 3. Atras. ";
        cout << endl;
        cout << endl;
        cout << "\t \t 9. Cerrar el programa";

        cout << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            loginUser();
            break;
        case 2:
            registerUser();
            break;
        case 3:
            cout << "\t Atras." << endl;
            break;
        case 9:
            cout << "\t CERRANDO EL PROGRAMA." << endl;
            exit(0);
        default:
            cout << "Opcion no valida. Intente de nuevo.\n";
        }
        
    } while (opcion != 3);

}


void menuAdministradorLogin(){

    system("cls");

    int opcion;

    do
    {

        cout << "\t ADMINISTRADOR";
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "\t \t 1. Ingresar Admin.";
        cout << endl;
        cout << "\t \t 2. Registrase como Admin.";
        cout << endl;
        cout << endl;
        cout << "\t \t 3. Atras.";
        cout << endl;
        cout << "\t \t 9. Cerrar Programa.";
        cout << endl;
        cout << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            loginAdmin();
            break;
        case 2:
            registerAdmin();
            break;
        case 3:
            cout << "\t Atras." << endl;
            break;
        case 9:
            cout << "\t CERRANDO EL PROGRAMA." << endl;
            exit(0);
        default:
            cout << "Opcion no valida. Intente de nuevo.\n";
        }
        
    } while (opcion != 3);

}

void menuCliente(){

    system("cls");

    cout << "Bienvenido Cliente" << endl;

    
int opcion;



        // PRODUCTOS funciones
    do
    {

        cout << "\t CLIENTE";
        cout << "\t \t 1. Comprar Producto." << endl;;
        cout << "\t \t 2. Funcion usuario." << endl;;
        cout << "\t \t 3. Atras." << endl;
        cout << "\t \t 9. Cerrar Programa." << endl;
        
        cout << "Ingrese opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            buyProducts();
            break;
        case 2:
            //  funcion usuario 1
            break;
        case 3:
            cout << "\t Atras." << endl;
            break;
        case 9:
            cout << "\t CERRANDO EL PROGRAMA.";
            exit(0);
        default:
            cout << "Opcion no valida. Intente de nuevo.\n";
        }
        
    } while (opcion != 3);

}


void menuAdmin()
{
    int opcion;

    do
    {

        cout << "\t \t \t 1. Ver lista de productos." << endl;
        cout << "\t \t \t 2. Ver lista de productos por categoria." << endl;        
        cout << "\t \t \t 3. Registrar producto." << endl;
        cout << "\t \t \t 4. Borrar Producto. "<< endl;
        cout << "\t \t \t 5. Atras. " << endl;
        cout << "\t \t \t 9. Cerrar el programa" << endl;
        cout << endl;
        cout << "Ingrese opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            displayAllProducts();
            break;
        case 2:
            displayProductsByCategory();
            break;
        case 3:
            addProduct();
            break;
        case 4:
            deleteProduct();
            break;
        case 5:
            cout << "\t Atras." << endl;
            break;
        case 9:
            cout << "\t CERRANDO EL PROGRAMA.";
            exit(0);
        default:
            cout << "Opcion no valida. Intente de nuevo.\n" << endl;
        }
        
    } while (opcion != 5);
}