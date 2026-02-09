#include "movie.h"
#include "relation.h"
#include <iostream>

using namespace std;

// Basic SLL

void createListMovie(listMovie &LM) {
    LM.first = nullptr;
}

elementMovie* createElementMovie(movie x) {
    elementMovie* p = new elementMovie;
    p->info = x;
    p->next = nullptr;
    p->firstRel = nullptr;
    return p;
}

void insertFirstMovie(listMovie &LM, elementMovie* p) {
    if (LM.first == nullptr) {
        LM.first = p;
    } else {
        p->next = LM.first;
        LM.first = p;
    }
}

void insertLastMovie(listMovie &LM, elementMovie* p) {
    if (LM.first == nullptr) {
        LM.first = p;
    } else {
        elementMovie* current = LM.first;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = p;
    }
}

void insertAfterMovie(elementMovie* prec, elementMovie* p) {
    if (prec != nullptr) {
        p->next = prec->next;
        prec->next = p;
    }
}

void insertElementMovie(listMovie &LM, elementMovie* p, string method, elementMovie* prec) {
    if (method == "first") {
        insertFirstMovie(LM, p);
    } else if (method == "last") {
        insertLastMovie(LM, p);
    } else if (method == "after" && prec != nullptr) {
        insertAfterMovie(prec, p);
    }
}

void deleteFirstMovie(listMovie &LM, elementMovie* &p) {
    if (LM.first == nullptr) {
        p = nullptr;
    } else {
        p = LM.first;
        LM.first = LM.first->next;
        p->next = nullptr;
    }
}

void deleteLastMovie(listMovie &LM, elementMovie* &p) {
    if (LM.first == nullptr) {
        p = nullptr;
    } else if (LM.first->next == nullptr) {
        p = LM.first;
        LM.first = nullptr;
    } else {
        elementMovie* current = LM.first;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        p = current->next;
        current->next = nullptr;
    }
}

void deleteAfterMovie(elementMovie* prec, elementMovie* &p) {
    if (prec != nullptr && prec->next != nullptr) {
        p = prec->next;
        prec->next = p->next;
        p->next = nullptr;
    } else {
        p = nullptr;
    }
}

void deleteElementMovie(listMovie &LM, elementMovie* &p, string method, elementMovie* prec) {
    if (method == "first") {
        deleteFirstMovie(LM, p);
    } else if (method == "last") {
        deleteLastMovie(LM, p);
    } else if (method == "after" && prec != nullptr) {
        deleteAfterMovie(prec, p);
    }
}

// Search Procedure

elementMovie* findMovieByCode(listMovie LM, string code) {
    elementMovie* current = LM.first;
    while (current != nullptr) {
        if (current->info.code == code) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

elementMovie* findElementMovie(listMovie LM, string code) {
    return findMovieByCode(LM, code);
}

// Display Procedure

void showAllMovie(listMovie LM) {
    elementMovie* current = LM.first;
    int count = 1;

    cout << "=== ALL MOVIES ===" << endl;
    if (current == nullptr) {
        cout << "No movies found." << endl;
        return;
    }

    while (current != nullptr) {
        cout << count << ". Movie Code: " << current->info.code << endl;
        cout << "   Title: " << current->info.title << endl;
        cout << "   Genre: " << current->info.genre << endl;
        cout << "   Year: " << current->info.year << endl;
        cout << "   Price: $" << current->info.price << endl;
        cout << "   Active rentals: " << countMovieRentals(current) << endl;
        cout << "--------------------------------" << endl;
        current = current->next;
        count++;
    }
}

void showMovieData(elementMovie* mov) {
    if (mov != nullptr) {
        cout << "Movie Code: " << mov->info.code << endl;
        cout << "Title: " << mov->info.title << endl;
        cout << "Genre: " << mov->info.genre << endl;
        cout << "Year: " << mov->info.year << endl;
        cout << "Price: $" << mov->info.price << endl;
    }
}

// Relation Procedure

int countMovieRentals(elementMovie* movie) {
    int count = 0;
    if (movie != nullptr) {
        relMovieRent* current = movie->firstRel;
        while (current != nullptr) {
            count++;
            current = current->nextRel;
        }
    }
    return count;
}

int countMoviesWithNoRentals(listMovie LM) {
    int count = 0;
    elementMovie* current = LM.first;

    while (current != nullptr) {
        if (current->firstRel == nullptr) {
            count++;
        }
        current = current->next;
    }
    return count;
}

int countMoviesForRental(listMovie LM, string rentalId) {
    int count = 0;
    elementMovie* current = LM.first;

    while (current != nullptr) {
        relMovieRent* rel = current->firstRel;
        while (rel != nullptr) {
            if (rel->rental->info.rentId == rentalId) {
                count++;
                break;
            }
            rel = rel->nextRel;
        }
        current = current->next;
    }
    return count;
}
