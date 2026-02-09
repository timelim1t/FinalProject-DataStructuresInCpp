#ifndef RELATION_H_INCLUDED
#define RELATION_H_INCLUDED

#include "customer.h"
#include "movie.h"
#include "rental.h"

// Relasi 1: Customer-Movie
struct relCustMovie {
    elementMovie* movie;
    relCustMovie* nextRel;
};

// Relasi 2: Movie-Rental
struct relMovieRent {
    elementRental* rental;
    relMovieRent* nextRel;
};


// [CUSTOMER-MOVIE RELATION]

// Create & Insert
relCustMovie* createElementRelCustMovie(elementMovie* movie);
void insertElementRelCustMovie(elementCustomer* customer, elementMovie* movie);

// Delete
void deleteFirstRelCustMovie(elementCustomer* customer, relCustMovie* &p);
void deleteLastRelCustMovie(elementCustomer* customer, relCustMovie* &p);
void deleteAfterRelCustMovie(relCustMovie* prec, relCustMovie* &p);
void deleteElementRelCustMovie(elementCustomer* customer, relCustMovie* &p, string method = "first", relCustMovie* prec = nullptr);

// Search
relCustMovie* findRelCustMovieByMovie(elementCustomer* customer, string movieCode);
relCustMovie* findElementRelCustMovie(elementCustomer* customer, string movieCode);

// Display
void showCustomerMovies(elementCustomer* customer);
void showMoviesForCustomer(listCustomer LC, string customerId);
void showAllCustomersWithMovies(listCustomer LC);


// [MOVIE-RENTAL RELATION]

// Create & Insert
relMovieRent* createElementRelMovieRent(elementRental* rental);
void insertElementRelMovieRent(elementMovie* movie, elementRental* rental);

// Deletion
void deleteFirstRelMovieRent(elementMovie* movie, relMovieRent* &p);
void deleteLastRelMovieRent(elementMovie* movie, relMovieRent* &p);
void deleteAfterRelMovieRent(relMovieRent* prec, relMovieRent* &p);
void deleteElementRelMovieRent(elementMovie* movie, relMovieRent* &p, string method = "first", relMovieRent* prec = nullptr);

// Search
relMovieRent* findRelMovieRentByRental(elementMovie* movie, string rentalId);
relMovieRent* findElementRelMovieRent(elementMovie* movie, string rentalId);

// Display
void showMovieRentals(elementMovie* movie);
void showAllMoviesWithRentals(listMovie LM);
void showCustomersForMovie(listCustomer LC, listMovie LM, string movieCode);

void showAllRentalsWithMovies(listRental LR, listMovie LM); //n
void showMoviesForRental(listMovie LM, string rentalId); //o

//extra
elementCustomer* findCustomerByMovieCode(listCustomer LC, string movieCode);
relCustMovie* findRelCustMovieByMovieCode(listCustomer LC, string movieCode);
#endif // RELATION_H_INCLUDED
