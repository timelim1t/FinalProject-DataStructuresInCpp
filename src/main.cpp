#include <iostream>
#include <string>

#include "data.h"
#include "customer.h"
#include "movie.h"
#include "rental.h"
#include "relation.h"

#include "customer.cpp"
#include "movie.cpp"
#include "rental.cpp"
#include "relation.cpp"

using namespace std;

// Global lists
listCustomer LC;
listMovie LM;
listRental LR;

// Inisialisasi list
void initData() {
    createListCustomer(LC);
    createListMovie(LM);
    createListRental(LR);
}


// Extra menu
void clearScreen() {
    cout << "\033[2J\033[1;1H"; // ANSI code untuk simulasi screen menu (menampilkan line 1 teks terbaru tiap program dipanggil)
}

void pressEnterToContinue() {
    cout << "\nTekan Enter untuk lanjut...";
    cin.get();
}


// Display Menu
void displayMainMenu() {
    clearScreen();
    cout << "=========================================\n";
    cout << "    MOVIE RENTAL MANAGEMENT SYSTEM\n";
    cout << "=========================================\n";
    cout << "1.  CUSTOMER Menu\n";
    cout << "2.  MOVIE Menu\n";
    cout << "3.  RENTAL Menu\n";
    cout << "4.  RELATION Menu\n";
    cout << "5.  VIEW All Data\n";
    cout << "6.  STATISTICS & REPORTS\n";
    cout << "7.  Load Template Data\n";
    cout << "0.  Exit Program\n";
    cout << "=========================================\n";
    cout << "Masukkan pilihan: ";
}

void displayCustomerMenu() {
    clearScreen();
    cout << "=========================================\n";
    cout << "        CUSTOMER OPERATIONS\n";
    cout << "=========================================\n";
    cout << "1.  Insert New Customer (a)\n";
    cout << "2.  View All Customers (j)\n";
    cout << "3.  Search Customer by ID (g)\n";
    cout << "4.  Update Customer Data\n";
    cout << "5.  Delete Customer (d)\n";
    cout << "6.  Add Movie to Customer (c)Insert Rel\n";
    cout << "7.  Remove Movie from Customer (f)Delete Rel\n";
    cout << "8.  View Customer's Movies (l)\n";
    cout << "9.  Count Customer's Movies (Count Rel)\n";
    cout << "10. Replace Movies (Change Child) (s)\n";
    cout << "11. Gift Movie (Change Parent)\n";
    cout << "0.  Kembali ke Main Menu\n";
    cout << "=========================================\n";
    cout << "Masukkan pilihan: ";
}

void displayMovieMenu() {
    clearScreen();
    cout << "=========================================\n";
    cout << "         MOVIE OPERATIONS\n";
    cout << "=========================================\n";
    cout << "1.  Insert New Movie (a)\n";
    cout << "2.  View All Movies (j)\n";
    cout << "3.  Search Movie by Code (g)\n";
    cout << "4.  Update Movie Data\n";
    cout << "5.  Delete Movie (d)\n";
    cout << "6.  Add Rental to Movie (c)Insert Rel\n";
    cout << "7.  Remove Rental from Movie (f)Delete Rel\n";
    cout << "8.  Update Rental Relation\n";
    cout << "9.  View Movie's Rentals (l)\n";
    cout << "10. Count Movie's Rentals (Count Rel)\n";
    cout << "0.  Kembali ke Main Menu\n";
    cout << "=========================================\n";
    cout << "Masukkan pilihan: ";
}

void displayRentalMenu() {
    clearScreen();
    cout << "=========================================\n";
    cout << "        RENTAL OPERATIONS\n";
    cout << "=========================================\n";
    cout << "1.  Insert New Rental (b)\n";
    cout << "2.  View All Rentals (k)\n";
    cout << "3.  Search Rental by ID (h)Find Child\n";
    cout << "4.  Update Rental Data\n";
    cout << "5.  Delete Rental (e)\n";
    cout << "6.  View Rentals tanpa Movies\n";
    cout << "7.  View All Rentals with Movies (n)\n";
    cout << "0.  Back to Main Menu\n";
    cout << "=========================================\n";
    cout << "Masukkan pilihan: ";
}

void displayRelationMenu() {
    clearScreen();
    cout << "=========================================\n";
    cout << "        RELATION OPERATIONS\n";
    cout << "=========================================\n";
    cout << "1.  Find Customer-Movie Relation (i)\n";
    cout << "2.  Find Movie-Rental Relation (i)\n";
    cout << "3.  Show All Relations\n";
    cout << "0.  Back to Main Menu\n";
    cout << "=========================================\n";
    cout << "Masukkan pilihan: ";
}

void displayViewMenu() {
    clearScreen();
    cout << "=========================================\n";
    cout << "        VIEW ALL DATA\n";
    cout << "=========================================\n";
    cout << "1.  View All Customers with Movies (m)\n";
    cout << "2.  View All Movies with Rentals\n";
    cout << "3.  View All Rentals with Movies\n";
    cout << "4.  View Movies for Specific Customer\n";
    cout << "5.  View Rentals for Specific Movie\n";
    cout << "6.  View Movies for Specific Rental (o)\n";
    cout << "7.  View Customers for Specific Movie (o)\n";
    cout << "0.  Back to Main Menu\n";
    cout << "=========================================\n";
    cout << "Masukkan pilihan: ";
}

void displayStatisticsMenu() {
    clearScreen();
    cout << "=========================================\n";
    cout << "        STATISTICS & REPORTS\n";
    cout << "=========================================\n";
    cout << "1.  Relation Count untuk tiap Customer (p)\n";
    cout << "2.  Relation Count untuk tiap Movie (p)\n";
    cout << "3.  Count Relations for Specific Rental (q)\n";
    cout << "4.  Count Rentals tanpa Movie Relation (r)\n";
    cout << "5.  Total Customers dengan/tanpa Movies\n";
    cout << "6.  Total Movies dengan/tanpa Rentals\n";
    cout << "0.  Back to Main Menu\n";
    cout << "=========================================\n";
    cout << "Masukkan pilihan: ";
}

// Program menu
void handleCustomerMenu() {
    int choice;

    do {
        displayCustomerMenu();
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1: {
                clearScreen();
                cout << "=== INSERT NEW CUSTOMER ===\n";
                customer m;
                cout << "Customer ID: ";
                getline(cin, m.id);
                cout << "Customer Name: ";
                getline(cin, m.name);
                cout << "Customer Phone: ";
                getline(cin, m.phone);
                cin.ignore();

                if (findCustomerByID(LC, m.id)) {
                    cout << "Error: Customer ID sudah dipakai!\n";
                } else {
                    elementCustomer* newCust = createElementCustomer(m);

                    // Ask for insertion method
                    cout << "\nInsertion Method:\n";
                    cout << "1. Insert at beginning\n";
                    cout << "2. Insert at end\n";
                    cout << "3. Insert after specific customer\n";
                    cout << "Choose (1-3): ";
                    int insertChoice;
                    cin >> insertChoice;
                    cin.ignore();

                    if (insertChoice == 1) {
                        insertElementCustomer(LC, newCust, "first");
                        cout << "Customer berhasil ditambahkan di awal!\n";
                    } else if (insertChoice == 2) {
                        insertElementCustomer(LC, newCust, "last");
                        cout << "Customer berhasil ditambahkan di akhir!\n";
                    } else if (insertChoice == 3) {
                        cout << "Enter Customer ID to insert after: ";
                        string afterID;
                        getline(cin, afterID);
                        elementCustomer* prec = findCustomerByID(LC, afterID);
                        if (prec) {
                            insertElementCustomer(LC, newCust, "after", prec);
                            cout << "Customer berhasil ditambahkan setelah " << prec->info.id << "!\n";
                        } else {
                            cout << "Customer not found! Inserting at end instead.\n";
                            insertElementCustomer(LC, newCust, "last");
                        }
                    } else {
                        cout << "Invalid choice! Inserting at end by default.\n";
                        insertElementCustomer(LC, newCust, "last");
                    }
                }
                pressEnterToContinue();
                break;
            }

            case 2: {
                clearScreen();
                showAllCustomer(LC);
                pressEnterToContinue();
                break;
            }

            case 3: {
                clearScreen();
                cout << "=== SEARCH CUSTOMER ===\n";
                string id;
                cout << "Enter Customer ID: ";
                getline(cin, id);

                elementCustomer* cust = findCustomerByID(LC, id);
                if (cust) {
                    cout << "\n--- CUSTOMER FOUND ---\n";
                    showCustomerData(cust);
                } else {
                    cout << "Customer not found!\n";
                }
                pressEnterToContinue();
                break;
            }

            case 4: {
                clearScreen();
                cout << "=== UPDATE CUSTOMER ===\n";
                string id;
                cout << "Enter Customer ID: ";
                getline(cin, id);

                elementCustomer* cust = findCustomerByID(LC, id);
                if (cust) {
                    cout << "\nCurrent Data:\n";
                    showCustomerData(cust);

                    cout << "\nEnter new name: ";
                    getline(cin, cust->info.name);
                    cout << "Enter new phone: ";
                    getline(cin, cust->info.phone);

                    cout << "Customer berhasil di-update!\n";
                } else {
                    cout << "Customer not found!\n";
                }
                pressEnterToContinue();
                break;
            }

            case 5: {
                clearScreen();
                cout << "=== DELETE CUSTOMER ===\n";
                cout << "Delete Method:\n";
                cout << "1. Delete by ID\n";
                cout << "2. Delete first customer\n";
                cout << "3. Delete last customer\n";
                cout << "Choose (1-3): ";
                int deleteChoice;
                cin >> deleteChoice;
                cin.ignore();

                elementCustomer* toDelete = nullptr;

                if (deleteChoice == 1) {
                    string id;
                    cout << "Enter Customer ID: ";
                    getline(cin, id);
                    elementCustomer* cust = findCustomerByID(LC, id);
                    if (cust) {
                        if (cust->firstRel != nullptr) {
                            cout << "Tidak bisa dihapus karena relasi cust-movie!\n";
                        } else {
                            // Find previous element
                            elementCustomer* prev = nullptr;
                            elementCustomer* curr = LC.first;
                            while (curr && curr != cust) {
                                prev = curr;
                                curr = curr->next;
                            }

                            if (prev) {
                                deleteAfterCustomer(prev, toDelete);
                            } else {
                                deleteFirstCustomer(LC, toDelete);
                            }
                            delete toDelete;
                            cout << "Customer berhasil dihapus!\n";
                        }
                    } else {
                        cout << "Customer not found!\n";
                    }
                } else if (deleteChoice == 2) {
                    if (LC.first) {
                        if (LC.first->firstRel != nullptr) {
                            cout << "Tidak bisa dihapus karena relasi cust-movie!\n";
                        } else {
                            deleteFirstCustomer(LC, toDelete);
                            if (toDelete) {
                                delete toDelete;
                                cout << "First customer berhasil dihapus!\n";
                            }
                        }
                    } else {
                        cout << "No customers to delete!\n";
                    }
                } else if (deleteChoice == 3) {
                    if (LC.first) {
                        // Check if last customer has relations
                        elementCustomer* last = LC.first;
                        elementCustomer* prev = nullptr;
                        while (last->next) {
                            prev = last;
                            last = last->next;
                        }
                        if (last->firstRel != nullptr) {
                            cout << "Tidak bisa dihapus karena relasi cust-movie!\n";
                        } else {
                            if (prev) {
                                deleteAfterCustomer(prev, toDelete);
                            } else {
                                deleteFirstCustomer(LC, toDelete);
                            }
                            if (toDelete) {
                                delete toDelete;
                                cout << "Last customer berhasil dihapus!\n";
                            }
                        }
                    } else {
                        cout << "No customers to delete!\n";
                    }
                } else {
                    cout << "Invalid choice!\n";
                }
                pressEnterToContinue();
                break;
            }

            case 6: {
                clearScreen();
                cout << "=== ADD MOVIE TO CUSTOMER ===\n";
                string custId, movieCode;
                cout << "Customer ID: ";
                getline(cin, custId);
                cout << "Movie Code: ";
                getline(cin, movieCode);

                elementCustomer* cust = findCustomerByID(LC, custId);
                elementMovie* mov = findMovieByCode(LM, movieCode);

                if (!cust) {
                    cout << "Customer not found!\n";
                } else if (!mov) {
                    cout << "Movie not found!\n";
                } else if (findRelCustMovieByMovie(cust, movieCode)) {
                    cout << "Customer sudah menyewa movie ini!\n";
                } else {
                    insertElementRelCustMovie(cust, mov);
                    cout << "Movie berhasil ditambahkan ke customer!\n";
                }
                pressEnterToContinue();
                break;
            }

            case 7: {
                clearScreen();
                cout << "=== REMOVE MOVIE FROM CUSTOMER ===\n";
                cout << "Delete Method:\n";
                cout << "1. Delete specific movie relation\n";
                cout << "2. Delete first movie relation\n";
                cout << "3. Delete last movie relation\n";
                cout << "Choose (1-3): ";
                int deleteChoice;
                cin >> deleteChoice;
                cin.ignore();

                if (deleteChoice == 1) {
                    string custId, movieCode;
                    cout << "Customer ID: ";
                    getline(cin, custId);
                    cout << "Movie Code: ";
                    getline(cin, movieCode);

                    elementCustomer* cust = findCustomerByID(LC, custId);
                    if (cust) {
                        relCustMovie* rel = findRelCustMovieByMovie(cust, movieCode);
                        if (rel) {
                            relCustMovie* current = cust->firstRel;
                            relCustMovie* prev = nullptr;

                            while (current && current != rel) {
                                prev = current;
                                current = current->nextRel;
                            }

                            relCustMovie* toDelete;
                            if (prev) {
                                deleteAfterRelCustMovie(prev, toDelete);
                            } else {
                                deleteFirstRelCustMovie(cust, toDelete);
                            }
                            delete toDelete;
                            cout << "Movie dihapus dari customer!\n";
                        } else {
                            cout << "Customer tidak punya movie ini!\n";
                        }
                    } else {
                        cout << "Customer not found!\n";
                    }
                } else if (deleteChoice == 2) {
                    string custId;
                    cout << "Customer ID: ";
                    getline(cin, custId);
                    elementCustomer* cust = findCustomerByID(LC, custId);
                    if (cust && cust->firstRel) {
                        relCustMovie* toDelete;
                        deleteFirstRelCustMovie(cust, toDelete);
                        delete toDelete;
                        cout << "First movie relation deleted!\n";
                    } else {
                        cout << "Customer not found or no relations!\n";
                    }
                } else if (deleteChoice == 3) {
                    string custId;
                    cout << "Customer ID: ";
                    getline(cin, custId);
                    elementCustomer* cust = findCustomerByID(LC, custId);
                    if (cust && cust->firstRel) {
                        if (cust->firstRel->nextRel == nullptr) {
                            relCustMovie* toDelete;
                            deleteFirstRelCustMovie(cust, toDelete);
                            delete toDelete;
                            cout << "Last movie relation deleted!\n";
                        } else {
                            relCustMovie* current = cust->firstRel;
                            while (current->nextRel->nextRel != nullptr) {
                                current = current->nextRel;
                            }
                            relCustMovie* toDelete;
                            deleteAfterRelCustMovie(current, toDelete);
                            delete toDelete;
                            cout << "Last movie relation deleted!\n";
                        }
                    } else {
                        cout << "Customer not found or no relations!\n";
                    }
                } else {
                    cout << "Invalid choice!\n";
                }
                pressEnterToContinue();
                break;
            }
            case 8: {
                clearScreen();
                cout << "=== VIEW CUSTOMER'S MOVIES ===\n";
                string id;
                cout << "Enter Customer ID: ";
                getline(cin, id);

                elementCustomer* cust = findCustomerByID(LC, id);
                if (cust) {
                    cout << "\nCustomer: " << cust->info.name << " (" << cust->info.id << ")\n";
                    cout << "Rented Movies:\n";

                    if (cust->firstRel) {
                        relCustMovie* rel = cust->firstRel;
                        int count = 1;
                        while (rel) {
                            cout << count++ << ". " << rel->movie->info.code << " - "
                                 << rel->movie->info.title << endl;
                            rel = rel->nextRel;
                        }
                    } else {
                        cout << "No movies rented.\n";
                    }
                } else {
                    cout << "Customer not found!\n";
                }
                pressEnterToContinue();
                break;
            }

            case 9: {
                clearScreen();
                cout << "=== COUNT CUSTOMER'S MOVIES ===\n";
                string id;
                cout << "Enter Customer ID: ";
                getline(cin, id);

                elementCustomer* cust = findCustomerByID(LC, id);
                if (cust) {
                    int count = countCustomerMovies(cust);
                    cout << "Customer " << cust->info.name << " has " << count << " movie(s)\n";
                } else {
                    cout << "Customer not found!\n";
                }
                pressEnterToContinue();
                break;
            }
            case 10: {
                clearScreen();
                cout << "=== CUSTOMER CHANGE MOVIE (Change Child)===\n";
                string customerId, oldMovieCode, newMovieCode;
                cout << "Customer ID: ";
                getline(cin, customerId);
                cout << "Current Movie Code (to replace): ";
                getline(cin, oldMovieCode);
                cout << "New Movie Code: ";
                getline(cin, newMovieCode);

                // Find the customer
                elementCustomer* cust = findCustomerByID(LC, customerId);
                if (!cust) {
                    cout << "Customer not found!\n";
                    pressEnterToContinue();
                    break;
                }

                // Find the new movie
                elementMovie* newMovie = findMovieByCode(LM, newMovieCode);
                if (!newMovie) {
                    cout << "New movie not found!\n";
                    pressEnterToContinue();
                    break;
                }

                // Check if customer already has the new movie
                if (findRelCustMovieByMovie(cust, newMovieCode)) {
                    cout << "Customer already has movie " << newMovieCode << "!\n";
                    pressEnterToContinue();
                    break;
                }

                // Check if customer has the old movie
                relCustMovie* oldRel = findRelCustMovieByMovie(cust, oldMovieCode);
                if (!oldRel) {
                    cout << "Customer doesn't have movie " << oldMovieCode << "!\n";
                    pressEnterToContinue();
                    break;
                }

                // Find the old movie
                elementMovie* oldMovie = findMovieByCode(LM, oldMovieCode);
                if (!oldMovie) {
                    cout << "Old movie not found in system!\n";
                    pressEnterToContinue();
                    break;
                }

                // Remove old movie from customer
                relCustMovie* current = cust->firstRel;
                relCustMovie* prev = nullptr;

                while (current && current != oldRel) {
                    prev = current;
                    current = current->nextRel;
                }

                relCustMovie* toDelete;
                if (prev) {
                    deleteAfterRelCustMovie(prev, toDelete);
                } else {
                    deleteFirstRelCustMovie(cust, toDelete);
                }

                // Add new movie to customer
                insertElementRelCustMovie(cust, newMovie);

                // Clean up
                delete toDelete;

                cout << "\n=== MOVIE CHANGED SUCCESSFULLY ===\n";
                cout << "Customer: " << cust->info.name << " (" << customerId << ")\n";
                cout << "Changed from: " << oldMovie->info.title << " (" << oldMovieCode << ")\n";
                cout << "Changed to: " << newMovie->info.title << " (" << newMovieCode << ")\n";

                pressEnterToContinue();
                break;
            }
            case 11: {
                clearScreen();
                cout << "=== CHANGE CUSTOMER FOR MOVIE (Change Parent) ===\n";
                string movieCode, newCustomerId;
                cout << "Movie Code: ";
                getline(cin, movieCode);
                cout << "New Customer ID: ";
                getline(cin, newCustomerId);

                //Find the movie
                elementMovie* movie = findMovieByCode(LM, movieCode);
                if (!movie) {
                    cout << "Movie not found!\n";
                    pressEnterToContinue();
                    break;
                }

                //Find the new customer
                elementCustomer* newCustomer = findCustomerByID(LC, newCustomerId);
                if (!newCustomer) {
                    cout << "New customer not found!\n";
                    pressEnterToContinue();
                    break;
                }

                //Check if new customer already has this movie
                if (findRelCustMovieByMovie(newCustomer, movieCode)) {
                    cout << "New customer already has this movie!\n";
                    pressEnterToContinue();
                    break;
                }

                //Find the old customer (current parent)
                elementCustomer* oldCustomer = findCustomerByMovieCode(LC, movieCode);

                if (!oldCustomer) {
                    cout << "Movie is not currently rented by any customer!\n";
                    pressEnterToContinue();
                    break;
                }

                //Find the specific relation in old customer
                relCustMovie* oldRel = findRelCustMovieByMovie(oldCustomer, movieCode);

                if (!oldRel) {
                    cout << "Error: Relation not found in old customer!\n";
                    pressEnterToContinue();
                    break;
                }

                //Remove movie from old customer
                relCustMovie* current = oldCustomer->firstRel;
                relCustMovie* prev = nullptr;

                while (current && current != oldRel) {
                    prev = current;
                    current = current->nextRel;
                }

                relCustMovie* toDelete;
                if (prev) {
                    deleteAfterRelCustMovie(prev, toDelete);
                } else {
                    deleteFirstRelCustMovie(oldCustomer, toDelete);
                }

                //Add movie to new customer
                insertElementRelCustMovie(newCustomer, movie);

                //Clean up
                delete toDelete;

                cout << "\nSuccessfully transferred movie!\n";
                cout << "Movie '" << movie->info.title << "' moved from:\n";
                cout << "Old Customer: " << oldCustomer->info.name << " (" << oldCustomer->info.id << ")\n";
                cout << "New Customer: " << newCustomer->info.name << " (" << newCustomer->info.id << ")\n";

                pressEnterToContinue();
                break;
            }

        }
    } while (choice != 0);
}

void handleMovieMenu() {
    int choice;

    do {
        displayMovieMenu();
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1: {
                clearScreen();
                cout << "=== INSERT NEW MOVIE ===\n";
                movie m;
                cout << "Movie Code: ";
                getline(cin, m.code);
                cout << "Title: ";
                getline(cin, m.title);
                cout << "Genre: ";
                getline(cin, m.genre);
                cout << "Year: ";
                cin >> m.year;
                cout << "Price: ";
                cin >> m.price;
                cin.ignore();

                if (findMovieByCode(LM, m.code)) {
                    cout << "Error: Movie Code sudah dipakai!\n";
                } else {
                    elementMovie* newMovie = createElementMovie(m);

                    cout << "\nInsertion Method:\n";
                    cout << "1. Insert first\n";
                    cout << "2. Insert last\n";
                    cout << "3. Insert after specific movie\n";
                    cout << "Choose (1-3): ";
                    int insertChoice;
                    cin >> insertChoice;
                    cin.ignore();

                    if (insertChoice == 1) {
                        insertElementMovie(LM, newMovie, "first");
                        cout << "Movie berhasil ditambahkan di awal!\n";
                    } else if (insertChoice == 2) {
                        insertElementMovie(LM, newMovie, "last");
                        cout << "Movie berhasil ditambahkan di akhir!\n";
                    } else if (insertChoice == 3) {
                        cout << "Enter Code of movie to insert after: ";
                        string afterCode;
                        getline(cin, afterCode);
                        elementMovie* prec = findMovieByCode(LM, afterCode);
                        if (prec) {
                            insertElementMovie(LM, newMovie, "after", prec);
                            cout << "Movie berhasil ditambahkan setelah " << prec->info.title << "!\n";
                        } else {
                            cout << "Movie not found! Inserting at end instead.\n";
                            insertElementMovie(LM, newMovie, "last");
                        }
                    } else {
                        cout << "Invalid choice! Inserting at end by default.\n";
                        insertElementMovie(LM, newMovie, "last");
                    }
                }
                pressEnterToContinue();
                break;
            }

            case 2: {
                clearScreen();
                showAllMovie(LM);
                pressEnterToContinue();
                break;
            }

            case 3: {
                clearScreen();
                cout << "=== SEARCH MOVIE ===\n";
                string code;
                cout << "Enter Movie Code: ";
                getline(cin, code);

                elementMovie* mov = findMovieByCode(LM, code);
                if (mov) {
                    cout << "\n--- MOVIE FOUND ---\n";
                    showMovieData(mov);
                } else {
                    cout << "Movie not found!\n";
                }
                pressEnterToContinue();
                break;
            }

            case 4: {
                clearScreen();
                cout << "=== UPDATE MOVIE ===\n";
                string code;
                cout << "Enter Movie Code: ";
                getline(cin, code);

                elementMovie* mov = findMovieByCode(LM, code);
                if (mov) {
                    cout << "\nCurrent Data:\n";
                    showMovieData(mov);

                    cout << "\nEnter new title: ";
                    getline(cin, mov->info.title);
                    cout << "Enter new genre: ";
                    getline(cin, mov->info.genre);
                    cout << "Enter new year: ";
                    cin >> mov->info.year;
                    cout << "Enter new price: ";
                    cin >> mov->info.price;
                    cin.ignore();

                    cout << "Movie berhasil di-update!\n";
                } else {
                    cout << "Movie not found!\n";
                }
                pressEnterToContinue();
                break;
            }

            case 5: {
                clearScreen();
                cout << "=== DELETE MOVIE ===\n";
                cout << "Delete Method:\n";
                cout << "1. Delete by Code\n";
                cout << "2. Delete first movie\n";
                cout << "3. Delete last movie\n";
                cout << "4. Delete after specific movie\n";
                cout << "Choose (1-4): ";
                int deleteChoice;
                cin >> deleteChoice;
                cin.ignore();

                elementMovie* toDelete = nullptr;

                if (deleteChoice == 1) {
                    string code;
                    cout << "Enter Movie Code: ";
                    getline(cin, code);
                    elementMovie* mov = findMovieByCode(LM, code);
                    if (mov) {
                        if (mov->firstRel != nullptr) {
                            cout << "Tidak bisa dihapus karena relasi movie-rental!\n";
                        } else {
                            elementMovie* prev = nullptr;
                            elementMovie* curr = LM.first;
                            while (curr && curr != mov) {
                                prev = curr;
                                curr = curr->next;
                            }

                            if (prev) {
                                deleteAfterMovie(prev, toDelete);
                            } else {
                                deleteFirstMovie(LM, toDelete);
                            }
                            delete toDelete;
                            cout << "Movie berhasil dihapus!\n";
                        }
                    } else {
                        cout << "Movie not found!\n";
                    }
                } else if (deleteChoice == 2) {
                    if (LM.first) {
                        if (LM.first->firstRel != nullptr) {
                            cout << "Tidak bisa dihapus karena relasi movie-rental!\n";
                        } else {
                            deleteFirstMovie(LM, toDelete);
                            if (toDelete) {
                                delete toDelete;
                                cout << "First movie berhasil dihapus!\n";
                            }
                        }
                    } else {
                        cout << "No movies to delete!\n";
                    }
                } else if (deleteChoice == 3) {
                    if (LM.first) {
                        elementMovie* last = LM.first;
                        elementMovie* prev = nullptr;
                        while (last->next) {
                            prev = last;
                            last = last->next;
                        }
                        if (last->firstRel != nullptr) {
                            cout << "Tidak bisa dihapus karena relasi movie-rental!\n";
                        } else {
                            if (prev) {
                                deleteAfterMovie(prev, toDelete);
                            } else {
                                deleteFirstMovie(LM, toDelete);
                            }
                            if (toDelete) {
                                delete toDelete;
                                cout << "Last movie berhasil dihapus!\n";
                            }
                        }
                    } else {
                        cout << "No movies to delete!\n";
                    }
                } else if (deleteChoice == 4) {
                    cout << "Enter Code of movie to delete after: ";
                    string afterCode;
                    getline(cin, afterCode);
                    elementMovie* afterMov = findMovieByCode(LM, afterCode);
                    if (afterMov && afterMov->next) {
                        elementMovie* nextMov = afterMov->next;
                        if (nextMov->firstRel != nullptr) {
                            cout << "Tidak bisa dihapus karena relasi movie-rental!\n";
                        } else {
                            deleteAfterMovie(afterMov, toDelete);
                            if (toDelete) {
                                delete toDelete;
                                cout << "Movie berhasil dihapus!\n";
                            }
                        }
                    } else {
                        cout << "Movie not found or no movie after!\n";
                    }
                } else {
                    cout << "Invalid choice!\n";
                }
                pressEnterToContinue();
                break;
            }

            case 6: {
                clearScreen();
                cout << "=== ADD RENTAL TO MOVIE ===\n";
                string movieCode, rentalId;
                cout << "Movie Code: ";
                getline(cin, movieCode);
                cout << "Rental ID: ";
                getline(cin, rentalId);

                elementMovie* mov = findMovieByCode(LM, movieCode);
                elementRental* rent = findRentalByID(LR, rentalId);

                if (!mov) {
                    cout << "Movie not found!\n";
                } else if (!rent) {
                    cout << "Rental not found!\n";
                } else if (findRelMovieRentByRental(mov, rentalId)) {
                    cout << "Movie sudah punya rental ini!\n";
                } else {
                    insertElementRelMovieRent(mov, rent);
                    cout << "Rental berhasil ditambahkan ke movie!\n";
                }
                pressEnterToContinue();
                break;
            }

            case 7: {
                clearScreen();
                cout << "=== REMOVE RENTAL FROM MOVIE ===\n";
                cout << "Delete Method:\n";
                cout << "1. Delete specific rental relation\n";
                cout << "2. Delete first rental relation\n";
                cout << "3. Delete last rental relation\n";
                cout << "Choose (1-3): ";
                int deleteChoice;
                cin >> deleteChoice;
                cin.ignore();

                if (deleteChoice == 1) {
                    string movieCode, rentalId;
                    cout << "Movie Code: ";
                    getline(cin, movieCode);
                    cout << "Rental ID: ";
                    getline(cin, rentalId);

                    elementMovie* mov = findMovieByCode(LM, movieCode);
                    if (mov) {
                        relMovieRent* rel = findRelMovieRentByRental(mov, rentalId);
                        if (rel) {
                            relMovieRent* current = mov->firstRel;
                            relMovieRent* prev = nullptr;

                            while (current && current != rel) {
                                prev = current;
                                current = current->nextRel;
                            }

                            relMovieRent* toDelete;
                            if (prev) {
                                deleteAfterRelMovieRent(prev, toDelete);
                            } else {
                                deleteFirstRelMovieRent(mov, toDelete);
                            }
                            delete toDelete;
                            cout << "Rental dihapus dari movie!\n";
                        } else {
                            cout << "Movie tidak punya rental ini!\n";
                        }
                    } else {
                        cout << "Movie not found!\n";
                    }
                } else if (deleteChoice == 2) {
                    string movieCode;
                    cout << "Movie Code: ";
                    getline(cin, movieCode);
                    elementMovie* mov = findMovieByCode(LM, movieCode);
                    if (mov && mov->firstRel) {
                        relMovieRent* toDelete;
                        deleteFirstRelMovieRent(mov, toDelete);
                        delete toDelete;
                        cout << "First rental relation deleted!\n";
                    } else {
                        cout << "Movie not found or no relations!\n";
                    }
                } else if (deleteChoice == 3) {
                    string movieCode;
                    cout << "Movie Code: ";
                    getline(cin, movieCode);
                    elementMovie* mov = findMovieByCode(LM, movieCode);
                    if (mov && mov->firstRel) {
                        if (mov->firstRel->nextRel == nullptr) {
                            relMovieRent* toDelete;
                            deleteFirstRelMovieRent(mov, toDelete);
                            delete toDelete;
                            cout << "Last rental relation deleted!\n";
                        } else {
                            relMovieRent* current = mov->firstRel;
                            while (current->nextRel->nextRel != nullptr) {
                                current = current->nextRel;
                            }
                            relMovieRent* toDelete;
                            deleteAfterRelMovieRent(current, toDelete);
                            delete toDelete;
                            cout << "Last rental relation deleted!\n";
                        }
                    } else {
                        cout << "Movie not found or no relations!\n";
                    }
                } else {
                    cout << "Invalid choice!\n";
                }
                pressEnterToContinue();
                break;
            }

            case 8: {
                clearScreen();
                cout << "=== UPDATE RENTAL RELATION ===\n";
                string movieCode, oldRentalId, newRentalId;
                cout << "Movie Code: ";
                getline(cin, movieCode);
                cout << "Current Rental ID: ";
                getline(cin, oldRentalId);
                cout << "New Rental ID: ";
                getline(cin, newRentalId);

                elementMovie* mov = findMovieByCode(LM, movieCode);
                if (!mov) {
                    cout << "Movie not found!\n";
                    pressEnterToContinue();
                    break;
                }

                relMovieRent* oldRel = findRelMovieRentByRental(mov, oldRentalId);
                elementRental* newRent = findRentalByID(LR, newRentalId);

                if (!oldRel) {
                    cout << "Old rental relation not found!\n";
                } else if (!newRent) {
                    cout << "New rental not found!\n";
                } else if (findRelMovieRentByRental(mov, newRentalId)) {
                    cout << "Movie sudah punya rental ini!\n";
                } else {
                    oldRel->rental = newRent;
                    cout << "Rental relation berhasil di-update!\n";
                }
                pressEnterToContinue();
                break;
            }

            case 9: {
                clearScreen();
                cout << "=== VIEW MOVIE'S RENTALS ===\n";
                string code;
                cout << "Enter Movie Code: ";
                getline(cin, code);

                elementMovie* mov = findMovieByCode(LM, code);
                if (mov) {
                    cout << "\nMovie: " << mov->info.title << " (" << mov->info.code << ")\n";
                    cout << "Active Rentals:\n";

                    if (mov->firstRel) {
                        relMovieRent* rel = mov->firstRel;
                        int count = 1;
                        while (rel) {
                            cout << count++ << ". " << rel->rental->info.rentId
                                 << " - " << rel->rental->info.date << endl;
                            rel = rel->nextRel;
                        }
                    } else {
                        cout << "No active rentals.\n";
                    }
                } else {
                    cout << "Movie not found!\n";
                }
                pressEnterToContinue();
                break;
            }

            case 10: {
                clearScreen();
                cout << "=== COUNT MOVIE'S RENTALS ===\n";
                string code;
                cout << "Enter Movie Code: ";
                getline(cin, code);

                elementMovie* mov = findMovieByCode(LM, code);
                if (mov) {
                    int count = countMovieRentals(mov);
                    cout << "Movie " << mov->info.title << " has " << count << " rental(s)\n";
                } else {
                    cout << "Movie not found!\n";
                }
                pressEnterToContinue();
                break;
            }
        }
    } while (choice != 0);
}

void handleRentalMenu() {
    int choice;

    do {
        displayRentalMenu();
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1: {
                clearScreen();
                cout << "=== ADD NEW RENTAL ===\n";
                rental r;
                cout << "Rental ID: ";
                getline(cin, r.rentId);
                cout << "Date (YYYY-MM-DD): ";
                getline(cin, r.date);

                cout << "Movie Code: ";
                getline(cin, r.movieCode);

                elementMovie* movie = findMovieByCode(LM, r.movieCode);
                if (!movie) {
                    cout << "Error: Movie not found!\n";
                    pressEnterToContinue();
                    break;
                }

                cout << "Duration (days): ";
                cin >> r.duration;
                r.totalFee = r.duration * movie->info.price;

                cout << "Price per day: $" << movie->info.price << endl;
                cout << "Total fee: $" << r.totalFee << "\n";

                cin.ignore();

                if (findRentalByID(LR, r.rentId)) {
                    cout << "Error: Rental ID sudah dipakai\n";
                } else {
                    elementRental* newRental = createElementRental(r);

                    cout << "\nInsertion Method:\n";
                    cout << "1. Insert first\n";
                    cout << "2. Insert last\n";
                    cout << "3. Insert after specific rental\n";
                    cout << "Choose (1-3): ";
                    int insertChoice;
                    cin >> insertChoice;
                    cin.ignore();

                    if (insertChoice == 1) {
                        insertElementRental(LR, newRental, "first");
                        cout << "Rental berhasil ditambahkan di awal!\n";
                    } else if (insertChoice == 2) {
                        insertElementRental(LR, newRental, "last");
                        cout << "Rental berhasil ditambahkan di akhir!\n";
                    } else if (insertChoice == 3) {
                        cout << "Enter ID of rental to insert after: ";
                        string afterId;
                        getline(cin, afterId);
                        elementRental* prec = findRentalByID(LR, afterId);
                        if (prec) {
                            insertElementRental(LR, newRental, "after", prec);
                            cout << "Rental berhasil ditambahkan setelah " << prec->info.rentId << "!\n";
                        } else {
                            cout << "Rental not found! Inserting at end instead.\n";
                            insertElementRental(LR, newRental, "last");
                        }
                    } else {
                        cout << "Invalid choice! Inserting at end by default.\n";
                        insertElementRental(LR, newRental, "last");
                    }

                    insertElementRelMovieRent(movie, newRental);
                    cout << "Relation with movie '" << movie->info.title << "' dibuat otomatis!\n";
                }
                pressEnterToContinue();
                break;
            }

            case 2: {
                clearScreen();
                showAllRental(LR);
                pressEnterToContinue();
                break;
            }

            case 3: {
                clearScreen();
                cout << "=== SEARCH RENTAL ===\n";
                string id;
                cout << "Enter Rental ID: ";
                getline(cin, id);

                elementRental* rent = findRentalByID(LR, id);
                if (rent) {
                    cout << "\n--- RENTAL FOUND ---\n";
                    showRentalData(rent);
                } else {
                    cout << "Rental not found!\n";
                }
                pressEnterToContinue();
                break;
            }

            case 4: {
                clearScreen();
                cout << "=== UPDATE RENTAL ===\n";
                string id;
                cout << "Enter Rental ID to update: ";
                getline(cin, id);

                elementRental* rent = findRentalByID(LR, id);
                if (rent) {
                    cout << "\nCurrent Data:\n";
                    showRentalData(rent);

                    cout << "\nEnter NEW data (all fields required):\n";

                    string newDate;
                    cout << "New Date: ";
                    getline(cin, newDate);

                    string newMovieCode;
                    cout << "New Movie Code: ";
                    getline(cin, newMovieCode);

                    elementMovie* movie = findMovieByCode(LM, newMovieCode);
                    if (!movie) {
                        cout << "Error: Movie not found!\n";
                        pressEnterToContinue();
                        break;
                    }

                    int newDuration;
                    cout << "New Duration (days): ";
                    cin >> newDuration;
                    cin.ignore();

                    rent->info.date = newDate;
                    rent->info.movieCode = newMovieCode;
                    rent->info.duration = newDuration;

                    rent->info.totalFee = newDuration * movie->info.price;

                    cout << "\nRental Updated:\n";
                    cout << "Movie: " << movie->info.title << endl;
                    cout << "Duration: " << newDuration << " days" << endl;
                    cout << "Price per day: $" << movie->info.price << endl;
                    cout << "Total fee: $" << rent->info.totalFee << endl;

                    cout << "Rental berhasil di-update!\n";
                } else {
                    cout << "Rental not found!\n";
                }
                pressEnterToContinue();
                break;
            }

            case 5: {
                clearScreen();
                cout << "=== DELETE RENTAL ===\n";
                cout << "Delete Method:\n";
                cout << "1. Delete by ID\n";
                cout << "2. Delete first rental\n";
                cout << "3. Delete last rental\n";
                cout << "4. Delete after specific rental\n";
                cout << "Choose (1-4): ";
                int deleteChoice;
                cin >> deleteChoice;
                cin.ignore();

                elementRental* toDelete = nullptr;

                if (deleteChoice == 1) {
                    string id;
                    cout << "Enter Rental ID: ";
                    getline(cin, id);
                    elementRental* rent = findRentalByID(LR, id);
                    if (rent) {
                        bool hasRelation = false;
                        elementMovie* current = LM.first;
                        while (current && !hasRelation) {
                            if (findRelMovieRentByRental(current, id)) {
                                hasRelation = true;
                            }
                            current = current->next;
                        }

                        if (hasRelation) {
                            cout << "Tidak bisa dihapus karena relasi movie-rental!\n";
                        } else {
                            elementRental* prev = nullptr;
                            elementRental* curr = LR.first;
                            while (curr && curr != rent) {
                                prev = curr;
                                curr = curr->next;
                            }

                            if (prev) {
                                deleteAfterRental(prev, toDelete);
                            } else {
                                deleteFirstRental(LR, toDelete);
                            }
                            delete toDelete;
                            cout << "Rental deleted successfully!\n";
                        }
                    } else {
                        cout << "Rental not found!\n";
                    }
                } else if (deleteChoice == 2) {
                    if (LR.first) {
                        bool hasRelation = false;
                        elementMovie* current = LM.first;
                        while (current && !hasRelation) {
                            if (findRelMovieRentByRental(current, LR.first->info.rentId)) {
                                hasRelation = true;
                            }
                            current = current->next;
                        }

                        if (hasRelation) {
                            cout << "Tidak bisa dihapus karena relasi movie-rental!\n";
                        } else {
                            deleteFirstRental(LR, toDelete);
                            if (toDelete) {
                                delete toDelete;
                                cout << "First rental deleted successfully!\n";
                            }
                        }
                    } else {
                        cout << "No rentals to delete!\n";
                    }
                } else if (deleteChoice == 3) {
                    if (LR.first) {
                        elementRental* last = LR.first;
                        elementRental* prev = nullptr;
                        while (last->next) {
                            prev = last;
                            last = last->next;
                        }

                        bool hasRelation = false;
                        elementMovie* current = LM.first;
                        while (current && !hasRelation) {
                            if (findRelMovieRentByRental(current, last->info.rentId)) {
                                hasRelation = true;
                            }
                            current = current->next;
                        }

                        if (hasRelation) {
                            cout << "Tidak bisa dihapus karena relasi movie-rental!\n";
                        } else {
                            if (prev) {
                                deleteAfterRental(prev, toDelete);
                            } else {
                                deleteFirstRental(LR, toDelete);
                            }
                            if (toDelete) {
                                delete toDelete;
                                cout << "Last rental deleted successfully!\n";
                            }
                        }
                    } else {
                        cout << "No rentals to delete!\n";
                    }
                } else if (deleteChoice == 4) {
                    cout << "Enter ID of rental to delete after: ";
                    string afterId;
                    getline(cin, afterId);
                    elementRental* afterRent = findRentalByID(LR, afterId);
                    if (afterRent && afterRent->next) {
                        elementRental* nextRent = afterRent->next;

                        bool hasRelation = false;
                        elementMovie* current = LM.first;
                        while (current && !hasRelation) {
                            if (findRelMovieRentByRental(current, nextRent->info.rentId)) {
                                hasRelation = true;
                            }
                            current = current->next;
                        }

                        if (hasRelation) {
                            cout << "Tidak bisa dihapus karena relasi movie-rental!\n";
                        } else {
                            deleteAfterRental(afterRent, toDelete);
                            if (toDelete) {
                                delete toDelete;
                                cout << "Rental deleted successfully!\n";
                            }
                        }
                    } else {
                        cout << "Rental not found or no rental after!\n";
                    }
                } else {
                    cout << "Invalid choice!\n";
                }
                pressEnterToContinue();
                break;
            }

            case 6: {
                clearScreen();
                cout << "=== RENTALS WITHOUT MOVIE RELATION ===\n";
                int count = countRentalsWithNoMovie(LR, LM);
                cout << "Total: " << count << " rental(s)\n\n";

                elementRental* current = LR.first;
                int num = 1;
                while (current) {
                    if (!hasMovieRelation(current, LM)) {
                        cout << num++ << ". " << current->info.rentId
                             << " - " << current->info.date << endl;
                    }
                    current = current->next;
                }
                pressEnterToContinue();
                break;
            }

            case 7: {
                clearScreen();
                showAllRentalsWithMovies(LR, LM);
                pressEnterToContinue();
                break;
            }
        }
    } while (choice != 0);
}

void handleViewMenu() {
    int choice;

    do {
        displayViewMenu();
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1: {
                clearScreen();
                showAllCustomersWithMovies(LC);
                pressEnterToContinue();
                break;
            }

            case 2: {
                clearScreen();
                showAllMoviesWithRentals(LM);
                pressEnterToContinue();
                break;
            }

            case 3: {
                clearScreen();
                showAllRentalsWithMovies(LR, LM);
                pressEnterToContinue();
                break;
            }

            case 4: {
                clearScreen();
                cout << "=== MOVIES FOR SPECIFIC CUSTOMER ===\n";
                string id;
                cout << "Enter Customer ID: ";
                getline(cin, id);

                showMoviesForCustomer(LC, id);
                pressEnterToContinue();
                break;
            }

            case 5: {
                clearScreen();
                cout << "=== RENTALS FOR SPECIFIC MOVIE ===\n";
                string code;
                cout << "Enter Movie Code: ";
                getline(cin, code);

                elementMovie* mov = findMovieByCode(LM, code);
                if (mov) {
                    cout << "\nMovie: " << mov->info.title << "\n";
                    showMovieRentals(mov);
                } else {
                    cout << "Movie not found!\n";
                }
                pressEnterToContinue();
                break;
            }

            case 6: {
                clearScreen();
                cout << "=== MOVIES FOR SPECIFIC RENTAL ===\n";
                string id;
                cout << "Enter Rental ID: ";
                getline(cin, id);

                int count = countMoviesForRental(LM, id);
                cout << "Rental " << id << " is connected to " << count << " movie(s)\n\n";

                if (count > 0) {
                    elementMovie* current = LM.first;
                    int num = 1;
                    while (current) {
                        relMovieRent* rel = current->firstRel;
                        while (rel) {
                            if (rel->rental->info.rentId == id) {
                                cout << num++ << ". " << current->info.code
                                     << " - " << current->info.title << endl;
                                break;
                            }
                            rel = rel->nextRel;
                        }
                        current = current->next;
                    }
                }
                pressEnterToContinue();
                break;
            }
            case 7: {
                clearScreen();
                cout << "=== SHOW CUSTOMERS FOR SPECIFIC MOVIE (Parent from Child) ===\n";
                string movieCode;
                cout << "Enter Movie Code: ";
                getline(cin, movieCode);

                showCustomersForMovie(LC, LM, movieCode);
                pressEnterToContinue();
                break;
            }
        }
    } while (choice != 0);
}

void handleStatisticsMenu() {
    int choice;

    do {
        displayStatisticsMenu();
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1: {
                clearScreen();
                cout << "=== RELATION COUNT PER CUSTOMER ===\n";
                elementCustomer* current = LC.first;
                int num = 1;

                if (!current) {
                    cout << "No customers found!\n";
                } else {
                    while (current) {
                        int movieCount = countCustomerMovies(current);
                        cout << num++ << ". " << current->info.name
                             << " (" << current->info.id << "): "
                             << movieCount << " movie(s)\n";
                        current = current->next;
                    }
                }
                pressEnterToContinue();
                break;
            }

            case 2: {
                clearScreen();
                cout << "=== RELATION COUNT PER MOVIE ===\n";
                elementMovie* current = LM.first;
                int num = 1;

                if (!current) {
                    cout << "No movies found!\n";
                } else {
                    while (current) {
                        int rentalCount = countMovieRentals(current);
                        cout << num++ << ". " << current->info.title
                             << " (" << current->info.code << "): "
                             << rentalCount << " rental(s)\n";
                        current = current->next;
                    }
                }
                pressEnterToContinue();
                break;
            }

            case 3: {
                clearScreen();
                cout << "=== COUNT RELATIONS FOR SPECIFIC RENTAL ===\n";
                string rentalId;
                cout << "Enter Rental ID: ";
                getline(cin, rentalId);

                elementRental* rent = findRentalByID(LR, rentalId);
                if (!rent) {
                    cout << "Rental not found!\n";
                } else {
                    int movieCount = countMoviesForRental(LM, rentalId);
                    cout << "Rental " << rentalId << " is connected to "
                         << movieCount << " movie(s)\n";
                }
                pressEnterToContinue();
                break;
            }

            case 4: {
                clearScreen();
                cout << "=== COUNT RENTALS WITHOUT MOVIE RELATION ===\n";
                int count = countRentalsWithNoMovie(LR, LM);
                cout << "Total rentals without movie relation: " << count << "\n";
                pressEnterToContinue();
                break;
            }

            case 5: { // Total Customers dengan/tanpa Movies
                clearScreen();
                cout << "=== CUSTOMER STATISTICS ===\n";
                elementCustomer* current = LC.first;
                int total = 0, withMovies = 0, withoutMovies = 0;

                while (current) {
                    total++;
                    if (current->firstRel) {
                        withMovies++;
                    } else {
                        withoutMovies++;
                    }
                    current = current->next;
                }

                cout << "Total Customers: " << total << "\n";
                cout << "Customers with movies: " << withMovies << "\n";
                cout << "Customers without movies: " << withoutMovies << "\n";
                pressEnterToContinue();
                break;
            }

            case 6: { // Total Movies dengan/tanpa Rentals
                clearScreen();
                cout << "=== MOVIE STATISTICS ===\n";
                elementMovie* current = LM.first;
                int total = 0, withRentals = 0, withoutRentals = 0;

                while (current) {
                    total++;
                    if (current->firstRel) {
                        withRentals++;
                    } else {
                        withoutRentals++;
                    }
                    current = current->next;
                }

                cout << "Total Movies: " << total << "\n";
                cout << "Movies with rentals: " << withRentals << "\n";
                cout << "Movies without rentals: " << withoutRentals << "\n";
                pressEnterToContinue();
                break;
            }
        }
    } while (choice != 0);
}

void loadTemplateData() {
    clearScreen();
    cout << "=== LOAD TEMPLATE DATA ===\n";
    cout << "Loading sample data...\n\n";

    createListCustomer(LC);
    createListMovie(LM);
    createListRental(LR);

    // Sample Customers
    customer customers[] = {
        {"C001", "John Doe", "123-456-7890"},
        {"C002", "Jane Smith", "987-654-3210"},
        {"C003", "Bob Johnson", "555-123-4567"},
        {"C004", "Alice Williams", "444-555-6666"},
        {"C005", "Charlie Brown", "777-888-9999"},
        {"C006", "Emma Wilson", "111-222-3333"}
    };
    int customerCount = 6;

    // Sample Movies
    movie movies[] = {
        {"M001", "Inception", "Sci-Fi", 2010, 3.99},
        {"M002", "The Matrix", "Action", 1999, 2.99},
        {"M003", "Titanic", "Romance", 1997, 2.49},
        {"M004", "Avatar", "Adventure", 2009, 3.49},
        {"M005", "Avengers: Endgame", "Action", 2019, 4.99},
        {"M006", "The Dark Knight", "Action", 2008, 3.79},
        {"M007", "Parasite", "Drama", 2019, 3.29},
        {"M008", "Spirited Away", "Animation", 2001, 2.99},
        {"M009", "Interstellar", "Sci-Fi", 2014, 3.89},
        {"M010", "The Shawshank Redemption", "Drama", 1994, 2.99},
        {"M011", "Pulp Fiction", "Crime", 1994, 2.79},
        {"M012", "The Godfather", "Crime", 1972, 2.99}
    };
    int movieCount = 12;

    // Sample Rentals
    rental rentals[] = {
        {"R001", "2024-01-15", 7, 27.93},
        {"R002", "2024-01-20", 3, 8.97},
        {"R003", "2024-01-25", 5, 17.45},
        {"R004", "2024-02-01", 4, 15.96},
        {"R005", "2024-02-05", 6, 23.94},
        {"R006", "2024-02-10", 2, 9.98},
        {"R007", "2024-02-15", 7, 27.93},
        {"R008", "2024-02-20", 5, 19.95},
        {"R009", "2024-02-25", 3, 11.97}
    };
    int rentalCount = 9;

    for (int i = 0; i < customerCount; i++) {
        elementCustomer* newCust = createElementCustomer(customers[i]);
        insertLastCustomer(LC, newCust);
    }
    for (int i = 0; i < movieCount; i++) {
        elementMovie* newMovie = createElementMovie(movies[i]);
        insertLastMovie(LM, newMovie);
    }
    for (int i = 0; i < rentalCount; i++) {
        elementRental* newRental = createElementRental(rentals[i]);
        insertLastRental(LR, newRental);
    }

    // Create relations
    elementCustomer* cust1 = findCustomerByID(LC, "C001");
    elementCustomer* cust2 = findCustomerByID(LC, "C002");
    elementCustomer* cust3 = findCustomerByID(LC, "C003");
    elementCustomer* cust4 = findCustomerByID(LC, "C004");
    elementCustomer* cust5 = findCustomerByID(LC, "C005");
    elementCustomer* cust6 = findCustomerByID(LC, "C006");

    elementMovie* mov1 = findMovieByCode(LM, "M001");
    elementMovie* mov2 = findMovieByCode(LM, "M002");
    elementMovie* mov3 = findMovieByCode(LM, "M003");
    elementMovie* mov4 = findMovieByCode(LM, "M004");
    elementMovie* mov5 = findMovieByCode(LM, "M005");
    elementMovie* mov6 = findMovieByCode(LM, "M006");
    elementMovie* mov7 = findMovieByCode(LM, "M007");
    elementMovie* mov8 = findMovieByCode(LM, "M008");
    elementMovie* mov9 = findMovieByCode(LM, "M009");
    elementMovie* mov10 = findMovieByCode(LM, "M010");
    elementMovie* mov11 = findMovieByCode(LM, "M011");
    elementMovie* mov12 = findMovieByCode(LM, "M012");

    elementRental* rent1 = findRentalByID(LR, "R001");
    elementRental* rent2 = findRentalByID(LR, "R002");
    elementRental* rent3 = findRentalByID(LR, "R003");
    elementRental* rent4 = findRentalByID(LR, "R004");
    elementRental* rent5 = findRentalByID(LR, "R005");
    elementRental* rent6 = findRentalByID(LR, "R006");
    elementRental* rent7 = findRentalByID(LR, "R007");
    elementRental* rent8 = findRentalByID(LR, "R008");
    elementRental* rent9 = findRentalByID(LR, "R009");

    // Customer-Movie Relations (customers renting movies)
    if (cust1 && mov1) insertElementRelCustMovie(cust1, mov1);  // John rents Inception
    if (cust1 && mov2) insertElementRelCustMovie(cust1, mov2);  // John rents The Matrix
    if (cust1 && mov5) insertElementRelCustMovie(cust1, mov5);  // John rents Avengers
    if (cust1 && mov6) insertElementRelCustMovie(cust1, mov6);  // John rents Dark Knight

    if (cust2 && mov3) insertElementRelCustMovie(cust2, mov3);  // Jane rents Titanic
    if (cust2 && mov7) insertElementRelCustMovie(cust2, mov7);  // Jane rents Parasite
    if (cust2 && mov8) insertElementRelCustMovie(cust2, mov8);  // Jane rents Spirited Away

    if (cust3 && mov4) insertElementRelCustMovie(cust3, mov4);  // Bob rents Avatar
    if (cust3 && mov9) insertElementRelCustMovie(cust3, mov9);  // Bob rents Interstellar

    if (cust4 && mov10) insertElementRelCustMovie(cust4, mov10); // Alice rents Shawshank
    if (cust4 && mov11) insertElementRelCustMovie(cust4, mov11); // Alice rents Pulp Fiction
    if (cust4 && mov12) insertElementRelCustMovie(cust4, mov12); // Alice rents Godfather

    if (cust5 && mov5) insertElementRelCustMovie(cust5, mov5);  // Charlie rents Avengers
    if (cust5 && mov6) insertElementRelCustMovie(cust5, mov6);  // Charlie rents Dark Knight
    if (cust5 && mov9) insertElementRelCustMovie(cust5, mov9);  // Charlie rents Interstellar

    if (cust6 && mov1) insertElementRelCustMovie(cust6, mov1);  // Emma rents Inception
    if (cust6 && mov7) insertElementRelCustMovie(cust6, mov7);  // Emma rents Parasite
    if (cust6 && mov8) insertElementRelCustMovie(cust6, mov8);  // Emma rents Spirited Away

    // Movie-Rental Relations (movies in rentals)
    if (mov1 && rent1) insertElementRelMovieRent(mov1, rent1);  // Inception in R001
    if (mov2 && rent2) insertElementRelMovieRent(mov2, rent2);  // The Matrix in R002
    if (mov3 && rent3) insertElementRelMovieRent(mov3, rent3);  // Titanic in R003
    if (mov4 && rent4) insertElementRelMovieRent(mov4, rent4);  // Avatar in R004
    if (mov5 && rent5) insertElementRelMovieRent(mov5, rent5);  // Avengers in R005
    if (mov6 && rent6) insertElementRelMovieRent(mov6, rent6);  // Dark Knight in R006
    if (mov7 && rent7) insertElementRelMovieRent(mov7, rent7);  // Parasite in R007
    if (mov8 && rent8) insertElementRelMovieRent(mov8, rent8);  // Spirited Away in R008
    if (mov9 && rent9) insertElementRelMovieRent(mov9, rent9);  // Interstellar in R009
    if (mov10 && rent1) insertElementRelMovieRent(mov10, rent1); // Shawshank in R001
    if (mov11 && rent2) insertElementRelMovieRent(mov11, rent2); // Pulp Fiction in R002
    if (mov12 && rent3) insertElementRelMovieRent(mov12, rent3); // Godfather in R003

    cout << "Template data loaded successfully!\n";
    cout << "- " << customerCount << " Customers\n";
    cout << "- " << movieCount << " Movies\n";
    cout << "- " << rentalCount << " Rentals\n";
    cout << "- Sample relations created\n";

    pressEnterToContinue();
}


int main() {
    initData();
    int choice;

    do {
        displayMainMenu();
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1:
                handleCustomerMenu();
                break;
            case 2:
                handleMovieMenu();
                break;
            case 3:
                handleRentalMenu();
                break;
            case 4:
                clearScreen();
                cout << "=== RELATION OPERATIONS ===\n";
                cout << "1. Find Customer-Movie Relation\n";
                cout << "2. Find Movie-Rental Relation\n";
                cout << "Enter choice (0 to back): ";
                int relChoice;
                cin >> relChoice;
                cin.ignore();

                if (relChoice == 1) {
                    clearScreen();
                    cout << "=== FIND CUSTOMER-MOVIE RELATION ===\n";
                    string custId, movieCode;
                    cout << "Customer ID: ";
                    getline(cin, custId);
                    cout << "Movie Code: ";
                    getline(cin, movieCode);

                    elementCustomer* cust = findCustomerByID(LC, custId);
                    if (cust) {
                        relCustMovie* rel = findRelCustMovieByMovie(cust, movieCode);
                        if (rel) {
                            cout << "Relation found! Customer " << custId
                                 << " has movie " << movieCode << endl;
                        } else {
                            cout << "Relation not found.\n";
                        }
                    } else {
                        cout << "Customer not found.\n";
                    }
                } else if (relChoice == 2) {
                    clearScreen();
                    cout << "=== FIND MOVIE-RENTAL RELATION ===\n";
                    string movieCode, rentalId;
                    cout << "Movie Code: ";
                    getline(cin, movieCode);
                    cout << "Rental ID: ";
                    getline(cin, rentalId);

                    elementMovie* mov = findMovieByCode(LM, movieCode);
                    if (mov) {
                        relMovieRent* rel = findRelMovieRentByRental(mov, rentalId);
                        if (rel) {
                            cout << "Relation found! Movie " << movieCode
                                 << " has rental " << rentalId << endl;
                        } else {
                            cout << "Relation not found.\n";
                        }
                    } else {
                        cout << "Movie not found.\n";
                    }
                }
                pressEnterToContinue();
                break;
            case 5:
                handleViewMenu();
                break;
            case 6:
                handleStatisticsMenu();
                break;
            case 7:
                loadTemplateData();
                break;
            case 0:
                clearScreen();
                cout << "Keluar dari Program..\n";
                break;
            default:
                cout << "Invalid choice! Coba pilihan lain.\n";
                pressEnterToContinue();
        }

    } while (choice != 0);

    return 0;
}

