#include "customer.h"
#include "relation.h"
#include <iostream>

using namespace std;

// Basic SLL
void createListCustomer(listCustomer &LC) {
    LC.first = nullptr;
}

elementCustomer* createElementCustomer(customer x) {
    elementCustomer* p = new elementCustomer;
    p->info = x;
    p->next = nullptr;
    p->firstRel = nullptr;
    return p;
}

void insertFirstCustomer(listCustomer &LC, elementCustomer* p) {
    if (LC.first == nullptr) {
        LC.first = p;
    } else {
        p->next = LC.first;
        LC.first = p;
    }
}

void insertLastCustomer(listCustomer &LC, elementCustomer* p) {
    if (LC.first == nullptr) {
        LC.first = p;
    } else {
        elementCustomer* current = LC.first;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = p;
    }
}

void insertAfterCustomer(elementCustomer* prec, elementCustomer* p) {
    if (prec != nullptr) {
        p->next = prec->next;
        prec->next = p;
    }
}

void insertElementCustomer(listCustomer &LC, elementCustomer* p, string method, elementCustomer* prec) {
    if (method == "first") {
        insertFirstCustomer(LC, p);
    } else if (method == "last") {
        insertLastCustomer(LC, p);
    } else if (method == "after" && prec != nullptr) {
        insertAfterCustomer(prec, p);
    }
}

void deleteFirstCustomer(listCustomer &LC, elementCustomer* &p) {
    if (LC.first == nullptr) {
        p = nullptr;
    } else {
        p = LC.first;
        LC.first = LC.first->next;
        p->next = nullptr;
    }
}

void deleteLastCustomer(listCustomer &LC, elementCustomer* &p) {
    if (LC.first == nullptr) {
        p = nullptr;
    } else if (LC.first->next == nullptr) {
        p = LC.first;
        LC.first = nullptr;
    } else {
        elementCustomer* current = LC.first;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        p = current->next;
        current->next = nullptr;
    }
}

void deleteAfterCustomer(elementCustomer* prec, elementCustomer* &p) {
    if (prec != nullptr && prec->next != nullptr) {
        p = prec->next;
        prec->next = p->next;
        p->next = nullptr;
    } else {
        p = nullptr;
    }
}

void deleteElementCustomer(listCustomer &LC, elementCustomer* &p, string method, elementCustomer* prec) {
    if (method == "first") {
        deleteFirstCustomer(LC, p);
    } else if (method == "last") {
        deleteLastCustomer(LC, p);
    } else if (method == "after" && prec != nullptr) {
        deleteAfterCustomer(prec, p);
    }
}

// Search Procedure

elementCustomer* findCustomerByID(listCustomer LC, string id) {
    elementCustomer* current = LC.first;
    while (current != nullptr) {
        if (current->info.id == id) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

elementCustomer* findElementCustomer(listCustomer LC, string id) {
    return findCustomerByID(LC, id);
}

// Display Procedure

void showAllCustomer(listCustomer LC) {
    elementCustomer* current = LC.first;
    int count = 1;

    cout << "=== ALL CUSTOMERS ===" << endl;
    if (current == nullptr) {
        cout << "No customers found." << endl;
        return;
    }

    while (current != nullptr) {
        cout << count << ". Customer ID: " << current->info.id << endl;
        cout << "   Name: " << current->info.name << endl;
        cout << "   Phone: " << current->info.phone << endl;
        cout << "   Movies rented: " << countCustomerMovies(current) << endl;
        cout << "--------------------------------" << endl;
        current = current->next;
        count++;
    }
}

void showCustomerData(elementCustomer* cust) {
    if (cust != nullptr) {
        cout << "Customer ID: " << cust->info.id << endl;
        cout << "Name: " << cust->info.name << endl;
        cout << "Phone: " << cust->info.phone << endl;
    }
}

// Relation Procedure

int countCustomerMovies(elementCustomer* customer) {
    int count = 0;
    if (customer != nullptr) {
        relCustMovie* current = customer->firstRel;
        while (current != nullptr) {
            count++;
            current = current->nextRel;
        }
    }
    return count;
}

int countCustomersForMovie(listCustomer LC, string movieCode) {
    int count = 0;
    elementCustomer* current = LC.first;

    while (current != nullptr) {
        relCustMovie* rel = current->firstRel;
        while (rel != nullptr) {
            if (rel->movie->info.code == movieCode) {
                count++;
                break;
            }
            rel = rel->nextRel;
        }
        current = current->next;
    }
    return count;
}
