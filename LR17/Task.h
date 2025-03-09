#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "../LR16/Task.h"

#define ERROR_FILE_OPPENING -1;
#define SUCCESS 1;

typedef enum {
	WriteData = 1,
	AddData = 2,
	ReadData = 3,
	SelectByYear = 4,
	FindByName = 5,
	FinishWork = 6,
} operation;

int select_game_by_year(const char* orig_file_name, const char* new_file_name);
void print_game_data(const game_t game);
void print_game_table_header();
void fill_game_data(game_t* game);
int print_data_from_file(const char* file_name);
int write_data_to_file(const char* file_name, const char* mode);
int find_record_in_file_by_name(const char* file_name);
