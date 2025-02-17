#pragma once

#include <iostream>
#include "../LR16/Task.h"

#define ERROR_FILE_OPPENING -1;
#define SUCCESS 1;

int print_data_from_file(const char* file_name);
int write_data_to_file(const char* file_name, const game_t game, const char* mode);
