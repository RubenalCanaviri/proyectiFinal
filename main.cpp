#include <iostream>
#include "callFunctions.h"
#include "structures.h"

using namespace std;

int main()
{

    //  Para correr el archivo se debe de poner todos los archivos (.cpp).
    //  si antes con g++ poniamos: 
    //  ---------------------
    //  g++ main.cpp o main
    //  ---------------------

    //  Ahora debemos poner el nombre de todos los archivos.
    //  --------------------------------------------------------------------------
    //  g++ main.cpp menus.cpp funcionesArchivos.cpp functionProducts.cpp -o main 
    //  --------------------------------------------------------------------------

    // Incompleto. falta conectar funciones para el usuario/admin.
    // falta crear funciones para el usuario/admin.
    // falta el apartado de reportes.
    // falta ajustar la interfaz, al desplegar el menu y los datos, para comodidad del usuario/admin.
    
    menuPrincipal();

    return 0;
}

