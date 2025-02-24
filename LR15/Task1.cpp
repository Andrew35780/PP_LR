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