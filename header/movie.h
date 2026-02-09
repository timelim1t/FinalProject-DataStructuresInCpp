#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED

#include "data.h"

struct relMovieRent;

struct elementMovie {
    movie info;
    elementMovie* next;
    relMovieRent* firstRel;
};

struct listMovie {
    elementMovie* first;
};

// Basic SLL
void createListMovie(listMovie &LM);
elementMovie* createElementMovie(movie x);
void insertFirstMovie(listMovie &LM, elementMovie* p);
void insertLastMovie(listMovie &LM, elementMovie* p);
void insertAfterMovie(elementMovie* prec, elementMovie* p);
void insertElementMovie(listMovie &LM, elementMovie* p, string method = "first", elementMovie* prec = nullptr);

void deleteFirstMovie(listMovie &LM, elementMovie* &p);
void deleteLastMovie(listMovie &LM, elementMovie* &p);
void deleteAfterMovie(elementMovie* prec, elementMovie* &p);
void deleteElementMovie(listMovie &LM, elementMovie* &p, string method = "first", elementMovie* prec = nullptr);

// Search
elementMovie* findMovieByCode(listMovie LM, string code);
elementMovie* findElementMovie(listMovie LM, string code);

// Display
void showAllMovie(listMovie LM);
void showMovieData(elementMovie* mov);

// Relation
int countMovieRentals(elementMovie* movie);
int countMoviesWithNoRentals(listMovie LM);
int countMoviesForRental(listMovie LM, string rentalId);

#endif // MOVIE_H_INCLUDED
