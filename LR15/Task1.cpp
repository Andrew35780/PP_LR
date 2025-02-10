#include <stdio.h>
#include <string.h>
#include <map>
#include <iostream>

#define WORDS_SIZE 1000

using namespace std;

void main() {
    setlocale(LC_CTYPE, "");
    system("color f0");

	char words[WORDS_SIZE];

    cout << "\nВведите строку слов: " << endl;
	fgets(words, WORDS_SIZE, stdin);

    words[strcspn(words, "\n")] = '\0';

	map<string, int> words_frequence;

	char separators[] = " ,_";
	char* context;
	char* lexem = strtok_s(words, separators, &context);

	while (lexem != NULL) {
		words_frequence[lexem]++;

		lexem = strtok_s(NULL, separators, &context);
	}

	multimap<int, string, greater<int>> sorted_words;

	for (const auto& [word, freq] : words_frequence)
		sorted_words.insert({ freq, word });

	cout << "\nСлова в порядке убывания частоты:\n";
	for (const auto& [freq, word] : sorted_words)
		cout << word << "\t" << freq << endl;
}

/*
//Переделанная программа на чистом C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORDS_SIZE 1000
#define MAX_WORDS 100

typedef struct {
    char word[50]; // Одно слово (до 50 символов)
    int count;     // Частота слова
} WordFreq;

// Функция для сортировки по убыванию частоты (для qsort)
int compare(const void* a, const void* b) {
    return ((WordFreq*)b)->count - ((WordFreq*)a)->count;
}

int main() {
    char words[WORDS_SIZE];
    WordFreq wordList[MAX_WORDS]; // Массив для хранения слов и их частоты
    int wordCount = 0; // Количество уникальных слов

    printf("Введите строку: ");
    fgets(words, WORDS_SIZE, stdin);

    // Удаляем символ новой строки, если он есть
    words[strcspn(words, "\n")] = '\0';

    char* separators = " ,_";
    char* lexem = strtok(words, separators);

    while (lexem != NULL) {
        // Проверяем, есть ли уже это слово в wordList
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(wordList[i].word, lexem) == 0) {
                wordList[i].count++; // Увеличиваем частоту
                found = 1;
                break;
            }
        }

        // Если слово новое, добавляем его в wordList
        if (!found && wordCount < MAX_WORDS) {
            strcpy(wordList[wordCount].word, lexem);
            wordList[wordCount].count = 1;
            wordCount++;
        }

        lexem = strtok(NULL, separators);
    }

    // Сортируем слова по убыванию частоты
    qsort(wordList, wordCount, sizeof(WordFreq), compare);

    printf("\nСлова в порядке убывания частоты:\n");
    for (int i = 0; i < wordCount; i++)
        printf("%s\t%d\n", wordList[i].word, wordList[i].count);

    return 0;
}
*/