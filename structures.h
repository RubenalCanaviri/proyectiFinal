#ifndef STRUCTURES_H
#define STRUCTURE_H

struct User
{

    long id;
    char firstName[21];
    char lastName[21];
    long identityCard;
    char password[21];
    char email[30];
    long phoneNumber;
    char birthdate[11];
    char accountCreationDate[11];
    char department[11];
    char address[51];
    long points;
};

struct Admin
{
    long id;
    char firstName[21];
    char lastName[21];
    long identityCard;
    char password[21];
    char email[21];
    long phoneNumber;
    char birthdate[11];
    char accountCreationDate[11];
    char department[11];
    char address[51];

};

struct Product
{
    int number;
    int category;
    char brand[21];
    char description[30];
    float price;
    int stock;
    long _points;
};

struct BuyProduct
{
    long identityCard;
    int number;
    int stock;
    float price;
    float totalPrice;
    char brand[21];
    char description[30];
    long _points;
    char date[11];
};


#endif

