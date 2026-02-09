#include "relation.h"
#include <iostream>

using namespace std;




// [CUSTOMER-MOVIE RELATION]

relCustMovie* createElementRelCustMovie(elementMovie* movie) {
    relCustMovie* p = new relCustMovie;
    p->movie = movie;
    p->nextRel = nullptr;
    return p;
}

void insertElementRelCustMovie(elementCustomer* customer, elementMovie* movie) {
    relCustMovie* newRel = createElementRelCustMovie(movie);

    if (customer->firstRel == nullptr) {
        customer->firstRel = newRel;
    } else {
        relCustMovie* current = customer->firstRel;
        while (current->nextRel != nullptr) {
            current = current->nextRel;
        }
        current->nextRel = newRel;
    }
}

void deleteFirstRelCustMovie(elementCustomer* customer, relCustMovie* &p) {
    if (customer->firstRel == nullptr) {
        p = nullptr;
    } else {
        p = customer->firstRel;
        customer->firstRel = customer->firstRel->nextRel;
        p->nextRel = nullptr;
    }
}

void deleteLastRelCustMovie(elementCustomer* customer, relCustMovie* &p) {
    if (customer->firstRel == nullptr) {
        p = nullptr;
    } else if (customer->firstRel->nextRel == nullptr) {
        p = customer->firstRel;
        customer->firstRel = nullptr;
    } else {
        relCustMovie* current = customer->firstRel;
        while (current->nextRel->nextRel != nullptr) {
            current = current->nextRel;
        }
        p = current->nextRel;
        current->nextRel = nullptr;
    }
}

void deleteAfterRelCustMovie(relCustMovie* prec, relCustMovie* &p) {
    if (prec != nullptr && prec->nextRel != nullptr) {
        p = prec->nextRel;
        prec->nextRel = p->nextRel;
        p->nextRel = nullptr;
    } else {
        p = nullptr;
    }
}

void deleteElementRelCustMovie(elementCustomer* customer, relCustMovie* &p, string method, relCustMovie* prec) {
    if (method == "first") {
        deleteFirstRelCustMovie(customer, p);
    } else if (method == "last") {
        deleteLastRelCustMovie(customer, p);
    } else if (method == "after" && prec != nullptr) {
        deleteAfterRelCustMovie(prec, p);
    }
}

relCustMovie* findRelCustMovieByMovie(elementCustomer* customer, string movieCode) {
    if (customer->firstRel == nullptr) {
        return nullptr;
    }

    relCustMovie* current = customer->firstRel;
    while (current != nullptr) {
        if (current->movie->info.code == movieCode) {
            return current;
        }
        current = current->nextRel;
    }
    return nullptr;
}

relCustMovie* findElementRelCustMovie(elementCustomer* customer, string movieCode) {
    return findRelCustMovieByMovie(customer, movieCode);
}

void showCustomerMovies(elementCustomer* customer) {
    if (customer->firstRel != nullptr) {
        cout << "   Rented Movies: ";
        relCustMovie* rel = customer->firstRel;
        while (rel != nullptr) {
            cout << rel->movie->info.title;
            rel = rel->nextRel;
            if (rel != nullptr) cout << ", ";
        }
        cout << endl;
    } else {
        cout << "   Rented Movies: None" << endl;
    }
}

void showMoviesForCustomer(listCustomer LC, string customerId) {
    elementCustomer* cust = findCustomerByID(LC, customerId);

    if (cust == nullptr) {
        cout << "Customer with ID '" << customerId << "' not found!" << endl;
        return;
    }

    cout << "Movies rented by " << cust->info.name << " (" << customerId << "):" << endl;

    if (cust->firstRel == nullptr) {
        cout << "No movies rented." << endl;
        return;
    }

    relCustMovie* rel = cust->firstRel;
    int count = 1;

    while (rel != nullptr) {
        cout << count << ". " << rel->movie->info.code << " - "
             << rel->movie->info.title << endl;
        rel = rel->nextRel;
        count++;
    }
}

void showAllCustomersWithMovies(listCustomer LC) {
    elementCustomer* current = LC.first;
    int customerCount = 1;

    cout << "\n=== ALL CUSTOMERS WITH THEIR RENTED MOVIES ===" << endl;

    if (current == nullptr) {
        cout << "No customers found in the system." << endl;
        return;
    }

    while (current != nullptr) {
        cout << "\n[" << customerCount << "] CUSTOMER:" << endl;
        cout << "ID: " << current->info.id << endl;
        cout << "Name: " << current->info.name << endl;
        cout << "Phone: " << current->info.phone << endl;

        if (current->firstRel != nullptr) {
            cout << "RENTED MOVIES DETAILS:" << endl;
            relCustMovie* rel = current->firstRel;
            int movieCount = 0;
            while (rel != nullptr) {
                movieCount++;
                cout << "   " << movieCount << ". " << rel->movie->info.code
                     << " - " << rel->movie->info.title << endl;
                cout << "      Genre: " << rel->movie->info.genre << endl;
                cout << "      Year: " << rel->movie->info.year << endl;
                cout << "      Price: $" << rel->movie->info.price << endl;
                if (rel->nextRel != nullptr) cout << endl;
                rel = rel->nextRel;
            }
            cout << "Total movies rented: " << movieCount << endl;
        } else {
            cout << "Rented Movies: None" << endl;
        }

        cout << "---" << endl;
        current = current->next;
        customerCount++;
    }

    cout << "\n=== TOTAL CUSTOMERS: " << (customerCount - 1) << " ===" << endl;
}

void showCustomersForMovie(listCustomer LC, listMovie LM, string movieCode) {
    // Cari movie dulu
    elementMovie* movie = findMovieByCode(LM, movieCode);
    if (!movie) {
        cout << "Movie with code '" << movieCode << "' not found!" << endl;
        return;
    }

    cout << "=== CUSTOMERS RENTING: " << movie->info.title << " (" << movieCode << ") ===" << endl;
    cout << "Genre: " << movie->info.genre << " | Year: " << movie->info.year << " | Price: $" << movie->info.price << endl;
    cout << "=========================================\n";

    elementCustomer* current = LC.first;
    int count = 0;

    while (current != nullptr) {
        relCustMovie* rel = current->firstRel;
        while (rel != nullptr) {
            if (rel->movie->info.code == movieCode) {
                count++;
                cout << "\n[" << count << "] CUSTOMER:" << endl;
                cout << "ID: " << current->info.id << endl;
                cout << "Name: " << current->info.name << endl;
                cout << "Phone: " << current->info.phone << endl;
                cout << "Movies rented by this customer: " << countCustomerMovies(current) << endl;
                break;
            }
            rel = rel->nextRel;
        }
        current = current->next;
    }

    if (count == 0) {
        cout << "\nNo customers are currently renting this movie." << endl;
    } else {
        cout << "\n=========================================" << endl;
        cout << "TOTAL CUSTOMERS RENTING THIS MOVIE: " << count << endl;
    }
}



// [MOVIE-RENTAL RELATION]

relMovieRent* createElementRelMovieRent(elementRental* rental) {
    relMovieRent* p = new relMovieRent;
    p->rental = rental;
    p->nextRel = nullptr;
    return p;
}

void insertElementRelMovieRent(elementMovie* movie, elementRental* rental) {
    relMovieRent* newRel = createElementRelMovieRent(rental);

    if (movie->firstRel == nullptr) {
        movie->firstRel = newRel;
    } else {
        relMovieRent* current = movie->firstRel;
        while (current->nextRel != nullptr) {
            current = current->nextRel;
        }
        current->nextRel = newRel;
    }
}

void deleteFirstRelMovieRent(elementMovie* movie, relMovieRent* &p) {
    if (movie->firstRel == nullptr) {
        p = nullptr;
    } else {
        p = movie->firstRel;
        movie->firstRel = movie->firstRel->nextRel;
        p->nextRel = nullptr;
    }
}

void deleteLastRelMovieRent(elementMovie* movie, relMovieRent* &p) {
    if (movie->firstRel == nullptr) {
        p = nullptr;
    } else if (movie->firstRel->nextRel == nullptr) {
        p = movie->firstRel;
        movie->firstRel = nullptr;
    } else {
        relMovieRent* current = movie->firstRel;
        while (current->nextRel->nextRel != nullptr) {
            current = current->nextRel;
        }
        p = current->nextRel;
        current->nextRel = nullptr;
    }
}

void deleteAfterRelMovieRent(relMovieRent* prec, relMovieRent* &p) {
    if (prec != nullptr && prec->nextRel != nullptr) {
        p = prec->nextRel;
        prec->nextRel = p->nextRel;
        p->nextRel = nullptr;
    } else {
        p = nullptr;
    }
}

void deleteElementRelMovieRent(elementMovie* movie, relMovieRent* &p, string method, relMovieRent* prec) {
    if (method == "first") {
        deleteFirstRelMovieRent(movie, p);
    } else if (method == "last") {
        deleteLastRelMovieRent(movie, p);
    } else if (method == "after" && prec != nullptr) {
        deleteAfterRelMovieRent(prec, p);
    }
}

relMovieRent* findRelMovieRentByRental(elementMovie* movie, string rentalId) {
    if (movie->firstRel == nullptr) {
        return nullptr;
    }

    relMovieRent* current = movie->firstRel;
    while (current != nullptr) {
        if (current->rental->info.rentId == rentalId) {
            return current;
        }
        current = current->nextRel;
    }
    return nullptr;
}

relMovieRent* findElementRelMovieRent(elementMovie* movie, string rentalId) {
    return findRelMovieRentByRental(movie, rentalId);
}

void showMovieRentals(elementMovie* movie) {
    if (movie->firstRel != nullptr) {
        cout << "   Active Rentals: ";
        relMovieRent* rel = movie->firstRel;
        while (rel != nullptr) {
            cout << rel->rental->info.rentId;
            rel = rel->nextRel;
            if (rel != nullptr) cout << ", ";
        }
        cout << endl;
    } else {
        cout << "   Active Rentals: None" << endl;
    }
}

void showAllMoviesWithRentals(listMovie LM) {
    elementMovie* current = LM.first;
    int movieCount = 1;

    cout << "\n=== ALL MOVIES WITH THEIR ACTIVE RENTALS ===" << endl;

    if (current == nullptr) {
        cout << "No movies found in the system." << endl;
        return;
    }

    while (current != nullptr) {
        cout << "\n[" << movieCount << "] MOVIE:" << endl;
        cout << "Code: " << current->info.code << endl;
        cout << "Title: " << current->info.title << endl;
        cout << "Genre: " << current->info.genre << endl;
        cout << "Year: " << current->info.year << endl;
        cout << "Price: $" << current->info.price << endl;

        // Show rentals
        if (current->firstRel != nullptr) {
            cout << "Active Rentals: ";
            relMovieRent* rel = current->firstRel;
            int rentalCount = 0;
            while (rel != nullptr) {
                if (rentalCount > 0) cout << ", ";
                cout << rel->rental->info.rentId;
                rel = rel->nextRel;
                rentalCount++;
            }
            cout << endl;
            cout << "Total active rentals: " << rentalCount << endl;
        } else {
            cout << "Active Rentals: None" << endl;
        }

        cout << "---" << endl;
        current = current->next;
        movieCount++;
    }

    cout << "\n=== TOTAL MOVIES: " << (movieCount - 1) << " ===" << endl;
}

void showAllRentalsWithMovies(listRental LR, listMovie LM) {
    cout << "=== ALL RENTALS WITH THEIR MOVIES ===" << endl;

    elementRental* rentCurrent = LR.first;
    int count = 1;

    if (!rentCurrent) {
        cout << "No rentals found." << endl;
        return;
    }

    while (rentCurrent) {
        cout << "\n[" << count << "] RENTAL:" << endl;
        cout << "ID: " << rentCurrent->info.rentId << endl;
        cout << "Date: " << rentCurrent->info.date << endl;
        cout << "Duration: " << rentCurrent->info.duration << " days" << endl;
        cout << "Fee: $" << rentCurrent->info.totalFee << endl;

        cout << "Connected Movies: ";
        elementMovie* movieCurrent = LM.first;
        bool hasMovies = false;
        int movieCount = 0;

        while (movieCurrent) {
            relMovieRent* rel = movieCurrent->firstRel;
            while (rel) {
                if (rel->rental->info.rentId == rentCurrent->info.rentId) {
                    if (movieCount > 0) cout << ", ";
                    cout << movieCurrent->info.title << " (" << movieCurrent->info.code << ")";
                    hasMovies = true;
                    movieCount++;
                    break;
                }
                rel = rel->nextRel;
            }
            movieCurrent = movieCurrent->next;
        }

        if (!hasMovies) {
            cout << "None";
        }
        cout << endl;

        rentCurrent = rentCurrent->next;
        count++;
    }
}

void showMoviesForRental(listMovie LM, string rentalId) {
    cout << "=== MOVIES CONNECTED TO RENTAL " << rentalId << " ===" << endl;

    int count = 0;
    elementMovie* current = LM.first;

    while (current) {
        relMovieRent* rel = current->firstRel;
        while (rel) {
            if (rel->rental->info.rentId == rentalId) {
                count++;
                cout << count << ". " << current->info.code
                     << " - " << current->info.title
                     << " (" << current->info.genre << ")" << endl;
                break;
            }
            rel = rel->nextRel;
        }
        current = current->next;
    }

    if (count == 0) {
        cout << "No movies found for rental " << rentalId << endl;
    } else {
        cout << "Total: " << count << " movie(s)" << endl;
    }
}

elementCustomer* findCustomerByMovieCode(listCustomer LC, string movieCode) {
    elementCustomer* current = LC.first;
    while (current != nullptr) {
        relCustMovie* rel = current->firstRel;
        while (rel != nullptr) {
            if (rel->movie->info.code == movieCode) {
                return current;
            }
            rel = rel->nextRel;
        }
        current = current->next;
    }
    return nullptr;
}

relCustMovie* findRelCustMovieByMovieCode(listCustomer LC, string movieCode) {
    elementCustomer* current = LC.first;
    while (current != nullptr) {
        relCustMovie* rel = current->firstRel;
        while (rel != nullptr) {
            if (rel->movie->info.code == movieCode) {
                return rel;
            }
            rel = rel->nextRel;
        }
        current = current->next;
    }
    return nullptr;
}
