#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

#include "data.h"

struct relCustMovie;

struct elementCustomer {
    customer info;
    elementCustomer* next;
    relCustMovie* firstRel;
};

struct listCustomer {
    elementCustomer* first;
};

// Basic SLL
void createListCustomer(listCustomer &LC);
elementCustomer* createElementCustomer(customer x);
void insertFirstCustomer(listCustomer &LC, elementCustomer* p);
void insertLastCustomer(listCustomer &LC, elementCustomer* p);
void insertAfterCustomer(elementCustomer* prec, elementCustomer* p);
void insertElementCustomer(listCustomer &LC, elementCustomer* p, string method = "first", elementCustomer* prec = nullptr);

void deleteFirstCustomer(listCustomer &LC, elementCustomer* &p);
void deleteLastCustomer(listCustomer &LC, elementCustomer* &p);
void deleteAfterCustomer(elementCustomer* prec, elementCustomer* &p);
void deleteElementCustomer(listCustomer &LC, elementCustomer* &p, string method = "first", elementCustomer* prec = nullptr);

// Search
elementCustomer* findCustomerByID(listCustomer LC, string id);
elementCustomer* findElementCustomer(listCustomer LC, string id);

// Display
void showAllCustomer(listCustomer LC);
void showCustomerData(elementCustomer* cust);

// Relation
int countCustomerMovies(elementCustomer* customer);
int countCustomersForMovie(listCustomer LC, string movieCode);

#endif // CUSTOMER_H_INCLUDED
