#pragma once

#include <iomanip>
#include <iostream>

typedef struct date_t {
    unsigned short year;
    unsigned short month;
    unsigned short day;
};

typedef struct game_t {
    char name[100];
    char platform[50];
    char genre[50];
    char age_rating[10];
    char format[20];
    float price;
    unsigned short discount;
    date_t release_date;
    unsigned int count;
    char article[30];
};

void fill_game_data(game_t* game);
void print_game_disk_header();
void print_game_disk(const game_t disc);
