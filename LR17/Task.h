#pragma once

#include <iostream>
#include "../LR16/Task.h"

#define ERROR_FILE_OPPENING -1;
#define SUCCESS 1;

typedef enum {
	WriteData = 1,
	AddData = 2,
	ReadData = 3,
	SelectByYear = 4,
	FinishWork = 5,
} operation;

void fill_game_data(game_t* game);
int print_data_from_file(const char* file_name);
//int write_data_to_file(const char* file_name, const game_t game, const char* mode);
int write_data_to_file(const char* file_name, const char* mode);
