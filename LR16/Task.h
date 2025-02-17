#pragma once

typedef struct game_t
{
    char name[100];
    char platform[50];
    char genre[50];
    char age_rating[10];
    char format[20];
    char article[30];
    float price;
    float discount;
    unsigned int count;
    unsigned short release_year;
    bool is_used;
};

void print_game_disk(const game_t disc);