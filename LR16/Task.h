#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iomanip>
#include <iostream>

typedef struct date_t {
    unsigned short year;
    unsigned short month;
    unsigned short day;
};

typedef struct game_t
{
    char name[100];
    char platform[50];
    char genre[50];
    char age_rating[10];
    char format[20];
    char article[30];
    float price;
    unsigned short discount;
    unsigned int count;
    date_t release_date;
};

void print_game_disk(const game_t disc);
void fill_game_data(game_t* game);
void print_game_disk_header();