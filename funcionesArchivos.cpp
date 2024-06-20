#include <iostream>
#include "callFunctions.h"
#include "structures.h"
#include <fstream>
#include <cstring>

using namespace std;

// //-----------------------------------------------------------------------
// void registerUser(){

//     ofstream userFile;
//     User _user;
//     userFile.open("users.bin", ios:: binary | ios:: app);

//     _user.id = generateID_User();

//     cout << "Ingrese nombre: ";
//     cin.ignore();
//     cin.getline(_user.firstName, sizeof(_user.firstName));

//     cout << "Ingrese apellido: ";
//     cin.getline(_user.lastName, sizeof(_user.lastName));

//     cout << "Ingrese Carnet de Identidad: ";
//     // cin.ignore();
//     cin >> _user.identityCard;

//     cout << "Ingrese password: ";
//     cin.ignore();
//     cin.getline(_user.password, sizeof(_user.password));

//     cout << "Ingrese correo electronico: ";
//     cin.getline(_user.email, sizeof(_user.email));

//     cout << "Ingrese numero de telefono: ";
//     // cin.ignore();
//     cin >> _user.phoneNumber;
//     cout << endl;

//     cout << "Ingrese fecha de nacimiento: ";
//     cin.ignore();
//     cin.getline(_user.birthdate, sizeof(_user.birthdate));
//     // fecha de creacion de la cuenta.
//     cout << "Ingrese fecha de creacion de la cuenta:";
//     cin.getline(_user.accountCreationDate, sizeof(_user.accountCreationDate));

//     cout << "Ingrese departamento: ";
//     cin.getline(_user.department, sizeof(_user.department));

//     cout << "Ingrese direccion: ";
//     cin.getline(_user.address, sizeof(_user.address));

//     _user.points = 0;

//     userFile.write((char*)&_user, sizeof(User));

//     userFile.close();

//     cout << "Cuenta Registrada." << endl;
// };

int generateID_User();
int generateID_Admin();
void displayUsers();
void registerUser();
void registerAdmin();
void loginUser();
void loginAdmin();


void registerUser() {
    ofstream userFile;
    User _user;
    userFile.open("users.bin", ios::binary | ios::app);

    if (!userFile) {
        cout << "No se pudo abrir el archivo para registrar el usuario." << endl;
        return;
    }

    _user.id = generateID_User();

    cout << "Ingrese nombre: ";
    cin.ignore();
    cin.getline(_user.firstName, sizeof(_user.firstName));

    cout << "Ingrese apellido: ";
    cin.getline(_user.lastName, sizeof(_user.lastName));

    cout << "Ingrese Carnet de Identidad: ";
    cin >> _user.identityCard;

    cout << "Ingrese password: ";
    cin.ignore();
    cin.getline(_user.password, sizeof(_user.password));

    cout << "Ingrese correo electronico: ";
    cin.getline(_user.email, sizeof(_user.email));

    cout << "Ingrese numero de telefono: ";
    cin >> _user.phoneNumber;

    cout << "Ingrese fecha de nacimiento (DD/MM/AAAA): ";
    cin.ignore();
    cin.getline(_user.birthdate, sizeof(_user.birthdate));

    cout << "Ingrese fecha de creacion de la cuenta (DD/MM/AAAA): ";
    cin.getline(_user.accountCreationDate, sizeof(_user.accountCreationDate));

    cout << "Ingrese departamento: ";
    cin.getline(_user.department, sizeof(_user.department));

    cout << "Ingrese direccion: ";
    cin.getline(_user.address, sizeof(_user.address));

    _user.points = 0;

    userFile.write((char*)&_user, sizeof(User));
    userFile.close();

    cout << "Cuenta Registrada." << endl;
}

int generateID_User() {

    ifstream userFile;
    User _user;
    userFile.open("users.bin", ios::binary);
    int contador = 0;
    while (userFile.read((char*)&_user, sizeof(User)))
    {
        contador ++;
    }
    userFile.close();
    return contador+1;    
}

// ----------------------------------------------------------------------
void registerAdmin(){

    ofstream adminFile;
    Admin _admin;
    adminFile.open("admins.bin", ios:: binary | ios:: app);

    _admin.id = generateID_Admin();

    cout << "Ingrese nombre: ";
    cin.ignore();
    cin.getline(_admin.firstName, sizeof(_admin.firstName));

    cout << "Ingrese apellido: ";
    cin.getline(_admin.lastName, sizeof(_admin.lastName));

    cout << "Ingrese Carnet de Identidad: ";
    cin >> _admin.identityCard;

    cout << "Ingrese password: ";
    cin.ignore();
    cin.getline(_admin.password, sizeof(_admin.password));

    cout << "Ingrese correo electronico: ";
    cin.getline(_admin.email, sizeof(_admin.email));

    cout << "Ingrese numero de telefono: ";
    cin >> _admin.phoneNumber;

    cout << "Ingrese fecha de nacimiento: ";
    cin.ignore();
    cin.getline(_admin.birthdate, sizeof(_admin.birthdate));

    // fecha de creacion de la cuenta.
    cout << "Ingrese fecha de creacion de la cuenta:";
    cin.getline(_admin.accountCreationDate, sizeof(_admin.accountCreationDate));

    cout << "Ingrese departamento: ";
    cin.getline(_admin.department, sizeof(_admin.department));

    cout << "Ingrese direccion: ";
    cin.getline(_admin.address, sizeof(_admin.address));


    adminFile.write((char*)&_admin, sizeof(Admin));
    adminFile.close();

    cout << "Administrador Registrado." << endl;
};

int generateID_Admin() {

    ifstream adminFile;
    Admin _admin;
    adminFile.open("admin.bin", ios::binary);
    int contador = 0;
    while (adminFile.read((char*)&_admin, sizeof(Admin)))
    {
        contador += 1;
    }
    adminFile.close();
    return contador+1;   
}
//--------------------------------------------------------------------  

void loginUser()
{
    ifstream userFile;
    User _user;
    userFile.open("users.bin", ios:: binary);

    if (userFile.fail())
    {
        cout << "El archivo no se pudo abrir. " << endl;
        exit(1);
    }
    
    long numeroCI;
    char password[21];
    cout << "Ingrese numero de CI: ";
    // cin.ignore();
    cin >> numeroCI;

    while (userFile.read((char*)&_user, sizeof(User)))
    {

        if (_user.identityCard == numeroCI)
        {
            cout << "Ingrese password: ";
            cin.ignore();
            cin.getline(password, 21);

            if (strcmp(password, _user.password) == 0)
            {
                cout << "Ingreso exitoso." << endl;

                cout << "\t Bienvenido " << _user.firstName << endl;

                menuCliente();


            } else {
                cout << "La password es incorrecta.";
                return;
            }
            
        } else

        {
            cout << "El numero de carnet es incorrecto.";
            return;
        }

    }    

    userFile.close();
};

void loginAdmin(){

    ifstream adminFile;
    Admin _admin;
    adminFile.open("admins.bin", ios:: binary);

    if (adminFile.fail())
    {
        cout << "El archivo no se pudo abrir. " << endl;
        exit(1);
    }
    
    long numeroCI;
    char password[21];
    cout << "Ingrese numero de CI: ";
    cin >> numeroCI;

    while (adminFile.read((char*)&_admin, sizeof(Admin)))
    {

        if (_admin.identityCard == numeroCI)
        {
            cout << "Ingrese password: ";
            cin.ignore();
            cin.getline(password, 21);

            if (strcmp(password, _admin.password) == 0)
            {
                cout << "Ingreso exitoso." << endl;

                cout << "\t Bienvenido " << _admin.firstName << endl;

                menuAdmin();
                // menu pe.
                // Aqui va la funciones que puede hacer el administrador.

            } else

            {
                cout << "La contraseña es incorrecta." << endl;
                return;
            }
            
        } else

        {
            cout << "La cuenta no existe." << endl;
            return;
        }

    }  

    adminFile.close() ;
}

void displayUsers(){
    ifstream userFile;
    User _user;
    userFile.open("users.bin", ios:: binary);

    cout << "Nro" << " NOMBRES " << " APELLIDOS " << endl;
    while (userFile.read((char*)&_user, sizeof(User)))
    {
        cout << _user.id << _user.firstName << _user.lastName << endl;
    }

    userFile.close();

};