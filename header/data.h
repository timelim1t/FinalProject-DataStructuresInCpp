#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

struct customer {
    string id;
    string name;
    string phone;
};

struct movie {
    string code;
    string title;
    string genre;
    int year;
    float price; // harga per hari
};

struct rental {
    string rentId;
    string date;
    int duration;    // jumlah hari
    float totalFee;  // duration * movie.price
    string movieCode;  // movie yang dipinjam
};

#endif // DATA_H_INCLUDED
