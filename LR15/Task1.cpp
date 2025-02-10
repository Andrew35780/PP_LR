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

    cout << "\n������� ������ ����: " << endl;
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

	cout << "\n����� � ������� �������� �������:\n";
	for (const auto& [freq, word] : sorted_words)
		cout << word << "\t" << freq << endl;
}

/*
//������������ ��������� �� ������ C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORDS_SIZE 1000
#define MAX_WORDS 100

typedef struct {
    char word[50]; // ���� ����� (�� 50 ��������)
    int count;     // ������� �����
} WordFreq;

// ������� ��� ���������� �� �������� ������� (��� qsort)
int compare(const void* a, const void* b) {
    return ((WordFreq*)b)->count - ((WordFreq*)a)->count;
}

int main() {
    char words[WORDS_SIZE];
    WordFreq wordList[MAX_WORDS]; // ������ ��� �������� ���� � �� �������
    int wordCount = 0; // ���������� ���������� ����

    printf("������� ������: ");
    fgets(words, WORDS_SIZE, stdin);

    // ������� ������ ����� ������, ���� �� ����
    words[strcspn(words, "\n")] = '\0';

    char* separators = " ,_";
    char* lexem = strtok(words, separators);

    while (lexem != NULL) {
        // ���������, ���� �� ��� ��� ����� � wordList
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(wordList[i].word, lexem) == 0) {
                wordList[i].count++; // ����������� �������
                found = 1;
                break;
            }
        }

        // ���� ����� �����, ��������� ��� � wordList
        if (!found && wordCount < MAX_WORDS) {
            strcpy(wordList[wordCount].word, lexem);
            wordList[wordCount].count = 1;
            wordCount++;
        }

        lexem = strtok(NULL, separators);
    }

    // ��������� ����� �� �������� �������
    qsort(wordList, wordCount, sizeof(WordFreq), compare);

    printf("\n����� � ������� �������� �������:\n");
    for (int i = 0; i < wordCount; i++)
        printf("%s\t%d\n", wordList[i].word, wordList[i].count);

    return 0;
}
*/