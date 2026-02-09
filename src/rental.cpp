#include "rental.h"
#include "relation.h"
#include <iostream>

using namespace std;

// Basic SLL

void createListRental(listRental &LR) {
    LR.first = nullptr;
}

elementRental* createElementRental(rental x) {
    elementRental* p = new elementRental;
    p->info = x;
    p->next = nullptr;
    return p;
}

void insertFirstRental(listRental &LR, elementRental* p) {
    if (LR.first == nullptr) {
        LR.first = p;
    } else {
        p->next = LR.first;
        LR.first = p;
    }
}

void insertLastRental(listRental &LR, elementRental* p) {
    if (LR.first == nullptr) {
        LR.first = p;
    } else {
        elementRental* current = LR.first;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = p;
    }
}

void insertAfterRental(elementRental* prec, elementRental* p) {
    if (prec != nullptr) {
        p->next = prec->next;
        prec->next = p;
    }
}

void insertElementRental(listRental &LR, elementRental* p, string method, elementRental* prec) {
    if (method == "first") {
        insertFirstRental(LR, p);
    } else if (method == "last") {
        insertLastRental(LR, p);
    } else if (method == "after" && prec != nullptr) {
        insertAfterRental(prec, p);
    }
}

void deleteFirstRental(listRental &LR, elementRental* &p) {
    if (LR.first == nullptr) {
        p = nullptr;
    } else {
        p = LR.first;
        LR.first = LR.first->next;
        p->next = nullptr;
    }
}

void deleteLastRental(listRental &LR, elementRental* &p) {
    if (LR.first == nullptr) {
        p = nullptr;
    } else if (LR.first->next == nullptr) {
        p = LR.first;
        LR.first = nullptr;
    } else {
        elementRental* current = LR.first;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        p = current->next;
        current->next = nullptr;
    }
}

void deleteAfterRental(elementRental* prec, elementRental* &p) {
    if (prec != nullptr && prec->next != nullptr) {
        p = prec->next;
        prec->next = p->next;
        p->next = nullptr;
    } else {
        p = nullptr;
    }
}

void deleteElementRental(listRental &LR, elementRental* &p, string method, elementRental* prec) {
    if (method == "first") {
        deleteFirstRental(LR, p);
    } else if (method == "last") {
        deleteLastRental(LR, p);
    } else if (method == "after" && prec != nullptr) {
        deleteAfterRental(prec, p);
    }
}

// Search Procedure

elementRental* findRentalByID(listRental LR, string id) {
    elementRental* current = LR.first;
    while (current != nullptr) {
        if (current->info.rentId == id) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

elementRental* findElementRental(listRental LR, string id) {
    return findRentalByID(LR, id);
}

// Display Procedure

void showAllRental(listRental LR) {
    elementRental* current = LR.first;
    int count = 1;

    cout << "=== ALL RENTALS ===" << endl;
    if (current == nullptr) {
        cout << "No rentals found." << endl;
        return;
    }

    while (current != nullptr) {
        cout << count << ". Rental ID: " << current->info.rentId << endl;
        cout << "   Date: " << current->info.date << endl;
        cout << "   Duration: " << current->info.duration << " days" << endl;
        cout << "   Total Fee: $" << current->info.totalFee << endl;
        cout << "--------------------------------" << endl;
        current = current->next;
        count++;
    }
}

void showRentalData(elementRental* rent) {
    if (rent != nullptr) {
        cout << "Rental ID: " << rent->info.rentId << endl;
        cout << "Date: " << rent->info.date << endl;
        cout << "Movie: " << rent->info.movieCode << endl;
        cout << "Duration: " << rent->info.duration << " days" << endl;
        cout << "Total Fee: $" << rent->info.totalFee << endl;
    }
}

// Relation Procedure

bool hasMovieRelation(elementRental* rental, listMovie LM) {
    elementMovie* movieCurrent = LM.first;

    while (movieCurrent != nullptr) {
        relMovieRent* rel = movieCurrent->firstRel;
        while (rel != nullptr) {
            if (rel->rental == rental) {
                return true;
            }
            rel = rel->nextRel;
        }
        movieCurrent = movieCurrent->next;
    }
    return false;
}

int countRentalsWithNoMovie(listRental LR, listMovie LM) {
    int count = 0;
    elementRental* current = LR.first;

    while (current != nullptr) {
        if (!hasMovieRelation(current, LM)) {
            count++;
        }
        current = current->next;
    }
    return count;
}
