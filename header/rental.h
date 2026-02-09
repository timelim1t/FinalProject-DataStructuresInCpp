#ifndef RENTAL_H_INCLUDED
#define RENTAL_H_INCLUDED

#include "data.h"
#include "movie.h"

struct elementRental {
    rental info;
    elementRental* next;
};

struct listRental {
    elementRental* first;
};

// Basic SLL
void createListRental(listRental &LR);
elementRental* createElementRental(rental x);
void insertFirstRental(listRental &LR, elementRental* p);
void insertLastRental(listRental &LR, elementRental* p);
void insertAfterRental(elementRental* prec, elementRental* p);
void insertElementRental(listRental &LR, elementRental* p, string method = "first", elementRental* prec = nullptr);

void deleteFirstRental(listRental &LR, elementRental* &p);
void deleteLastRental(listRental &LR, elementRental* &p);
void deleteAfterRental(elementRental* prec, elementRental* &p);
void deleteElementRental(listRental &LR, elementRental* &p, string method = "first", elementRental* prec = nullptr);

// Search
elementRental* findRentalByID(listRental LR, string id);
elementRental* findElementRental(listRental LR, string id);

// Display
void showAllRental(listRental LR);
void showRentalData(elementRental* rent);

// Relation
bool hasMovieRelation(elementRental* rental, listMovie LM);
int countRentalsWithNoMovie(listRental LR, listMovie LM);
int countMoviesForRental(listMovie LM, string rentalId); // Ada di file movie

#endif // RENTAL_H_INCLUDED
