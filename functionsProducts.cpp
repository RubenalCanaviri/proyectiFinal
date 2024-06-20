#include <iostream>
#include "structures.h"
#include <fstream>
#include <stdlib.h>
#include "callFunctions.h"
#include <cstring>
#include <iomanip>
#include <vector>
#include <string>
#include <iomanip>


using namespace std;


// Prototipos
void addProduct();
void addN_product();
void displayAllProducts();
int generateCodeProduct();
void displayProductsByCategory();
void deleteProduct();
void reportGenerator(const User& user, const BuyProduct& buyProduct);

void addProduct()
{
    ofstream productFile;

    Product _product;

    vector <string>categorias;
    categorias = {"Cervezas y Chicha", "Gaseosas", "Maltas y Bi-cervecinas", "Agua, Isotonicos y otros"};

    productFile.open("inventory.bin", ios:: binary | ios:: app);

    if (productFile.fail())
    {
        cout << "No se pudo abrir el archivo." << endl;
        exit(1);
    }

    _product.number = generateCodeProduct();
    cout << "CATEGORIAS: " << endl;
    cout << "1. Cervezas y Chicha 2. Gaseosas 3. Maltas y Bi-cervecinas 4 Agua, Isotonicos y otros" << endl;
    cout << "Ingrese categoria del producto: ";
    cin >>_product.category;
    cout << "Ingrese marca del producto: ";
    cin.ignore();
    cin.getline(_product.brand, sizeof(_product.brand));

    cout << "Ingrese el descripcion del producto: ";
    cin.getline(_product.description, sizeof(_product.description));
    cout << "Ingresa el precio por caja/paquete: ";
    cin >> _product.price;
    cout << "Ingrese la cantidad de Cajas/Paquetes disponibles: ";
    cin >> _product.stock;
    cout << "Ingrese los puntos que se obtendran por cada compra de esta caja/producto: ";
    cin >> _product._points;

    productFile.write((char*)&_product, sizeof(Product));
    productFile.close();


    cout << "Producto adicionado." << endl;

};


void addN_product()
{
    int n;
    cout << "Cuantos productos deseas adicionar: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        addProduct();
    }
};  
void displayAllProducts()
{
    system("cls");
    ifstream productFile("inventory.bin", ios::binary);
    if (!productFile.is_open())
    {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    vector<string> categorias = {"Cervezas y Chicha", "Gaseosas", "Maltas y Bi-cervecinas", "Agua, Isotonicos y otros"};
    
    Product _product;

    cout << left << setw(5) << "Nro" << setw(25) << "Categoria" << setw(21) << "Marca" << setw(30) << "Descripcion" << setw(10) << "Cantidad" << setw(10) << "Precio" << setw(10) << "Puntos" << endl;
    
    while (productFile.read(reinterpret_cast<char*>(&_product), sizeof(Product)))
    {
        cout << left << setw(5) << _product.number
             << setw(25) << categorias[_product.category - 1]
             << setw(21) << _product.brand
             << setw(30) << _product.description
             << setw(10) << _product.stock
             << setw(10) << fixed << setprecision(2) << _product.price
             << setw(10) << _product._points << endl;
    }

    productFile.close();
}


void displayProductsByCategory()
{
    vector<string> categorias = {"Cervezas y Chicha", "Gaseosas", "Maltas y Bi-cervecinas", "Agua, Isotonicos y otros"};
    ifstream productFile("inventory.bin", ios::binary);

    if (!productFile.is_open())
    {
        cout << "El archivo no se pudo abrir." << endl;
        return;
    }

    int option = 0;
    do
    {
        cout << "CATEGORIAS: " << endl;
        cout << "1. Cervezas y Chicha 2. Gaseosas 3. Maltas y Bi-cervecinas 4. Agua, Isotonicos y otros" << endl;
        cout << "Ingrese categoría del producto: ";
        cin >> option;

        if (option < 1 || option > 4)
        {
            cout << "Número no válido. Intente de nuevo." << endl;
        }

    } while (option < 1 || option > 4);

    option = option - 1; // Ajuste del índice

    cout << "\tCATEGORIA: " << categorias[option] << endl;
    cout << left << setw(8) << "CODIGO" << setw(25) << "MARCA" << setw(30) << "DESCRIPCION" << setw(10) << "PRECIO" << setw(10) << "STOCK" << setw(10) << "PUNTOS" << endl;
    
    Product _product;
    while (productFile.read(reinterpret_cast<char*>(&_product), sizeof(Product)))
    {
        if (_product.category - 1 == option)
        {
            cout << left << setw(8) << _product.number
                 << setw(25) << _product.brand
                 << setw(30) << _product.description
                 << setw(10) << fixed << setprecision(2) << _product.price
                 << setw(10) << _product.stock
                 << setw(10) << _product._points << endl;
        }
    }

    productFile.close();
}

void deleteProduct()
{
    displayAllProducts();

    ifstream productFile;
    ofstream tempFile;

    productFile.open("inventory.bin", ios::binary);
    tempFile.open("temporal.bin", ios::binary | ios::app);

    if (productFile.fail() || tempFile.fail())
    {
        cout << "Uno de los archivos no se pudo abrir. " << endl;
        exit(1);
    }

    Product _product;

    int numero;
    cout << "Ingrese numero del producto a eliminar: ";
    cin >> numero;

    while (productFile.read((char*)&_product, sizeof(Product)))
    {
        if (_product.number != numero)
        {
            tempFile.write((char*)&_product, sizeof(Product));
        }
        
    }

    tempFile.close();
    productFile.close();
    
    remove("inventory.bin");
    rename("temporal.bin", "inventory.bin");
    
    
};

int generateCodeProduct() {

    ifstream productFile;
    Product _product;

    productFile.open("inventory.bin", ios::binary);
    int contador = 0;
    while (productFile.read((char*)&_product, sizeof(Product)))
    {
        contador ++;
    }
    productFile.close();
    return contador+1;   
};

void buyProducts() {
    BuyProduct _buyProduct;
    Product _product;
    User _user;

    ifstream userFile, productFile;
    ofstream shoppingFile, tempFile;
    userFile.open("users.bin", ios::binary);
    productFile.open("inventory.bin", ios::binary);
    shoppingFile.open("purchases.bin", ios::binary | ios::app);
    tempFile.open("temp_inventory.bin", ios::binary | ios::out);

    displayAllProducts();

    int option = 0;
    int numero = 0;
    int cantidad = 0;
    float precio = 0;
    float precioTotal = 0;


    do {
        cout << "Selecciona el numero del producto: ";
        cin >> numero;

        productFile.clear(); // Limpiar el estado de error
        productFile.seekg(0, ios::beg); // Volver al inicio del archivo

        bool productFound = false;
        while (productFile.read((char*)&_product, sizeof(Product))) {
            if (numero == _product.number) {
                productFound = true;
                cout << "Selecciona la cantidad que quieres comprar: ";
                cin >> cantidad;

                if (cantidad > _product.stock) {
                    cout << "No hay suficiente stock disponible." << endl;
                    break;
                }

                precio = _product.price;
                cout << "El precio por paquete/caja es: " << precio << " Bs." << endl;
                precioTotal = precio * cantidad;
                cout << "El precio total es: " << precioTotal << " Bs." << endl;
                cout << "Compra Exitosa." << endl;

                _product.stock -= cantidad;

                _buyProduct.identityCard = _user.identityCard;
                _buyProduct.number = numero;
                _buyProduct.stock = cantidad;
                _buyProduct.price = precio;
                _buyProduct.totalPrice = precioTotal;

                strcpy(_buyProduct.brand, _product.brand);
                strcpy(_buyProduct.description, _product.description);
                _buyProduct._points = _product._points;

                cout << "Ingrese la fecha en formato DD/MM/AAAA: ";
                cin.ignore();
                cin.getline(_buyProduct.date, sizeof(_buyProduct.date));

                shoppingFile.write((char*)&_buyProduct, sizeof(BuyProduct));
            }
            tempFile.write((char*)&_product, sizeof(Product));
        }

        if (!productFound) {
            cout << "El numero del producto no es valido." << endl;
        }

        cout << "Deseas comprar algo mas? 1. SI, Cualquier numero 'NO': ";
        cin >> option;
    } while (option == 1);

    userFile.close();
    productFile.close();
    shoppingFile.close();
    tempFile.close();

    remove("inventory.bin");
    
    rename("temp_inventory.bin", "inventory.bin");

    // Llamar a reportGenerator con los datos necesarios
    reportGenerator(_user, _buyProduct);
}

void reportGenerator(const User& user, const BuyProduct& buyProduct) {
    ofstream reportFileTxt;
    // Generar el nombre del archivo de reporte único
    string fileName = "reporteUsuario" + to_string(user.identityCard) + "Factura" + to_string(buyProduct.number) + ".txt";
    
    reportFileTxt.open(fileName);

    if (!reportFileTxt.is_open()) {
        cerr << "Error al abrir el archivo: " << fileName << endl;
        return;
    }

    // Escribir información en el archivo de reporte
    reportFileTxt << "********** Factura de Compra **********" << endl << endl;

    reportFileTxt << "NIT: 1020229024" << endl;
    reportFileTxt << "Usuario: " << user.firstName << " " << user.lastName << endl;
    reportFileTxt << "Carnet de Identidad: " << user.identityCard << endl << endl;

    reportFileTxt << "Producto Comprado:" << endl;
    reportFileTxt << "Número de Producto: " << buyProduct.number << endl;
    reportFileTxt << "Marca: " << buyProduct.brand << endl;
    reportFileTxt << "Descripción: " << buyProduct.description << endl;
    reportFileTxt << "Cantidad Comprada: " << buyProduct.stock << endl;
    reportFileTxt << "Precio por Caja/Paquete: " << buyProduct.price << " Bs." << endl;
    reportFileTxt << "Precio Total: " << buyProduct.totalPrice << " Bs." << endl << endl;

    reportFileTxt << "Fecha de Compra: " << buyProduct.date << endl;

    reportFileTxt.close();

    cout << "Reporte generado exitosamente: " << fileName << endl;
}