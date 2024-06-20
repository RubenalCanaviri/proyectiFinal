#ifndef FUNCIONES_H
#define FUNCIONES_H


using namespace std;
// funciones menu
void menuAdmin();
void menuPrincipal();
void menuClienteLogin();
void menuAdministradorLogin();
void menuCliente();
// funciones usuario-admin

void loginUser();
void loginAdmin();

//  Funciones registro.
void registerUser();
int generateID_User();
void registerAdmin();
int generateID_Admin();

// FUNCIONES PRODUCTOS. functionProducts.cpp
void addProduct();
void buyProducts();
//void addN_product();
void displayAllProducts();
void displayProductsByCategory();
void deleteProduct();

#endif
